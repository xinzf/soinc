
extern zend_class_entry *soinc_abstractmodule_ce;

ZEPHIR_INIT_CLASS(Soinc_AbstractModule);

PHP_METHOD(Soinc_AbstractModule, __get);
PHP_METHOD(Soinc_AbstractModule, setBootstrap);
PHP_METHOD(Soinc_AbstractModule, init);
PHP_METHOD(Soinc_AbstractModule, registerDirs);
PHP_METHOD(Soinc_AbstractModule, registerNamespaces);
PHP_METHOD(Soinc_AbstractModule, registerServices);

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_abstractmodule___get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_abstractmodule_setbootstrap, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, bootstrap, Soinc\\Bootstrap, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(soinc_abstractmodule_method_entry) {
	PHP_ME(Soinc_AbstractModule, __get, arginfo_soinc_abstractmodule___get, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_AbstractModule, setBootstrap, arginfo_soinc_abstractmodule_setbootstrap, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_AbstractModule, init, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_AbstractModule, registerDirs, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_AbstractModule, registerNamespaces, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_AbstractModule, registerServices, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};
