
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#if PHP_VERSION_ID < 50500
#include <locale.h>
#endif

#include "php_ext.h"
#include "soinc.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *soinc_logger_processor_abstractprocessor_ce;
zend_class_entry *soinc_abstractmodule_ce;
zend_class_entry *soinc_bootstrap_ce;
zend_class_entry *soinc_db_mysql_ce;
zend_class_entry *soinc_exception_ce;
zend_class_entry *soinc_http_curl_extended_ce;
zend_class_entry *soinc_http_request_extended_ce;
zend_class_entry *soinc_logger_formatter_line_ce;
zend_class_entry *soinc_logger_processor_trace_ce;
zend_class_entry *soinc_model_model_ce;
zend_class_entry *soinc_tools_ce;

ZEND_DECLARE_MODULE_GLOBALS(soinc)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(soinc)
{
#if PHP_VERSION_ID < 50500
	char* old_lc_all = setlocale(LC_ALL, NULL);
	if (old_lc_all) {
		size_t len = strlen(old_lc_all);
		char *tmp  = calloc(len+1, 1);
		if (UNEXPECTED(!tmp)) {
			return FAILURE;
		}

		memcpy(tmp, old_lc_all, len);
		old_lc_all = tmp;
	}

	setlocale(LC_ALL, "C");
#endif
	REGISTER_INI_ENTRIES();
	ZEPHIR_INIT(Soinc_Logger_Processor_AbstractProcessor);
	ZEPHIR_INIT(Soinc_AbstractModule);
	ZEPHIR_INIT(Soinc_Bootstrap);
	ZEPHIR_INIT(Soinc_Db_Mysql);
	ZEPHIR_INIT(Soinc_Exception);
	ZEPHIR_INIT(Soinc_Http_Curl_Extended);
	ZEPHIR_INIT(Soinc_Http_Request_Extended);
	ZEPHIR_INIT(Soinc_Logger_Formatter_Line);
	ZEPHIR_INIT(Soinc_Logger_Processor_Trace);
	ZEPHIR_INIT(Soinc_Model_Model);
	ZEPHIR_INIT(Soinc_Tools);

#if PHP_VERSION_ID < 50500
	setlocale(LC_ALL, old_lc_all);
	free(old_lc_all);
#endif
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(soinc)
{

	zephir_deinitialize_memory(TSRMLS_C);
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_soinc_globals *soinc_globals TSRMLS_DC)
{
	soinc_globals->initialized = 0;

	/* Memory options */
	soinc_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	soinc_globals->active_symbol_table = NULL;

	/* Cache Enabled */
	soinc_globals->cache_enabled = 1;

	/* Recursive Lock */
	soinc_globals->recursive_lock = 0;

	/* Static cache */
	memset(soinc_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);


}

static PHP_RINIT_FUNCTION(soinc)
{

	zend_soinc_globals *soinc_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(soinc_globals_ptr TSRMLS_CC);
	//zephir_init_interned_strings(TSRMLS_C);

	zephir_initialize_memory(soinc_globals_ptr TSRMLS_CC);


	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(soinc)
{

	

	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}

static PHP_MINFO_FUNCTION(soinc)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_SOINC_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_SOINC_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_SOINC_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_SOINC_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_SOINC_ZEPVERSION);
	php_info_print_table_end();

	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(soinc)
{
	php_zephir_init_globals(soinc_globals TSRMLS_CC);
}

static PHP_GSHUTDOWN_FUNCTION(soinc)
{

}


zend_function_entry php_soinc_functions[] = {
ZEND_FE_END

};

zend_module_entry soinc_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_SOINC_EXTNAME,
	php_soinc_functions,
	PHP_MINIT(soinc),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(soinc),
#else
	NULL,
#endif
	PHP_RINIT(soinc),
	PHP_RSHUTDOWN(soinc),
	PHP_MINFO(soinc),
	PHP_SOINC_VERSION,
	ZEND_MODULE_GLOBALS(soinc),
	PHP_GINIT(soinc),
	PHP_GSHUTDOWN(soinc),
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_SOINC
ZEND_GET_MODULE(soinc)
#endif
