
extern zend_class_entry *soinc_http_response_cookies_ce;

ZEPHIR_INIT_CLASS(Soinc_Http_Response_Cookies);

PHP_METHOD(Soinc_Http_Response_Cookies, useEncryption);
PHP_METHOD(Soinc_Http_Response_Cookies, getCrypt);
PHP_METHOD(Soinc_Http_Response_Cookies, setExpiration);
PHP_METHOD(Soinc_Http_Response_Cookies, getExpiration);
PHP_METHOD(Soinc_Http_Response_Cookies, setPath);
PHP_METHOD(Soinc_Http_Response_Cookies, getPath);
PHP_METHOD(Soinc_Http_Response_Cookies, setDomain);
PHP_METHOD(Soinc_Http_Response_Cookies, getDomain);
PHP_METHOD(Soinc_Http_Response_Cookies, setSecure);
PHP_METHOD(Soinc_Http_Response_Cookies, getSecure);
PHP_METHOD(Soinc_Http_Response_Cookies, setHttpOnly);
PHP_METHOD(Soinc_Http_Response_Cookies, getHttpOnly);
PHP_METHOD(Soinc_Http_Response_Cookies, get);
PHP_METHOD(Soinc_Http_Response_Cookies, set);
PHP_METHOD(Soinc_Http_Response_Cookies, has);
PHP_METHOD(Soinc_Http_Response_Cookies, delete);

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_http_response_cookies_useencryption, 0, 0, 1)
	ZEND_ARG_INFO(0, serviceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_http_response_cookies_setexpiration, 0, 0, 1)
	ZEND_ARG_INFO(0, seconds)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_http_response_cookies_setpath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_http_response_cookies_setdomain, 0, 0, 1)
	ZEND_ARG_INFO(0, domain)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_http_response_cookies_setsecure, 0, 0, 1)
	ZEND_ARG_INFO(0, secure)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_http_response_cookies_sethttponly, 0, 0, 1)
	ZEND_ARG_INFO(0, only)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_http_response_cookies_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_http_response_cookies_set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_http_response_cookies_has, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_http_response_cookies_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(soinc_http_response_cookies_method_entry) {
	PHP_ME(Soinc_Http_Response_Cookies, useEncryption, arginfo_soinc_http_response_cookies_useencryption, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Http_Response_Cookies, getCrypt, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Http_Response_Cookies, setExpiration, arginfo_soinc_http_response_cookies_setexpiration, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Http_Response_Cookies, getExpiration, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Http_Response_Cookies, setPath, arginfo_soinc_http_response_cookies_setpath, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Http_Response_Cookies, getPath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Http_Response_Cookies, setDomain, arginfo_soinc_http_response_cookies_setdomain, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Http_Response_Cookies, getDomain, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Http_Response_Cookies, setSecure, arginfo_soinc_http_response_cookies_setsecure, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Http_Response_Cookies, getSecure, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Http_Response_Cookies, setHttpOnly, arginfo_soinc_http_response_cookies_sethttponly, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Http_Response_Cookies, getHttpOnly, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Http_Response_Cookies, get, arginfo_soinc_http_response_cookies_get, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Http_Response_Cookies, set, arginfo_soinc_http_response_cookies_set, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Http_Response_Cookies, has, arginfo_soinc_http_response_cookies_has, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Http_Response_Cookies, delete, arginfo_soinc_http_response_cookies_delete, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
