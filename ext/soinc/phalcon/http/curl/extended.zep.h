
extern zend_class_entry *soinc_phalcon_http_curl_extended_ce;

ZEPHIR_INIT_CLASS(Soinc_Phalcon_Http_Curl_Extended);

PHP_METHOD(Soinc_Phalcon_Http_Curl_Extended, __construct);
PHP_METHOD(Soinc_Phalcon_Http_Curl_Extended, close);
PHP_METHOD(Soinc_Phalcon_Http_Curl_Extended, setUrl);
PHP_METHOD(Soinc_Phalcon_Http_Curl_Extended, setPort);
PHP_METHOD(Soinc_Phalcon_Http_Curl_Extended, setPostData);
PHP_METHOD(Soinc_Phalcon_Http_Curl_Extended, setCookie);
PHP_METHOD(Soinc_Phalcon_Http_Curl_Extended, setUserAgent);
PHP_METHOD(Soinc_Phalcon_Http_Curl_Extended, setHeader);
PHP_METHOD(Soinc_Phalcon_Http_Curl_Extended, setReferer);
PHP_METHOD(Soinc_Phalcon_Http_Curl_Extended, send);
PHP_METHOD(Soinc_Phalcon_Http_Curl_Extended, parseResponse);
PHP_METHOD(Soinc_Phalcon_Http_Curl_Extended, getResponseHeaders);
PHP_METHOD(Soinc_Phalcon_Http_Curl_Extended, getLastRequest);
PHP_METHOD(Soinc_Phalcon_Http_Curl_Extended, getError);
PHP_METHOD(Soinc_Phalcon_Http_Curl_Extended, setOptions);
static zend_object_value zephir_init_properties_Soinc_Phalcon_Http_Curl_Extended(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_phalcon_http_curl_extended_seturl, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_phalcon_http_curl_extended_setport, 0, 0, 1)
	ZEND_ARG_INFO(0, port)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_phalcon_http_curl_extended_setpostdata, 0, 0, 1)
	ZEND_ARG_INFO(0, postdata)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_phalcon_http_curl_extended_setcookie, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_phalcon_http_curl_extended_setuseragent, 0, 0, 1)
	ZEND_ARG_INFO(0, userAgent)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_phalcon_http_curl_extended_setheader, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_phalcon_http_curl_extended_setreferer, 0, 0, 1)
	ZEND_ARG_INFO(0, referer)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_phalcon_http_curl_extended_parseresponse, 0, 0, 1)
	ZEND_ARG_INFO(0, response)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_phalcon_http_curl_extended_setoptions, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(soinc_phalcon_http_curl_extended_method_entry) {
	PHP_ME(Soinc_Phalcon_Http_Curl_Extended, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Soinc_Phalcon_Http_Curl_Extended, close, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Phalcon_Http_Curl_Extended, setUrl, arginfo_soinc_phalcon_http_curl_extended_seturl, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Phalcon_Http_Curl_Extended, setPort, arginfo_soinc_phalcon_http_curl_extended_setport, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Phalcon_Http_Curl_Extended, setPostData, arginfo_soinc_phalcon_http_curl_extended_setpostdata, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Phalcon_Http_Curl_Extended, setCookie, arginfo_soinc_phalcon_http_curl_extended_setcookie, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Phalcon_Http_Curl_Extended, setUserAgent, arginfo_soinc_phalcon_http_curl_extended_setuseragent, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Phalcon_Http_Curl_Extended, setHeader, arginfo_soinc_phalcon_http_curl_extended_setheader, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Phalcon_Http_Curl_Extended, setReferer, arginfo_soinc_phalcon_http_curl_extended_setreferer, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Phalcon_Http_Curl_Extended, send, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Phalcon_Http_Curl_Extended, parseResponse, arginfo_soinc_phalcon_http_curl_extended_parseresponse, ZEND_ACC_PRIVATE)
	PHP_ME(Soinc_Phalcon_Http_Curl_Extended, getResponseHeaders, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Phalcon_Http_Curl_Extended, getLastRequest, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Phalcon_Http_Curl_Extended, getError, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Phalcon_Http_Curl_Extended, setOptions, arginfo_soinc_phalcon_http_curl_extended_setoptions, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
