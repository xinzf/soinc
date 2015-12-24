namespace Soinc;

abstract Class AbstractModule
{
    protected appPath;
    protected config;
    protected env;

    final public function setBootstrap(<\Soinc\Bootstrap> bootstrap)
    {
        let this->appPath = bootstrap->getAppPath();
        let this->config = bootstrap->getConfig();
        let this->env = bootstrap->getEnv();
    }

    abstract public function registerDirs();

    abstract public function registerNamespaces();

    abstract public function registerServices();

}