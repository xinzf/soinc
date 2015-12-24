//<?php

namespace Soinc\Http\Curl;

class Extended {

    private handle     = null;

    private url        = null;

    private port       = null;

    private headers    = [];

    private cookie     = null;

    private user_agent = null;

    private referer    = null;

    private postdata   = [];

    private defaultHeaders = [];

    private defaultOptions = [];

    private _http_code = [];

    private response_headers = [];
    private response_body = [];
    private lastRequest = "";

    private error = "";

    public function __construct() {
        let this->defaultHeaders = [
            "Accept"          : "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8",
            "Accept-Encoding" : "gzip,deflate,sdch",
            "Accept-Language" : "zh-CN,zh;q=0.8,en;q=0.6",
            "Cache-Control"   : "max-age=0",
            "Connection"      : "keep-alive",
            "Expect"          : ""
        ];
        let this->defaultOptions = [
            CURLOPT_RETURNTRANSFER  : true,
            CURLOPT_AUTOREFERER     : true,
            CURLOPT_FOLLOWLOCATION  : true,
            CURLOPT_MAXREDIRS       : 20,
            CURLOPT_HEADER          : true,
            CURLOPT_USERAGENT       : "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_9_3) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/37.0.2062.122 Safari/537.36",
            CURLOPT_CONNECTTIMEOUT  : 30,
            CURLOPT_TIMEOUT         : 30,
            CURLOPT_AUTOREFERER     : true,
            CURLOPT_FAILONERROR     : false,
            CURLOPT_ENCODING        : "gzip",
            CURLOPT_SSL_VERIFYPEER  : false
        ];
        let this->_http_code = [
            0    : "Unable to access",
            // Informational 1xx
            100 : "Continue",
            101 : "Switching Protocols",

            // Success 2xx
            200 : "OK",
            201 : "Created",
            202 : "Accepted",
            203 : "Non-Authoritative Information",
            204 : "No Content",
            205 : "Reset Content",
            206 : "Partial Content",

            // Redirection 3xx
            300 : "Multiple Choices",
            301 : "Moved Permanently",
            302 : "Found",  // 1.1
            303 : "See Other",
            304 : "Not Modified",
            305 : "Use Proxy",
            // 306 is deprecated but reserved
            307 : "Temporary Redirect",

            // Client Error 4xx
            400 : "Bad Request",
            401 : "Unauthorized",
            402 : "Payment Required",
            403 : "Forbidden",
            404 : "Not Found",
            405 : "Method Not Allowed",
            406 : "Not Acceptable",
            407 : "Proxy Authentication Required",
            408 : "Request Timeout",
            409 : "Conflict",
            410 : "Gone",
            411 : "Length Required",
            412 : "Precondition Failed",
            413 : "Request Entity Too Large",
            414 : "Request-URI Too Long",
            415 : "Unsupported Media Type",
            416 : "Requested Range Not Satisfiable",
            417 : "Expectation Failed",

            // Server Error 5xx
            500 : "Internal Server Error",
            501 : "Not Implemented",
            502 : "Bad Gateway",
            503 : "Service Unavailable",
            504 : "Gateway Timeout",
            505 : "HTTP Version Not Supported",
            509 : "Bandwidth Limit Exceeded"
        ];
    }

    public function close() {
       if is_resource(this->handle) {
            curl_close(this->handle);
            let this->handle           = null;
            let this->url              = null;
            let this->port             = null;
            let this->headers          = [];
            let this->cookie           = null;
            let this->postdata         = [];
        }
    }

    public function setUrl(string! url) {
        let this->url = url;
        return this;
    }

    public function setPort(int! port) {
        if !is_integer(port) {
            throw new \Exception("http port in not ingeter", 1);
        }
        let this->port = port;
        return this;
    }

    public function setPostData(postdata) {
        if is_array(postdata) {
            let this->postdata = http_build_query(postdata);
        }
        else {
            let this->postdata = postdata;
        }

        return this;
    }

