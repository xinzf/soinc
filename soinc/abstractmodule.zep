namespace Soinc;

abstract Class AbstractModule
{
    protected appPath;
    protected config;
    protected env;
    protected loader;

    final public function setBootstrap(<\Soinc\Bootstrap> bootstrap)
    {
        let this->appPath = bootstrap->getAppPath();
        let this->config  = bootstrap->getConfig();
        let this->env     = bootstrap->getEnv();
        let this->loader  = bootstrap->getLoader();
    }

    abstract public function registerDirs();

    abstract public function registerNamespaces();

    abstract public function registerServices();

}