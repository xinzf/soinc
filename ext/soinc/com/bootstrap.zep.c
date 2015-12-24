
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
#include "kernel/require.h"
#include "kernel/exit.h"


/**
* Bootsrap
*/
ZEPHIR_INIT_CLASS(Soinc_Com_Bootstrap) {

	ZEPHIR_REGISTER_CLASS(Soinc\\Com, Bootstrap, soinc, com_bootstrap, soinc_com_bootstrap_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_declare_property_null(soinc_com_bootstrap_ce, SL("config"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(soinc_com_bootstrap_ce, SL("di"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(soinc_com_bootstrap_ce, SL("appPath"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(soinc_com_bootstrap_ce, SL("loader"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(soinc_com_bootstrap_ce, SL("modeMap"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(soinc_com_bootstrap_ce, SL("env"), "dev", ZEND_ACC_PROTECTED TSRMLS_CC);

	soinc_com_bootstrap_ce->create_object = zephir_init_properties_Soinc_Com_Bootstrap;
	zend_declare_class_constant_string(soinc_com_bootstrap_ce, SL("CONFIG_DIR_NAME"), "config" TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Soinc_Com_Bootstrap, __construct) {

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


	ZEPHIR_CALL_FUNCTION(&_0, "is_dir", NULL, 1, appPath);
	zephir_check_call_status();
	if (!zephir_is_true(_0)) {
		ZEPHIR_INIT_VAR(_1$$3);
		object_init_ex(_1$$3, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(_2$$3);
		ZVAL_STRING(_2$$3, "The application path is not exists", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_3$$3);
		ZVAL_LONG(_3$$3, 1);
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 2, _2$$3, _3$$3);
		zephir_check_temp_parameter(_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$3, "soinc/com/Bootstrap.zep", 32 TSRMLS_CC);
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

PHP_METHOD(Soinc_Com_Bootstrap, initEnv) {

	zval *env = NULL, _0 = zval_used_for_init, *_2, *globalIni = NULL, *appConfigPath = NULL, *_8, *paths = NULL, *_11, *_12, *_13 = NULL, *_14, *_15, *_16 = NULL, *_17 = NULL, *_18 = NULL, *_19 = NULL, *debug$$4 = NULL, *_3$$6, *_4$$6, *_5$$6, *_6$$5, *_7$$7, *_9$$8, *_10$$8;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "soinc.env", 0);
	ZEPHIR_CALL_FUNCTION(&env, "get_cfg_var", &_1, 3, &_0);
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
	ZVAL_STRING(&_0, "soinc.global_ini", 0);
	ZEPHIR_CALL_FUNCTION(&globalIni, "get_cfg_var", &_1, 3, &_0);
	zephir_check_call_status();
	if (zephir_is_true(globalIni)) {
		if (!((zephir_file_exists(globalIni TSRMLS_CC) == SUCCESS))) {
			ZEPHIR_INIT_VAR(_3$$6);
			object_init_ex(_3$$6, zend_exception_get_default(TSRMLS_C));
			ZEPHIR_INIT_VAR(_4$$6);
			ZVAL_STRING(_4$$6, "The global ini file is not exists!", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_VAR(_5$$6);
			ZVAL_LONG(_5$$6, 1);
			ZEPHIR_CALL_METHOD(NULL, _3$$6, "__construct", NULL, 2, _4$$6, _5$$6);
			zephir_check_temp_parameter(_4$$6);
			zephir_check_call_status();
			zephir_throw_exception_debug(_3$$6, "soinc/com/Bootstrap.zep", 56 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(_6$$5);
		object_init_ex(_6$$5, zephir_get_internal_ce(SS("phalcon\\config\\adapter\\ini") TSRMLS_CC));
		ZEPHIR_CALL_METHOD(NULL, _6$$5, "__construct", NULL, 0, globalIni);
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
	ZEPHIR_INIT_VAR(appConfigPath);
	ZEPHIR_CONCAT_VS(appConfigPath, _8, "config/config.php");
	if ((zephir_file_exists(appConfigPath TSRMLS_CC) == SUCCESS)) {
		_9$$8 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_10$$8);
		object_init_ex(_10$$8, zephir_get_internal_ce(SS("phalcon\\config\\adapter\\php") TSRMLS_CC));
		ZEPHIR_CALL_METHOD(NULL, _10$$8, "__construct", NULL, 0, appConfigPath);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _9$$8, "merge", NULL, 0, _10$$8);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(paths);
	array_init(paths);
	ZEPHIR_INIT_NVAR(paths);
	zephir_create_array(paths, 1, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(_11);
	zephir_read_property_this(&_11, this_ptr, SL("appPath"), PH_NOISY_CC);
	zephir_array_fast_append(paths, _11);
	_12 = zephir_fetch_nproperty_this(this_ptr, SL("loader"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_13, _12, "registerdirs", NULL, 0, paths);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, _13, "register", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_14);
	object_init_ex(_14, zephir_get_internal_ce(SS("phalcon\\di\\factorydefault") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, _14, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("di"), _14 TSRMLS_CC);
	_15 = zephir_fetch_nproperty_this(this_ptr, SL("loader"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(_16, _15);
	if (zephir_set_symbol_str(SS("loader"), _16 TSRMLS_CC) == FAILURE){
	  return;
	}
	_15 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(_17, _15);
	if (zephir_set_symbol_str(SS("config"), _17 TSRMLS_CC) == FAILURE){
	  return;
	}
	ZEPHIR_CPY_WRT(_18, this_ptr);
	if (zephir_set_symbol_str(SS("bootstrap"), _18 TSRMLS_CC) == FAILURE){
	  return;
	}
	_15 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(_19, _15);
	if (zephir_set_symbol_str(SS("di"), _19 TSRMLS_CC) == FAILURE){
	  return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Soinc_Com_Bootstrap, initBaseService) {

	zval *_0, *_1 = NULL, *_2, *_3, *_4, *_5, *_6, *_7 = NULL, *_8, *_9;
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
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_1);
	ZEPHIR_INIT_NVAR(_1);
	zephir_create_closure_ex(_1, NULL, soinc_0__closure_ce, SS("__invoke") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_7);
	ZVAL_STRING(_7, "request", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _6, "set", NULL, 0, _7, _1);
	zephir_check_temp_parameter(_7);
	zephir_check_call_status();
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_7);
	ZEPHIR_INIT_NVAR(_7);
	zephir_create_closure_ex(_7, NULL, soinc_1__closure_ce, SS("__invoke") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_9);
	ZVAL_STRING(_9, "curl", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _8, "set", NULL, 0, _9, _7);
	zephir_check_temp_parameter(_9);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Soinc_Com_Bootstrap, exec) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *argv = NULL, *_0, *_1, *handleMethod = NULL, *_5, *_6, *_7, *_8, *_9, *_10, *_2$$3, *_3$$3, *_4$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &argv);

	if (!argv) {
		argv = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initenv", NULL, 4);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initbaseservice", NULL, 5);
	zephir_check_call_status();
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property(&_1, _0, SL("application"), PH_NOISY_CC);
	if (!(zephir_isset_property(_1, SS("mode") TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_2$$3);
		object_init_ex(_2$$3, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(_3$$3);
		ZVAL_STRING(_3$$3, "Miss the application mode configure!", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_4$$3);
		ZVAL_LONG(_4$$3, 1);
		ZEPHIR_CALL_METHOD(NULL, _2$$3, "__construct", NULL, 2, _3$$3, _4$$3);
		zephir_check_temp_parameter(_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2$$3, "soinc/com/Bootstrap.zep", 100 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("modeMap"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_7);
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_9);
	zephir_read_property(&_9, _8, SL("application"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_10);
	zephir_read_property(&_10, _9, SL("mode"), PH_NOISY_CC);
	zephir_ucfirst(_7, _10);
	zephir_array_fetch(&_6, _5, _7, PH_NOISY | PH_READONLY, "soinc/com/Bootstrap.zep", 104 TSRMLS_CC);
	ZEPHIR_INIT_VAR(handleMethod);
	ZEPHIR_CONCAT_SV(handleMethod, "exec", _6);
	ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, handleMethod, NULL, 0, argv);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Soinc_Com_Bootstrap, execTask) {

	zend_bool _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *argv_param = NULL, *_0, *_2, *_4, *_5, *console = NULL, *_6, *task = NULL, *action = NULL, *params = NULL, *_3$$3, *err$$4 = NULL, *_7$$4, _8$$4;
	zval *argv = NULL, *arguments = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &argv_param);

	zephir_get_arrval(argv, argv_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	_1 = Z_TYPE_P(_0) == IS_NULL;
	if (!(_1)) {
		ZEPHIR_OBS_VAR(_2);
		zephir_read_property_this(&_2, this_ptr, SL("di"), PH_NOISY_CC);
		_1 = !(zephir_instance_of_ev(_2, zephir_get_internal_ce(SS("phalcon\\di\\factorydefault\\cli") TSRMLS_CC) TSRMLS_CC));
	}
	if (_1) {
		ZEPHIR_INIT_VAR(_3$$3);
		object_init_ex(_3$$3, zephir_get_internal_ce(SS("phalcon\\di\\factorydefault\\cli") TSRMLS_CC));
		ZEPHIR_CALL_METHOD(NULL, _3$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("di"), _3$$3 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "initbaseservice", NULL, 5);
		zephir_check_call_status();
	}
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("appPath"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_5);
	ZEPHIR_CONCAT_VS(_5, _4, "config/load.php");
	if (zephir_require_zval(_5 TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(console);
	object_init_ex(console, zephir_get_internal_ce(SS("phalcon\\cli\\console") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, console, "__construct", NULL, 0);
	zephir_check_call_status();
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, console, "setdi", NULL, 0, _6);
	zephir_check_call_status();
	if (zephir_fast_count_int(argv TSRMLS_CC) < 3) {
		ZEPHIR_INIT_VAR(_7$$4);
		ZEPHIR_GET_CONSTANT(_7$$4, "PHP_EOL");
		ZEPHIR_INIT_VAR(err$$4);
		ZEPHIR_CONCAT_SV(err$$4, "Error: Requires at least one 'task' and an 'action' parameters!", _7$$4);
		zend_print_zval(err$$4, 0);
		ZEPHIR_MM_RESTORE();
		ZEPHIR_SINIT_VAR(_8$$4);
		ZVAL_LONG(&_8$$4, 255);
		zephir_exit(&_8$$4);
	}
	ZEPHIR_INIT_VAR(arguments);
	array_init(arguments);
	ZEPHIR_INIT_VAR(params);
	array_init(params);
	ZEPHIR_OBS_VAR(task);
	zephir_array_fetch_long(&task, argv, 1, PH_NOISY, "soinc/com/Bootstrap.zep", 133 TSRMLS_CC);
	ZEPHIR_OBS_VAR(action);
	zephir_array_fetch_long(&action, argv, 2, PH_NOISY, "soinc/com/Bootstrap.zep", 134 TSRMLS_CC);
	zephir_array_unset_long(&argv, 0, PH_SEPARATE);
	zephir_array_unset_long(&argv, 1, PH_SEPARATE);
	zephir_array_unset_long(&argv, 2, PH_SEPARATE);
	ZEPHIR_CALL_FUNCTION(&params, "array_values", NULL, 6, argv);
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

PHP_METHOD(Soinc_Com_Bootstrap, getDI) {

	

	RETURN_MEMBER(this_ptr, "di");

}

PHP_METHOD(Soinc_Com_Bootstrap, getEnv) {

	

	RETURN_MEMBER(this_ptr, "env");

}

PHP_METHOD(Soinc_Com_Bootstrap, getConfig) {

	

	RETURN_MEMBER(this_ptr, "config");

}

PHP_METHOD(Soinc_Com_Bootstrap, getAppPath) {

	

	RETURN_MEMBER(this_ptr, "appPath");

}

static zend_object_value zephir_init_properties_Soinc_Com_Bootstrap(zend_class_entry *class_type TSRMLS_DC) {

		zval *_1$$3;
	zval *_0;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("modeMap"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			zephir_create_array(_1$$3, 4, 0 TSRMLS_CC);
			add_assoc_stringl_ex(_1$$3, SS("Web"), SL("Module"), 1);
			add_assoc_stringl_ex(_1$$3, SS("Cli"), SL("Task"), 1);
			add_assoc_stringl_ex(_1$$3, SS("Srv"), SL("Srv"), 1);
			add_assoc_stringl_ex(_1$$3, SS("Micro"), SL("Micro"), 1);
			zephir_update_property_this(this_ptr, SL("modeMap"), _1$$3 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

