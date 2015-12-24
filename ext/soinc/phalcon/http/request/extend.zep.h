
extern zend_class_entry *soinc_phalcon_http_request_extend_ce;

ZEPHIR_INIT_CLASS(Soinc_Phalcon_Http_Request_Extend);

PHP_METHOD(Soinc_Phalcon_Http_Request_Extend, fromMobile);
PHP_METHOD(Soinc_Phalcon_Http_Request_Extend, fromWeixin);
PHP_METHOD(Soinc_Phalcon_Http_Request_Extend, fromWeibo);
PHP_METHOD(Soinc_Phalcon_Http_Request_Extend, fromAndroid);
PHP_METHOD(Soinc_Phalcon_Http_Request_Extend, fromIOS);

ZEPHIR_INIT_FUNCS(soinc_phalcon_http_request_extend_method_entry) {
	PHP_ME(Soinc_Phalcon_Http_Request_Extend, fromMobile, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Phalcon_Http_Request_Extend, fromWeixin, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Phalcon_Http_Request_Extend, fromWeibo, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Phalcon_Http_Request_Extend, fromAndroid, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Phalcon_Http_Request_Extend, fromIOS, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