    public function setCookie(string! file) {
        let this->cookie = file;
        return this;
    }

    public function setUserAgent(string! userAgent) {
        let this->user_agent = userAgent;
        return this;
    }

    public function setHeader(string! name, string! value) {
        let this->headers[name] = value;
        return this;
    }

    public function setReferer(string! referer) {
        let this->referer = referer;
        return this;
    }

    public function send() {

        this->close();

        let this->handle = curl_init();
        curl_setopt_array(this->handle,this->defaultOptions);

        array headers = [];
        var temp;
        var key;
        var value;
        let temp = array_merge(this->defaultHeaders,this->headers);
        for key, value in temp {
            let headers[] = key . ":" . value;
        }

        // let temp = null;
        // unset(temp);

        curl_setopt(this->handle, CURLOPT_URL, this->url);
        curl_setopt(this->handle, CURLOPT_HTTPHEADER, headers);
        if this->user_agent {
            curl_setopt(this->handle, CURLOPT_USERAGENT, this->user_agent);
        }

        if !empty(this->postdata) {
            if is_array(this->postdata) {
                let this->postdata = http_build_query(this->postdata);
            }
            curl_setopt(this->handle, CURLOPT_POSTFIELDS, this->postdata);
            curl_setopt(this->handle, CURLOPT_POST, true);
        }

        if this->port {
            curl_setopt(this->handle, CURLOPT_PORT, this->port);
        }

        if !empty(this->cookie) {
            curl_setopt(this->handle, CURLOPT_COOKIEJAR, this->cookie);
            curl_setopt(this->handle, CURLOPT_COOKIEFILE, this->cookie);
        }

        if !empty(this->referer) {
            curl_setopt(this->handle, CURLOPT_REFERER, this->referer);
        }

        var response;
        var errcode;
        let response = curl_exec(this->handle);
        let this->lastRequest = this->url;
        let errcode = curl_errno(this->handle);
        if errcode != 0 {
            let this->error = curl_error(this->handle);
            return false;
        }

        var httpCode;
        var codes = [200,304];
        let httpCode = curl_getinfo(this->handle,CURLINFO_HTTP_CODE);
        if !in_array(httpCode, codes) {
            let this->error = isset(this->_http_code[httpCode])
                      ? this->_http_code[httpCode] : "Unknow error";
            return false;
        }

        this->parseResponse(response);
        this->close();
        return this->response_body;
    }

    private function parseResponse(string response) {

        var header_size;
        var header;
        let header_size = curl_getinfo(this->handle, CURLINFO_HEADER_SIZE);
        let header = substr(response, 0, header_size);
        let this->response_body = substr(response, header_size);

        let header = explode("\n\r", header);

        var key;
        var value;
        for key, value in header {
            let value = trim(value);
            if empty(value) {
                continue;
            }

            var temp;
            let temp = explode("\n", value);
            var k;
            var v;
            for k, v in temp {
                if strlen(v) < 1 {
                    continue;
                }

                if substr($v, 0, 4) == "HTTP" {
                    continue;
                }

                var pos;
                var headerKey;
                var headerVal;
                let pos = strpos(v,":");
                let headerKey = substr(v, 0, pos);
                let headerVal = substr(v, pos+1);
                let headerKey = trim(headerKey);
                let headerVal = trim(headerVal);

                let this->response_headers[key][headerKey] = headerVal;
            }
        }
        return true;
    }

    public function getResponseHeaders() -> array
    {
        return this->response_headers;
    }

    public function getLastRequest() -> string
    {
        return this->lastRequest;
    }

    public function getError() -> string
    {
        return this->error;
    }

    public function setOptions(array! options){
        if !is_array(options) {
            return false;
        }

        var key;
        var item;
        for key, item in options {
            let this->defaultOptions[key] = item;
        }

        return this;
    }
}
