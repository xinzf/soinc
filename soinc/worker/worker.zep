//<?php

namespace Soinc\Worker;

// declare(ticks = 1);

/**
* Worker 
*/
class Worker extends \Phalcon\Mvc\User\Component
{

    const STATUS_STARTING = 1;

    const STATUS_RUNNING = 2;

    const STATUS_SHUTDOWN = 4;

    protected daemonize = false;

    protected name;

    protected stdoutFile = "/dev/null";

    protected runtimePath = "";

    protected pidFile = "";

    protected logFile = "";

    protected statusFile = "";

    protected _masterPid = 0;

    /**
     * \Phalcon\Process\Worker
     * @var Worker
     */
    private _currentWorker = null;

    protected _pids = [];

    protected _pidsToRestart = [];

    protected _pidsToShutdown = [];

    protected _status = self::STATUS_STARTING;

    public function setDaemonize(boolean flag = true)
    {
        let this->daemonize = flag;
        return this;
    }

    public function setRuntimePath(string path)
    {
        if !is_dir(path) {
            if !mkdir(path,0777,true)
            {
                echo "The folder: ".path." is not exists or is not writeable\n";
                exit(255);
            }    
        }

        let this->runtimePath = path;
        return this;
    }

    public function setWorker(<\Soinc\Worker\TaskAbstract> task)
    {
        let this->_currentWorker = task;
        return this;
    }

    public function start()
    {
        this->initStart();
        this->daemonize();
        this->installSignal();
        this->saveMasterPid();
        this->forkChildren();
        // $this->displayUI();
        // $this->resetStd();
        this->monitorWorkers();
    }

    public function restart()
    {
        this->stop();
        this->reinstallSignal();
        this->start();
        echo "Restart worker successfull!\n";
    }

    public function status()
    {
    }

    public function reload()
    {

    }

    public function stop()
    {
        this->initStop();
        posix_kill(this->_masterPid,SIGINT);
        echo "Waiting shutdown....\n";
        while true {
            var pid = posix_kill(this->_masterPid,0);
            if !pid {
                break;
            }
            usleep(7000);
        }
        echo "Success shutdown\n";
    }

    private function stopAll()
    {
        var mpid;
        let this->_status = self::STATUS_SHUTDOWN;
        let mpid = getmypid();
        if this->_masterPid === getmypid() 
        {
            var _pids,_pid;
            let _pids = this->getAllChildrenPids();
            this->log("Task[".this->name."] Stopping...");
            for _pid in _pids {
                posix_kill(_pid,SIGTERM);
                let this->_pidsToShutdown[_pid] = time();
            }
        }
        else {
            this->_currentWorker->stop();
            exit(0);
        }
    }

    protected function init()
    {
        if empty(this->_currentWorker) {
            this->log("Please provide the Worker!");
            exit(0);
        }

        let this->name = this->_currentWorker->getName();
        if !this->name {
            this->log("Please provide the Worker's name!");
            exit(0);
        }

        if empty(this->runtimePath) {
            let this->pidFile    = sys_get_temp_dir()."/task.".this->name.".pid";
            let this->logFile    = sys_get_temp_dir()."/task.".this->name.".log";
            let this->statusFile = sys_get_temp_dir()."/task.".this->name.".status";
        }
        else {
            let this->pidFile    = rtrim(this->runtimePath,"/")."/task.".this->name.".pid";
            let this->logFile    = rtrim(this->runtimePath,"/")."/task.".this->name.".log";
            let this->statusFile = rtrim(this->runtimePath,"/")."/task.".this->name.".status";
        }
    }

    protected function initStart()
    {
        this->init();

        if this->isAlive() {
            this->log("task[".this->name."] is running!");
            exit(0);
        }

        let this->_status = self::STATUS_STARTING;
        this->setProcessTitle("task: master process ".this->name);
    }

    protected function initStop()
    {
        this->init();
        if !this->isAlive() {
            this->log("task[".this->name."] is not running!");
            exit(0);
        }

        let this->_masterPid = file_get_contents(this->pidFile);
    }

    protected function daemonize()
    {
        if !this->daemonize {
            return;
        }

        umask(0);

        var pid;
        let pid = pcntl_fork();
        if -1 == $pid {
            this->log("fork fail!");
            exit(254);
        }
        elseif pid > 0 {
            exit(0);
        }

        if -1 == posix_setsid() {
            this->log("setsid fail!");
            exit(254);
        }

        let pid = pcntl_fork();
        if -1 == pid {
            this->log("fork fail!");
            exit(254);
        }
        elseif 0 != pid {
            exit(0);
        }
    }

    protected function installSignal()
    {
        pcntl_signal(SIGINT,[this,"signalHandler"],false);
        pcntl_signal(SIGUSR1,[this,"signalHandler"],false);
        pcntl_signal(SIGUSR2,[this,"signalHandler"],false);
        pcntl_signal(SIGPIPE,SIG_IGN,false);
    }

    protected function reinstallSignal()
    {
        pcntl_signal(SIGINT,  SIG_IGN, false);
        pcntl_signal(SIGUSR1, SIG_IGN, false);
        pcntl_signal(SIGUSR2, SIG_IGN, false);
        $this->installSignal();
    }

