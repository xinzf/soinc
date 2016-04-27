
extern zend_class_entry *soinc_abstractdfs_ce;

ZEPHIR_INIT_CLASS(Soinc_AbstractDfs);

PHP_METHOD(Soinc_AbstractDfs, __construct);
PHP_METHOD(Soinc_AbstractDfs, uploadFile);
PHP_METHOD(Soinc_AbstractDfs, uploadData);
PHP_METHOD(Soinc_AbstractDfs, info);
PHP_METHOD(Soinc_AbstractDfs, delete);
PHP_METHOD(Soinc_AbstractDfs, download);

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_abstractdfs___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_abstractdfs_uploadfile, 0, 0, 1)
	ZEND_ARG_INFO(0, srcFile)
	ZEND_ARG_INFO(0, ext)
	ZEND_ARG_ARRAY_INFO(0, metas, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_abstractdfs_uploaddata, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, ext)
	ZEND_ARG_ARRAY_INFO(0, metas, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_abstractdfs_info, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_INFO(0, metas)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_abstractdfs_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_soinc_abstractdfs_download, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(soinc_abstractdfs_method_entry) {
	PHP_ME(Soinc_AbstractDfs, __construct, arginfo_soinc_abstractdfs___construct, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED|ZEND_ACC_CTOR)
	PHP_ME(Soinc_AbstractDfs, uploadFile, arginfo_soinc_abstractdfs_uploadfile, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_AbstractDfs, uploadData, arginfo_soinc_abstractdfs_uploaddata, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_AbstractDfs, info, arginfo_soinc_abstractdfs_info, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_AbstractDfs, delete, arginfo_soinc_abstractdfs_delete, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Soinc_AbstractDfs, download, arginfo_soinc_abstractdfs_download, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};
