
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


ZEPHIR_INIT_CLASS(Soinc_AbstractModule) {

	ZEPHIR_REGISTER_CLASS(Soinc, AbstractModule, soinc, abstractmodule, soinc_abstractmodule_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(soinc_abstractmodule_ce, SL("appPath"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(soinc_abstractmodule_ce, SL("config"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(soinc_abstractmodule_ce, SL("env"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(soinc_abstractmodule_ce, SL("loader"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(soinc_abstractmodule_ce, SL("di"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(soinc_abstractmodule_ce, SL("application"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Soinc_AbstractModule, __get) {

	zval *name, *_0$$3, *_1$$4, *_2$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);



	if (zephir_isset_property_zval(this_ptr, name TSRMLS_CC)) {
		ZEPHIR_OBS_VAR(_0$$3);
		zephir_read_property_zval(&_0$$3, this_ptr, name, PH_NOISY_CC);
		RETURN_CCTOR(_0$$3);
	} else {
		ZEPHIR_OBS_VAR(_1$$4);
		zephir_read_property_this(&_1$$4, this_ptr, SL("application"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(_2$$4);
		zephir_read_property_zval(&_2$$4, _1$$4, name, PH_NOISY_CC);
		RETURN_CCTOR(_2$$4);
	}

}

PHP_METHOD(Soinc_AbstractModule, setBootstrap) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *bootstrap, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &bootstrap);



	ZEPHIR_CALL_METHOD(&_0, bootstrap, "getapppath", NULL, 1);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("appPath"), _0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_1, bootstrap, "getconfig", NULL, 2);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("config"), _1 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_2, bootstrap, "getenv", NULL, 3);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("env"), _2 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_3, bootstrap, "getloader", NULL, 4);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("loader"), _3 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_4, bootstrap, "getdi", NULL, 5);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("di"), _4 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_5, bootstrap, "getapplication", NULL, 6);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("application"), _5 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Soinc_AbstractModule, init) {

	


}

PHP_METHOD(Soinc_AbstractModule, registerDirs) {

}

PHP_METHOD(Soinc_AbstractModule, registerNamespaces) {

}

PHP_METHOD(Soinc_AbstractModule, registerServices) {

}

