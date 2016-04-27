
extern zend_class_entry *soinc_worker_taskabstract_ce;

ZEPHIR_INIT_CLASS(Soinc_Worker_TaskAbstract);

PHP_METHOD(Soinc_Worker_TaskAbstract, getName);
PHP_METHOD(Soinc_Worker_TaskAbstract, getProcessNum);
PHP_METHOD(Soinc_Worker_TaskAbstract, getUser);
PHP_METHOD(Soinc_Worker_TaskAbstract, onMasterStart);
PHP_METHOD(Soinc_Worker_TaskAbstract, onMasterStop);
PHP_METHOD(Soinc_Worker_TaskAbstract, onStart);
PHP_METHOD(Soinc_Worker_TaskAbstract, onStop);
PHP_METHOD(Soinc_Worker_TaskAbstract, run);

ZEPHIR_INIT_FUNCS(soinc_worker_taskabstract_method_entry) {
	PHP_ME(Soinc_Worker_TaskAbstract, getName, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Worker_TaskAbstract, getProcessNum, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Worker_TaskAbstract, getUser, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Worker_TaskAbstract, onMasterStart, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Worker_TaskAbstract, onMasterStop, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Worker_TaskAbstract, onStart, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Worker_TaskAbstract, onStop, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Worker_TaskAbstract, run, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};
