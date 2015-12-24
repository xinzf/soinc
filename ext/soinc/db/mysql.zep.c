
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/hash.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Soinc_Db_Mysql) {

	ZEPHIR_REGISTER_CLASS(Soinc\\Db, Mysql, soinc, db_mysql, soinc_db_mysql_method_entry, 0);

	zend_declare_property_null(soinc_db_mysql_ce, SL("dbConfigs"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(soinc_db_mysql_ce, SL("name"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(soinc_db_mysql_ce, SL("connection"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_bool(soinc_db_mysql_ce, SL("connected"), 0, ZEND_ACC_PRIVATE TSRMLS_CC);

	soinc_db_mysql_ce->create_object = zephir_init_properties_Soinc_Db_Mysql;
	return SUCCESS;

}

PHP_METHOD(Soinc_Db_Mysql, __construct) {

	zval *_6$$3, *_11$$5 = NULL, *_13$$5 = NULL;
	HashTable *_9;
	HashPosition _8;
	zend_class_entry *_1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *config = NULL, *_index = NULL, *_0 = NULL, *_2, *_3, *_4, *_5 = NULL, *_7, **_10, *_12$$5 = NULL, *_14$$5, *_15$$5 = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	zephir_update_property_this(this_ptr, SL("name"), name TSRMLS_CC);
		_1 = zend_fetch_class(SL("Phalcon\\Di"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(&_0, _1, "getdefault", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "config", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&config, _0, "get", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_3);
	zephir_read_property(&_3, config, SL("mysql"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_4);
	zephir_read_property_zval(&_4, _3, name, PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&config, _4, "toarray", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MAKE_REF(config);
	ZEPHIR_CALL_FUNCTION(&_5, "reset", NULL, 14, config);
	ZEPHIR_UNREF(config);
	zephir_check_call_status();
	if (!(Z_TYPE_P(_5) == IS_ARRAY)) {
		ZEPHIR_INIT_VAR(_6$$3);
		zephir_create_array(_6$$3, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(_6$$3, config);
		zephir_update_property_this(this_ptr, SL("dbConfigs"), _6$$3 TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("dbConfigs"), config TSRMLS_CC);
	}
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("dbConfigs"), PH_NOISY_CC);
	zephir_is_iterable(_7, &_9, &_8, 0, 0, "soinc/db/mysql.zep", 39);
	for (
	  ; zephir_hash_get_current_data_ex(_9, (void**) &_10, &_8) == SUCCESS
	  ; zephir_hash_move_forward_ex(_9, &_8)
	) {
		ZEPHIR_GET_HMKEY(_index, _9, _8);
		ZEPHIR_GET_HVALUE(config, _10);
		ZEPHIR_INIT_NVAR(_11$$5);
		zephir_create_array(_11$$5, 6, 0 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(_12$$5);
		zephir_array_fetch_string(&_12$$5, config, SL("host"), PH_NOISY, "soinc/db/mysql.zep", 27 TSRMLS_CC);
		zephir_array_update_string(&_11$$5, SL("host"), &_12$$5, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(_12$$5);
		zephir_array_fetch_string(&_12$$5, config, SL("port"), PH_NOISY, "soinc/db/mysql.zep", 28 TSRMLS_CC);
		zephir_array_update_string(&_11$$5, SL("port"), &_12$$5, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(_12$$5);
		zephir_array_fetch_string(&_12$$5, config, SL("username"), PH_NOISY, "soinc/db/mysql.zep", 29 TSRMLS_CC);
		zephir_array_update_string(&_11$$5, SL("username"), &_12$$5, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(_12$$5);
		zephir_array_fetch_string(&_12$$5, config, SL("password"), PH_NOISY, "soinc/db/mysql.zep", 30 TSRMLS_CC);
		zephir_array_update_string(&_11$$5, SL("password"), &_12$$5, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(_12$$5);
		zephir_array_fetch_string(&_12$$5, config, SL("dbname"), PH_NOISY, "soinc/db/mysql.zep", 31 TSRMLS_CC);
		zephir_array_update_string(&_11$$5, SL("dbname"), &_12$$5, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_13$$5);
		zephir_create_array(_13$$5, 3, 0 TSRMLS_CC);
		zephir_array_fetch_string(&_14$$5, config, SL("charset"), PH_NOISY | PH_READONLY, "soinc/db/mysql.zep", 33 TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_15$$5);
		ZEPHIR_CONCAT_SV(_15$$5, "SET NAMES ", _14$$5);
		zephir_array_update_long(&_13$$5, 1002, &_15$$5, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
		ZEPHIR_OBS_NVAR(_12$$5);
		zephir_array_fetch_string(&_12$$5, config, SL("timeout"), PH_NOISY, "soinc/db/mysql.zep", 34 TSRMLS_CC);
		zephir_array_update_long(&_13$$5, 2, &_12$$5, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
		add_index_long(_13$$5, 3, 2);
		zephir_array_update_string(&_11$$5, SL("options"), &_13$$5, PH_COPY | PH_SEPARATE);
		zephir_update_property_array(this_ptr, SL("dbConfigs"), _index, _11$$5 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Soinc_Db_Mysql, getConnection) {

	zval *_0, *dbNum$$3 = NULL, *e$$3 = NULL, *_1$$3, *_3$$4 = NULL, *_4$$4, *_5$$4, *_7$$5, *_8$$5, *_9$$5, *_10$$5, *_11$$5, *_12$$5, *_13$$5 = NULL, *_15$$5, *_16$$5;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL, *_6 = NULL, *_14 = NULL;

	ZEPHIR_MM_GROW();

	while (1) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("connected"), PH_NOISY_CC);
		if (!(!(zephir_is_true(_0)))) {
			break;
		}
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("dbConfigs"), PH_NOISY_CC);
		ZEPHIR_MAKE_REF(_1$$3);
		ZEPHIR_CALL_FUNCTION(NULL, "shuffle", &_2, 15, _1$$3);
		ZEPHIR_UNREF(_1$$3);
		zephir_check_call_status();

		/* try_start_1: */

			ZEPHIR_INIT_NVAR(_3$$4);
			object_init_ex(_3$$4, zephir_get_internal_ce(SS("phalcon\\db\\adapter\\pdo\\mysql") TSRMLS_CC));
			_4$$4 = zephir_fetch_nproperty_this(this_ptr, SL("dbConfigs"), PH_NOISY_CC);
			zephir_array_fetch_long(&_5$$4, _4$$4, 0, PH_NOISY | PH_READONLY, "soinc/db/mysql.zep", 48 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(NULL, _3$$4, "__construct", &_6, 0, _5$$4);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_update_property_this(this_ptr, SL("connection"), _3$$4 TSRMLS_CC);
			if (1) {
				zephir_update_property_this(this_ptr, SL("connected"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
			} else {
				zephir_update_property_this(this_ptr, SL("connected"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
			}

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_CPY_WRT(e$$3, EG(exception));
			if (zephir_instance_of_ev(e$$3, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
				zend_clear_exception(TSRMLS_C);
				_7$$5 = zephir_fetch_nproperty_this(this_ptr, SL("dbConfigs"), PH_NOISY_CC);
				zephir_array_fetch_long(&_8$$5, _7$$5, 0, PH_NOISY | PH_READONLY, "soinc/db/mysql.zep", 51 TSRMLS_CC);
				zephir_array_fetch_string(&_9$$5, _8$$5, SL("host"), PH_NOISY | PH_READONLY, "soinc/db/mysql.zep", 51 TSRMLS_CC);
				_10$$5 = zephir_fetch_nproperty_this(this_ptr, SL("dbConfigs"), PH_NOISY_CC);
				zephir_array_fetch_long(&_11$$5, _10$$5, 0, PH_NOISY | PH_READONLY, "soinc/db/mysql.zep", 51 TSRMLS_CC);
				zephir_array_fetch_string(&_12$$5, _11$$5, SL("username"), PH_NOISY | PH_READONLY, "soinc/db/mysql.zep", 51 TSRMLS_CC);
				ZEPHIR_INIT_LNVAR(_13$$5);
				ZEPHIR_CONCAT_SVSV(_13$$5, "PHP Fatal error:  Soinc::Db::MySQL::connect() failed to connect to MySQL. Detail: hostname is ", _9$$5, " the user is ", _12$$5);
				ZEPHIR_CALL_FUNCTION(NULL, "error_log", &_14, 16, _13$$5);
				zephir_check_call_status();
				_15$$5 = zephir_fetch_nproperty_this(this_ptr, SL("dbConfigs"), PH_NOISY_CC);
				zephir_array_unset_long(&_15$$5, 0, PH_SEPARATE);
				_16$$5 = zephir_fetch_nproperty_this(this_ptr, SL("dbConfigs"), PH_NOISY_CC);
				ZEPHIR_INIT_NVAR(dbNum$$3);
				ZVAL_LONG(dbNum$$3, zephir_fast_count_int(_16$$5 TSRMLS_CC));
				if (ZEPHIR_LT_LONG(dbNum$$3, 1)) {
					zephir_throw_exception_debug(e$$3, "soinc/db/mysql.zep", 55 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
	}
	RETURN_MM_MEMBER(this_ptr, "connection");

}

static zend_object_value zephir_init_properties_Soinc_Db_Mysql(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1$$3;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("dbConfigs"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(this_ptr, SL("dbConfigs"), _1$$3 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

