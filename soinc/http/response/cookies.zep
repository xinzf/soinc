namespace Soinc\Http\Response;

class Cookies
{
    protected expire        = 3600;
    protected domain        = "";
    protected path          = "/";
    protected secure        = false;
    protected httpOnly      = false;
    protected useEncryption = NULL;

    public function useEncryption(string serviceName) -> <\Soinc\Http\Response\Cookies>
    {
        let this->useEncryption = serviceName;
        return this;
    }

    public function getCrypt() -> string
    {
        return this->useEncryption;
    }

    public function setExpiration(int seconds) -> <\Soinc\Http\Response\Cookies>
    {
        if is_int(seconds) {
            let this->expire = seconds;
        }
        return this;
    }

    public function getExpiration() -> int
    {
        return this->expire;
    }

    public function setPath(string path) -> <\Soinc\Http\Response\Cookies>
    {
        let this->path = path;
        return this;
    }

    public function getPath() -> string
    {
        return this->path;
    }

    public function setDomain(string domain) -> <\Soinc\Http\Response\Cookies>
    {
        let this->domain = domain;
        return this;
    }

    public function getDomain() -> string
    {
        return this->domain;
    }

    public function setSecure(boolean secure) -> <\Soinc\Http\Response\Cookies>
    {
        let this->secure = secure;
        return this;
    }

    public function getSecure() -> boolean
    {
        return this->secure;
    }

    public function setHttpOnly(boolean only) -> <\Soinc\Http\Response\Cookies>
    {
        let this->httpOnly = only;
        return this;
    }

    public function getHttpOnly() -> boolean
    {
        return this->httpOnly;
    }

    public function get(string name) -> string
    {
        if ! this->has(name) {
            return "";
        }

        var value;
        let value = _COOKIE[name];

        if !empty(value) {
            if this->useEncryption {
                var crypt;
                let crypt = \Phalcon\Di::getDefault()->get(this->useEncryption);
                if !(crypt instanceof \Phalcon\CryptInterface) {
                    throw new \Exception("The encrypt is not extnds Phalcon\\CryptInterface");
                }
                let value = crypt->decryptBase64(value);
            }
        }

        return value;
    }

    public function set(string name, string value) -> boolean
    {
        if this->useEncryption {
            var crypt;
            let crypt = \Phalcon\Di::getDefault()->get(this->useEncryption);
            if !(crypt instanceof \Phalcon\CryptInterface) {
                throw new \Exception("The encrypt is not extnds Phalcon\\CryptInterface");
            }
            let value = crypt->encryptBase64(value);
        }
        return setcookie(name,value,time()+this->expire,this->path,this->domain,this->secure,this->httpOnly);
    }

    public function has(string name) -> boolean
    {
        return isset(_COOKIE[name]);
    }

    public function delete(string name) -> boolean
    {
        setcookie(name,"",time(),this->path,this->domain,this->secure,this->httpOnly);
        if this->has(name) {
            unset(_COOKIE[name]);
        }
        return true;
    }
}