
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
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Soinc_Exception) {

	ZEPHIR_REGISTER_CLASS_EX(Soinc, Exception, soinc, exception, zend_exception_get_default(TSRMLS_C), soinc_exception_method_entry, 0);

	zend_declare_property_string(soinc_exception_ce, SL("message"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(soinc_exception_ce, SL("level"), "Exception", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(soinc_exception_ce, SL("code"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(soinc_exception_ce, SL("logger"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Soinc_Exception, __construct) {

	zval *message = NULL, *code = NULL, *logger = NULL, *_0$$3, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &message, &code, &logger);

	if (!message) {
		ZEPHIR_INIT_VAR(message);
		ZVAL_STRING(message, "", 1);
	} else {
		ZEPHIR_SEPARATE_PARAM(message);
	}
	if (!code) {
		code = ZEPHIR_GLOBAL(global_null);
	}
	if (!logger) {
		logger = ZEPHIR_GLOBAL(global_null);
	}


	if (ZEPHIR_IS_EMPTY(message)) {
		ZEPHIR_INIT_VAR(_0$$3);
		zephir_get_called_class(_0$$3 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(message);
		ZEPHIR_CONCAT_SV(message, "An exception created: ", _0$$3);
	}
	zephir_update_property_this(this_ptr, SL("logger"), logger TSRMLS_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("message"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_1)) {
		zephir_update_property_this(this_ptr, SL("message"), message TSRMLS_CC);
	}
	if (!(Z_TYPE_P(code) == IS_NULL)) {
		zephir_update_property_this(this_ptr, SL("code"), code TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Soinc_Exception, getLevel) {

	

	RETURN_MEMBER(this_ptr, "level");

}

PHP_METHOD(Soinc_Exception, setCode) {

	zval *code;

	zephir_fetch_params(0, 1, 0, &code);



	zephir_update_property_this(this_ptr, SL("code"), code TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Soinc_Exception, setLevel) {

	zval *level;

	zephir_fetch_params(0, 1, 0, &level);



	zephir_update_property_this(this_ptr, SL("level"), level TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Soinc_Exception, __desctruct) {

	zval *_0, *_1$$3, *_2$$3 = NULL, *_3$$3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("logger"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("logger"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "getlevel", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_3$$3, this_ptr, "getmessage", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "log", NULL, 0, _2$$3, _3$$3);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

