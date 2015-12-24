
extern zend_class_entry *soinc_logger_processor_trace_ce;

ZEPHIR_INIT_CLASS(Soinc_Logger_Processor_Trace);

PHP_METHOD(Soinc_Logger_Processor_Trace, __construct);
PHP_METHOD(Soinc_Logger_Processor_Trace, __toString);
static zend_object_value zephir_init_properties_Soinc_Logger_Processor_Trace(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_logger_processor_trace___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, mode)
	ZEND_ARG_ARRAY_INFO(0, skipClassesPartials, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(soinc_logger_processor_trace_method_entry) {
	PHP_ME(Soinc_Logger_Processor_Trace, __construct, arginfo_soinc_logger_processor_trace___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Soinc_Logger_Processor_Trace, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
