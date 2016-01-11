
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
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/memory.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Soinc_Tools) {

	ZEPHIR_REGISTER_CLASS(Soinc, Tools, soinc, tools, soinc_tools_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Soinc_Tools, xml2Array) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *xml, *data = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &xml);



	ZEPHIR_CALL_FUNCTION(&data, "simplexml_load_string", NULL, 39, xml);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	zephir_json_encode(_0, &(_0), data, 0  TSRMLS_CC);
	zephir_json_decode(return_value, &(return_value), _0, zephir_get_intval(ZEPHIR_GLOBAL(global_true))  TSRMLS_CC);
	RETURN_MM();

}

