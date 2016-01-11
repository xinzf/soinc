
extern zend_class_entry *soinc_exception_db_ce;

ZEPHIR_INIT_CLASS(Soinc_Exception_Db);

PHP_METHOD(Soinc_Exception_Db, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_exception_db___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_OBJ_INFO(0, logger, Phalcon\\Logger\\Adapter, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(soinc_exception_db_method_entry) {
	PHP_ME(Soinc_Exception_Db, __construct, arginfo_soinc_exception_db___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
