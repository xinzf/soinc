
extern zend_class_entry *soinc_model_ce;

ZEPHIR_INIT_CLASS(Soinc_Model);

PHP_METHOD(Soinc_Model, initialize);
PHP_METHOD(Soinc_Model, __get);
PHP_METHOD(Soinc_Model, getMessage);
PHP_METHOD(Soinc_Model, getFirstMessage);
PHP_METHOD(Soinc_Model, getLastMessage);
PHP_METHOD(Soinc_Model, getErrCode);
PHP_METHOD(Soinc_Model, createBuilder);
PHP_METHOD(Soinc_Model, getInstance);
PHP_METHOD(Soinc_Model, beforeValidationOnCreate);
PHP_METHOD(Soinc_Model, afterFetch);
PHP_METHOD(Soinc_Model, beforeSave);

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_model___get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_model_geterrcode, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlErr)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_model_createbuilder, 0, 0, 0)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(soinc_model_method_entry) {
	PHP_ME(Soinc_Model, initialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Model, __get, arginfo_soinc_model___get, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Model, getMessage, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Model, getFirstMessage, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Model, getLastMessage, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Model, getErrCode, arginfo_soinc_model_geterrcode, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Model, createBuilder, arginfo_soinc_model_createbuilder, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Model, getInstance, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Soinc_Model, beforeValidationOnCreate, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Model, afterFetch, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_Model, beforeSave, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
