
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


ZEPHIR_INIT_CLASS(Soinc_Logger_Processor_AbstractProcessor) {

	ZEPHIR_REGISTER_CLASS(Soinc\\Logger\\Processor, AbstractProcessor, soinc, logger_processor_abstractprocessor, soinc_logger_processor_abstractprocessor_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;

}

PHP_METHOD(Soinc_Logger_Processor_AbstractProcessor, __toString) {

}

