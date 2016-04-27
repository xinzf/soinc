//<?php

namespace Soinc\Worker;

/**
* Worker
*/
abstract class TaskAbstract extends \Phalcon\Mvc\User\Component
{
    /**
     * 获取Worker名称
     * @return string 名称
     */
    abstract public function getName();

    /**
     * 获取进程数量
     * @return integer 数量
     */
    abstract public function getProcessNum();

    /**
     * 获取进程运行用户
     * @return string 用户名
     */
    abstract public function getUser();

    /**
     * 主进程启动后立刻回调
     * @return function 匿名函数
     */
    abstract public function onMasterStart();

    /**
     * 主进程结束后回调
     * @return function 匿名函数
     */
    abstract public function onMasterStop();

    /**
     * 逻辑进程启动后立刻回调
     * @param  {[type]} <SoincWorkerWorker> worker        [description]
     * @return {[type]}                     [description]
     */
    abstract public function onStart();

    /**
     * 逻辑进程结束时回调
     * @param  {[type]} <SoincWorkerWorker> worker        [description]
     * @return {[type]}                     [description]
     */
    abstract public function onStop();

    /**
     * 执行进程逻辑
     * @return boolean 执行结果
     */
    abstract public function run();
}