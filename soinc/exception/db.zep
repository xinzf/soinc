namespace Soinc\Exception;

class Db extends \Soinc\Exception
{
    public function __construct(var message = "", <\Phalcon\Logger\Adapter> logger = null)
    {
        var result,matches = [];
        if empty message {
            let message = "An exception created: " . get_called_class();
        }
        else {
            let this->message = message;
            let result = preg_match_all("/(?:\[)(.*)(?:\])/i",message, matches);
            if result == 1 {
                let this->code = matches[1][0];
            }
        }

        if !is_null(logger) {
            logger->log(message, this->getLevel());
        }

        if empty this->message {
            let this->message = message;
        }
    }
}