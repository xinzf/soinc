
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/file.h"
#include "kernel/array.h"
#include "kernel/exit.h"
#include "kernel/hash.h"
#include "kernel/require.h"


/**
* Bootsrap
*/
ZEPHIR_INIT_CLASS(Soinc_Bootstrap) {

	ZEPHIR_REGISTER_CLASS(Soinc, Bootstrap, soinc, bootstrap, soinc_bootstrap_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_declare_property_null(soinc_bootstrap_ce, SL("config"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(soinc_bootstrap_ce, SL("di"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(soinc_bootstrap_ce, SL("appPath"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(soinc_bootstrap_ce, SL("loader"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(soinc_bootstrap_ce, SL("modeMap"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(soinc_bootstrap_ce, SL("env"), "dev", ZEND_ACC_PROTECTED TSRMLS_CC);

	soinc_bootstrap_ce->create_object = zephir_init_properties_Soinc_Bootstrap;
	zend_declare_class_constant_string(soinc_bootstrap_ce, SL("CONFIG_DIR_NAME"), "config" TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Soinc_Bootstrap, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *appPath_param = NULL, *_0 = NULL, *_4, _5, *_6, *_7, *_1$$3, *_2$$3, *_3$$3;
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


	ZEPHIR_CALL_FUNCTION(&_0, "is_dir", NULL, 5, appPath);
	zephir_check_call_status();
	if (!zephir_is_true(_0)) {
		ZEPHIR_INIT_VAR(_1$$3);
		object_init_ex(_1$$3, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(_2$$3);
		ZVAL_STRING(_2$$3, "The application path is not exists", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_3$$3);
		ZVAL_LONG(_3$$3, 1);
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 6, _2$$3, _3$$3);
		zephir_check_temp_parameter(_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$3, "soinc/bootstrap.zep", 35 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_STRING(&_5, "/", 0);
	zephir_fast_trim(_4, appPath, &_5, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	ZEPHIR_INIT_VAR(_6);
	ZEPHIR_CONCAT_VS(_6, _4, "/");
	zephir_update_property_this(this_ptr, SL("appPath"), _6 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_7);
	object_init_ex(_7, zephir_get_internal_ce(SS("phalcon\\loader") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, _7, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("loader"), _7 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Soinc_Bootstrap, initEnv) {

	zval *env = NULL, _0 = zval_used_for_init, *_2, *globalConfig = NULL, *appConfigPath = NULL, *_8, *_9, *paths = NULL, *_13, *_14, *_15 = NULL, *debug$$4 = NULL, *_3$$6, *_4$$6, *_5$$6, *_6$$5, *_7$$7, *_10$$8, *_11$$8, *_12$$8 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "soinc.env", 0);
	ZEPHIR_CALL_FUNCTION(&env, "get_cfg_var", &_1, 7, &_0);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(env))) {
		zephir_update_property_this(this_ptr, SL("env"), env TSRMLS_CC);
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("env"), PH_NOISY_CC);
	if (!ZEPHIR_IS_STRING(_2, "product")) {
		ZEPHIR_INIT_VAR(debug$$4);
		object_init_ex(debug$$4, zephir_get_internal_ce(SS("phalcon\\debug") TSRMLS_CC));
		if (zephir_has_constructor(debug$$4 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, debug$$4, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(NULL, debug$$4, "listen", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "soinc.global_conf", 0);
	ZEPHIR_CALL_FUNCTION(&globalConfig, "get_cfg_var", &_1, 7, &_0);
	zephir_check_call_status();
	if (zephir_is_true(globalConfig)) {
		if (!((zephir_file_exists(globalConfig TSRMLS_CC) == SUCCESS))) {
			ZEPHIR_INIT_VAR(_3$$6);
			object_init_ex(_3$$6, zend_exception_get_default(TSRMLS_C));
			ZEPHIR_INIT_VAR(_4$$6);
			ZEPHIR_CONCAT_SV(_4$$6, "The global configure file is not exists! Detail: ", globalConfig);
			ZEPHIR_INIT_VAR(_5$$6);
			ZVAL_LONG(_5$$6, 1);
			ZEPHIR_CALL_METHOD(NULL, _3$$6, "__construct", NULL, 6, _4$$6, _5$$6);
			zephir_check_call_status();
			zephir_throw_exception_debug(_3$$6, "soinc/bootstrap.zep", 59 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(_6$$5);
		object_init_ex(_6$$5, zephir_get_internal_ce(SS("phalcon\\config\\adapter\\php") TSRMLS_CC));
		ZEPHIR_CALL_METHOD(NULL, _6$$5, "__construct", NULL, 0, globalConfig);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("config"), _6$$5 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_VAR(_7$$7);
		object_init_ex(_7$$7, zephir_get_internal_ce(SS("phalcon\\config") TSRMLS_CC));
		ZEPHIR_CALL_METHOD(NULL, _7$$7, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("config"), _7$$7 TSRMLS_CC);
	}
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("appPath"), PH_NOISY_CC);
	_9 = zephir_fetch_nproperty_this(this_ptr, SL("env"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(appConfigPath);
	ZEPHIR_CONCAT_VSVS(appConfigPath, _8, "config/", _9, ".php");
	if ((zephir_file_exists(appConfigPath TSRMLS_CC) == SUCCESS)) {
		_10$$8 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_11$$8);
		object_init_ex(_11$$8, zephir_get_internal_ce(SS("phalcon\\config") TSRMLS_CC));
		ZEPHIR_CALL_METHOD(&_12$$8, this_ptr, "load", NULL, 8, appConfigPath);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _11$$8, "__construct", NULL, 0, _12$$8);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _10$$8, "merge", NULL, 0, _11$$8);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(paths);
	array_init(paths);
	ZEPHIR_INIT_NVAR(paths);
	zephir_create_array(paths, 1, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(_13);
	zephir_read_property_this(&_13, this_ptr, SL("appPath"), PH_NOISY_CC);
	zephir_array_fast_append(paths, _13);
	_14 = zephir_fetch_nproperty_this(this_ptr, SL("loader"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_15, _14, "registerdirs", NULL, 0, paths);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, _15, "register", NULL, 0);
	zephir_check_call_status();
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


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initenv", NULL, 9);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "Unsupported mode", "soinc/bootstrap.zep", 89);
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
		ZEPHIR_CALL_METHOD(NULL, _7$$4, "__construct", NULL, 6, _8$$4, _9$$4);
		zephir_check_temp_parameter(_8$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_7$$4, "soinc/bootstrap.zep", 93 TSRMLS_CC);
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
	zephir_array_fetch(&_11, _10, _12, PH_NOISY | PH_READONLY, "soinc/bootstrap.zep", 97 TSRMLS_CC);
	ZEPHIR_INIT_VAR(handleMethod);
	ZEPHIR_CONCAT_SV(handleMethod, "exec", _11);
	ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, handleMethod, NULL, 0, argv);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Soinc_Bootstrap, execTask) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *argv_param = NULL, *console = NULL, *_0, *_1, *task = NULL, *action = NULL, *params = NULL, *err$$3 = NULL, *_2$$3, _3$$3;
	zval *argv = NULL, *arguments = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &argv_param);

	zephir_get_arrval(argv, argv_param);


	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, zephir_get_internal_ce(SS("phalcon\\di\\factorydefault\\cli") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("di"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(console);
	object_init_ex(console, zephir_get_internal_ce(SS("phalcon\\cli\\console") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, console, "__construct", NULL, 0);
	zephir_check_call_status();
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, console, "setdi", NULL, 0, _1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initbaseservice", NULL, 10);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "loadermodule", NULL, 11);
	zephir_check_call_status();
	if (zephir_fast_count_int(argv TSRMLS_CC) < 3) {
		ZEPHIR_INIT_VAR(_2$$3);
		ZEPHIR_GET_CONSTANT(_2$$3, "PHP_EOL");
		ZEPHIR_INIT_VAR(err$$3);
		ZEPHIR_CONCAT_SV(err$$3, "Error: Requires at least one 'task' and an 'action' parameters!", _2$$3);
		zend_print_zval(err$$3, 0);
		ZEPHIR_MM_RESTORE();
		ZEPHIR_SINIT_VAR(_3$$3);
		ZVAL_LONG(&_3$$3, 255);
		zephir_exit(&_3$$3);
	}
	ZEPHIR_INIT_VAR(arguments);
	array_init(arguments);
	ZEPHIR_INIT_VAR(params);
	array_init(params);
	ZEPHIR_OBS_VAR(task);
	zephir_array_fetch_long(&task, argv, 1, PH_NOISY, "soinc/bootstrap.zep", 124 TSRMLS_CC);
	ZEPHIR_OBS_VAR(action);
	zephir_array_fetch_long(&action, argv, 2, PH_NOISY, "soinc/bootstrap.zep", 125 TSRMLS_CC);
	zephir_array_unset_long(&argv, 0, PH_SEPARATE);
	zephir_array_unset_long(&argv, 1, PH_SEPARATE);
	zephir_array_unset_long(&argv, 2, PH_SEPARATE);
	ZEPHIR_CALL_FUNCTION(&params, "array_values", NULL, 12, argv);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(arguments);
	zephir_create_array(arguments, 3, 0 TSRMLS_CC);
	zephir_array_update_string(&arguments, SL("task"), &task, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&arguments, SL("action"), &action, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&arguments, SL("params"), &params, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, console, "handle", NULL, 0, arguments);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Soinc_Bootstrap, execWeb) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *uri_param = NULL, *application = NULL, *_0, *_1, *e = NULL, *_2$$3 = NULL, *_3$$3 = NULL, *str$$4 = NULL, *_4$$4 = NULL, *_5$$4 = NULL, *_6$$4 = NULL;
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
	ZEPHIR_INIT_VAR(application);
	object_init_ex(application, zephir_get_internal_ce(SS("phalcon\\mvc\\application") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, application, "__construct", NULL, 0);
	zephir_check_call_status();
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, application, "setdi", NULL, 0, _1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initbaseservice", NULL, 10);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "loadermodule", NULL, 11);
	zephir_check_call_status();

	/* try_start_1: */

		ZEPHIR_CALL_METHOD(&_2$$3, application, "handle", NULL, 0, uri);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(&_3$$3, _2$$3, "getcontent", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		zend_print_zval(_3$$3, 0);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_CPY_WRT(e, EG(exception));
		if (zephir_instance_of_ev(e, zephir_get_internal_ce(SS("phalcon\\mvc\\application\\exception") TSRMLS_CC) TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CALL_METHOD(&_4$$4, e, "getmessage", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_5$$4, e, "gettraceasstring", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(str$$4);
			ZEPHIR_CONCAT_VSV(str$$4, _4$$4, "[{e->getFile()}: {e->getLine()}]\n", _5$$4);
			ZEPHIR_CALL_FUNCTION(&_6$$4, "nl2br", NULL, 13, str$$4);
			zephir_check_call_status();
			zend_print_zval(_6$$4, 0);
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Soinc_Bootstrap, execMicro) {

	HashTable *_11$$3;
	HashPosition _10$$3;
	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *argv = NULL, *app = NULL, *e = NULL, *handleFiles = NULL, *index = NULL, *file = NULL, *response = NULL, *_0, *_1 = NULL, *_2, *_3, *_4 = NULL, *_6, *_7, *_8 = NULL, *_9$$3, **_12$$3, *_13$$6 = NULL, *_14$$7 = NULL;

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
	ZEPHIR_INIT_VAR(app);
	object_init_ex(app, zephir_get_internal_ce(SS("phalcon\\mvc\\micro") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, app, "__construct", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(_1, app);
	if (zephir_set_symbol_str(SS("app"), _1 TSRMLS_CC) == FAILURE){
	  return;
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("appPath"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_VS(_3, _2, "handlers/*.php");
	ZEPHIR_CALL_FUNCTION(&_4, "glob", &_5, 14, _3);
	zephir_check_call_status();
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("appPath"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_7);
	ZEPHIR_CONCAT_VS(_7, _6, "handlers/*/*.php");
	ZEPHIR_CALL_FUNCTION(&_8, "glob", &_5, 14, _7);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(handleFiles);
	zephir_fast_array_merge(handleFiles, &(_4), &(_8) TSRMLS_CC);

	/* try_start_1: */

		_9$$3 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, app, "setdi", NULL, 0, _9$$3);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "initbaseservice", NULL, 10);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "loadermodule", NULL, 11);
		zephir_check_call_status_or_jump(try_end_1);
		zephir_is_iterable(handleFiles, &_11$$3, &_10$$3, 0, 0, "soinc/bootstrap.zep", 172);
		for (
		  ; zephir_hash_get_current_data_ex(_11$$3, (void**) &_12$$3, &_10$$3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_11$$3, &_10$$3)
		) {
			ZEPHIR_GET_HMKEY(index, _11$$3, _10$$3);
			ZEPHIR_GET_HVALUE(file, _12$$3);
			if (zephir_require_zval(file TSRMLS_CC) == FAILURE) {
				RETURN_MM_NULL();
			}
		}
		ZEPHIR_CALL_METHOD(&response, app, "handle", NULL, 0);
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
			ZEPHIR_CALL_METHOD(&_13$$6, e, "getmessage", NULL, 0);
			zephir_check_call_status();
			zend_print_zval(_13$$6, 0);
		}
		ZEPHIR_CPY_WRT(e, EG(exception));
		if (zephir_instance_of_ev(e, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CALL_METHOD(&_14$$7, e, "getmessage", NULL, 0);
			zephir_check_call_status();
			zend_print_zval(_14$$7, 0);
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Soinc_Bootstrap, getDI) {

	

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
	if (zephir_set_symbol_str(SS("loader"), _1 TSRMLS_CC) == FAILURE){
	  return;
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(_2, _0);
	if (zephir_set_symbol_str(SS("config"), _2 TSRMLS_CC) == FAILURE){
	  return;
	}
	ZEPHIR_CPY_WRT(_3, this_ptr);
	if (zephir_set_symbol_str(SS("bootstrap"), _3 TSRMLS_CC) == FAILURE){
	  return;
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(_4, _0);
	if (zephir_set_symbol_str(SS("di"), _4 TSRMLS_CC) == FAILURE){
	  return;
	}
	ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_5);
	if (zephir_require_zval_ret(&_5, filePath TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	RETURN_CCTOR(_5);

}

PHP_METHOD(Soinc_Bootstrap, loaderModule) {

	HashTable *_10;
	HashPosition _9;
	zephir_nts_static zend_class_entry *_4 = NULL;
	zval *_0, *_1, *module = NULL, *dirs = NULL, *namespaces = NULL, *services = NULL, *_2, *_3, *_5, *_6 = NULL, *_7, *_8, *name = NULL, *obj = NULL, **_11, *_12$$5;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("appPath"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VS(_1, _0, "Module.php");
	if (!((zephir_file_exists(_1 TSRMLS_CC) == SUCCESS))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "Miss the Module.php", "soinc/bootstrap.zep", 220);
		return;
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("appPath"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_VS(_3, _2, "Module.php");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "load", NULL, 8, _3);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "The module is not extends \\Soinc\\AbstractModule", "soinc/bootstrap.zep", 227);
		return;
	}
	ZEPHIR_CALL_METHOD(NULL, module, "setbootstrap", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&dirs, module, "registerdirs", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&namespaces, module, "registernamespaces", NULL, 0);
	zephir_check_call_status();
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("loader"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_BOOL(_6, 1);
	ZEPHIR_CALL_METHOD(NULL, _5, "registerdirs", NULL, 0, dirs, _6);
	zephir_check_call_status();
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("loader"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_6);
	ZVAL_BOOL(_6, 1);
	ZEPHIR_CALL_METHOD(NULL, _7, "registernamespaces", NULL, 0, namespaces, _6);
	zephir_check_call_status();
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("loader"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _8, "register", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&services, module, "registerservices", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(services, &_10, &_9, 0, 0, "soinc/bootstrap.zep", 243);
	for (
	  ; zephir_hash_get_current_data_ex(_10, (void**) &_11, &_9) == SUCCESS
	  ; zephir_hash_move_forward_ex(_10, &_9)
	) {
		ZEPHIR_GET_HMKEY(name, _10, _9);
		ZEPHIR_GET_HVALUE(obj, _11);
		_12$$5 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _12$$5, "setshared", NULL, 0, name, obj);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

static zend_object_value zephir_init_properties_Soinc_Bootstrap(zend_class_entry *class_type TSRMLS_DC) {

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

