
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
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Soinc_Exception_Db) {

	ZEPHIR_REGISTER_CLASS_EX(Soinc\\Exception, Db, soinc, exception_db, soinc_exception_ce, soinc_exception_db_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Soinc_Exception_Db, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *message = NULL, *logger = NULL, *result = NULL, *matches = NULL, *_5, *_0$$3, _1$$4, *_2$$5, *_3$$5, *_4$$6 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &message, &logger);

	if (!message) {
		ZEPHIR_INIT_VAR(message);
		ZVAL_STRING(message, "", 1);
	} else {
		ZEPHIR_SEPARATE_PARAM(message);
	}
	if (!logger) {
		logger = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(matches);
	array_init(matches);
	if (ZEPHIR_IS_EMPTY(message)) {
		ZEPHIR_INIT_VAR(_0$$3);
		zephir_get_called_class(_0$$3 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(message);
		ZEPHIR_CONCAT_SV(message, "An exception created: ", _0$$3);
	} else {
		zephir_update_property_this(this_ptr, SL("message"), message TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_1$$4);
		ZVAL_STRING(&_1$$4, "/(?:\\[)(.*)(?:\\])/i", 0);
		ZEPHIR_INIT_VAR(result);
		zephir_preg_match(result, &_1$$4, message, matches, 1, 0 , 0  TSRMLS_CC);
		if (ZEPHIR_IS_LONG(result, 1)) {
			zephir_array_fetch_long(&_2$$5, matches, 1, PH_NOISY | PH_READONLY, "soinc/exception/db.zep", 15 TSRMLS_CC);
			zephir_array_fetch_long(&_3$$5, _2$$5, 0, PH_NOISY | PH_READONLY, "soinc/exception/db.zep", 15 TSRMLS_CC);
			zephir_update_property_this(this_ptr, SL("code"), _3$$5 TSRMLS_CC);
		}
	}
	if (!(Z_TYPE_P(logger) == IS_NULL)) {
		ZEPHIR_CALL_METHOD(&_4$$6, this_ptr, "getlevel", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, logger, "log", NULL, 0, message, _4$$6);
		zephir_check_call_status();
	}
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("message"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_5)) {
		zephir_update_property_this(this_ptr, SL("message"), message TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

