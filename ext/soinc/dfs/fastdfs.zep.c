
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


/**
* Fastdfs
*/
ZEPHIR_INIT_CLASS(Soinc_Dfs_Fastdfs) {

	ZEPHIR_REGISTER_CLASS(Soinc\\Dfs, Fastdfs, soinc, dfs_fastdfs, NULL, 0);

	return SUCCESS;

}

