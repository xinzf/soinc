
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/exit.h"
#include "kernel/string.h"
#include "kernel/hash.h"
#include "kernel/time.h"
#include "kernel/file.h"
#include "kernel/array.h"


/**
* Worker 
*/
ZEPHIR_INIT_CLASS(Soinc_Worker_Worker) {

	ZEPHIR_REGISTER_CLASS_EX(Soinc\\Worker, Worker, soinc, worker_worker, zephir_get_internal_ce(SS("phalcon\\mvc\\user\\component") TSRMLS_CC), soinc_worker_worker_method_entry, 0);

	zend_declare_property_bool(soinc_worker_worker_ce, SL("daemonize"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(soinc_worker_worker_ce, SL("name"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(soinc_worker_worker_ce, SL("stdoutFile"), "/dev/null", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(soinc_worker_worker_ce, SL("runtimePath"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(soinc_worker_worker_ce, SL("pidFile"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(soinc_worker_worker_ce, SL("logFile"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(soinc_worker_worker_ce, SL("statusFile"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(soinc_worker_worker_ce, SL("_masterPid"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * \Soinc\Worker\TaskAbstract
	 * @var Worker
	 */
	zend_declare_property_null(soinc_worker_worker_ce, SL("_task"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(soinc_worker_worker_ce, SL("_pids"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(soinc_worker_worker_ce, SL("_pidsToRestart"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(soinc_worker_worker_ce, SL("_pidsToShutdown"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(soinc_worker_worker_ce, SL("_status"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	soinc_worker_worker_ce->create_object = zephir_init_properties_Soinc_Worker_Worker;
	zend_declare_class_constant_long(soinc_worker_worker_ce, SL("STATUS_STARTING"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(soinc_worker_worker_ce, SL("STATUS_RUNNING"), 2 TSRMLS_CC);

	zend_declare_class_constant_long(soinc_worker_worker_ce, SL("STATUS_SHUTDOWN"), 4 TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Soinc_Worker_Worker, setDaemonize) {

	zval *flag_param = NULL;
	zend_bool flag;

	zephir_fetch_params(0, 0, 1, &flag_param);

	if (!flag_param) {
		flag = 1;
	} else {
		flag = zephir_get_boolval(flag_param);
	}


	if (flag) {
		zephir_update_property_this(this_ptr, SL("daemonize"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("daemonize"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	RETURN_THISW();

}

PHP_METHOD(Soinc_Worker_Worker, setRuntimePath) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, *_0 = NULL, _1$$3, *_2$$3 = NULL, _4$$4;
	zval *path = NULL, *_3$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	zephir_get_strval(path, path_param);


	ZEPHIR_CALL_FUNCTION(&_0, "is_dir", NULL, 8, path);
	zephir_check_call_status();
	if (!(zephir_is_true(_0))) {
		ZEPHIR_SINIT_VAR(_1$$3);
		ZVAL_LONG(&_1$$3, 0777);
		ZEPHIR_CALL_FUNCTION(&_2$$3, "mkdir", NULL, 36, path, &_1$$3, ZEPHIR_GLOBAL(global_true));
		zephir_check_call_status();
		if (!(zephir_is_true(_2$$3))) {
			ZEPHIR_INIT_VAR(_3$$4);
			ZEPHIR_CONCAT_SVS(_3$$4, "The folder: ", path, " is not exists or is not writeable\n");
			zend_print_zval(_3$$4, 0);
			ZEPHIR_MM_RESTORE();
			ZEPHIR_SINIT_VAR(_4$$4);
			ZVAL_LONG(&_4$$4, 255);
			zephir_exit(&_4$$4);
		}
	}
	zephir_update_property_this(this_ptr, SL("runtimePath"), path TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Soinc_Worker_Worker, setWorker) {

	zval *task;

	zephir_fetch_params(0, 1, 0, &task);



	zephir_update_property_this(this_ptr, SL("_task"), task TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Soinc_Worker_Worker, start) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initstart", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "daemonize", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "installsignal", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "savemasterpid", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "forkchildren", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "monitorworkers", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Soinc_Worker_Worker, restart) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "stop", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "reinstallsignal", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "start", NULL, 0);
	zephir_check_call_status();
	php_printf("%s", "Restart worker successfull!\n");
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Soinc_Worker_Worker, status) {

	


}

PHP_METHOD(Soinc_Worker_Worker, reload) {

	


}

PHP_METHOD(Soinc_Worker_Worker, stop) {

	zval *_0, _1, *pid$$3 = NULL, *_2$$3, _3$$3 = zval_used_for_init;
	zephir_fcall_cache_entry *_4 = NULL, *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initstop", NULL, 0);
	zephir_check_call_status();
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_masterPid"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, 2);
	ZEPHIR_CALL_FUNCTION(NULL, "posix_kill", NULL, 43, _0, &_1);
	zephir_check_call_status();
	php_printf("%s", "\nWaiting shutdown....\n");
	while (1) {
		if (!(1)) {
			break;
		}
		_2$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_masterPid"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_3$$3);
		ZVAL_LONG(&_3$$3, 0);
		ZEPHIR_CALL_FUNCTION(&pid$$3, "posix_kill", &_4, 43, _2$$3, &_3$$3);
		zephir_check_call_status();
		if (!(zephir_is_true(pid$$3))) {
			break;
		}
		ZEPHIR_SINIT_NVAR(_3$$3);
		ZVAL_LONG(&_3$$3, 7000);
		ZEPHIR_CALL_FUNCTION(NULL, "usleep", &_5, 44, &_3$$3);
		zephir_check_call_status();
	}
	php_printf("%s", "Success shutdown\n");
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Soinc_Worker_Worker, stopAll) {

	HashTable *_9$$3;
	HashPosition _8$$3;
	zval *mpid = NULL, *_0, *_2 = NULL, *_pids$$3 = NULL, *_pid$$3 = NULL, *_3$$3, *_4$$3, *_6$$3, *_7$$3, **_10$$3, _11$$4 = zval_used_for_init, *_13$$4 = NULL, *_14$$5, _15$$5;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_5 = NULL, *_12 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 4);
	zephir_update_property_this(this_ptr, SL("_status"), _0 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&mpid, "getmypid", &_1, 45);
	zephir_check_call_status();
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_masterPid"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_2, "getmypid", &_1, 45);
	zephir_check_call_status();
	if (ZEPHIR_IS_IDENTICAL(_0, _2)) {
		ZEPHIR_CALL_METHOD(&_pids$$3, this_ptr, "getallchildrenpids", NULL, 0);
		zephir_check_call_status();
		_3$$3 = zephir_fetch_nproperty_this(this_ptr, SL("name"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_4$$3);
		ZEPHIR_CONCAT_SVS(_4$$3, "Task[", _3$$3, "] Stopping...");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", &_5, 0, _4$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_6$$3);
		zephir_json_encode(_6$$3, &(_6$$3), _pids$$3, 0  TSRMLS_CC);
		ZEPHIR_INIT_VAR(_7$$3);
		ZEPHIR_CONCAT_SV(_7$$3, "pids:", _6$$3);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", &_5, 0, _7$$3);
		zephir_check_call_status();
		zephir_is_iterable(_pids$$3, &_9$$3, &_8$$3, 0, 0, "soinc/worker/worker.zep", 134);
		for (
		  ; zephir_hash_get_current_data_ex(_9$$3, (void**) &_10$$3, &_8$$3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_9$$3, &_8$$3)
		) {
			ZEPHIR_GET_HVALUE(_pid$$3, _10$$3);
			ZEPHIR_SINIT_NVAR(_11$$4);
			ZVAL_LONG(&_11$$4, 15);
			ZEPHIR_CALL_FUNCTION(NULL, "posix_kill", &_12, 43, _pid$$3, &_11$$4);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_13$$4);
			zephir_time(_13$$4);
			zephir_update_property_array(this_ptr, SL("_pidsToShutdown"), _pid$$3, _13$$4 TSRMLS_CC);
		}
	} else {
		_14$$5 = zephir_fetch_nproperty_this(this_ptr, SL("_task"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _14$$5, "onstop", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_MM_RESTORE();
		ZEPHIR_SINIT_VAR(_15$$5);
		ZVAL_LONG(&_15$$5, 0);
		zephir_exit(&_15$$5);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Soinc_Worker_Worker, init) {

	zval *_0, *_4, *_5 = NULL, *_6, *_9, *_1$$3, _3$$3, *_7$$4, _8$$4, *_10$$5 = NULL, *_12$$5, *_13$$5, *_14$$5 = NULL, *_15$$5, *_16$$5, *_17$$5 = NULL, *_18$$5, *_19$$5, *_20$$6, *_21$$6, _22$$6, *_23$$6, *_24$$6, *_25$$6, *_26$$6, _27$$6, *_28$$6, *_29$$6, *_30$$6, *_31$$6, _32$$6, *_33$$6, *_34$$6;
	zephir_fcall_cache_entry *_2 = NULL, *_11 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_task"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_0)) {
		ZEPHIR_INIT_VAR(_1$$3);
		ZVAL_STRING(_1$$3, "Please provide the Task!", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", &_2, 0, _1$$3);
		zephir_check_temp_parameter(_1$$3);
		zephir_check_call_status();
		ZEPHIR_MM_RESTORE();
		ZEPHIR_SINIT_VAR(_3$$3);
		ZVAL_LONG(&_3$$3, 0);
		zephir_exit(&_3$$3);
	}
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("_task"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_5, _4, "getname", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("name"), _5 TSRMLS_CC);
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("name"), PH_NOISY_CC);
	if (!(zephir_is_true(_6))) {
		ZEPHIR_INIT_VAR(_7$$4);
		ZVAL_STRING(_7$$4, "Please provide the Task's name!", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", &_2, 0, _7$$4);
		zephir_check_temp_parameter(_7$$4);
		zephir_check_call_status();
		ZEPHIR_MM_RESTORE();
		ZEPHIR_SINIT_VAR(_8$$4);
		ZVAL_LONG(&_8$$4, 0);
		zephir_exit(&_8$$4);
	}
	ZEPHIR_OBS_VAR(_9);
	zephir_read_property_this(&_9, this_ptr, SL("runtimePath"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_9)) {
		ZEPHIR_CALL_FUNCTION(&_10$$5, "sys_get_temp_dir", &_11, 46);
		zephir_check_call_status();
		_12$$5 = zephir_fetch_nproperty_this(this_ptr, SL("name"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_13$$5);
		ZEPHIR_CONCAT_VSVS(_13$$5, _10$$5, "/task.", _12$$5, ".pid");
		zephir_update_property_this(this_ptr, SL("pidFile"), _13$$5 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_14$$5, "sys_get_temp_dir", &_11, 46);
		zephir_check_call_status();
		_15$$5 = zephir_fetch_nproperty_this(this_ptr, SL("name"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_16$$5);
		ZEPHIR_CONCAT_VSVS(_16$$5, _14$$5, "/task.", _15$$5, ".log");
		zephir_update_property_this(this_ptr, SL("logFile"), _16$$5 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_17$$5, "sys_get_temp_dir", &_11, 46);
		zephir_check_call_status();
		_18$$5 = zephir_fetch_nproperty_this(this_ptr, SL("name"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_19$$5);
		ZEPHIR_CONCAT_VSVS(_19$$5, _17$$5, "/task.", _18$$5, ".status");
		zephir_update_property_this(this_ptr, SL("statusFile"), _19$$5 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_VAR(_20$$6);
		_21$$6 = zephir_fetch_nproperty_this(this_ptr, SL("runtimePath"), PH_NOISY_CC);
		ZEPHIR_SINIT_VAR(_22$$6);
		ZVAL_STRING(&_22$$6, "/", 0);
		zephir_fast_trim(_20$$6, _21$$6, &_22$$6, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
		_23$$6 = zephir_fetch_nproperty_this(this_ptr, SL("name"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_24$$6);
		ZEPHIR_CONCAT_VSVS(_24$$6, _20$$6, "/task.", _23$$6, ".pid");
		zephir_update_property_this(this_ptr, SL("pidFile"), _24$$6 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_25$$6);
		_26$$6 = zephir_fetch_nproperty_this(this_ptr, SL("runtimePath"), PH_NOISY_CC);
		ZEPHIR_SINIT_VAR(_27$$6);
		ZVAL_STRING(&_27$$6, "/", 0);
		zephir_fast_trim(_25$$6, _26$$6, &_27$$6, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
		_28$$6 = zephir_fetch_nproperty_this(this_ptr, SL("name"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_29$$6);
		ZEPHIR_CONCAT_VSVS(_29$$6, _25$$6, "/task.", _28$$6, ".log");
		zephir_update_property_this(this_ptr, SL("logFile"), _29$$6 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_30$$6);
		_31$$6 = zephir_fetch_nproperty_this(this_ptr, SL("runtimePath"), PH_NOISY_CC);
		ZEPHIR_SINIT_VAR(_32$$6);
		ZVAL_STRING(&_32$$6, "/", 0);
		zephir_fast_trim(_30$$6, _31$$6, &_32$$6, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
		_33$$6 = zephir_fetch_nproperty_this(this_ptr, SL("name"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_34$$6);
		ZEPHIR_CONCAT_VSVS(_34$$6, _30$$6, "/task.", _33$$6, ".status");
		zephir_update_property_this(this_ptr, SL("statusFile"), _34$$6 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Soinc_Worker_Worker, initStart) {

	zval *_0 = NULL, *_4, *_5, *_1$$3, *_2$$3, _3$$3;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "init", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isalive", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("name"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_2$$3);
		ZEPHIR_CONCAT_SVS(_2$$3, "task[", _1$$3, "] is running!");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, _2$$3);
		zephir_check_call_status();
		ZEPHIR_MM_RESTORE();
		ZEPHIR_SINIT_VAR(_3$$3);
		ZVAL_LONG(&_3$$3, 0);
		zephir_exit(&_3$$3);
	}
	ZEPHIR_INIT_ZVAL_NREF(_4);
	ZVAL_LONG(_4, 1);
	zephir_update_property_this(this_ptr, SL("_status"), _4 TSRMLS_CC);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("name"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_5);
	ZEPHIR_CONCAT_SV(_5, "task: master process ", _4);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setprocesstitle", NULL, 0, _5);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Soinc_Worker_Worker, initStop) {

	zval *_0 = NULL, *_4, *_5, *_1$$3, *_2$$3, _3$$3;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "init", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isalive", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(_0))) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("name"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_2$$3);
		ZEPHIR_CONCAT_SVS(_2$$3, "task[", _1$$3, "] is not running!");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, _2$$3);
		zephir_check_call_status();
		ZEPHIR_MM_RESTORE();
		ZEPHIR_SINIT_VAR(_3$$3);
		ZVAL_LONG(&_3$$3, 0);
		zephir_exit(&_3$$3);
	}
	ZEPHIR_INIT_VAR(_4);
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("pidFile"), PH_NOISY_CC);
	zephir_file_get_contents(_4, _5 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_masterPid"), _4 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Soinc_Worker_Worker, daemonize) {

	zval *_13;
	zval *_0, _1, *pid = NULL, *_7 = NULL, *_14, *_15, *_3$$4, _5$$4, _6$$5, *_8$$6, _9$$6, *_10$$7, _11$$7, _12$$8;
	zephir_fcall_cache_entry *_2 = NULL, *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("daemonize"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, 0);
	ZEPHIR_CALL_FUNCTION(NULL, "umask", NULL, 47, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&pid, "pcntl_fork", &_2, 48);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(pid, -1)) {
		ZEPHIR_INIT_VAR(_3$$4);
		ZVAL_STRING(_3$$4, "fork fail!", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", &_4, 0, _3$$4);
		zephir_check_temp_parameter(_3$$4);
		zephir_check_call_status();
		ZEPHIR_MM_RESTORE();
		ZEPHIR_SINIT_VAR(_5$$4);
		ZVAL_LONG(&_5$$4, 254);
		zephir_exit(&_5$$4);
	} else if (ZEPHIR_GT_LONG(pid, 0)) {
		ZEPHIR_MM_RESTORE();
		ZEPHIR_SINIT_VAR(_6$$5);
		ZVAL_LONG(&_6$$5, 0);
		zephir_exit(&_6$$5);
	}
	ZEPHIR_CALL_FUNCTION(&_7, "posix_setsid", NULL, 49);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(_7, -1)) {
		ZEPHIR_INIT_VAR(_8$$6);
		ZVAL_STRING(_8$$6, "setsid fail!", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", &_4, 0, _8$$6);
		zephir_check_temp_parameter(_8$$6);
		zephir_check_call_status();
		ZEPHIR_MM_RESTORE();
		ZEPHIR_SINIT_VAR(_9$$6);
		ZVAL_LONG(&_9$$6, 254);
		zephir_exit(&_9$$6);
	}
	ZEPHIR_CALL_FUNCTION(&pid, "pcntl_fork", &_2, 48);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(pid, -1)) {
		ZEPHIR_INIT_VAR(_10$$7);
		ZVAL_STRING(_10$$7, "fork fail!", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", &_4, 0, _10$$7);
		zephir_check_temp_parameter(_10$$7);
		zephir_check_call_status();
		ZEPHIR_MM_RESTORE();
		ZEPHIR_SINIT_VAR(_11$$7);
		ZVAL_LONG(&_11$$7, 254);
		zephir_exit(&_11$$7);
	} else if (!ZEPHIR_IS_LONG(pid, 0)) {
		ZEPHIR_MM_RESTORE();
		ZEPHIR_SINIT_VAR(_12$$8);
		ZVAL_LONG(&_12$$8, 0);
		zephir_exit(&_12$$8);
	}
	ZEPHIR_INIT_VAR(_13);
	zephir_create_array(_13, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_13, this_ptr);
	ZEPHIR_INIT_VAR(_14);
	ZVAL_STRING(_14, "stopAll", 1);
	zephir_array_fast_append(_13, _14);
	ZEPHIR_CALL_FUNCTION(NULL, "register_shutdown_function", NULL, 50, _13);
	zephir_check_call_status();
	_15 = zephir_fetch_nproperty_this(this_ptr, SL("_task"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _15, "onmasterstart", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Soinc_Worker_Worker, installSignal) {

	zval *_1 = NULL, _2 = zval_used_for_init, _7;
	zval *_0, *_4, *_5, *_6;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_0, this_ptr);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "signalHandler", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, 15);
	ZEPHIR_CALL_FUNCTION(NULL, "pcntl_signal", &_3, 51, &_2, _0, ZEPHIR_GLOBAL(global_false));
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_4);
	zephir_create_array(_4, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_4, this_ptr);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "signalHandler", 1);
	zephir_array_fast_append(_4, _1);
	ZEPHIR_SINIT_NVAR(_2);
	ZVAL_LONG(&_2, 2);
	ZEPHIR_CALL_FUNCTION(NULL, "pcntl_signal", &_3, 51, &_2, _4, ZEPHIR_GLOBAL(global_false));
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_5);
	zephir_create_array(_5, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_5, this_ptr);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "signalHandler", 1);
	zephir_array_fast_append(_5, _1);
	ZEPHIR_SINIT_NVAR(_2);
	ZVAL_LONG(&_2, 30);
	ZEPHIR_CALL_FUNCTION(NULL, "pcntl_signal", &_3, 51, &_2, _5, ZEPHIR_GLOBAL(global_false));
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_6);
	zephir_create_array(_6, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_6, this_ptr);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "signalHandler", 1);
	zephir_array_fast_append(_6, _1);
	ZEPHIR_SINIT_NVAR(_2);
	ZVAL_LONG(&_2, 31);
	ZEPHIR_CALL_FUNCTION(NULL, "pcntl_signal", &_3, 51, &_2, _6, ZEPHIR_GLOBAL(global_false));
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_2);
	ZVAL_LONG(&_2, 13);
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_LONG(&_7, 1);
	ZEPHIR_CALL_FUNCTION(NULL, "pcntl_signal", &_3, 51, &_2, &_7, ZEPHIR_GLOBAL(global_false));
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Soinc_Worker_Worker, reinstallSignal) {

	zval _0 = zval_used_for_init, _1 = zval_used_for_init;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 2);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, 1);
	ZEPHIR_CALL_FUNCTION(NULL, "pcntl_signal", &_2, 51, &_0, &_1, ZEPHIR_GLOBAL(global_false));
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 30);
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 1);
	ZEPHIR_CALL_FUNCTION(NULL, "pcntl_signal", &_2, 51, &_0, &_1, ZEPHIR_GLOBAL(global_false));
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 31);
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 1);
	ZEPHIR_CALL_FUNCTION(NULL, "pcntl_signal", &_2, 51, &_0, &_1, ZEPHIR_GLOBAL(global_false));
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "installsignal", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Soinc_Worker_Worker, signalHandler) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *signal, *_0, *_1$$4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &signal);



	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_SV(_0, "Signal:", signal);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, _0);
	zephir_check_call_status();
	do {
		if (ZEPHIR_IS_LONG(signal, 2) || ZEPHIR_IS_LONG(signal, 15)) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "stopall", NULL, 52);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_LONG(signal, 30)) {
			ZEPHIR_CALL_METHOD(&_1$$4, this_ptr, "getallchildrenpids", NULL, 0);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("_childrenToRestart"), _1$$4 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "reload", NULL, 0);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_LONG(signal, 31)) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "writetostatus", NULL, 0);
			zephir_check_call_status();
			break;
		}
		break;
	} while(0);

	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Soinc_Worker_Worker, saveMasterPid) {

	zval *_0 = NULL, *_1, *_2, *_3, *_8, *_9, *_10, *_4$$3, *_5$$3, _7$$3;
	zephir_fcall_cache_entry *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&_0, "getmypid", NULL, 45);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_masterPid"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("pidFile"), PH_NOISY_CC);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_masterPid"), PH_NOISY_CC);
	zephir_file_put_contents(_1, _2, _3 TSRMLS_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(_1)) {
		_4$$3 = zephir_fetch_nproperty_this(this_ptr, SL("pidFile"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_5$$3);
		ZEPHIR_CONCAT_SVS(_5$$3, "Can't save pid to ", _4$$3, "!");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", &_6, 0, _5$$3);
		zephir_check_call_status();
		ZEPHIR_MM_RESTORE();
		ZEPHIR_SINIT_VAR(_7$$3);
		ZVAL_LONG(&_7$$3, 254);
		zephir_exit(&_7$$3);
	}
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("name"), PH_NOISY_CC);
	_9 = zephir_fetch_nproperty_this(this_ptr, SL("_masterPid"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_10);
	ZEPHIR_CONCAT_SVSVS(_10, "task[", _8, "] master ", _9, " start success!");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", &_6, 0, _10);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Soinc_Worker_Worker, forkChildren) {

	zval *_0, *_1, *_2 = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	while (1) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_pids"), PH_NOISY_CC);
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_task"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_2, _1, "getprocessnum", NULL, 0);
		zephir_check_call_status();
		if (!(ZEPHIR_GT_LONG(_2, zephir_fast_count_int(_0 TSRMLS_CC)))) {
			break;
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "forkonechild", &_3, 53);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Soinc_Worker_Worker, forkOneChild) {

	zval *pid = NULL, *_0$$4, *mypid$$4 = NULL, *_1$$4, *_2$$4, *_3$$4 = NULL, *_4$$4, *_5$$4, *_6$$4 = NULL, *_7$$4, *_8$$4, *_9$$4, *_10$$4, _11$$4, *_12$$5, _13$$5;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&pid, "pcntl_fork", NULL, 48);
	zephir_check_call_status();
	if (ZEPHIR_GT_LONG(pid, 0)) {
		zephir_update_property_array(this_ptr, SL("_pids"), pid, pid TSRMLS_CC);
	} else if (ZEPHIR_IS_LONG(pid, 0)) {
		_0$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_status"), PH_NOISY_CC);
		if (ZEPHIR_IS_LONG(_0$$4, 1)) {
		}
		ZEPHIR_INIT_VAR(_1$$4);
		array_init(_1$$4);
		zephir_update_property_this(this_ptr, SL("_pids"), _1$$4 TSRMLS_CC);
		_2$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_task"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_3$$4, _2$$4, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_4$$4);
		ZEPHIR_CONCAT_SV(_4$$4, "Task: worker process ", _3$$4);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setprocesstitle", NULL, 0, _4$$4);
		zephir_check_call_status();
		_5$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_task"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_6$$4, _5$$4, "getuser", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setprocessuser", NULL, 0, _6$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&mypid$$4, "getmypid", NULL, 45);
		zephir_check_call_status();
		_7$$4 = zephir_fetch_nproperty_this(this_ptr, SL("name"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_8$$4);
		ZEPHIR_CONCAT_SVSVS(_8$$4, "Task[", _7$$4, "]: worker process ", mypid$$4, " start success!");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, _8$$4);
		zephir_check_call_status();
		_9$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_task"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _9$$4, "onstart", NULL, 0);
		zephir_check_call_status();
		_10$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_task"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _10$$4, "run", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_MM_RESTORE();
		ZEPHIR_SINIT_VAR(_11$$4);
		ZVAL_LONG(&_11$$4, 250);
		zephir_exit(&_11$$4);
	} else {
		ZEPHIR_INIT_VAR(_12$$5);
		ZVAL_STRING(_12$$5, "fork child fail\n", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, _12$$5);
		zephir_check_temp_parameter(_12$$5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "stopall", NULL, 52);
		zephir_check_call_status();
		ZEPHIR_MM_RESTORE();
		ZEPHIR_SINIT_VAR(_13$$5);
		ZVAL_LONG(&_13$$5, 254);
		zephir_exit(&_13$$5);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Soinc_Worker_Worker, displayUI) {

	


}

PHP_METHOD(Soinc_Worker_Worker, resetStd) {

	


}

PHP_METHOD(Soinc_Worker_Worker, monitorWorkers) {

	zval *_15$$7 = NULL;
	zval *_0, *pid$$3 = NULL, *_2$$3 = NULL, *_3$$3 = NULL, *_5$$4, *_11$$4, *_6$$6, _7$$6 = zval_used_for_init, *_8$$6 = NULL, *_10$$5, *_12$$8, _14$$7 = zval_used_for_init, *_16$$9 = NULL, *_17$$10, *_19$$10, *_20$$10 = NULL, *_21$$10, _22$$10 = zval_used_for_init;
	int ZEPHIR_LAST_CALL_STATUS, max, i, status$$3;
	zephir_fcall_cache_entry *_1 = NULL, *_4 = NULL, *_9 = NULL, *_13 = NULL, *_18 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 2);
	zephir_update_property_this(this_ptr, SL("_status"), _0 TSRMLS_CC);
	max = 10;
	i = 0;
	while (1) {
		if (!(1)) {
			break;
		}
		ZEPHIR_CALL_FUNCTION(NULL, "pcntl_signal_dispatch", &_1, 54);
		zephir_check_call_status();
		status$$3 = 0;
		ZEPHIR_INIT_NVAR(_2$$3);
		ZVAL_LONG(_2$$3, status$$3);
		ZEPHIR_INIT_NVAR(_3$$3);
		ZVAL_LONG(_3$$3, 2);
		ZEPHIR_MAKE_REF(_2$$3);
		ZEPHIR_CALL_FUNCTION(&pid$$3, "pcntl_wait", &_4, 55, _2$$3, _3$$3);
		ZEPHIR_UNREF(_2$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(NULL, "pcntl_signal_dispatch", &_1, 54);
		zephir_check_call_status();
		if (ZEPHIR_GT_LONG(pid$$3, 0)) {
			_5$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_pids"), PH_NOISY_CC);
			if (zephir_array_isset(_5$$4, pid$$3)) {
				if (status$$3 != 0) {
					_6$$6 = zephir_fetch_nproperty_this(this_ptr, SL("name"), PH_NOISY_CC);
					ZEPHIR_SINIT_NVAR(_7$$6);
					ZVAL_LONG(&_7$$6, status$$3);
					ZEPHIR_INIT_LNVAR(_8$$6);
					ZEPHIR_CONCAT_SVSVSV(_8$$6, "Task[", _6$$6, "]:", pid$$3, " exit with status ", &_7$$6);
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", &_9, 0, _8$$6);
					zephir_check_call_status();
				}
				_10$$5 = zephir_fetch_nproperty_this(this_ptr, SL("_pids"), PH_NOISY_CC);
				zephir_array_unset(&_10$$5, pid$$3, PH_SEPARATE);
			}
			_11$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_status"), PH_NOISY_CC);
			if (!ZEPHIR_IS_LONG_IDENTICAL(_11$$4, 4)) {
				if (i >= max) {
					ZEPHIR_INIT_ZVAL_NREF(_12$$8);
					ZVAL_LONG(_12$$8, 4);
					zephir_update_property_this(this_ptr, SL("_status"), _12$$8 TSRMLS_CC);
				}
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "forkchildren", &_13, 0);
				zephir_check_call_status();
				i = (i + 1);
				ZEPHIR_SINIT_NVAR(_14$$7);
				ZVAL_LONG(&_14$$7, i);
				ZEPHIR_INIT_LNVAR(_15$$7);
				ZEPHIR_CONCAT_SVS(_15$$7, "Try times:", &_14$$7, "\n");
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", &_9, 0, _15$$7);
				zephir_check_call_status();
			} else {
				ZEPHIR_OBS_NVAR(_16$$9);
				zephir_read_property_this(&_16$$9, this_ptr, SL("_pids"), PH_NOISY_CC);
				if (ZEPHIR_IS_EMPTY(_16$$9)) {
					_17$$10 = zephir_fetch_nproperty_this(this_ptr, SL("pidFile"), PH_NOISY_CC);
					ZEPHIR_CALL_FUNCTION(NULL, "unlink", &_18, 56, _17$$10);
					zephir_check_call_status();
					_19$$10 = zephir_fetch_nproperty_this(this_ptr, SL("name"), PH_NOISY_CC);
					ZEPHIR_INIT_LNVAR(_20$$10);
					ZEPHIR_CONCAT_SVS(_20$$10, "Task[", _19$$10, "] has been stopped!");
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", &_9, 0, _20$$10);
					zephir_check_call_status();
					_21$$10 = zephir_fetch_nproperty_this(this_ptr, SL("_task"), PH_NOISY_CC);
					ZEPHIR_CALL_METHOD(NULL, _21$$10, "onmasterstop", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_MM_RESTORE();
					ZEPHIR_SINIT_NVAR(_22$$10);
					ZVAL_LONG(&_22$$10, 0);
					zephir_exit(&_22$$10);
				}
			}
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Soinc_Worker_Worker, getCurrentUser) {

	zval *userinfo = NULL, *_0 = NULL, *_1;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(userinfo);
	array_init(userinfo);
	ZEPHIR_CALL_FUNCTION(&_0, "posix_getuid", NULL, 57);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&userinfo, "posix_getpwuid", NULL, 58, _0);
	zephir_check_call_status();
	zephir_array_fetch_string(&_1, userinfo, SL("name"), PH_NOISY | PH_READONLY, "soinc/worker/worker.zep", 384 TSRMLS_CC);
	RETURN_CTOR(_1);

}

PHP_METHOD(Soinc_Worker_Worker, setProcessUser) {

	zend_bool _0, _5, _10$$4;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *username_param = NULL, *_1 = NULL, *userinfo = NULL, *_3, *_4 = NULL, *_6, *_7 = NULL, *_8$$4, *_9$$4 = NULL, *_11$$4, *_12$$4 = NULL;
	zval *username = NULL, *_13$$5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &username_param);

	zephir_get_strval(username, username_param);


	_0 = ZEPHIR_IS_EMPTY(username);
	if (!(_0)) {
		ZEPHIR_CALL_FUNCTION(&_1, "posix_getuid", &_2, 57);
		zephir_check_call_status();
		_0 = !ZEPHIR_IS_LONG_IDENTICAL(_1, 0);
	}
	if (_0) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(userinfo);
	array_init(userinfo);
	ZEPHIR_CALL_FUNCTION(&userinfo, "posix_getpwnam", NULL, 59, username);
	zephir_check_call_status();
	zephir_array_fetch_string(&_3, userinfo, SL("uid"), PH_NOISY | PH_READONLY, "soinc/worker/worker.zep", 395 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_4, "posix_getuid", &_2, 57);
	zephir_check_call_status();
	_5 = !ZEPHIR_IS_EQUAL(_3, _4);
	if (!(_5)) {
		zephir_array_fetch_string(&_6, userinfo, SL("gid"), PH_NOISY | PH_READONLY, "soinc/worker/worker.zep", 395 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_7, "posix_getgid", NULL, 60);
		zephir_check_call_status();
		_5 = !ZEPHIR_IS_EQUAL(_6, _7);
	}
	if (_5) {
		zephir_array_fetch_string(&_8$$4, userinfo, SL("gid"), PH_NOISY | PH_READONLY, "soinc/worker/worker.zep", 396 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_9$$4, "posix_setgid", NULL, 61, _8$$4);
		zephir_check_call_status();
		_10$$4 = !zephir_is_true(_9$$4);
		if (!(_10$$4)) {
			zephir_array_fetch_string(&_11$$4, userinfo, SL("uid"), PH_NOISY | PH_READONLY, "soinc/worker/worker.zep", 396 TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&_12$$4, "posix_setuid", NULL, 62, _11$$4);
			zephir_check_call_status();
			_10$$4 = !zephir_is_true(_12$$4);
		}
		if (_10$$4) {
			ZEPHIR_INIT_VAR(_13$$5);
			ZEPHIR_CONCAT_SVS(_13$$5, "Notice: Can not run worker as ", username, ", You should be root");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, _13$$5);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Soinc_Worker_Worker, setProcessTitle) {

	zend_bool _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *title_param = NULL, _0, *_1 = NULL;
	zval *title = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &title_param);

	zephir_get_strval(title, title_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "proctitle", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "extension_loaded", NULL, 63, &_0);
	zephir_check_call_status();
	_2 = zephir_is_true(_1);
	if (_2) {
		_2 = (zephir_function_exists_ex(SS("proctitle") TSRMLS_CC) == SUCCESS);
	}
	if ((zephir_function_exists_ex(SS("cli_set_process_title") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_FUNCTION(NULL, "cli_set_process_title", NULL, 64, title);
		zephir_check_call_status();
	} else if (_2) {
		ZEPHIR_CALL_FUNCTION(NULL, "setproctitle", NULL, 65, title);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Soinc_Worker_Worker, log) {

	zend_bool _3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *msg = NULL, *_0$$3 = NULL, *_1 = NULL, *_2, *_4, *_5, _6 = zval_used_for_init, *_7 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &msg);

	ZEPHIR_SEPARATE_PARAM(msg);


	if (!(Z_TYPE_P(msg) == IS_STRING)) {
		ZEPHIR_CALL_FUNCTION(&_0$$3, "print_r", NULL, 66, msg, ZEPHIR_GLOBAL(global_true));
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(msg, _0$$3);
	}
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VS(_1, msg, "\n");
	ZEPHIR_CPY_WRT(msg, _1);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_status"), PH_NOISY_CC);
	_3 = ZEPHIR_IS_LONG(_2, 1);
	if (!(_3)) {
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("daemonize"), PH_NOISY_CC);
		_3 = !zephir_is_true(_4);
	}
	if (_3) {
		zend_print_zval(msg, 0);
	}
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("logFile"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_STRING(&_6, "Y-m-d H:i:s", 0);
	ZEPHIR_CALL_FUNCTION(&_7, "date", NULL, 37, &_6);
	zephir_check_call_status();
	ZEPHIR_INIT_LNVAR(_1);
	ZEPHIR_CONCAT_VSV(_1, _7, " ", msg);
	ZEPHIR_SINIT_NVAR(_6);
	ZVAL_LONG(&_6, 8);
	ZEPHIR_CALL_FUNCTION(NULL, "file_put_contents", NULL, 67, _5, _1, &_6);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Soinc_Worker_Worker, getAllChildrenPids) {

	

	RETURN_MEMBER(this_ptr, "_pids");

}

PHP_METHOD(Soinc_Worker_Worker, writeToStatus) {

	


}

PHP_METHOD(Soinc_Worker_Worker, isAlive) {

	zval *_0, *pid = NULL, *_1, *pid_is_alive = NULL, *_2$$4, _3$$5;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("pidFile"), PH_NOISY_CC);
	if (!((zephir_file_exists(_0 TSRMLS_CC) == SUCCESS))) {
		RETURN_MM_BOOL(0);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("pidFile"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(pid);
	zephir_file_get_contents(pid, _1 TSRMLS_CC);
	if (ZEPHIR_IS_EMPTY(pid)) {
		_2$$4 = zephir_fetch_nproperty_this(this_ptr, SL("pidFile"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "unlink", NULL, 56, _2$$4);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	if (zephir_is_true(pid)) {
		ZEPHIR_SINIT_VAR(_3$$5);
		ZVAL_LONG(&_3$$5, 0);
		ZEPHIR_CALL_FUNCTION(&pid_is_alive, "posix_kill", NULL, 43, pid, &_3$$5);
		zephir_check_call_status();
	}
	if (zephir_is_true(pid_is_alive)) {
		RETURN_MM_BOOL(1);
	} else {
		RETURN_MM_BOOL(0);
	}

}

zend_object_value zephir_init_properties_Soinc_Worker_Worker(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_2, *_4, *_1$$3, *_3$$4, *_5$$5;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_pidsToShutdown"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(this_ptr, SL("_pidsToShutdown"), _1$$3 TSRMLS_CC);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_pidsToRestart"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(_3$$4);
			array_init(_3$$4);
			zephir_update_property_this(this_ptr, SL("_pidsToRestart"), _3$$4 TSRMLS_CC);
		}
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_pids"), PH_NOISY_CC);
		if (Z_TYPE_P(_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(_5$$5);
			array_init(_5$$5);
			zephir_update_property_this(this_ptr, SL("_pids"), _5$$5 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

