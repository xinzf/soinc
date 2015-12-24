
extern zend_class_entry *soinc_db_mysql_ce;

ZEPHIR_INIT_CLASS(Soinc_Db_Mysql);

PHP_METHOD(Soinc_Db_Mysql, __construct);
PHP_METHOD(Soinc_Db_Mysql, getConnection);
static zend_object_value zephir_init_properties_Soinc_Db_Mysql(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_db_mysql___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(soinc_db_mysql_method_entry) {
	PHP_ME(Soinc_Db_Mysql, __construct, arginfo_soinc_db_mysql___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Soinc_Db_Mysql, getConnection, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
