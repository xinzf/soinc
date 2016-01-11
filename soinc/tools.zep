namespace Soinc;

class Tools 
{
    public static function xml2Array(var xml)
    {
        var data;
        let data = simplexml_load_string(xml);
        return json_decode(json_encode(data),TRUE);
    }
}