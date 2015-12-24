
extern zend_class_entry *soinc_module_ce;

ZEPHIR_INIT_CLASS(Soinc_Module);

PHP_METHOD(Soinc_Module, setBootstrap);
PHP_METHOD(Soinc_Module, getDI);
PHP_METHOD(Soinc_Module, getLoader);
PHP_METHOD(Soinc_Module, getConfig);

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_module_setbootstrap, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, bootstrap, Soinc\\Bootstrap, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(soinc_module_method_entry) {
	PHP_ME(Soinc_Module, setBootstrap, arginfo_soinc_module_setbootstrap, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Module, getDI, NULL, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Module, getLoader, NULL, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Module, getConfig, NULL, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_FE_END
};
