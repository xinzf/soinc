
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/exit.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/file.h"
#include "kernel/array.h"
#include "kernel/require.h"
#include "kernel/hash.h"


/**
* Bootsrap
*/
ZEPHIR_INIT_CLASS(Soinc_Bootstrap) {

	ZEPHIR_REGISTER_CLASS(Soinc, Bootstrap, soinc, bootstrap, soinc_bootstrap_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_declare_property_null(soinc_bootstrap_ce, SL("config"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(soinc_bootstrap_ce, SL("di"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(soinc_bootstrap_ce, SL("appPath"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(soinc_bootstrap_ce, SL("loader"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(soinc_bootstrap_ce, SL("application"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(soinc_bootstrap_ce, SL("modeMap"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(soinc_bootstrap_ce, SL("env"), "dev", ZEND_ACC_PROTECTED TSRMLS_CC);

	soinc_bootstrap_ce->create_object = zephir_init_properties_Soinc_Bootstrap;
	zend_declare_class_constant_string(soinc_bootstrap_ce, SL("CONFIG_DIR_NAME"), "config" TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Soinc_Bootstrap, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *appPath_param = NULL, _0, *_2 = NULL, *_6, _7, *_8, *_9, _1$$3, *_3$$4, *_4$$4, *_5$$4;
	zval *appPath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &appPath_param);

	if (unlikely(Z_TYPE_P(appPath_param) != IS_STRING && Z_TYPE_P(appPath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'appPath' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(appPath_param) == IS_STRING)) {
		zephir_get_strval(appPath, appPath_param);
	} else {
		ZEPHIR_INIT_VAR(appPath);
		ZVAL_EMPTY_STRING(appPath);
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "\\Phalcon\\Loader", 0);
	if (!(zephir_class_exists(&_0, zephir_is_true(ZEPHIR_GLOBAL(global_false))  TSRMLS_CC))) {
		ZEPHIR_SINIT_VAR(_1$$3);
		ZVAL_STRING(&_1$$3, "Soinc must requied Phalcon Framework!", 0);
		ZEPHIR_CALL_FUNCTION(NULL, "error_log", NULL, 7, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_MM_RESTORE();
		zephir_exit_empty();
	}
	ZEPHIR_CALL_FUNCTION(&_2, "is_dir", NULL, 8, appPath);
	zephir_check_call_status();
	if (!zephir_is_true(_2)) {
		ZEPHIR_INIT_VAR(_3$$4);
		object_init_ex(_3$$4, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(_4$$4);
		ZVAL_STRING(_4$$4, "The application path is not exists", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_5$$4);
		ZVAL_LONG(_5$$4, 1);
		ZEPHIR_CALL_METHOD(NULL, _3$$4, "__construct", NULL, 9, _4$$4, _5$$4);
		zephir_check_temp_parameter(_4$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_3$$4, "soinc/bootstrap.zep", 36 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(_6);
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_STRING(&_7, "/", 0);
	zephir_fast_trim(_6, appPath, &_7, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	ZEPHIR_INIT_VAR(_8);
	ZEPHIR_CONCAT_VS(_8, _6, "/");
	zephir_update_property_this(this_ptr, SL("appPath"), _8 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_9);
	object_init_ex(_9, zephir_get_internal_ce(SS("phalcon\\loader") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, _9, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("loader"), _9 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Soinc_Bootstrap, initEnv) {

	zval *env = NULL, _0 = zval_used_for_init, *globalConfig = NULL, *appConfigPath = NULL, *_10, *_11, *paths = NULL, *_17, *_18, *_19 = NULL, *composer = NULL, *_2$$5, *_3$$5, *_4$$5, *ext$$4 = NULL, _5$$4, *_6$$6, *_7$$7, *_8$$8, *_9$$9, *_12$$10, *_13$$10, *_14$$10 = NULL, *_15$$11, *_16$$11, *_20$$13, *_21$$13, *_22$$13;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "soinc.env", 0);
	ZEPHIR_CALL_FUNCTION(&env, "get_cfg_var", &_1, 10, &_0);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(env))) {
		zephir_update_property_this(this_ptr, SL("env"), env TSRMLS_CC);
	}
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "soinc.conf", 0);
	ZEPHIR_CALL_FUNCTION(&globalConfig, "get_cfg_var", &_1, 10, &_0);
	zephir_check_call_status();
	if (zephir_is_true(globalConfig)) {
		if (!((zephir_file_exists(globalConfig TSRMLS_CC) == SUCCESS))) {
			ZEPHIR_INIT_VAR(_2$$5);
			object_init_ex(_2$$5, zend_exception_get_default(TSRMLS_C));
			ZEPHIR_INIT_VAR(_3$$5);
			ZEPHIR_CONCAT_SV(_3$$5, "The global configure file is not exists! Detail: ", globalConfig);
			ZEPHIR_INIT_VAR(_4$$5);
			ZVAL_LONG(_4$$5, 1);
			ZEPHIR_CALL_METHOD(NULL, _2$$5, "__construct", NULL, 9, _3$$5, _4$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(_2$$5, "soinc/bootstrap.zep", 60 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_SINIT_VAR(_5$$4);
		ZVAL_LONG(&_5$$4, 4);
		ZEPHIR_CALL_FUNCTION(&ext$$4, "pathinfo", NULL, 11, globalConfig, &_5$$4);
		zephir_check_call_status();
		if (ZEPHIR_IS_STRING(ext$$4, "ini")) {
			ZEPHIR_INIT_VAR(_6$$6);
			object_init_ex(_6$$6, zephir_get_internal_ce(SS("phalcon\\config\\adapter\\ini") TSRMLS_CC));
			ZEPHIR_CALL_METHOD(NULL, _6$$6, "__construct", NULL, 0, globalConfig);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("config"), _6$$6 TSRMLS_CC);
		} else if (ZEPHIR_IS_STRING(ext$$4, "php")) {
			ZEPHIR_INIT_VAR(_7$$7);
			object_init_ex(_7$$7, zephir_get_internal_ce(SS("phalcon\\config\\adapter\\php") TSRMLS_CC));
			ZEPHIR_CALL_METHOD(NULL, _7$$7, "__construct", NULL, 0, globalConfig);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("config"), _7$$7 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_VAR(_8$$8);
			object_init_ex(_8$$8, zephir_get_internal_ce(SS("phalcon\\config") TSRMLS_CC));
			ZEPHIR_CALL_METHOD(NULL, _8$$8, "__construct", NULL, 0);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("config"), _8$$8 TSRMLS_CC);
		}
	} else {
		ZEPHIR_INIT_VAR(_9$$9);
		object_init_ex(_9$$9, zephir_get_internal_ce(SS("phalcon\\config") TSRMLS_CC));
		ZEPHIR_CALL_METHOD(NULL, _9$$9, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("config"), _9$$9 TSRMLS_CC);
	}
	_10 = zephir_fetch_nproperty_this(this_ptr, SL("appPath"), PH_NOISY_CC);
	_11 = zephir_fetch_nproperty_this(this_ptr, SL("env"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(appConfigPath);
	ZEPHIR_CONCAT_VSVS(appConfigPath, _10, "Config/", _11, ".php");
	if ((zephir_file_exists(appConfigPath TSRMLS_CC) == SUCCESS)) {
		_12$$10 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_13$$10);
		object_init_ex(_13$$10, zephir_get_internal_ce(SS("phalcon\\config") TSRMLS_CC));
		ZEPHIR_CALL_METHOD(&_14$$10, this_ptr, "load", NULL, 12, appConfigPath);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _13$$10, "__construct", NULL, 0, _14$$10);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _12$$10, "merge", NULL, 0, _13$$10);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(_15$$11);
		object_init_ex(_15$$11, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(_16$$11);
		ZEPHIR_CONCAT_SVS(_16$$11, "The config file:", appConfigPath, " not exists!");
		ZEPHIR_CALL_METHOD(NULL, _15$$11, "__construct", NULL, 9, _16$$11);
		zephir_check_call_status();
		zephir_throw_exception_debug(_15$$11, "soinc/bootstrap.zep", 85 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(paths);
	array_init(paths);
	ZEPHIR_INIT_NVAR(paths);
	zephir_create_array(paths, 1, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(_17);
	zephir_read_property_this(&_17, this_ptr, SL("appPath"), PH_NOISY_CC);
	zephir_array_fast_append(paths, _17);
	_18 = zephir_fetch_nproperty_this(this_ptr, SL("loader"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_19, _18, "registerdirs", NULL, 0, paths);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, _19, "register", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "soinc.composer", 0);
	ZEPHIR_CALL_FUNCTION(&composer, "get_cfg_var", &_1, 10, &_0);
	zephir_check_call_status();
	if (zephir_is_true(composer)) {
		if (!((zephir_file_exists(composer TSRMLS_CC) == SUCCESS))) {
			ZEPHIR_INIT_VAR(_20$$13);
			object_init_ex(_20$$13, zend_exception_get_default(TSRMLS_C));
			ZEPHIR_INIT_VAR(_21$$13);
			ZEPHIR_CONCAT_SV(_21$$13, "The composer autoload file is not exists! Detail: ", composer);
			ZEPHIR_INIT_VAR(_22$$13);
			ZVAL_LONG(_22$$13, 1);
			ZEPHIR_CALL_METHOD(NULL, _20$$13, "__construct", NULL, 9, _21$$13, _22$$13);
			zephir_check_call_status();
			zephir_throw_exception_debug(_20$$13, "soinc/bootstrap.zep", 96 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (zephir_require_zval(composer TSRMLS_CC) == FAILURE) {
			RETURN_MM_NULL();
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Soinc_Bootstrap, initBaseService) {

	zval *_0, *_1 = NULL, *_2, *_3, *_4, *_5;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "bootstrap", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _0, "setshared", NULL, 0, _1, this_ptr);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("loader"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "loader", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _2, "setshared", NULL, 0, _1, _3);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "config", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _4, "setshared", NULL, 0, _1, _5);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Soinc_Bootstrap, exec) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *argv = NULL, *_0, *_1, *_2, *_3, *_4, *_5, *_6, *handleMethod = NULL, *_10, *_11, *_12, *_13, *_14, *_15, *_7$$4, *_8$$4, *_9$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &argv);

	if (!argv) {
		argv = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initenv", NULL, 13);
	zephir_check_call_status();
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("modeMap"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_3);
	zephir_read_property(&_3, _2, SL("application"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_4);
	zephir_read_property(&_4, _3, SL("mode"), PH_NOISY_CC);
	zephir_ucfirst(_1, _4);
	if (!(zephir_array_isset(_0, _1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "Unsupported mode", "soinc/bootstrap.zep", 113);
		return;
	}
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_6);
	zephir_read_property(&_6, _5, SL("application"), PH_NOISY_CC);
	if (!(zephir_isset_property(_6, SS("mode") TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_7$$4);
		object_init_ex(_7$$4, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(_8$$4);
		ZVAL_STRING(_8$$4, "Miss the application mode configure!", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_9$$4);
		ZVAL_LONG(_9$$4, 1);
		ZEPHIR_CALL_METHOD(NULL, _7$$4, "__construct", NULL, 9, _8$$4, _9$$4);
		zephir_check_temp_parameter(_8$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_7$$4, "soinc/bootstrap.zep", 117 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_10 = zephir_fetch_nproperty_this(this_ptr, SL("modeMap"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_12);
	_13 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_14);
	zephir_read_property(&_14, _13, SL("application"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_15);
	zephir_read_property(&_15, _14, SL("mode"), PH_NOISY_CC);
	zephir_ucfirst(_12, _15);
	zephir_array_fetch(&_11, _10, _12, PH_NOISY | PH_READONLY, "soinc/bootstrap.zep", 121 TSRMLS_CC);
	ZEPHIR_INIT_VAR(handleMethod);
	ZEPHIR_CONCAT_SV(handleMethod, "exec", _11);
	ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, handleMethod, NULL, 0, argv);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Soinc_Bootstrap, execTask) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *argv_param = NULL, *_0, *_1, *_2, *_3, *task = NULL, *action = NULL, *params = NULL, *_6, *err$$3 = NULL, *_4$$3, _5$$3;
	zval *argv = NULL, *arguments = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &argv_param);

	zephir_get_arrval(argv, argv_param);


	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, zephir_get_internal_ce(SS("phalcon\\di\\factorydefault\\cli") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("di"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	object_init_ex(_1, zephir_get_internal_ce(SS("phalcon\\cli\\console") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("application"), _1 TSRMLS_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("application"), PH_NOISY_CC);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _2, "setdi", NULL, 0, _3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initbaseservice", NULL, 14);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "loadermodule", NULL, 15);
	zephir_check_call_status();
	if (zephir_fast_count_int(argv TSRMLS_CC) < 3) {
		ZEPHIR_INIT_VAR(_4$$3);
		ZEPHIR_GET_CONSTANT(_4$$3, "PHP_EOL");
		ZEPHIR_INIT_VAR(err$$3);
		ZEPHIR_CONCAT_SV(err$$3, "Error: Requires at least one 'task' and an 'action' parameters!", _4$$3);
		zend_print_zval(err$$3, 0);
		ZEPHIR_MM_RESTORE();
		ZEPHIR_SINIT_VAR(_5$$3);
		ZVAL_LONG(&_5$$3, 255);
		zephir_exit(&_5$$3);
	}
	ZEPHIR_INIT_VAR(arguments);
	array_init(arguments);
	ZEPHIR_INIT_VAR(params);
	array_init(params);
	ZEPHIR_OBS_VAR(task);
	zephir_array_fetch_long(&task, argv, 1, PH_NOISY, "soinc/bootstrap.zep", 146 TSRMLS_CC);
	ZEPHIR_OBS_VAR(action);
	zephir_array_fetch_long(&action, argv, 2, PH_NOISY, "soinc/bootstrap.zep", 147 TSRMLS_CC);
	zephir_array_unset_long(&argv, 0, PH_SEPARATE);
	zephir_array_unset_long(&argv, 1, PH_SEPARATE);
	zephir_array_unset_long(&argv, 2, PH_SEPARATE);
	ZEPHIR_CALL_FUNCTION(&params, "array_values", NULL, 16, argv);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(arguments);
	zephir_create_array(arguments, 3, 0 TSRMLS_CC);
	zephir_array_update_string(&arguments, SL("task"), &task, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&arguments, SL("action"), &action, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&arguments, SL("params"), &params, PH_COPY | PH_SEPARATE);
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("application"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _6, "handle", NULL, 0, arguments);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Soinc_Bootstrap, execWeb) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *uri_param = NULL, *_0, *_1, *_2, *_3, *e = NULL, *_4$$3, *_5$$3 = NULL, *_6$$3 = NULL, *str$$4 = NULL, *_7$$4 = NULL, *_8$$4 = NULL, *_9$$4 = NULL;
	zval *uri = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &uri_param);

	if (!uri_param) {
		ZEPHIR_INIT_VAR(uri);
		ZVAL_EMPTY_STRING(uri);
	} else {
	if (unlikely(Z_TYPE_P(uri_param) != IS_STRING && Z_TYPE_P(uri_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'uri' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(uri_param) == IS_STRING)) {
		zephir_get_strval(uri, uri_param);
	} else {
		ZEPHIR_INIT_VAR(uri);
		ZVAL_EMPTY_STRING(uri);
	}
	}


	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, zephir_get_internal_ce(SS("phalcon\\di\\factorydefault") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("di"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	object_init_ex(_1, zephir_get_internal_ce(SS("phalcon\\mvc\\application") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("application"), _1 TSRMLS_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("application"), PH_NOISY_CC);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _2, "setdi", NULL, 0, _3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initbaseservice", NULL, 14);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "loadermodule", NULL, 15);
	zephir_check_call_status();

	/* try_start_1: */

		_4$$3 = zephir_fetch_nproperty_this(this_ptr, SL("application"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_5$$3, _4$$3, "handle", NULL, 0, uri);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(&_6$$3, _5$$3, "getcontent", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		zend_print_zval(_6$$3, 0);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_CPY_WRT(e, EG(exception));
		if (zephir_instance_of_ev(e, zephir_get_internal_ce(SS("phalcon\\mvc\\application\\exception") TSRMLS_CC) TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CALL_METHOD(&_7$$4, e, "getmessage", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_8$$4, e, "gettraceasstring", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(str$$4);
			ZEPHIR_CONCAT_VSV(str$$4, _7$$4, "[{e->getFile()}: {e->getLine()}]\n", _8$$4);
			ZEPHIR_CALL_FUNCTION(&_9$$4, "nl2br", NULL, 17, str$$4);
			zephir_check_call_status();
			zend_print_zval(_9$$4, 0);
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Soinc_Bootstrap, execMicro) {

	HashTable *_13$$3;
	HashPosition _12$$3;
	zephir_fcall_cache_entry *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *argv = NULL, *e = NULL, *handleFiles = NULL, *file = NULL, *response = NULL, *_0, *_1, *_2, *_3 = NULL, *_4, *_5 = NULL, *_7, *_8, *_9 = NULL, *_10$$3, *_11$$3, **_14$$3, *_15$$3, *_16$$6 = NULL, *_17$$7 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &argv);

	if (!argv) {
		argv = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, zephir_get_internal_ce(SS("phalcon\\di\\factorydefault") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("di"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	object_init_ex(_1, zephir_get_internal_ce(SS("phalcon\\mvc\\micro") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("application"), _1 TSRMLS_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("application"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(_3, _2);
	if (zephir_set_symbol_str(SS("app"), _3 TSRMLS_CC) == FAILURE) {
	  return;
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("appPath"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_VS(_4, _2, "Handlers/*.php");
	ZEPHIR_CALL_FUNCTION(&_5, "glob", &_6, 18, _4);
	zephir_check_call_status();
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("appPath"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_8);
	ZEPHIR_CONCAT_VS(_8, _7, "Handlers/*/*.php");
	ZEPHIR_CALL_FUNCTION(&_9, "glob", &_6, 18, _8);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(handleFiles);
	zephir_fast_array_merge(handleFiles, &(_5), &(_9) TSRMLS_CC);

	/* try_start_1: */

		_10$$3 = zephir_fetch_nproperty_this(this_ptr, SL("application"), PH_NOISY_CC);
		_11$$3 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _10$$3, "setdi", NULL, 0, _11$$3);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "initbaseservice", NULL, 14);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "loadermodule", NULL, 15);
		zephir_check_call_status_or_jump(try_end_1);
		zephir_is_iterable(handleFiles, &_13$$3, &_12$$3, 0, 0, "soinc/bootstrap.zep", 193);
		for (
		  ; zephir_hash_get_current_data_ex(_13$$3, (void**) &_14$$3, &_12$$3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_13$$3, &_12$$3)
		) {
			ZEPHIR_GET_HVALUE(file, _14$$3);
			if (zephir_require_zval(file TSRMLS_CC) == FAILURE) {
				RETURN_MM_NULL();
			}
		}
		_15$$3 = zephir_fetch_nproperty_this(this_ptr, SL("application"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&response, _15$$3, "handle", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		if (zephir_is_instance_of(response, SL("Phalcon\\Http\\ResponseInterface") TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, response, "send", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
		}

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_CPY_WRT(e, EG(exception));
		if (zephir_instance_of_ev(e, zephir_get_internal_ce(SS("phalcon\\exception") TSRMLS_CC) TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CALL_METHOD(&_16$$6, e, "getmessage", NULL, 0);
			zephir_check_call_status();
			zend_print_zval(_16$$6, 0);
		}
		ZEPHIR_CPY_WRT(e, EG(exception));
		if (zephir_instance_of_ev(e, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CALL_METHOD(&_17$$7, e, "getmessage", NULL, 0);
			zephir_check_call_status();
			zend_print_zval(_17$$7, 0);
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Soinc_Bootstrap, getApplication) {

	

	RETURN_MEMBER(this_ptr, "application");

}

PHP_METHOD(Soinc_Bootstrap, getDi) {

	

	RETURN_MEMBER(this_ptr, "di");

}

PHP_METHOD(Soinc_Bootstrap, getEnv) {

	

	RETURN_MEMBER(this_ptr, "env");

}

PHP_METHOD(Soinc_Bootstrap, getConfig) {

	

	RETURN_MEMBER(this_ptr, "config");

}

PHP_METHOD(Soinc_Bootstrap, getAppPath) {

	

	RETURN_MEMBER(this_ptr, "appPath");

}

PHP_METHOD(Soinc_Bootstrap, getLoader) {

	

	RETURN_MEMBER(this_ptr, "loader");

}

PHP_METHOD(Soinc_Bootstrap, load) {

	zval *filePath, *_0, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filePath);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("loader"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(_1, _0);
	if (zephir_set_symbol_str(SS("loader"), _1 TSRMLS_CC) == FAILURE) {
	  return;
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(_2, _0);
	if (zephir_set_symbol_str(SS("config"), _2 TSRMLS_CC) == FAILURE) {
	  return;
	}
	ZEPHIR_CPY_WRT(_3, this_ptr);
	if (zephir_set_symbol_str(SS("bootstrap"), _3 TSRMLS_CC) == FAILURE) {
	  return;
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(_4, _0);
	if (zephir_set_symbol_str(SS("di"), _4 TSRMLS_CC) == FAILURE) {
	  return;
	}
	ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_5);
	if (zephir_require_zval_ret(&_5, filePath TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	RETURN_CCTOR(_5);

}

PHP_METHOD(Soinc_Bootstrap, loaderModule) {

	HashTable *_11$$7;
	HashPosition _10$$7;
	zephir_nts_static zend_class_entry *_4 = NULL;
	zval *_0, *_1, *module = NULL, *dirs = NULL, *namespaces = NULL, *services = NULL, *_2, *_3, *_9, *_5$$5, *_6$$5, *_7$$6, *_8$$6, *name$$7 = NULL, *obj$$7 = NULL, **_12$$7, *_13$$8;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("appPath"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VS(_1, _0, "Module.php");
	if (!((zephir_file_exists(_1 TSRMLS_CC) == SUCCESS))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "Miss the Module.php", "soinc/bootstrap.zep", 245);
		return;
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("appPath"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_VS(_3, _2, "Module.php");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "load", NULL, 12, _3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(module);
	if (!_4) {
		_4 = zend_fetch_class(SL("Module"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	}
	object_init_ex(module, _4);
	if (zephir_has_constructor(module TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, module, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	if (!(zephir_instance_of_ev(module, soinc_abstractmodule_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "The module is not extends \\Soinc\\AbstractModule", "soinc/bootstrap.zep", 252);
		return;
	}
	ZEPHIR_CALL_METHOD(NULL, module, "setbootstrap", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&dirs, module, "registerdirs", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&namespaces, module, "registernamespaces", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(dirs)) {
		_5$$5 = zephir_fetch_nproperty_this(this_ptr, SL("loader"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_6$$5);
		ZVAL_BOOL(_6$$5, 1);
		ZEPHIR_CALL_METHOD(NULL, _5$$5, "registerdirs", NULL, 0, dirs, _6$$5);
		zephir_check_call_status();
	}
	if (zephir_is_true(namespaces)) {
		_7$$6 = zephir_fetch_nproperty_this(this_ptr, SL("loader"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_8$$6);
		ZVAL_BOOL(_8$$6, 1);
		ZEPHIR_CALL_METHOD(NULL, _7$$6, "registernamespaces", NULL, 0, namespaces, _8$$6);
		zephir_check_call_status();
	}
	_9 = zephir_fetch_nproperty_this(this_ptr, SL("loader"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _9, "register", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&services, module, "registerservices", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(services)) {
		zephir_is_iterable(services, &_11$$7, &_10$$7, 0, 0, "soinc/bootstrap.zep", 275);
		for (
		  ; zephir_hash_get_current_data_ex(_11$$7, (void**) &_12$$7, &_10$$7) == SUCCESS
		  ; zephir_hash_move_forward_ex(_11$$7, &_10$$7)
		) {
			ZEPHIR_GET_HMKEY(name$$7, _11$$7, _10$$7);
			ZEPHIR_GET_HVALUE(obj$$7, _12$$7);
			_13$$8 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(NULL, _13$$8, "setshared", NULL, 0, name$$7, obj$$7);
			zephir_check_call_status();
		}
	}
	ZEPHIR_CALL_METHOD(NULL, module, "init", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

zend_object_value zephir_init_properties_Soinc_Bootstrap(zend_class_entry *class_type TSRMLS_DC) {

		zval *_1$$3;
	zval *_0;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("modeMap"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			zephir_create_array(_1$$3, 3, 0 TSRMLS_CC);
			add_assoc_stringl_ex(_1$$3, SS("Web"), SL("Web"), 1);
			add_assoc_stringl_ex(_1$$3, SS("Cli"), SL("Task"), 1);
			add_assoc_stringl_ex(_1$$3, SS("Micro"), SL("Micro"), 1);
			zephir_update_property_this(this_ptr, SL("modeMap"), _1$$3 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

