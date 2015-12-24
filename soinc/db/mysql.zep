namespace Soinc\Db;

class Mysql
{
    private dbConfigs = [];
    private name;
    private connection = null;
    private connected = false;

    public function __construct(string! name)
    {
        let this->name = name;

        var config, _index;
        let config = \Phalcon\DI::getDefault()->get("config");
        let config = config->mysql->{name}->toArray();

        if !is_array(reset(config)) {
            let this->dbConfigs = [config];
        }
        else {
            let this->dbConfigs = config;
        }

        for _index, config in this->dbConfigs {
            let this->dbConfigs[_index] = [
                "host" : config["host"],
                "port" : config["port"],
                "username" : config["username"],
                "password" : config["password"],
                "dbname" : config["dbname"],
                "options" : [
                    \PDO::MYSQL_ATTR_INIT_COMMAND : "SET NAMES " . config["charset"],
                    \PDO::ATTR_TIMEOUT : config["timeout"], // seconds
                    \PDO::ATTR_ERRMODE : \PDO::ERRMODE_EXCEPTION
                ]
            ];
        }
    }

    public function getConnection() -> <\Phalcon\Db\Adapter\Pdo\Mysql>
    {
        while !this->connected {
            var dbNum, e;
            shuffle(this->dbConfigs);

            try {
                let this->connection = new \Phalcon\Db\Adapter\Pdo\Mysql(this->dbConfigs[0]);
                let this->connected = true;
            } catch \Exception, e {
                error_log("PHP Fatal error:  Soinc::Db::MySQL::connect() failed to connect to MySQL. Detail: hostname is " .this->dbConfigs[0]["host"] . " the user is ".this->dbConfigs[0]["username"]);
                unset(this->dbConfigs[0]);
                let dbNum = count(this->dbConfigs);
                if dbNum < 1 {
                    throw e;
                }
            }
        }
        return this->connection;
    }
}