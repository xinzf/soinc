
extern zend_class_entry *soinc_logger_formatter_line_ce;

ZEPHIR_INIT_CLASS(Soinc_Logger_Formatter_Line);

PHP_METHOD(Soinc_Logger_Formatter_Line, __construct);
PHP_METHOD(Soinc_Logger_Formatter_Line, format);
PHP_METHOD(Soinc_Logger_Formatter_Line, addProcessor);
PHP_METHOD(Soinc_Logger_Formatter_Line, __get);
zend_object_value zephir_init_properties_Soinc_Logger_Formatter_Line(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_logger_formatter_line___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, formatString)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_logger_formatter_line_format, 0, 0, 3)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, date)
	ZEND_ARG_INFO(0, context)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_logger_formatter_line_addprocessor, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_OBJ_INFO(0, processor, Soinc\\Logger\\Processor\\AbstractProcessor, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_logger_formatter_line___get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(soinc_logger_formatter_line_method_entry) {
	PHP_ME(Soinc_Logger_Formatter_Line, __construct, arginfo_soinc_logger_formatter_line___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Soinc_Logger_Formatter_Line, format, arginfo_soinc_logger_formatter_line_format, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Logger_Formatter_Line, addProcessor, arginfo_soinc_logger_formatter_line_addprocessor, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Logger_Formatter_Line, __get, arginfo_soinc_logger_formatter_line___get, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
