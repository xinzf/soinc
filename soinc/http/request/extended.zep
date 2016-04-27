//<?php
namespace Soinc\Http\Request;

/**
* Extend
*/
class Extended extends \Phalcon\Http\Request
{
    protected allowds = [];

    public function setAllowed(iplist) {
        let this->allowds = array_merge(this->allowds,iplist);
        return true;
    }

    private function compareIp(clientIp,serverIp) {
        if (strpos(serverIp,"*") !== false) {
            var key;
            var num;

            let clientIp = explode(".",clientIp);
            let serverIp = explode(".",serverIp);

            for key,num in serverIp {
                if (num === "*" || (num === clientIp[key])) {
                    continue;
                }
                else {
                    return false;
                }
            }   
            return true;
        }
        elseif (clientIp === serverIp) {
            return true;
        }
        else {
            return false;
        }
    }

    public function isAllowed() {
        var clientIp;
        var currentIp;
        var serverIp;

        let clientIp  = this->getClientAddress();
        let currentIp = this->getServerAddress();

        if clientIp === currentIp {
            return true;
        }

        if !this->allowds {
            return true;
        }

        for serverIp in this->allowds {
            if this->compareIp(clientIp,serverIp) {
                return true;
            }
        }

        echo "Forbidden!";
        exit();
    }
    
    public function fromMobile()
    {
        if this->fromAndroid() || this->fromIOS() {
            return true;
        }
        elseif this->fromIOS() {
            return true;
        }
        else {
            return false;
        }
    }

    public function fromWeixin()
    {
        var userAgent;
        let userAgent = strtolower(this->getUserAgent());
        return strpos(userAgent,"micromessenger");
    }

    // 通过User-Agent判断客户端是否为微博
    public function fromWeibo()
    {
        var userAgent;
        let userAgent = strtolower(this->getUserAgent());
        return strpos(userAgent,"weibo");
    }

    public function fromAndroid()
    {
        var userAgent;
        let userAgent = strtolower(this->getUserAgent());
        return strpos(userAgent,"android");
    }

    public function fromIOS()
    {
        var userAgent;
        let userAgent = strtolower(this->getUserAgent());
        return strpos(userAgent,"iphone");
    }
}