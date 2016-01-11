namespace Soinc\Logger\Adapter;

class File extends \Phalcon\Logger\Adapter\File
{
    public function __construct(string! filePath, var options = null)
    {
        if file_exists(filePath) {
            if !is_writable(filePath) {
                throw new \Exception("PHP Fatal error: Soinc::Logger::File failed to write log path: ".filePath);
                // error_log("PHP Fatal error: Soinc::Logger::File failed to write log path: ".filePath);
            }
            else {
                parent::__construct(filePath,options);
            }
        }
        else {
            var parentPath;
            let parentPath = dirname(filePath);
            if !is_dir(parentPath) {
                if !mkdir(parentPath,0777,true) {
                    throw new \Exception("PHP Fatal error: Soinc::Logger::File failed to create log path: ".parentPath);
                }
            }

            parent::__construct(filePath,options);

        }
    }
}