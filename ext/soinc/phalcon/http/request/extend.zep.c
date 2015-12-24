
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
#include "kernel/string.h"


/**
* Extend
*/
ZEPHIR_INIT_CLASS(Soinc_Phalcon_Http_Request_Extend) {

	ZEPHIR_REGISTER_CLASS_EX(Soinc\\Phalcon\\Http\\Request, Extend, soinc, phalcon_http_request_extend, zephir_get_internal_ce(SS("phalcon\\http\\request") TSRMLS_CC), soinc_phalcon_http_request_extend_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Soinc_Phalcon_Http_Request_Extend, fromMobile) {

	zend_bool _1;
	zval *_0 = NULL, *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fromandroid", NULL, 0);
	zephir_check_call_status();
	_1 = zephir_is_true(_0);
	if (!(_1)) {
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "fromios", NULL, 0);
		zephir_check_call_status();
		_1 = zephir_is_true(_2);
	}
	if (_1) {
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(Soinc_Phalcon_Http_Request_Extend, fromWeixin) {

	zval *userAgent = NULL, *_0 = NULL, _1;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getuseragent", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(userAgent);
	zephir_fast_strtolower(userAgent, _0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "micromessenger", 0);
	zephir_fast_strpos(return_value, userAgent, &_1, 0 );
	RETURN_MM();

}

PHP_METHOD(Soinc_Phalcon_Http_Request_Extend, fromWeibo) {

	zval *userAgent = NULL, *_0 = NULL, _1;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getuseragent", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(userAgent);
	zephir_fast_strtolower(userAgent, _0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "weibo", 0);
	zephir_fast_strpos(return_value, userAgent, &_1, 0 );
	RETURN_MM();

}

PHP_METHOD(Soinc_Phalcon_Http_Request_Extend, fromAndroid) {

	zval *userAgent = NULL, *_0 = NULL, _1;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getuseragent", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(userAgent);
	zephir_fast_strtolower(userAgent, _0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "android", 0);
	zephir_fast_strpos(return_value, userAgent, &_1, 0 );
	RETURN_MM();

}

PHP_METHOD(Soinc_Phalcon_Http_Request_Extend, fromIOS) {

	zval *userAgent = NULL, *_0 = NULL, _1;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getuseragent", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(userAgent);
	zephir_fast_strtolower(userAgent, _0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "iphone", 0);
	zephir_fast_strpos(return_value, userAgent, &_1, 0 );
	RETURN_MM();

}

