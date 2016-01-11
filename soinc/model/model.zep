namespace Soinc\Model;

class Model extends \Phalcon\Mvc\Model
{
    // 记录创建时间
    protected created;
    // 记录更新时间
    protected updated;

    public function initialize()
    {
        self::setUp([
            "notNullValidations" : false
        ]);
        this->useDynamicUpdate(true);
        this->keepSnapshots(true);
    }

    public function __get(string name)
    {
        if ! isset(this->{name}) {
            return this->getDI()->get(name);
        }
    }

    public function getMessage()
    {
        return this->getFirstMessage();
    }

    public function getFirstMessage()
    {
        if count(this->getMessages("")) {
            return (string) current(this->getMessages(""));
        }
        return false;
    }

    public function getLastMessage()
    {
        if count(this->getMessages("")) {
            return (string) end(this->getMessages(""));
        }
        return false;
    }

    public function getErrCode(var sqlErr)
    {
        var matches,result;
        let result = preg_match_all("/[(\w+)]/", sqlErr, matches);
        if result {
            return reset(result);
        }
        else {
            return 0;
        }
    }

    public function createBuilder(string! alias = "") -> <\Phalcon\Mvc\Model\Query\BuilderInterface>
    {
        var source;
        if !empty alias {
            let source = [alias:get_called_class()];
        } else {
            let source  = get_called_class();
        }
        return this->getModelsManager()->createBuilder()->from(source);
    }

    public static function getInstance() -> <\Phalcon\Mvc\Model>
    {
        var className;
        let className = get_called_class();
        return new {className}();
    }

    public function beforeValidationOnCreate()
    {
        let this->created = date("Y-m-d H:i:s");
        let this->updated = this->created;
    }

    public function afterFetch()
    {
        // nothing
    }

    public function beforeSave()
    {
        let this->updated = date("Y-m-d H:i:s");
        return true;
    }
}