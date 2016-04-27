
extern zend_class_entry *soinc_http_request_extended_ce;

ZEPHIR_INIT_CLASS(Soinc_Http_Request_Extended);

PHP_METHOD(Soinc_Http_Request_Extended, setAllowed);
PHP_METHOD(Soinc_Http_Request_Extended, compareIp);
PHP_METHOD(Soinc_Http_Request_Extended, isAllowed);
PHP_METHOD(Soinc_Http_Request_Extended, fromMobile);
PHP_METHOD(Soinc_Http_Request_Extended, fromWeixin);
PHP_METHOD(Soinc_Http_Request_Extended, fromWeibo);
PHP_METHOD(Soinc_Http_Request_Extended, fromAndroid);
PHP_METHOD(Soinc_Http_Request_Extended, fromIOS);
zend_object_value zephir_init_properties_Soinc_Http_Request_Extended(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_http_request_extended_setallowed, 0, 0, 1)
	ZEND_ARG_INFO(0, iplist)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_http_request_extended_compareip, 0, 0, 2)
	ZEND_ARG_INFO(0, clientIp)
	ZEND_ARG_INFO(0, serverIp)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(soinc_http_request_extended_method_entry) {
	PHP_ME(Soinc_Http_Request_Extended, setAllowed, arginfo_soinc_http_request_extended_setallowed, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Http_Request_Extended, compareIp, arginfo_soinc_http_request_extended_compareip, ZEND_ACC_PRIVATE)
	PHP_ME(Soinc_Http_Request_Extended, isAllowed, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Http_Request_Extended, fromMobile, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Http_Request_Extended, fromWeixin, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Http_Request_Extended, fromWeibo, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Http_Request_Extended, fromAndroid, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Http_Request_Extended, fromIOS, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
