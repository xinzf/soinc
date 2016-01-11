
extern zend_class_entry *soinc_tools_ce;

ZEPHIR_INIT_CLASS(Soinc_Tools);

PHP_METHOD(Soinc_Tools, xml2Array);

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_tools_xml2array, 0, 0, 1)
	ZEND_ARG_INFO(0, xml)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(soinc_tools_method_entry) {
	PHP_ME(Soinc_Tools, xml2Array, arginfo_soinc_tools_xml2array, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
