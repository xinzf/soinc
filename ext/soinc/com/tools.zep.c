
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
 * Tool
 *
 * description...
 *
 * @author Xiang Zhi <xiangzhi@cctvmall.cn>
 */
ZEPHIR_INIT_CLASS(Soinc_Com_Tools) {

	ZEPHIR_REGISTER_CLASS(Soinc\\Com, Tools, soinc, com_tools, NULL, 0);

	return SUCCESS;

}

