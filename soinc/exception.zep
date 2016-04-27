namespace Soinc;

class Exception extends \Exception
{
    protected message = "";
    protected level = "Exception";
    protected code = 0;
    protected logger = null;

    public function __construct(var message = "", var code = null, <\Phalcon\Logger\Adapter> logger = null)
    {
        if empty message {
            let message = "An exception created: " . get_called_class();
        }

        let this->logger = logger;
        // if !is_null(logger) {
            // logger->log(message, this->getLevel());
        // }

        if empty this->message {
            let this->message = message;
        }

        if !is_null(code) {
            let this->code = code;
        }
    }

    public function getLevel()
    {
        return this->level;
    }

    public function setCode(var code)
    {
        let this->code = code;
        return this;
    }

    public function setLevel(var level)
    {
        let this->level = level;
        return this;
    }

    public function __desctruct() {
        if !this->logger {
            this->logger->log(this->getLevel(),this->getMessage());
        }
    }
}