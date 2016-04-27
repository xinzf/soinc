//<?php

namespace Soinc\Dfs;

/**
* Fastdfs
*/
class Fastdfs
{
    // protected options;

    // private trackerServer = null;

    // private storageServer = null;
    
    // protected function __construct(var options = null) {
    //     let this->options = null;
    // }

    // public function uploadFile(string srcFile,string ext = null,array metas = []) {
    //     if !ext {
    //         let ext = null;
    //     }

    //     if !file_exists(srcFile) {
    //         throw new \Exception("Error to upload file,because the src file: ".srcFile." is not exists");
    //     }

    //     this->getServer();
    //     var fileInfo = [];
    //     let fileInfo = fastdfs_storage_upload_by_filename(
    //         srcFile,
    //         ext,
    //         metas,
    //         this->options["group"],
    //         this->trackerServer,
    //         this->storageServer
    //     );

    //     if !fileInfo {
    //         throw new \Exception(
    //             sprintf("Error to upload: %s",fastdfs_get_last_error_info()),
    //             fastdfs_get_last_error_no()
    //         );
    //     }

    //     return fileInfo;
    // }

    // public function uploadData(string! data,string ext = null,array metas = []) {
    //     this->getServer();

    //     var fileInfo = [];
    //     let fileInfo = fastdfs_storage_upload_by_filebuff(
    //         data,
    //         ext,
    //         metas,
    //         this->options["group"],
    //         this->trackerServer,
    //         this->storageServer
    //     );

    //     if false == fileInfo {
    //         throw new \Exception(
    //             sprintf("Error to upload: %s",fastdfs_get_last_error_info()),
    //             fastdfs_get_last_error_no()
    //         );
    //     }

    //     return fileInfo;
    // }

    // public function info(string id,boolean metas = false) {

    // }

    // public function delete(string id) {

    // }

    // public function download(string id) {

    // }

    // protected function getServer() {
    //     let this->trackerServer = fastdfs_tracker_get_connection();
    //     if !this->trackerServer {
    //         throw new \Exception("");
    //     }

    //     if !fastdfs_active_test(this->trackerServer) {
    //         throw new \Exception(
    //             sprintf("Error connect to tracker server: %s",fastdfs_get_last_error_info()),
    //             fastdfs_get_last_error_no()
    //         );
    //     }

    //     let this->storageServer = fastdfs_tracker_query_storage_store();
    //     if !this->storageServer {
    //         throw new \Exception(
    //             sprintf("Error connect to storage server: %s",fastdfs_get_last_error_info()),
    //             fastdfs_get_last_error_no()
    //         );
    //     }

    //     return true;
    // }
}