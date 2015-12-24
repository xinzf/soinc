
extern zend_class_entry *soinc_com_bootstrap_ce;

ZEPHIR_INIT_CLASS(Soinc_Com_Bootstrap);

PHP_METHOD(Soinc_Com_Bootstrap, __construct);
PHP_METHOD(Soinc_Com_Bootstrap, initEnv);
PHP_METHOD(Soinc_Com_Bootstrap, initBaseService);
PHP_METHOD(Soinc_Com_Bootstrap, exec);
PHP_METHOD(Soinc_Com_Bootstrap, execTask);
PHP_METHOD(Soinc_Com_Bootstrap, getDI);
PHP_METHOD(Soinc_Com_Bootstrap, getEnv);
PHP_METHOD(Soinc_Com_Bootstrap, getConfig);
PHP_METHOD(Soinc_Com_Bootstrap, getAppPath);
static zend_object_value zephir_init_properties_Soinc_Com_Bootstrap(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_com_bootstrap___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, appPath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_com_bootstrap_exec, 0, 0, 0)
	ZEND_ARG_INFO(0, argv)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_com_bootstrap_exectask, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, argv, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(soinc_com_bootstrap_method_entry) {
	PHP_ME(Soinc_Com_Bootstrap, __construct, arginfo_soinc_com_bootstrap___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Soinc_Com_Bootstrap, initEnv, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Com_Bootstrap, initBaseService, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Soinc_Com_Bootstrap, exec, arginfo_soinc_com_bootstrap_exec, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Com_Bootstrap, execTask, arginfo_soinc_com_bootstrap_exectask, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Com_Bootstrap, getDI, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Com_Bootstrap, getEnv, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Com_Bootstrap, getConfig, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Com_Bootstrap, getAppPath, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
