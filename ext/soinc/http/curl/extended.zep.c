
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
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/hash.h"
#include "kernel/concat.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Soinc_Http_Curl_Extended) {

	ZEPHIR_REGISTER_CLASS(Soinc\\Http\\Curl, Extended, soinc, http_curl_extended, soinc_http_curl_extended_method_entry, 0);

	zend_declare_property_null(soinc_http_curl_extended_ce, SL("handle"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(soinc_http_curl_extended_ce, SL("url"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(soinc_http_curl_extended_ce, SL("port"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(soinc_http_curl_extended_ce, SL("headers"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(soinc_http_curl_extended_ce, SL("cookie"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(soinc_http_curl_extended_ce, SL("user_agent"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(soinc_http_curl_extended_ce, SL("referer"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(soinc_http_curl_extended_ce, SL("postdata"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(soinc_http_curl_extended_ce, SL("defaultHeaders"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(soinc_http_curl_extended_ce, SL("defaultOptions"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(soinc_http_curl_extended_ce, SL("_http_code"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(soinc_http_curl_extended_ce, SL("response_headers"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(soinc_http_curl_extended_ce, SL("response_body"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_string(soinc_http_curl_extended_ce, SL("lastRequest"), "", ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_string(soinc_http_curl_extended_ce, SL("error"), "", ZEND_ACC_PRIVATE TSRMLS_CC);

	soinc_http_curl_extended_ce->create_object = zephir_init_properties_Soinc_Http_Curl_Extended;
	return SUCCESS;

}

PHP_METHOD(Soinc_Http_Curl_Extended, __construct) {

	zval *_0, *_1, *_2;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 6, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_0, SS("Accept"), SL("text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8"), 1);
	add_assoc_stringl_ex(_0, SS("Accept-Encoding"), SL("gzip,deflate,sdch"), 1);
	add_assoc_stringl_ex(_0, SS("Accept-Language"), SL("zh-CN,zh;q=0.8,en;q=0.6"), 1);
	add_assoc_stringl_ex(_0, SS("Cache-Control"), SL("max-age=0"), 1);
	add_assoc_stringl_ex(_0, SS("Connection"), SL("keep-alive"), 1);
	add_assoc_stringl_ex(_0, SS("Expect"), SL(""), 1);
	zephir_update_property_this(this_ptr, SL("defaultHeaders"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 12, 0 TSRMLS_CC);
	zephir_array_update_long(&_1, 19913, &ZEPHIR_GLOBAL(global_true), PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(&_1, 58, &ZEPHIR_GLOBAL(global_true), PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(&_1, 52, &ZEPHIR_GLOBAL(global_true), PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	add_index_long(_1, 68, 20);
	zephir_array_update_long(&_1, 42, &ZEPHIR_GLOBAL(global_true), PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	add_index_stringl(_1, 10018, SL("Mozilla/5.0 (Macintosh; Intel Mac OS X 10_9_3) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/37.0.2062.122 Safari/537.36"), 1);
	add_index_long(_1, 78, 30);
	add_index_long(_1, 13, 30);
	zephir_array_update_long(&_1, 58, &ZEPHIR_GLOBAL(global_true), PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(&_1, 45, &ZEPHIR_GLOBAL(global_false), PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	add_index_stringl(_1, 10102, SL("gzip"), 1);
	zephir_array_update_long(&_1, 64, &ZEPHIR_GLOBAL(global_false), PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_update_property_this(this_ptr, SL("defaultOptions"), _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	zephir_create_array(_2, 42, 0 TSRMLS_CC);
	add_index_stringl(_2, 0, SL("Unable to access"), 1);
	add_index_stringl(_2, 100, SL("Continue"), 1);
	add_index_stringl(_2, 101, SL("Switching Protocols"), 1);
	add_index_stringl(_2, 200, SL("OK"), 1);
	add_index_stringl(_2, 201, SL("Created"), 1);
	add_index_stringl(_2, 202, SL("Accepted"), 1);
	add_index_stringl(_2, 203, SL("Non-Authoritative Information"), 1);
	add_index_stringl(_2, 204, SL("No Content"), 1);
	add_index_stringl(_2, 205, SL("Reset Content"), 1);
	add_index_stringl(_2, 206, SL("Partial Content"), 1);
	add_index_stringl(_2, 300, SL("Multiple Choices"), 1);
	add_index_stringl(_2, 301, SL("Moved Permanently"), 1);
	add_index_stringl(_2, 302, SL("Found"), 1);
	add_index_stringl(_2, 303, SL("See Other"), 1);
	add_index_stringl(_2, 304, SL("Not Modified"), 1);
	add_index_stringl(_2, 305, SL("Use Proxy"), 1);
	add_index_stringl(_2, 307, SL("Temporary Redirect"), 1);
	add_index_stringl(_2, 400, SL("Bad Request"), 1);
	add_index_stringl(_2, 401, SL("Unauthorized"), 1);
	add_index_stringl(_2, 402, SL("Payment Required"), 1);
	add_index_stringl(_2, 403, SL("Forbidden"), 1);
	add_index_stringl(_2, 404, SL("Not Found"), 1);
	add_index_stringl(_2, 405, SL("Method Not Allowed"), 1);
	add_index_stringl(_2, 406, SL("Not Acceptable"), 1);
	add_index_stringl(_2, 407, SL("Proxy Authentication Required"), 1);
	add_index_stringl(_2, 408, SL("Request Timeout"), 1);
	add_index_stringl(_2, 409, SL("Conflict"), 1);
	add_index_stringl(_2, 410, SL("Gone"), 1);
	add_index_stringl(_2, 411, SL("Length Required"), 1);
	add_index_stringl(_2, 412, SL("Precondition Failed"), 1);
	add_index_stringl(_2, 413, SL("Request Entity Too Large"), 1);
	add_index_stringl(_2, 414, SL("Request-URI Too Long"), 1);
	add_index_stringl(_2, 415, SL("Unsupported Media Type"), 1);
	add_index_stringl(_2, 416, SL("Requested Range Not Satisfiable"), 1);
	add_index_stringl(_2, 417, SL("Expectation Failed"), 1);
	add_index_stringl(_2, 500, SL("Internal Server Error"), 1);
	add_index_stringl(_2, 501, SL("Not Implemented"), 1);
	add_index_stringl(_2, 502, SL("Bad Gateway"), 1);
	add_index_stringl(_2, 503, SL("Service Unavailable"), 1);
	add_index_stringl(_2, 504, SL("Gateway Timeout"), 1);
	add_index_stringl(_2, 505, SL("HTTP Version Not Supported"), 1);
	add_index_stringl(_2, 509, SL("Bandwidth Limit Exceeded"), 1);
	zephir_update_property_this(this_ptr, SL("_http_code"), _2 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Soinc_Http_Curl_Extended, close) {

	zval *_0, *_1$$3, *_2$$3, *_3$$3;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("handle"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) == IS_RESOURCE) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("handle"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "curl_close", NULL, 21, _1$$3);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("handle"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("url"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("port"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
		ZEPHIR_INIT_VAR(_2$$3);
		array_init(_2$$3);
		zephir_update_property_this(this_ptr, SL("headers"), _2$$3 TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("cookie"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
		ZEPHIR_INIT_VAR(_3$$3);
		array_init(_3$$3);
		zephir_update_property_this(this_ptr, SL("postdata"), _3$$3 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Soinc_Http_Curl_Extended, setUrl) {

	zval *url_param = NULL;
	zval *url = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &url_param);

	if (unlikely(Z_TYPE_P(url_param) != IS_STRING && Z_TYPE_P(url_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'url' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(url_param) == IS_STRING)) {
		zephir_get_strval(url, url_param);
	} else {
		ZEPHIR_INIT_VAR(url);
		ZVAL_EMPTY_STRING(url);
	}


	zephir_update_property_this(this_ptr, SL("url"), url TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Soinc_Http_Curl_Extended, setPort) {

	zval *port_param = NULL, _0, *_1 = NULL, *_5, *_2$$3, *_3$$3, *_4$$3;
	int port, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &port_param);

	if (unlikely(Z_TYPE_P(port_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'port' must be a int") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	port = Z_LVAL_P(port_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, port);
	ZEPHIR_CALL_FUNCTION(&_1, "is_integer", NULL, 22, &_0);
	zephir_check_call_status();
	if (!(zephir_is_true(_1))) {
		ZEPHIR_INIT_VAR(_2$$3);
		object_init_ex(_2$$3, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(_3$$3);
		ZVAL_STRING(_3$$3, "http port in not ingeter", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_4$$3);
		ZVAL_LONG(_4$$3, 1);
		ZEPHIR_CALL_METHOD(NULL, _2$$3, "__construct", NULL, 9, _3$$3, _4$$3);
		zephir_check_temp_parameter(_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2$$3, "soinc/http/curl/extended.zep", 133 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_ZVAL_NREF(_5);
	ZVAL_LONG(_5, port);
	zephir_update_property_this(this_ptr, SL("port"), _5 TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Soinc_Http_Curl_Extended, setPostData) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *postdata, *_0$$3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &postdata);



	if (Z_TYPE_P(postdata) == IS_ARRAY) {
		ZEPHIR_CALL_FUNCTION(&_0$$3, "http_build_query", NULL, 23, postdata);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("postdata"), _0$$3 TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("postdata"), postdata TSRMLS_CC);
	}
	RETURN_THIS();

}

PHP_METHOD(Soinc_Http_Curl_Extended, setCookie) {

	zval *file_param = NULL;
	zval *file = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &file_param);

	if (unlikely(Z_TYPE_P(file_param) != IS_STRING && Z_TYPE_P(file_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'file' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(file_param) == IS_STRING)) {
		zephir_get_strval(file, file_param);
	} else {
		ZEPHIR_INIT_VAR(file);
		ZVAL_EMPTY_STRING(file);
	}


	zephir_update_property_this(this_ptr, SL("cookie"), file TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Soinc_Http_Curl_Extended, setUserAgent) {

	zval *userAgent_param = NULL;
	zval *userAgent = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &userAgent_param);

	if (unlikely(Z_TYPE_P(userAgent_param) != IS_STRING && Z_TYPE_P(userAgent_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'userAgent' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(userAgent_param) == IS_STRING)) {
		zephir_get_strval(userAgent, userAgent_param);
	} else {
		ZEPHIR_INIT_VAR(userAgent);
		ZVAL_EMPTY_STRING(userAgent);
	}


	zephir_update_property_this(this_ptr, SL("user_agent"), userAgent TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Soinc_Http_Curl_Extended, setHeader) {

	zval *name_param = NULL, *value_param = NULL;
	zval *name = NULL, *value = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value_param);

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
	if (unlikely(Z_TYPE_P(value_param) != IS_STRING && Z_TYPE_P(value_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'value' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(value_param) == IS_STRING)) {
		zephir_get_strval(value, value_param);
	} else {
		ZEPHIR_INIT_VAR(value);
		ZVAL_EMPTY_STRING(value);
	}


	zephir_update_property_array(this_ptr, SL("headers"), name, value TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Soinc_Http_Curl_Extended, setReferer) {

	zval *referer_param = NULL;
	zval *referer = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &referer_param);

	if (unlikely(Z_TYPE_P(referer_param) != IS_STRING && Z_TYPE_P(referer_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referer' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(referer_param) == IS_STRING)) {
		zephir_get_strval(referer, referer_param);
	} else {
		ZEPHIR_INIT_VAR(referer);
		ZVAL_EMPTY_STRING(referer);
	}


	zephir_update_property_this(this_ptr, SL("referer"), referer TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(Soinc_Http_Curl_Extended, send) {

	HashTable *_7;
	HashPosition _6;
	zval *headers;
	zval *_1 = NULL, *_2, *_3, *temp = NULL, *key = NULL, *value = NULL, *_4, *_5, **_8, *_10, *_11, _12 = zval_used_for_init, *_14, *_15, *_19, *_27, *_31, *_37, *response = NULL, *errcode = NULL, *_41, *_42, *_43, *httpCode = NULL, *codes = NULL, *_46 = NULL, *_47, *_9$$3 = NULL, *_16$$4, *_17$$4, _18$$4, *_20$$5, *_23$$5, *_24$$5, _25$$5 = zval_used_for_init, *_26$$5, *_21$$6, *_22$$6 = NULL, *_28$$7, *_29$$7, _30$$7, *_32$$8, *_33$$8, _34$$8 = zval_used_for_init, *_35$$8, *_36$$8, *_38$$9, *_39$$9, _40$$9, *_44$$10, *_45$$10 = NULL, *_48$$11 = NULL, *_49$$11, *_50$$11;
	zephir_fcall_cache_entry *_0 = NULL, *_13 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "close", &_0, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_1, "curl_init", NULL, 24);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("handle"), _1 TSRMLS_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("handle"), PH_NOISY_CC);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("defaultOptions"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt_array", NULL, 25, _2, _3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(headers);
	array_init(headers);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("defaultHeaders"), PH_NOISY_CC);
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(temp);
	zephir_fast_array_merge(temp, &(_4), &(_5) TSRMLS_CC);
	zephir_is_iterable(temp, &_7, &_6, 0, 0, "soinc/http/curl/extended.zep", 189);
	for (
	  ; zephir_hash_get_current_data_ex(_7, (void**) &_8, &_6) == SUCCESS
	  ; zephir_hash_move_forward_ex(_7, &_6)
	) {
		ZEPHIR_GET_HMKEY(key, _7, _6);
		ZEPHIR_GET_HVALUE(value, _8);
		ZEPHIR_INIT_LNVAR(_9$$3);
		ZEPHIR_CONCAT_VSV(_9$$3, key, ":", value);
		zephir_array_append(&headers, _9$$3, PH_SEPARATE, "soinc/http/curl/extended.zep", 183);
	}
	_10 = zephir_fetch_nproperty_this(this_ptr, SL("handle"), PH_NOISY_CC);
	_11 = zephir_fetch_nproperty_this(this_ptr, SL("url"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_12);
	ZVAL_LONG(&_12, 10002);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_13, 26, _10, &_12, _11);
	zephir_check_call_status();
	_14 = zephir_fetch_nproperty_this(this_ptr, SL("handle"), PH_NOISY_CC);
	ZEPHIR_SINIT_NVAR(_12);
	ZVAL_LONG(&_12, 10023);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_13, 26, _14, &_12, headers);
	zephir_check_call_status();
	_15 = zephir_fetch_nproperty_this(this_ptr, SL("user_agent"), PH_NOISY_CC);
	if (zephir_is_true(_15)) {
		_16$$4 = zephir_fetch_nproperty_this(this_ptr, SL("handle"), PH_NOISY_CC);
		_17$$4 = zephir_fetch_nproperty_this(this_ptr, SL("user_agent"), PH_NOISY_CC);
		ZEPHIR_SINIT_VAR(_18$$4);
		ZVAL_LONG(&_18$$4, 10018);
		ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_13, 26, _16$$4, &_18$$4, _17$$4);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(_19);
	zephir_read_property_this(&_19, this_ptr, SL("postdata"), PH_NOISY_CC);
	if (!(ZEPHIR_IS_EMPTY(_19))) {
		_20$$5 = zephir_fetch_nproperty_this(this_ptr, SL("postdata"), PH_NOISY_CC);
		if (Z_TYPE_P(_20$$5) == IS_ARRAY) {
			_21$$6 = zephir_fetch_nproperty_this(this_ptr, SL("postdata"), PH_NOISY_CC);
			ZEPHIR_CALL_FUNCTION(&_22$$6, "http_build_query", NULL, 23, _21$$6);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("postdata"), _22$$6 TSRMLS_CC);
		}
		_23$$5 = zephir_fetch_nproperty_this(this_ptr, SL("handle"), PH_NOISY_CC);
		_24$$5 = zephir_fetch_nproperty_this(this_ptr, SL("postdata"), PH_NOISY_CC);
		ZEPHIR_SINIT_VAR(_25$$5);
		ZVAL_LONG(&_25$$5, 10015);
		ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_13, 26, _23$$5, &_25$$5, _24$$5);
		zephir_check_call_status();
		_26$$5 = zephir_fetch_nproperty_this(this_ptr, SL("handle"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_25$$5);
		ZVAL_LONG(&_25$$5, 47);
		ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_13, 26, _26$$5, &_25$$5, ZEPHIR_GLOBAL(global_true));
		zephir_check_call_status();
	}
	_27 = zephir_fetch_nproperty_this(this_ptr, SL("port"), PH_NOISY_CC);
	if (zephir_is_true(_27)) {
		_28$$7 = zephir_fetch_nproperty_this(this_ptr, SL("handle"), PH_NOISY_CC);
		_29$$7 = zephir_fetch_nproperty_this(this_ptr, SL("port"), PH_NOISY_CC);
		ZEPHIR_SINIT_VAR(_30$$7);
		ZVAL_LONG(&_30$$7, 3);
		ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_13, 26, _28$$7, &_30$$7, _29$$7);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(_31);
	zephir_read_property_this(&_31, this_ptr, SL("cookie"), PH_NOISY_CC);
	if (!(ZEPHIR_IS_EMPTY(_31))) {
		_32$$8 = zephir_fetch_nproperty_this(this_ptr, SL("handle"), PH_NOISY_CC);
		_33$$8 = zephir_fetch_nproperty_this(this_ptr, SL("cookie"), PH_NOISY_CC);
		ZEPHIR_SINIT_VAR(_34$$8);
		ZVAL_LONG(&_34$$8, 10082);
		ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_13, 26, _32$$8, &_34$$8, _33$$8);
		zephir_check_call_status();
		_35$$8 = zephir_fetch_nproperty_this(this_ptr, SL("handle"), PH_NOISY_CC);
		_36$$8 = zephir_fetch_nproperty_this(this_ptr, SL("cookie"), PH_NOISY_CC);
		ZEPHIR_SINIT_NVAR(_34$$8);
		ZVAL_LONG(&_34$$8, 10031);
		ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_13, 26, _35$$8, &_34$$8, _36$$8);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(_37);
	zephir_read_property_this(&_37, this_ptr, SL("referer"), PH_NOISY_CC);
	if (!(ZEPHIR_IS_EMPTY(_37))) {
		_38$$9 = zephir_fetch_nproperty_this(this_ptr, SL("handle"), PH_NOISY_CC);
		_39$$9 = zephir_fetch_nproperty_this(this_ptr, SL("referer"), PH_NOISY_CC);
		ZEPHIR_SINIT_VAR(_40$$9);
		ZVAL_LONG(&_40$$9, 10016);
		ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_13, 26, _38$$9, &_40$$9, _39$$9);
		zephir_check_call_status();
	}
	_41 = zephir_fetch_nproperty_this(this_ptr, SL("handle"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&response, "curl_exec", NULL, 27, _41);
	zephir_check_call_status();
	_42 = zephir_fetch_nproperty_this(this_ptr, SL("url"), PH_NOISY_CC);
	zephir_update_property_this(this_ptr, SL("lastRequest"), _42 TSRMLS_CC);
	_43 = zephir_fetch_nproperty_this(this_ptr, SL("handle"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&errcode, "curl_errno", NULL, 28, _43);
	zephir_check_call_status();
	if (!ZEPHIR_IS_LONG(errcode, 0)) {
		_44$$10 = zephir_fetch_nproperty_this(this_ptr, SL("handle"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_45$$10, "curl_error", NULL, 29, _44$$10);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("error"), _45$$10 TSRMLS_CC);
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(codes);
	zephir_create_array(codes, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_46);
	ZVAL_LONG(_46, 200);
	zephir_array_fast_append(codes, _46);
	ZEPHIR_INIT_NVAR(_46);
	ZVAL_LONG(_46, 304);
	zephir_array_fast_append(codes, _46);
	_47 = zephir_fetch_nproperty_this(this_ptr, SL("handle"), PH_NOISY_CC);
	ZEPHIR_SINIT_NVAR(_12);
	ZVAL_LONG(&_12, 2097154);
	ZEPHIR_CALL_FUNCTION(&httpCode, "curl_getinfo", NULL, 30, _47, &_12);
	zephir_check_call_status();
	if (!(zephir_fast_in_array(httpCode, codes TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_48$$11);
		_49$$11 = zephir_fetch_nproperty_this(this_ptr, SL("_http_code"), PH_NOISY_CC);
		if (zephir_array_isset(_49$$11, httpCode)) {
			_50$$11 = zephir_fetch_nproperty_this(this_ptr, SL("_http_code"), PH_NOISY_CC);
			ZEPHIR_OBS_NVAR(_48$$11);
			zephir_array_fetch(&_48$$11, _50$$11, httpCode, PH_NOISY, "soinc/http/curl/extended.zep", 231 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(_48$$11);
			ZVAL_STRING(_48$$11, "Unknow error", 1);
		}
		zephir_update_property_this(this_ptr, SL("error"), _48$$11 TSRMLS_CC);
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "parseresponse", NULL, 31, response);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "close", &_0, 0);
	zephir_check_call_status();
	RETURN_MM_MEMBER(this_ptr, "response_body");

}

PHP_METHOD(Soinc_Http_Curl_Extended, parseResponse) {

	HashTable *_5, *_9$$3;
	HashPosition _4, _8$$3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *response_param = NULL, *header_size = NULL, *header = NULL, *_0, _1 = zval_used_for_init, *_2, *_3, *key = NULL, *value = NULL, **_6, *_7$$3 = NULL, *temp$$3 = NULL, *k$$3 = NULL, *v$$3 = NULL, **_10$$3, _11$$5 = zval_used_for_init, _12$$5 = zval_used_for_init, *_13$$5 = NULL, *pos$$5 = NULL, *headerKey$$5 = NULL, *headerVal$$5 = NULL, _14$$5 = zval_used_for_init, _15$$5 = zval_used_for_init, _16$$5 = zval_used_for_init, *_17$$5 = NULL;
	zval *response = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &response_param);

	zephir_get_strval(response, response_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("handle"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, 2097163);
	ZEPHIR_CALL_FUNCTION(&header_size, "curl_getinfo", NULL, 30, _0, &_1);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 0);
	ZEPHIR_INIT_VAR(header);
	zephir_substr(header, response, 0 , zephir_get_intval(header_size), 0);
	ZEPHIR_INIT_VAR(_2);
	zephir_substr(_2, response, zephir_get_intval(header_size), 0, ZEPHIR_SUBSTR_NO_LENGTH);
	zephir_update_property_this(this_ptr, SL("response_body"), _2 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	zephir_fast_explode_str(_3, SL("\n\r"), header, LONG_MAX TSRMLS_CC);
	ZEPHIR_CPY_WRT(header, _3);
	zephir_is_iterable(header, &_5, &_4, 0, 0, "soinc/http/curl/extended.zep", 283);
	for (
	  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zephir_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HMKEY(key, _5, _4);
		ZEPHIR_GET_HVALUE(value, _6);
		ZEPHIR_INIT_NVAR(_7$$3);
		zephir_fast_trim(_7$$3, value, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
		ZEPHIR_CPY_WRT(value, _7$$3);
		if (ZEPHIR_IS_EMPTY(value)) {
			continue;
		}
		ZEPHIR_INIT_NVAR(temp$$3);
		zephir_fast_explode_str(temp$$3, SL("\n"), value, LONG_MAX TSRMLS_CC);
		zephir_is_iterable(temp$$3, &_9$$3, &_8$$3, 0, 0, "soinc/http/curl/extended.zep", 282);
		for (
		  ; zephir_hash_get_current_data_ex(_9$$3, (void**) &_10$$3, &_8$$3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_9$$3, &_8$$3)
		) {
			ZEPHIR_GET_HMKEY(k$$3, _9$$3, _8$$3);
			ZEPHIR_GET_HVALUE(v$$3, _10$$3);
			if (zephir_fast_strlen_ev(v$$3) < 1) {
				continue;
			}
			ZEPHIR_SINIT_NVAR(_11$$5);
			ZVAL_LONG(&_11$$5, 0);
			ZEPHIR_SINIT_NVAR(_12$$5);
			ZVAL_LONG(&_12$$5, 4);
			ZEPHIR_INIT_NVAR(_13$$5);
			zephir_substr(_13$$5, v$$3, 0 , 4 , 0);
			if (ZEPHIR_IS_STRING(_13$$5, "HTTP")) {
				continue;
			}
			ZEPHIR_SINIT_NVAR(_14$$5);
			ZVAL_STRING(&_14$$5, ":", 0);
			ZEPHIR_INIT_NVAR(pos$$5);
			zephir_fast_strpos(pos$$5, v$$3, &_14$$5, 0 );
			ZEPHIR_SINIT_NVAR(_15$$5);
			ZVAL_LONG(&_15$$5, 0);
			ZEPHIR_INIT_NVAR(headerKey$$5);
			zephir_substr(headerKey$$5, v$$3, 0 , zephir_get_intval(pos$$5), 0);
			ZEPHIR_SINIT_NVAR(_16$$5);
			ZVAL_LONG(&_16$$5, (zephir_get_numberval(pos$$5) + 1));
			ZEPHIR_INIT_NVAR(headerVal$$5);
			zephir_substr(headerVal$$5, v$$3, zephir_get_intval(&_16$$5), 0, ZEPHIR_SUBSTR_NO_LENGTH);
			ZEPHIR_INIT_NVAR(_17$$5);
			zephir_fast_trim(_17$$5, headerKey$$5, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
			ZEPHIR_CPY_WRT(headerKey$$5, _17$$5);
			ZEPHIR_INIT_NVAR(_17$$5);
			zephir_fast_trim(_17$$5, headerVal$$5, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
			ZEPHIR_CPY_WRT(headerVal$$5, _17$$5);
			zephir_update_property_array_multi(this_ptr, SL("response_headers"), &headerVal$$5 TSRMLS_CC, SL("zz"), 2, key, headerKey$$5);
		}
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(Soinc_Http_Curl_Extended, getResponseHeaders) {

	

	RETURN_MEMBER(this_ptr, "response_headers");

}

PHP_METHOD(Soinc_Http_Curl_Extended, getLastRequest) {

	

	RETURN_MEMBER(this_ptr, "lastRequest");

}

PHP_METHOD(Soinc_Http_Curl_Extended, getError) {

	

	RETURN_MEMBER(this_ptr, "error");

}

PHP_METHOD(Soinc_Http_Curl_Extended, setOptions) {

	HashTable *_1;
	HashPosition _0;
	zval *options_param = NULL, *key = NULL, *item = NULL, **_2;
	zval *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	options = options_param;


	if (!(Z_TYPE_P(options) == IS_ARRAY)) {
		RETURN_MM_BOOL(0);
	}
	zephir_is_iterable(options, &_1, &_0, 0, 0, "soinc/http/curl/extended.zep", 312);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(item, _2);
		zephir_update_property_array(this_ptr, SL("defaultOptions"), key, item TSRMLS_CC);
	}
	RETURN_THIS();

}

zend_object_value zephir_init_properties_Soinc_Http_Curl_Extended(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_2, *_4, *_6, *_8, *_10, *_12, *_1$$3, *_3$$4, *_5$$5, *_7$$6, *_9$$7, *_11$$8, *_13$$9;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("response_body"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(this_ptr, SL("response_body"), _1$$3 TSRMLS_CC);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("response_headers"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(_3$$4);
			array_init(_3$$4);
			zephir_update_property_this(this_ptr, SL("response_headers"), _3$$4 TSRMLS_CC);
		}
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_http_code"), PH_NOISY_CC);
		if (Z_TYPE_P(_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(_5$$5);
			array_init(_5$$5);
			zephir_update_property_this(this_ptr, SL("_http_code"), _5$$5 TSRMLS_CC);
		}
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("defaultOptions"), PH_NOISY_CC);
		if (Z_TYPE_P(_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(_7$$6);
			array_init(_7$$6);
			zephir_update_property_this(this_ptr, SL("defaultOptions"), _7$$6 TSRMLS_CC);
		}
		_8 = zephir_fetch_nproperty_this(this_ptr, SL("defaultHeaders"), PH_NOISY_CC);
		if (Z_TYPE_P(_8) == IS_NULL) {
			ZEPHIR_INIT_VAR(_9$$7);
			array_init(_9$$7);
			zephir_update_property_this(this_ptr, SL("defaultHeaders"), _9$$7 TSRMLS_CC);
		}
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("postdata"), PH_NOISY_CC);
		if (Z_TYPE_P(_10) == IS_NULL) {
			ZEPHIR_INIT_VAR(_11$$8);
			array_init(_11$$8);
			zephir_update_property_this(this_ptr, SL("postdata"), _11$$8 TSRMLS_CC);
		}
		_12 = zephir_fetch_nproperty_this(this_ptr, SL("headers"), PH_NOISY_CC);
		if (Z_TYPE_P(_12) == IS_NULL) {
			ZEPHIR_INIT_VAR(_13$$9);
			array_init(_13$$9);
			zephir_update_property_this(this_ptr, SL("headers"), _13$$9 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

