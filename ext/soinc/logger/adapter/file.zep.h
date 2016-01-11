
extern zend_class_entry *soinc_logger_adapter_file_ce;

ZEPHIR_INIT_CLASS(Soinc_Logger_Adapter_File);

PHP_METHOD(Soinc_Logger_Adapter_File, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_logger_adapter_file___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, filePath)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(soinc_logger_adapter_file_method_entry) {
	PHP_ME(Soinc_Logger_Adapter_File, __construct, arginfo_soinc_logger_adapter_file___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
