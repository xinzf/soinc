
extern zend_class_entry *soinc_exception_ce;

ZEPHIR_INIT_CLASS(Soinc_Exception);

PHP_METHOD(Soinc_Exception, __construct);
PHP_METHOD(Soinc_Exception, getLevel);
PHP_METHOD(Soinc_Exception, setCode);
PHP_METHOD(Soinc_Exception, setLevel);

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_exception___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, code)
	ZEND_ARG_OBJ_INFO(0, logger, Phalcon\\Logger\\Adapter, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_exception_setcode, 0, 0, 1)
	ZEND_ARG_INFO(0, code)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_exception_setlevel, 0, 0, 1)
	ZEND_ARG_INFO(0, level)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(soinc_exception_method_entry) {
	PHP_ME(Soinc_Exception, __construct, arginfo_soinc_exception___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Soinc_Exception, getLevel, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Exception, setCode, arginfo_soinc_exception_setcode, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Exception, setLevel, arginfo_soinc_exception_setlevel, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
