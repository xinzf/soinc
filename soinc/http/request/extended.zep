//<?php
namespace Soinc\Http\Request;

/**
* Extend
*/
class Extended extends \Phalcon\Http\Request
{
    
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