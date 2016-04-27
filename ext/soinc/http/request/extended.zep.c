
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
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/hash.h"
#include "kernel/fcall.h"
#include "kernel/exit.h"


/**
* Extend
*/
ZEPHIR_INIT_CLASS(Soinc_Http_Request_Extended) {

	ZEPHIR_REGISTER_CLASS_EX(Soinc\\Http\\Request, Extended, soinc, http_request_extended, zephir_get_internal_ce(SS("phalcon\\http\\request") TSRMLS_CC), soinc_http_request_extended_method_entry, 0);

	zend_declare_property_null(soinc_http_request_extended_ce, SL("allowds"), ZEND_ACC_PROTECTED TSRMLS_CC);

	soinc_http_request_extended_ce->create_object = zephir_init_properties_Soinc_Http_Request_Extended;
	return SUCCESS;

}

PHP_METHOD(Soinc_Http_Request_Extended, setAllowed) {

	zval *iplist, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &iplist);



	ZEPHIR_INIT_VAR(_0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("allowds"), PH_NOISY_CC);
	zephir_fast_array_merge(_0, &(_1), &(iplist) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("allowds"), _0 TSRMLS_CC);
	RETURN_MM_BOOL(1);

}

PHP_METHOD(Soinc_Http_Request_Extended, compareIp) {

	zend_bool _6$$4;
	HashTable *_4$$3;
	HashPosition _3$$3;
	zval *clientIp = NULL, *serverIp = NULL, _0, *_1, *key$$3 = NULL, *num$$3 = NULL, *_2$$3 = NULL, **_5$$3, *_7$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &clientIp, &serverIp);

	ZEPHIR_SEPARATE_PARAM(clientIp);
	ZEPHIR_SEPARATE_PARAM(serverIp);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "*", 0);
	ZEPHIR_INIT_VAR(_1);
	zephir_fast_strpos(_1, serverIp, &_0, 0 );
	if (!ZEPHIR_IS_FALSE_IDENTICAL(_1)) {
		ZEPHIR_INIT_VAR(_2$$3);
		zephir_fast_explode_str(_2$$3, SL("."), clientIp, LONG_MAX TSRMLS_CC);
		ZEPHIR_CPY_WRT(clientIp, _2$$3);
		ZEPHIR_INIT_NVAR(_2$$3);
		zephir_fast_explode_str(_2$$3, SL("."), serverIp, LONG_MAX TSRMLS_CC);
		ZEPHIR_CPY_WRT(serverIp, _2$$3);
		zephir_is_iterable(serverIp, &_4$$3, &_3$$3, 0, 0, "soinc/http/request/extended.zep", 32);
		for (
		  ; zephir_hash_get_current_data_ex(_4$$3, (void**) &_5$$3, &_3$$3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_4$$3, &_3$$3)
		) {
			ZEPHIR_GET_HMKEY(key$$3, _4$$3, _3$$3);
			ZEPHIR_GET_HVALUE(num$$3, _5$$3);
			_6$$4 = ZEPHIR_IS_STRING_IDENTICAL(num$$3, "*");
			if (!(_6$$4)) {
				zephir_array_fetch(&_7$$4, clientIp, key$$3, PH_NOISY | PH_READONLY, "soinc/http/request/extended.zep", 25 TSRMLS_CC);
				_6$$4 = (ZEPHIR_IS_IDENTICAL(num$$3, _7$$4));
			}
			if (_6$$4) {
				continue;
			} else {
				RETURN_MM_BOOL(0);
			}
		}
		RETURN_MM_BOOL(1);
	} else if (ZEPHIR_IS_IDENTICAL(clientIp, serverIp)) {
		RETURN_MM_BOOL(1);
	} else {
		RETURN_MM_BOOL(0);
	}

}

PHP_METHOD(Soinc_Http_Request_Extended, isAllowed) {

	HashTable *_3;
	HashPosition _2;
	zval *clientIp = NULL, *currentIp = NULL, *serverIp = NULL, *_0, *_1, **_4, *_5$$5 = NULL;
	zephir_fcall_cache_entry *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&clientIp, this_ptr, "getclientaddress", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&currentIp, this_ptr, "getserveraddress", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_IDENTICAL(clientIp, currentIp)) {
		RETURN_MM_BOOL(1);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("allowds"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		RETURN_MM_BOOL(1);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("allowds"), PH_NOISY_CC);
	zephir_is_iterable(_1, &_3, &_2, 0, 0, "soinc/http/request/extended.zep", 64);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HVALUE(serverIp, _4);
		ZEPHIR_CALL_METHOD(&_5$$5, this_ptr, "compareip", &_6, 32, clientIp, serverIp);
		zephir_check_call_status();
		if (zephir_is_true(_5$$5)) {
			RETURN_MM_BOOL(1);
		}
	}
	php_printf("%s", "Forbidden!");
	ZEPHIR_MM_RESTORE();
	zephir_exit_empty();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Soinc_Http_Request_Extended, fromMobile) {

	zend_bool _1;
	zval *_0 = NULL, *_2 = NULL, *_3 = NULL;
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
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "fromios", NULL, 0);
	zephir_check_call_status();
	if (_1) {
		RETURN_MM_BOOL(1);
	} else if (zephir_is_true(_3)) {
		RETURN_MM_BOOL(1);
	} else {
		RETURN_MM_BOOL(0);
	}

}

PHP_METHOD(Soinc_Http_Request_Extended, fromWeixin) {

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

PHP_METHOD(Soinc_Http_Request_Extended, fromWeibo) {

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

PHP_METHOD(Soinc_Http_Request_Extended, fromAndroid) {

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

PHP_METHOD(Soinc_Http_Request_Extended, fromIOS) {

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

zend_object_value zephir_init_properties_Soinc_Http_Request_Extended(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1$$3;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("allowds"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(this_ptr, SL("allowds"), _1$$3 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

