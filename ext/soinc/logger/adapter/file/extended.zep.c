
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Soinc_Logger_Adapter_File_Extended) {

	ZEPHIR_REGISTER_CLASS_EX(Soinc\\Logger\\Adapter\\File, Extended, soinc, logger_adapter_file_extended, zephir_get_internal_ce(SS("phalcon\\logger\\adapter\\file") TSRMLS_CC), soinc_logger_adapter_file_extended_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Soinc_Logger_Adapter_File_Extended, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *filePath_param = NULL, *options = NULL, *_0 = NULL;
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


	ZEPHIR_CALL_CE_STATIC(&_0, soinc_tools_ce, "mkdirs", &_1, 28, filePath);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		ZEPHIR_CALL_PARENT(NULL, soinc_logger_adapter_file_extended_ce, this_ptr, "__construct", NULL, 0, filePath, options);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(_2$$4);
		ZEPHIR_CONCAT_SV(_2$$4, "PHP Fatal error: Soinc::Logger::File failed to create log path: ", filePath);
		ZEPHIR_CALL_FUNCTION(NULL, "error_log", NULL, 16, _2$$4);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

