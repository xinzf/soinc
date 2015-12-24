
extern zend_class_entry *soinc_http_request_extended_ce;

ZEPHIR_INIT_CLASS(Soinc_Http_Request_Extended);

PHP_METHOD(Soinc_Http_Request_Extended, fromMobile);
PHP_METHOD(Soinc_Http_Request_Extended, fromWeixin);
PHP_METHOD(Soinc_Http_Request_Extended, fromWeibo);
PHP_METHOD(Soinc_Http_Request_Extended, fromAndroid);
PHP_METHOD(Soinc_Http_Request_Extended, fromIOS);

ZEPHIR_INIT_FUNCS(soinc_http_request_extended_method_entry) {
	PHP_ME(Soinc_Http_Request_Extended, fromMobile, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Http_Request_Extended, fromWeixin, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Http_Request_Extended, fromWeibo, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Http_Request_Extended, fromAndroid, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Http_Request_Extended, fromIOS, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
