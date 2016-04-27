
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/time.h"


ZEPHIR_INIT_CLASS(Soinc_Http_Response_Cookies) {

	ZEPHIR_REGISTER_CLASS(Soinc\\Http\\Response, Cookies, soinc, http_response_cookies, soinc_http_response_cookies_method_entry, 0);

	zend_declare_property_long(soinc_http_response_cookies_ce, SL("expire"), 3600, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(soinc_http_response_cookies_ce, SL("domain"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(soinc_http_response_cookies_ce, SL("path"), "/", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(soinc_http_response_cookies_ce, SL("secure"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(soinc_http_response_cookies_ce, SL("httpOnly"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(soinc_http_response_cookies_ce, SL("useEncryption"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Soinc_Http_Response_Cookies, useEncryption) {

	zval *serviceName_param = NULL;
	zval *serviceName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &serviceName_param);

	zephir_get_strval(serviceName, serviceName_param);


	zephir_update_property_this(this_ptr, SL("useEncryption"), serviceName TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Soinc_Http_Response_Cookies, getCrypt) {

	

	RETURN_MEMBER(this_ptr, "useEncryption");

}

PHP_METHOD(Soinc_Http_Response_Cookies, setExpiration) {

	zval *seconds_param = NULL, _0, *_1$$3;
	int seconds;

	zephir_fetch_params(0, 1, 0, &seconds_param);

	seconds = zephir_get_intval(seconds_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, seconds);
	if (Z_TYPE_P(&_0) == IS_LONG) {
		ZEPHIR_INIT_ZVAL_NREF(_1$$3);
		ZVAL_LONG(_1$$3, seconds);
		zephir_update_property_this(this_ptr, SL("expire"), _1$$3 TSRMLS_CC);
	}
	RETURN_THISW();

}

PHP_METHOD(Soinc_Http_Response_Cookies, getExpiration) {

	

	RETURN_MEMBER(this_ptr, "expire");

}

PHP_METHOD(Soinc_Http_Response_Cookies, setPath) {

	zval *path_param = NULL;
	zval *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	zephir_get_strval(path, path_param);


	zephir_update_property_this(this_ptr, SL("path"), path TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Soinc_Http_Response_Cookies, getPath) {

	

	RETURN_MEMBER(this_ptr, "path");

}

PHP_METHOD(Soinc_Http_Response_Cookies, setDomain) {

	zval *domain_param = NULL;
	zval *domain = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &domain_param);

	zephir_get_strval(domain, domain_param);


	zephir_update_property_this(this_ptr, SL("domain"), domain TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Soinc_Http_Response_Cookies, getDomain) {

	

	RETURN_MEMBER(this_ptr, "domain");

}

PHP_METHOD(Soinc_Http_Response_Cookies, setSecure) {

	zval *secure_param = NULL;
	zend_bool secure;

	zephir_fetch_params(0, 1, 0, &secure_param);

	secure = zephir_get_boolval(secure_param);


	if (secure) {
		zephir_update_property_this(this_ptr, SL("secure"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("secure"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	RETURN_THISW();

}

PHP_METHOD(Soinc_Http_Response_Cookies, getSecure) {

	

	RETURN_MEMBER(this_ptr, "secure");

}

PHP_METHOD(Soinc_Http_Response_Cookies, setHttpOnly) {

	zval *only_param = NULL;
	zend_bool only;

	zephir_fetch_params(0, 1, 0, &only_param);

	only = zephir_get_boolval(only_param);


	if (only) {
		zephir_update_property_this(this_ptr, SL("httpOnly"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("httpOnly"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	RETURN_THISW();

}

PHP_METHOD(Soinc_Http_Response_Cookies, getHttpOnly) {

	

	RETURN_MEMBER(this_ptr, "httpOnly");

}

PHP_METHOD(Soinc_Http_Response_Cookies, get) {

	zend_class_entry *_3$$5;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *_COOKIE, *_0 = NULL, *value = NULL, *_1$$4, *crypt$$5 = NULL, *_2$$5 = NULL, *_4$$5, *_5$$5 = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_COOKIE, SS("_COOKIE") TSRMLS_CC);
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "has", NULL, 0, name);
	zephir_check_call_status();
	if (!(zephir_is_true(_0))) {
		RETURN_MM_STRING("", 1);
	}
	ZEPHIR_OBS_VAR(value);
	zephir_array_fetch(&value, _COOKIE, name, PH_NOISY, "soinc/http/response/cookies.zep", 87 TSRMLS_CC);
	if (!(ZEPHIR_IS_EMPTY(value))) {
		_1$$4 = zephir_fetch_nproperty_this(this_ptr, SL("useEncryption"), PH_NOISY_CC);
		if (zephir_is_true(_1$$4)) {
				_3$$5 = zend_fetch_class(SL("Phalcon\\Di"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			ZEPHIR_CALL_CE_STATIC(&_2$$5, _3$$5, "getdefault", NULL, 0);
			zephir_check_call_status();
			_4$$5 = zephir_fetch_nproperty_this(this_ptr, SL("useEncryption"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&crypt$$5, _2$$5, "get", NULL, 0, _4$$5);
			zephir_check_call_status();
			if (!(zephir_is_instance_of(crypt$$5, SL("Phalcon\\CryptInterface") TSRMLS_CC))) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "The encrypt is not extnds Phalcon\\CryptInterface", "soinc/http/response/cookies.zep", 94);
				return;
			}
			ZEPHIR_CALL_METHOD(&_5$$5, crypt$$5, "decryptbase64", NULL, 0, value);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(value, _5$$5);
		}
	}
	RETURN_CCTOR(value);

}

PHP_METHOD(Soinc_Http_Response_Cookies, set) {

	zend_class_entry *_2$$3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *value_param = NULL, *_0, *_5, *_6, _7, *_8, *_9, *_10, *crypt$$3 = NULL, *_1$$3 = NULL, *_3$$3, *_4$$3 = NULL;
	zval *name = NULL, *value = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value_param);

	zephir_get_strval(name, name_param);
	zephir_get_strval(value, value_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("useEncryption"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
			_2$$3 = zend_fetch_class(SL("Phalcon\\Di"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		ZEPHIR_CALL_CE_STATIC(&_1$$3, _2$$3, "getdefault", NULL, 0);
		zephir_check_call_status();
		_3$$3 = zephir_fetch_nproperty_this(this_ptr, SL("useEncryption"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&crypt$$3, _1$$3, "get", NULL, 0, _3$$3);
		zephir_check_call_status();
		if (!(zephir_is_instance_of(crypt$$3, SL("Phalcon\\CryptInterface") TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "The encrypt is not extnds Phalcon\\CryptInterface", "soinc/http/response/cookies.zep", 109);
			return;
		}
		ZEPHIR_CALL_METHOD(&_4$$3, crypt$$3, "encryptbase64", NULL, 0, value);
		zephir_check_call_status();
		zephir_get_strval(value, _4$$3);
	}
	ZEPHIR_INIT_VAR(_5);
	zephir_time(_5);
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("expire"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_7);
	zephir_add_function(&_7, _5, _6);
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("path"), PH_NOISY_CC);
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("domain"), PH_NOISY_CC);
	_9 = zephir_fetch_nproperty_this(this_ptr, SL("secure"), PH_NOISY_CC);
	_10 = zephir_fetch_nproperty_this(this_ptr, SL("httpOnly"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_FUNCTION("setcookie", NULL, 33, name, value, &_7, _6, _8, _9, _10);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Soinc_Http_Response_Cookies, has) {

	zval *name_param = NULL, *_COOKIE;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_COOKIE, SS("_COOKIE") TSRMLS_CC);
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	RETURN_MM_BOOL(zephir_array_isset(_COOKIE, name));

}

PHP_METHOD(Soinc_Http_Response_Cookies, delete) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *_COOKIE, *_0, *_1, *_2, *_3, *_4, _5, *_6 = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_COOKIE, SS("_COOKIE") TSRMLS_CC);
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	ZEPHIR_INIT_VAR(_0);
	zephir_time(_0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("path"), PH_NOISY_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("domain"), PH_NOISY_CC);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("secure"), PH_NOISY_CC);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("httpOnly"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_STRING(&_5, "", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "setcookie", NULL, 33, name, &_5, _0, _1, _2, _3, _4);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "has", NULL, 0, name);
	zephir_check_call_status();
	if (zephir_is_true(_6)) {
		zephir_array_unset(&_COOKIE, name, PH_SEPARATE);
	}
	RETURN_MM_BOOL(1);

}

