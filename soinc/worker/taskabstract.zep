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
    abstract public function getCount();

    /**
     * 获取进程运行用户
     * @return string 用户名
     */
    abstract public function getUser();

    /**
     * 获取在主进程启动前的钩子
     * @return function 匿名函数
     */
    abstract public function getOnStart();

    /**
     * 获取在主进程结束后的钩子
     * @return function 匿名函数
     */
    abstract public function getOnStop();

    /**
     * 获取当进程出错的时候调用的钩子
     * @return function 匿名函数
     */
    abstract public function getOnError();

    /**
     * 执行进程逻辑
     * @return boolean 执行结果
     */
    abstract public function run();

    /**
     * 停止进程逻辑
     * @return [type] [description]
     */
    abstract public function stop();

}