
extern zend_class_entry *soinc_worker_taskabstract_ce;

ZEPHIR_INIT_CLASS(Soinc_Worker_TaskAbstract);

PHP_METHOD(Soinc_Worker_TaskAbstract, getName);
PHP_METHOD(Soinc_Worker_TaskAbstract, getCount);
PHP_METHOD(Soinc_Worker_TaskAbstract, getUser);
PHP_METHOD(Soinc_Worker_TaskAbstract, getOnStart);
PHP_METHOD(Soinc_Worker_TaskAbstract, getOnStop);
PHP_METHOD(Soinc_Worker_TaskAbstract, getOnError);
PHP_METHOD(Soinc_Worker_TaskAbstract, run);
PHP_METHOD(Soinc_Worker_TaskAbstract, stop);

ZEPHIR_INIT_FUNCS(soinc_worker_taskabstract_method_entry) {
	PHP_ME(Soinc_Worker_TaskAbstract, getName, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Worker_TaskAbstract, getCount, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Worker_TaskAbstract, getUser, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Worker_TaskAbstract, getOnStart, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Worker_TaskAbstract, getOnStop, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Worker_TaskAbstract, getOnError, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Worker_TaskAbstract, run, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Worker_TaskAbstract, stop, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};
