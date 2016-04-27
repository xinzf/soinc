
extern zend_class_entry *soinc_worker_worker_ce;

ZEPHIR_INIT_CLASS(Soinc_Worker_Worker);

PHP_METHOD(Soinc_Worker_Worker, setDaemonize);
PHP_METHOD(Soinc_Worker_Worker, setRuntimePath);
PHP_METHOD(Soinc_Worker_Worker, setWorker);
PHP_METHOD(Soinc_Worker_Worker, start);
PHP_METHOD(Soinc_Worker_Worker, restart);
PHP_METHOD(Soinc_Worker_Worker, status);
PHP_METHOD(Soinc_Worker_Worker, reload);
PHP_METHOD(Soinc_Worker_Worker, stop);
PHP_METHOD(Soinc_Worker_Worker, stopAll);
PHP_METHOD(Soinc_Worker_Worker, init);
PHP_METHOD(Soinc_Worker_Worker, initStart);
PHP_METHOD(Soinc_Worker_Worker, initStop);
PHP_METHOD(Soinc_Worker_Worker, daemonize);
PHP_METHOD(Soinc_Worker_Worker, installSignal);
PHP_METHOD(Soinc_Worker_Worker, reinstallSignal);
PHP_METHOD(Soinc_Worker_Worker, signalHandler);
PHP_METHOD(Soinc_Worker_Worker, saveMasterPid);
PHP_METHOD(Soinc_Worker_Worker, forkChildren);
PHP_METHOD(Soinc_Worker_Worker, forkOneChild);
PHP_METHOD(Soinc_Worker_Worker, displayUI);
PHP_METHOD(Soinc_Worker_Worker, resetStd);
PHP_METHOD(Soinc_Worker_Worker, monitorWorkers);
PHP_METHOD(Soinc_Worker_Worker, getCurrentUser);
PHP_METHOD(Soinc_Worker_Worker, setProcessUser);
PHP_METHOD(Soinc_Worker_Worker, setProcessTitle);
PHP_METHOD(Soinc_Worker_Worker, log);
PHP_METHOD(Soinc_Worker_Worker, getAllChildrenPids);
PHP_METHOD(Soinc_Worker_Worker, writeToStatus);
PHP_METHOD(Soinc_Worker_Worker, isAlive);
zend_object_value zephir_init_properties_Soinc_Worker_Worker(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_worker_worker_setdaemonize, 0, 0, 0)
	ZEND_ARG_INFO(0, flag)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_worker_worker_setruntimepath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_worker_worker_setworker, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, task, Soinc\\Worker\\TaskAbstract, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_worker_worker_signalhandler, 0, 0, 1)
	ZEND_ARG_INFO(0, signal)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_worker_worker_setprocessuser, 0, 0, 1)
	ZEND_ARG_INFO(0, username)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_worker_worker_setprocesstitle, 0, 0, 1)
	ZEND_ARG_INFO(0, title)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_worker_worker_log, 0, 0, 1)
	ZEND_ARG_INFO(0, msg)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(soinc_worker_worker_method_entry) {
	PHP_ME(Soinc_Worker_Worker, setDaemonize, arginfo_soinc_worker_worker_setdaemonize, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Worker_Worker, setRuntimePath, arginfo_soinc_worker_worker_setruntimepath, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Worker_Worker, setWorker, arginfo_soinc_worker_worker_setworker, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Worker_Worker, start, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Worker_Worker, restart, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Worker_Worker, status, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Worker_Worker, reload, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Worker_Worker, stop, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Worker_Worker, stopAll, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Soinc_Worker_Worker, init, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Soinc_Worker_Worker, initStart, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Soinc_Worker_Worker, initStop, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Soinc_Worker_Worker, daemonize, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Soinc_Worker_Worker, installSignal, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Soinc_Worker_Worker, reinstallSignal, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Soinc_Worker_Worker, signalHandler, arginfo_soinc_worker_worker_signalhandler, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Worker_Worker, saveMasterPid, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Soinc_Worker_Worker, forkChildren, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Soinc_Worker_Worker, forkOneChild, NULL, ZEND_ACC_PRIVATE)
	PHP_ME(Soinc_Worker_Worker, displayUI, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Soinc_Worker_Worker, resetStd, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Soinc_Worker_Worker, monitorWorkers, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Soinc_Worker_Worker, getCurrentUser, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Worker_Worker, setProcessUser, arginfo_soinc_worker_worker_setprocessuser, ZEND_ACC_PROTECTED)
	PHP_ME(Soinc_Worker_Worker, setProcessTitle, arginfo_soinc_worker_worker_setprocesstitle, ZEND_ACC_PROTECTED)
	PHP_ME(Soinc_Worker_Worker, log, arginfo_soinc_worker_worker_log, ZEND_ACC_PROTECTED)
	PHP_ME(Soinc_Worker_Worker, getAllChildrenPids, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Worker_Worker, writeToStatus, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Soinc_Worker_Worker, isAlive, NULL, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
