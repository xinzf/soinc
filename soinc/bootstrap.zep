//<?php
namespace Soinc;

// if !class_exists("\Phalcon\Loader",false) {
    // error_log("Soinc must requied Phalcon Framework!");
    // exit();
// }

/**
* Bootsrap
*/
final class Bootstrap
{
    const CONFIG_DIR_NAME = "config";

    protected config;

    protected di;

    protected appPath;

    protected loader;

    protected modeMap = [
        "Web"     : "Web",
        "Cli"     : "Task",
        "Micro"   : "Micro"
    ];

    protected env = "dev";

    public function __construct(string! appPath)
    {
        if (!is_dir(appPath)) {
            throw new \Exception("The application path is not exists", 1);
        }
        let this->appPath = rtrim(appPath, "/") . "/";
        let this->loader = new \Phalcon\Loader;
    }

    public function initEnv()
    {
        var env;
        let env = get_cfg_var("soinc.env");
        if !empty(env) {
            let this->env = env;
        }

        if this->env != "product" {
            var debug;
            let debug = new \Phalcon\Debug();
            debug->listen();
        }

        var globalConfig;
        let globalConfig = get_cfg_var("soinc.global_conf");
        if globalConfig {
            if !file_exists(globalConfig) {
                throw new \Exception("The global configure file is not exists! Detail: ".globalConfig, 1);
            }
            let this->config = new \Phalcon\Config\Adapter\Php(globalConfig);
        }
        else {
            let this->config = new \Phalcon\Config;
        }

        var appConfigPath;
        let appConfigPath = this->appPath . "config/".this->env.".php";
        if file_exists(appConfigPath) {
            this->config->merge(new \Phalcon\Config(this->load(appConfigPath)));
        }

        var paths = [];
        let paths = [this->appPath];
        this->loader->registerDirs(paths)->register();
    }

    protected function initBaseService()
    {
        this->di->setShared("bootstrap", this);
        this->di->setShared("loader",this->loader);
        this->di->setShared("config",this->config);
    }

    public function exec(var argv = null)
    {
        this->initEnv();
        if !isset(this->modeMap[ucfirst(this->config->application->mode)]) {
            throw new \Exception("Unsupported mode");
        }

        if (!isset(this->config->application->mode)) {
            throw new \Exception("Miss the application mode configure!", 1);
        }

        var handleMethod;
        let handleMethod = "exec" . this->modeMap[ucfirst(this->config->application->mode)];
        this->{handleMethod}(argv);
    }

    public function execTask(array argv)
    {
        var console;

        let this->di = new \Phalcon\DI\FactoryDefault\CLI();
        let console = new \Phalcon\ClI\Console();
        console->setDI(this->di);

        this->initBaseService();
        this->loaderModule();

        if count(argv) < 3 {
            var err;
            let err = "Error: Requires at least one 'task' and an 'action' parameters!".PHP_EOL;
            echo err;
            exit(255);
        }

        array arguments = [];
        var task;
        var action;
        var params = [];

        let task = argv[1];
        let action = argv[2];
        unset(argv[0]);
        unset(argv[1]);
        unset(argv[2]);
        let params = array_values(argv);
        let arguments = ["task":task,"action":action,"params":params];
        console->handle(arguments);
    }

    public function execWeb(string! uri = null)
    {
        var application;
        let this->di = new \Phalcon\DI\FactoryDefault();
        let application = new \Phalcon\Mvc\Application();
        application->setDI(this->di);

        this->initBaseService();
        this->loaderModule();

        var e;
        try {
            echo application->handle(uri)->getContent();
        } catch \Phalcon\Mvc\Application\Exception, e {
            var str;
            let str = e->getMessage()."[{e->getFile()}: {e->getLine()}]\n".e->getTraceAsString();
            echo nl2br(str);
        }
    }

    public function execMicro(var argv = null) 
    {
        var app, e, handleFiles, index, file, response;
        let this->di = new \Phalcon\DI\FactoryDefault();
        let app = new \Phalcon\Mvc\Micro();
        let {"app"} = app;
        let handleFiles = array_merge(glob(this->appPath."handlers/*.php"),glob(this->appPath."handlers/*/*.php"));

        try {
            app->setDI(this->di);

            this->initBaseService();
            this->loaderModule();

            for index, file in handleFiles {
                require file;
            }

            let response = app->handle();
            if response instanceof \Phalcon\Http\ResponseInterface {
                response->send();
            }
        } catch \Phalcon\Exception, e {
            echo e->getMessage();
        } catch \Exception, e {
            echo e->getMessage();
        }
    }

    public function getDI() -> <\Phalcon\DI>
    {
        return this->di;
    }

    public function getEnv() -> string
    {
        return this->env;
    }

    public function getConfig() -> <\Phalcon\Config>
    {
        return this->config;
    }

    public function getAppPath() -> string
    {
        return this->appPath;
    }

    public function getLoader() -> <\Phalcon\Loader>
    {
        return this->loader;
    }

    public function load(var filePath)
    {
        let {"loader"}   = this->loader;
        let {"config"}   = this->config;
        let {"bootstrap"}   = this;
        let {"di"}          = this->di;
        return require filePath;
    }

    public function loaderModule()
    {
        if ! file_exists(this->appPath."Module.php") {
            throw new \Exception("Miss the Module.php");
        }

        var module,dirs,namespaces,services;
        this->load(this->appPath."Module.php");
        let module = new \Module;
        if ! (module instanceof \Soinc\AbstractModule) {
            throw new \Exception("The module is not extends \Soinc\AbstractModule");
        }

        module->setBootstrap(this);
        let dirs       = module->registerDirs();
        let namespaces = module->registerNamespaces();

        this->loader->registerDirs(dirs,true);
        this->loader->registerNamespaces(namespaces,true);
        this->loader->register();

        let services   = module->registerServices();
        var name,obj;
        for name,obj in services {
            this->di->setShared(name,obj);
        }
    }
}