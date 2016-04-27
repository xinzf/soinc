
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


/**
* Dfs
*/
ZEPHIR_INIT_CLASS(Soinc_AbstractDfs) {

	ZEPHIR_REGISTER_CLASS_EX(Soinc, AbstractDfs, soinc, abstractdfs, zephir_get_internal_ce(SS("phalcon\\mvc\\user\\component") TSRMLS_CC), soinc_abstractdfs_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;

}

PHP_METHOD(Soinc_AbstractDfs, __construct) {

}

PHP_METHOD(Soinc_AbstractDfs, uploadFile) {

}

PHP_METHOD(Soinc_AbstractDfs, uploadData) {

}

PHP_METHOD(Soinc_AbstractDfs, info) {

}

PHP_METHOD(Soinc_AbstractDfs, delete) {

}

PHP_METHOD(Soinc_AbstractDfs, download) {

}

