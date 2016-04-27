
extern zend_class_entry *soinc_bootstrap_ce;

ZEPHIR_INIT_CLASS(Soinc_Bootstrap);

PHP_METHOD(Soinc_Bootstrap, __construct);
PHP_METHOD(Soinc_Bootstrap, initEnv);
PHP_METHOD(Soinc_Bootstrap, initBaseService);
PHP_METHOD(Soinc_Bootstrap, exec);
PHP_METHOD(Soinc_Bootstrap, execTask);
PHP_METHOD(Soinc_Bootstrap, execWeb);
PHP_METHOD(Soinc_Bootstrap, execMicro);
PHP_METHOD(Soinc_Bootstrap, getApplication);
PHP_METHOD(Soinc_Bootstrap, getDi);
PHP_METHOD(Soinc_Bootstrap, getEnv);
PHP_METHOD(Soinc_Bootstrap, getConfig);
PHP_METHOD(Soinc_Bootstrap, getAppPath);
PHP_METHOD(Soinc_Bootstrap, getLoader);
PHP_METHOD(Soinc_Bootstrap, load);
PHP_METHOD(Soinc_Bootstrap, loaderModule);
zend_object_value zephir_init_properties_Soinc_Bootstrap(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_bootstrap___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, appPath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_bootstrap_exec, 0, 0, 0)
	ZEND_ARG_INFO(0, argv)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_bootstrap_exectask, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, argv, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_bootstrap_execweb, 0, 0, 0)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_bootstrap_execmicro, 0, 0, 0)
	ZEND_ARG_INFO(0, argv)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_bootstrap_load, 0, 0, 1)
	ZEND_ARG_INFO(0, filePath)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(soinc_bootstrap_method_entry) {
	PHP_ME(Soinc_Bootstrap, __construct, arginfo_soinc_bootstrap___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Soinc_Bootstrap, initEnv, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Bootstrap, initBaseService, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Soinc_Bootstrap, exec, arginfo_soinc_bootstrap_exec, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Bootstrap, execTask, arginfo_soinc_bootstrap_exectask, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Bootstrap, execWeb, arginfo_soinc_bootstrap_execweb, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Bootstrap, execMicro, arginfo_soinc_bootstrap_execmicro, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Bootstrap, getApplication, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Bootstrap, getDi, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Bootstrap, getEnv, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Bootstrap, getConfig, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Bootstrap, getAppPath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Bootstrap, getLoader, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Bootstrap, load, arginfo_soinc_bootstrap_load, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Bootstrap, loaderModule, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
