
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
* Worker
*/
ZEPHIR_INIT_CLASS(Soinc_Worker_TaskAbstract) {

	ZEPHIR_REGISTER_CLASS_EX(Soinc\\Worker, TaskAbstract, soinc, worker_taskabstract, zephir_get_internal_ce(SS("phalcon\\mvc\\user\\component") TSRMLS_CC), soinc_worker_taskabstract_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;

}

/**
 * 获取Worker名称
 * @return string 名称
 */
PHP_METHOD(Soinc_Worker_TaskAbstract, getName) {

}

/**
 * 获取进程数量
 * @return integer 数量
 */
PHP_METHOD(Soinc_Worker_TaskAbstract, getProcessNum) {

}

/**
 * 获取进程运行用户
 * @return string 用户名
 */
PHP_METHOD(Soinc_Worker_TaskAbstract, getUser) {

}

/**
 * 主进程启动后立刻回调
 * @return function 匿名函数
 */
PHP_METHOD(Soinc_Worker_TaskAbstract, onMasterStart) {

}

/**
 * 主进程结束后回调
 * @return function 匿名函数
 */
PHP_METHOD(Soinc_Worker_TaskAbstract, onMasterStop) {

}

/**
 * 逻辑进程启动后立刻回调
 * @param  {[type]} <SoincWorkerWorker> worker        [description]
 * @return {[type]}                     [description]
 */
PHP_METHOD(Soinc_Worker_TaskAbstract, onStart) {

}

/**
 * 逻辑进程结束时回调
 * @param  {[type]} <SoincWorkerWorker> worker        [description]
 * @return {[type]}                     [description]
 */
PHP_METHOD(Soinc_Worker_TaskAbstract, onStop) {

}

/**
 * 执行进程逻辑
 * @return boolean 执行结果
 */
PHP_METHOD(Soinc_Worker_TaskAbstract, run) {

}

