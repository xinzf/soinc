
extern zend_class_entry *soinc_model_model_ce;

ZEPHIR_INIT_CLASS(Soinc_Model_Model);

PHP_METHOD(Soinc_Model_Model, initialize);
PHP_METHOD(Soinc_Model_Model, __get);
PHP_METHOD(Soinc_Model_Model, getMessage);
PHP_METHOD(Soinc_Model_Model, getFirstMessage);
PHP_METHOD(Soinc_Model_Model, getLastMessage);
PHP_METHOD(Soinc_Model_Model, getErrCode);
PHP_METHOD(Soinc_Model_Model, createBuilder);
PHP_METHOD(Soinc_Model_Model, getInstance);
PHP_METHOD(Soinc_Model_Model, beforeValidationOnCreate);
PHP_METHOD(Soinc_Model_Model, afterFetch);
PHP_METHOD(Soinc_Model_Model, beforeSave);

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_model_model___get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_model_model_geterrcode, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlErr)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_model_model_createbuilder, 0, 0, 0)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(soinc_model_model_method_entry) {
	PHP_ME(Soinc_Model_Model, initialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Model_Model, __get, arginfo_soinc_model_model___get, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Model_Model, getMessage, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Model_Model, getFirstMessage, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Model_Model, getLastMessage, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Model_Model, getErrCode, arginfo_soinc_model_model_geterrcode, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Model_Model, createBuilder, arginfo_soinc_model_model_createbuilder, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Model_Model, getInstance, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Soinc_Model_Model, beforeValidationOnCreate, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Model_Model, afterFetch, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Model_Model, beforeSave, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
