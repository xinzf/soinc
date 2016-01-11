//<?php

namespace Soinc;

/**
* Dfs
*/
abstract class Dfs extends \Phalcon\Mvc\User\Component
{

    abstract protected function __construct(var options = null);

    abstract public function uploadFile(string srcFile,string ext = null,array metas = []);

    abstract public function uploadData(string data,string ext = null,array metas = []);

    abstract public function info(string id,boolean metas = false);

    abstract public function delete(string id);

    abstract public function download(string id);
    
}