    public function signalHandler(var signal)
    {
        this->log("Signal:{signal}");
        switch signal {
            case SIGINT:
                this->stopAll();
                break;

            case SIGUSR1:
                let this->_childrenToRestart = this->getAllChildrenPids();
                this->reload();
                break;

            case SIGUSR2:
                this->writeToStatus();
                break;

            default:
                break;
        }
    }

    protected function saveMasterPid()
    {
        let this->_masterPid = getmypid();
        if false === file_put_contents(this->pidFile,this->_masterPid) {
            this->log("Can't save pid to ".this->pidFile."!");
            exit(254);
        }

        this->log("task[".this->name."] master ".this->_masterPid." start success!");
    }

    protected function forkChildren()
    {
        while count(this->_pids) < this->_currentWorker->getCount() {
            this->forkOneChild();
        }

        if this->_currentWorker->getOnStart() {
            call_user_func(this->_currentWorker->getOnStart(),this);
        }

    }

    private function forkOneChild()
    {
        var pid;
        let pid = pcntl_fork();
        if pid > 0 {
            let this->_pids[pid] = pid;
            // $this->_pids[$pid] = Worker::facotry($pid);
        }
        elseif 0 == pid {
            if this->_status == self::STATUS_STARTING {
                // $this->resetStd();
            }

            // set_error_handler(array($this,'errorHandler'));
            // set_exception_handler(array($this,'exceptionHandler'));

            var mypid;
            let this->_pids = [];
            this->setProcessTitle("Task: worker process ".this->_currentWorker->getName());
            this->setProcessUser(this->_currentWorker->getUser());
            let mypid = getmypid();
            this->log("Task[".this->name."]: worker process ".mypid." start success!");
            this->_currentWorker->run();
            exit(250);
        }
        else {
            this->log("fork child fail\n");
            this->stopAll();
            exit(254);
        }
    }

    protected function displayUI()
    {
    }

    protected function resetStd()
    {
        // if !this->daemonize {
        //     return;
        // }

        // global $STDOUT,$STDERR;
        // $handle = fopen($this->stdoutFile,'a');
        // if ($handle) {
        //     unset($handle);
        //     @fclose(STDOUT);
        //     @fclose(STDERR);
        //     $STDOUT = fopen($this->stdoutFile,'a');
        //     $STDERR = fopen($this->stdoutFile,'a');
        // }
        // else {
        //     $this->log("Can not open stdoutFile: {$this->stdoutFile}");
        // }
    }

    protected function monitorWorkers()
    {
        let this->_status = self::STATUS_RUNNING;
        // @todo max 需要定义
        var max = 10;
        var i = 0;
        while true {
            pcntl_signal_dispatch();
            var status = 0;
            var pid = pcntl_wait(status,WUNTRACED);
            pcntl_signal_dispatch();
            if pid > 0 {
                if isset(this->_pids[pid]) {
                    if status !== 0 {
                        this->log("Worker[".this->name."]:".pid." exit with status ".status);
                    }
                    unset(this->_pids[pid]);
                }

                if this->_status !== self::STATUS_SHUTDOWN {
                    if i >= max {
                        let this->_status = self::STATUS_SHUTDOWN;
                    }
                    this->forkChildren();
                    let i = i+1;
                    this->log("Try times:".i."\n");
                }
                else {
                    if empty(this->_pids) {
                        unlink(this->pidFile);
                        this->log("Task[".this->name."] has been stopped!");

                        if this->_currentWorker->getOnStop() {
                            call_user_func(this->_currentWorker->getOnStop(),this);
                        }

                        exit(0);
                    }
                }
            }
        }
    }

    public function getCurrentUser()
    {
        var userinfo = [];
        let userinfo = posix_getpwuid(posix_getuid());
        return userinfo["name"];
    }

    protected function setProcessUser(string username)
    {
        if empty(username) || posix_getuid() !== 0 {
            return;
        }

        var userinfo = [];
        let userinfo = posix_getpwnam(username);
        if userinfo["uid"] != posix_getuid() || userinfo["gid"] != posix_getgid() {
            if !posix_setgid(userinfo["gid"]) || !posix_setuid(userinfo["uid"]) {
                this->log("Notice: Can not run worker as ".username.", You should be root");
            }
        }
    }

    protected function setProcessTitle(string title)
    {
        if function_exists("cli_set_process_title") {
            cli_set_process_title(title);
        }
        elseif extension_loaded("proctitle") && function_exists("proctitle") {
            setproctitle(title);
        }
    }

    protected function log(var msg)
    {
        if !is_string(msg) {
            let msg = print_r(msg,true);
        }

        let msg = msg."\n";
        if this->_status == self::STATUS_STARTING || !this->daemonize {
            echo msg;
        }

        file_put_contents(this->logFile,date("Y-m-d H:i:s")." ".msg,FILE_APPEND);
    }

    public function getAllChildrenPids()
    {
        return this->_pids;
    }

    protected function writeToStatus()
    {
    }

    protected function isAlive()
    {
        if !file_exists(this->pidFile) {
            return false;
        }

        var pid = file_get_contents(this->pidFile);
        if empty(pid) {
            return false;
        }

        var pid_is_alive;
        if pid {
            let pid_is_alive = posix_kill(pid,0);
        }

        if pid_is_alive {
            return true;
        }
        else {
            return false;
        }
    }
}