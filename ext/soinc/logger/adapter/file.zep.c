
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/file.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"


ZEPHIR_INIT_CLASS(Soinc_Logger_Adapter_File) {

	ZEPHIR_REGISTER_CLASS_EX(Soinc\\Logger\\Adapter, File, soinc, logger_adapter_file, zephir_get_internal_ce(SS("phalcon\\logger\\adapter\\file") TSRMLS_CC), soinc_logger_adapter_file_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Soinc_Logger_Adapter_File, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *filePath_param = NULL, *options = NULL, *_0$$3 = NULL, *_1$$4, *parentPath$$6 = NULL, *_3$$6 = NULL, _4$$7, *_5$$7 = NULL, *_6$$8, *_7$$8;
	zval *filePath = NULL, *_2$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &filePath_param, &options);

	if (unlikely(Z_TYPE_P(filePath_param) != IS_STRING && Z_TYPE_P(filePath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'filePath' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(filePath_param) == IS_STRING)) {
		zephir_get_strval(filePath, filePath_param);
	} else {
		ZEPHIR_INIT_VAR(filePath);
		ZVAL_EMPTY_STRING(filePath);
	}
	if (!options) {
		options = ZEPHIR_GLOBAL(global_null);
	}


	if ((zephir_file_exists(filePath TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_FUNCTION(&_0$$3, "is_writable", NULL, 30, filePath);
		zephir_check_call_status();
		if (!(zephir_is_true(_0$$3))) {
			ZEPHIR_INIT_VAR(_1$$4);
			object_init_ex(_1$$4, zend_exception_get_default(TSRMLS_C));
			ZEPHIR_INIT_VAR(_2$$4);
			ZEPHIR_CONCAT_SV(_2$$4, "PHP Fatal error: Soinc::Logger::File failed to write log path: ", filePath);
			ZEPHIR_CALL_METHOD(NULL, _1$$4, "__construct", NULL, 6, _2$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_1$$4, "soinc/logger/adapter/file.zep", 9 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		} else {
			ZEPHIR_CALL_PARENT(NULL, soinc_logger_adapter_file_ce, this_ptr, "__construct", NULL, 0, filePath, options);
			zephir_check_call_status();
		}
	} else {
		ZEPHIR_CALL_FUNCTION(&parentPath$$6, "dirname", NULL, 31, filePath);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_3$$6, "is_dir", NULL, 5, parentPath$$6);
		zephir_check_call_status();
		if (!(zephir_is_true(_3$$6))) {
			ZEPHIR_SINIT_VAR(_4$$7);
			ZVAL_LONG(&_4$$7, 0777);
			ZEPHIR_CALL_FUNCTION(&_5$$7, "mkdir", NULL, 32, parentPath$$6, &_4$$7, ZEPHIR_GLOBAL(global_true));
			zephir_check_call_status();
			if (!(zephir_is_true(_5$$7))) {
				ZEPHIR_INIT_VAR(_6$$8);
				object_init_ex(_6$$8, zend_exception_get_default(TSRMLS_C));
				ZEPHIR_INIT_VAR(_7$$8);
				ZEPHIR_CONCAT_SV(_7$$8, "PHP Fatal error: Soinc::Logger::File failed to create log path: ", parentPath$$6);
				ZEPHIR_CALL_METHOD(NULL, _6$$8, "__construct", NULL, 6, _7$$8);
				zephir_check_call_status();
				zephir_throw_exception_debug(_6$$8, "soinc/logger/adapter/file.zep", 21 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		ZEPHIR_CALL_PARENT(NULL, soinc_logger_adapter_file_ce, this_ptr, "__construct", NULL, 0, filePath, options);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

