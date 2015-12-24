
extern zend_class_entry *soinc_logger_processor_abstractprocessor_ce;

ZEPHIR_INIT_CLASS(Soinc_Logger_Processor_AbstractProcessor);

PHP_METHOD(Soinc_Logger_Processor_AbstractProcessor, __toString);

ZEPHIR_INIT_FUNCS(soinc_logger_processor_abstractprocessor_method_entry) {
	PHP_ME(Soinc_Logger_Processor_AbstractProcessor, __toString, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};
