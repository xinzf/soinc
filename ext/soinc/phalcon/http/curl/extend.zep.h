
extern zend_class_entry *soinc_phalcon_http_curl_extend_ce;

ZEPHIR_INIT_CLASS(Soinc_Phalcon_Http_Curl_Extend);

PHP_METHOD(Soinc_Phalcon_Http_Curl_Extend, __construct);
PHP_METHOD(Soinc_Phalcon_Http_Curl_Extend, __destruct);
PHP_METHOD(Soinc_Phalcon_Http_Curl_Extend, close);
PHP_METHOD(Soinc_Phalcon_Http_Curl_Extend, setUrl);
PHP_METHOD(Soinc_Phalcon_Http_Curl_Extend, setPort);
PHP_METHOD(Soinc_Phalcon_Http_Curl_Extend, setPostData);
PHP_METHOD(Soinc_Phalcon_Http_Curl_Extend, setCookie);
PHP_METHOD(Soinc_Phalcon_Http_Curl_Extend, setUserAgent);
PHP_METHOD(Soinc_Phalcon_Http_Curl_Extend, setHeader);
PHP_METHOD(Soinc_Phalcon_Http_Curl_Extend, setReferer);
PHP_METHOD(Soinc_Phalcon_Http_Curl_Extend, send);
PHP_METHOD(Soinc_Phalcon_Http_Curl_Extend, parseResponse);
PHP_METHOD(Soinc_Phalcon_Http_Curl_Extend, getResponseHeaders);
PHP_METHOD(Soinc_Phalcon_Http_Curl_Extend, getLastRequest);
PHP_METHOD(Soinc_Phalcon_Http_Curl_Extend, getError);
PHP_METHOD(Soinc_Phalcon_Http_Curl_Extend, setOptions);
static zend_object_value zephir_init_properties_Soinc_Phalcon_Http_Curl_Extend(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_phalcon_http_curl_extend_seturl, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_phalcon_http_curl_extend_setport, 0, 0, 1)
	ZEND_ARG_INFO(0, port)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_phalcon_http_curl_extend_setpostdata, 0, 0, 1)
	ZEND_ARG_INFO(0, postdata)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_phalcon_http_curl_extend_setcookie, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_phalcon_http_curl_extend_setuseragent, 0, 0, 1)
	ZEND_ARG_INFO(0, userAgent)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_phalcon_http_curl_extend_setheader, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_phalcon_http_curl_extend_setreferer, 0, 0, 1)
	ZEND_ARG_INFO(0, referer)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_phalcon_http_curl_extend_parseresponse, 0, 0, 1)
	ZEND_ARG_INFO(0, response)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_phalcon_http_curl_extend_setoptions, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(soinc_phalcon_http_curl_extend_method_entry) {
	PHP_ME(Soinc_Phalcon_Http_Curl_Extend, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Soinc_Phalcon_Http_Curl_Extend, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_ME(Soinc_Phalcon_Http_Curl_Extend, close, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Phalcon_Http_Curl_Extend, setUrl, arginfo_soinc_phalcon_http_curl_extend_seturl, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Phalcon_Http_Curl_Extend, setPort, arginfo_soinc_phalcon_http_curl_extend_setport, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Phalcon_Http_Curl_Extend, setPostData, arginfo_soinc_phalcon_http_curl_extend_setpostdata, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Phalcon_Http_Curl_Extend, setCookie, arginfo_soinc_phalcon_http_curl_extend_setcookie, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Phalcon_Http_Curl_Extend, setUserAgent, arginfo_soinc_phalcon_http_curl_extend_setuseragent, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Phalcon_Http_Curl_Extend, setHeader, arginfo_soinc_phalcon_http_curl_extend_setheader, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Phalcon_Http_Curl_Extend, setReferer, arginfo_soinc_phalcon_http_curl_extend_setreferer, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Phalcon_Http_Curl_Extend, send, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Phalcon_Http_Curl_Extend, parseResponse, arginfo_soinc_phalcon_http_curl_extend_parseresponse, ZEND_ACC_PRIVATE)
	PHP_ME(Soinc_Phalcon_Http_Curl_Extend, getResponseHeaders, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Phalcon_Http_Curl_Extend, getLastRequest, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Phalcon_Http_Curl_Extend, getError, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Phalcon_Http_Curl_Extend, setOptions, arginfo_soinc_phalcon_http_curl_extend_setoptions, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
