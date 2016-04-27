namespace Soinc;

abstract Class AbstractModule
{
    protected appPath;
    protected config;
    protected env;
    protected loader;
    protected di;
    private application;

    public function __get(name) {
        if (isset(this->{name})) {
            return this->{name};
        }
        else {
            return this->application->{name};
        }
    }

    final public function setBootstrap(<\Soinc\Bootstrap> bootstrap)
    {
        let this->appPath = bootstrap->getAppPath();
        let this->config  = bootstrap->getConfig();
        let this->env     = bootstrap->getEnv();
        let this->loader  = bootstrap->getLoader();
        let this->di      = bootstrap->getDi();
        let this->application     = bootstrap->getApplication();
    }

    public function init(){}

    abstract public function registerDirs();

    abstract public function registerNamespaces();

    abstract public function registerServices();

}