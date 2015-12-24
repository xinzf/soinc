
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Soinc_Module) {

	ZEPHIR_REGISTER_CLASS(Soinc, Module, soinc, module, soinc_module_method_entry, 0);

	zend_declare_property_null(soinc_module_ce, SL("bootstrap"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(soinc_module_ce, SL("di"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(soinc_module_ce, SL("loader"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(soinc_module_ce, SL("config"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Soinc_Module, setBootstrap) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *bootstrap, *_0, *_1 = NULL, *_2, *_3 = NULL, *_4, *_5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &bootstrap);



	zephir_update_property_this(this_ptr, SL("bootstrap"), bootstrap TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("bootstrap"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, _0, "getdi", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("di"), _1 TSRMLS_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("bootstrap"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_3, _2, "getloader", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("loader"), _3 TSRMLS_CC);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("bootstrap"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_5, _4, "getconfig", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("config"), _5 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Soinc_Module, getDI) {

	

	RETURN_MEMBER(this_ptr, "di");

}

PHP_METHOD(Soinc_Module, getLoader) {

	

	RETURN_MEMBER(this_ptr, "loader");

}

PHP_METHOD(Soinc_Module, getConfig) {

	

	RETURN_MEMBER(this_ptr, "config");

}

