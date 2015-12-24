namespace Soinc\Logger\Formatter;

class Line extends \Phalcon\Logger\Formatter implements \Phalcon\Logger\FormatterInterface
{
    private processors = [];
    // private logLevel = [];
    private formatString = "[%date%][%type%] %message%";

    public function __construct(string! formatString)
    {
        if !empty formatString {
            let this->formatString = formatString;
        }
        //var reflection = null;
        //let reflection = new \ReflectionClass("\Phalcon\Logger");
        //let this->logLevel = array_flip(reflection->getConstants());
    }
    
    public function format (string! message, type, date, context = [])
    {
        let this->processors["message"] = message;
        let this->processors["date"] = date("Y-m-d H:i:s", date);
        let this->processors["type"] = this->getTypeString(type);
        
        var matches = [], result;
        let result = preg_match_all("/%(\w+)%/", this->formatString, matches);

        if result == false {
            throw new \Exception("Logger format is not valid: " . this->formatString);
        }

        var replace0, replace1;
        let replace0 = reset(matches);
        let replace1 = end(matches);

        var val1, val2, processors = [];
        
        for val1 in replace1 {
            if fetch val2, this->processors[val1] {
                let processors[val1] = strval(val2);
            } else {
                let processors[val1] = "undefined";
            }
        }
        
        var logStr;
        let logStr = str_replace(replace0, array_values(processors), this->formatString);
        return logStr . PHP_EOL;
    }

    public function addProcessor(string! name, <\Soinc\Logger\Processor\AbstractProcessor> processor)
    {
        let this->processors[name] = processor;
    }

    public function __get(string! key)
    {
        return (string) this->processors[key];
    }
}