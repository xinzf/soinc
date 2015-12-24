namespace Soinc;

/**
 * Tool
 *
 * description...
 *
 * @author Xiang Zhi <xiangzhi@cctvmall.cn>
 */

class Tools {

    // static public function mkdirs (string! dir,string mode = 0777) {
    //     if is_dir($dir) {
    //         self::mkdirs(dirname(dir),mode);
    //         if @mkdir(dir,mode) {
    //             @chmod(dir,mode);
    //             return true;
    //         }
    //         else {
    //             return false;
    //         }
    //     }
    //     else {
    //         return true;
    //     }
    // }

    // static public function imgToBase64(string! imgFile) {
    //     if !file_exists(imgFile) {
    //         return false;
    //     }

    //     var type;
    //     var fp;
    //     var file_content;
    //     var img;
    //     let type = getimagesize(imgFile);
    //     let fp = fopen(imgFile, 'r');
    //     let file_content=chunk_split(base64_encode(fread(fp,filesize(imgFile))));

    //     switch $type[2] {
    //         case 1:let img_type="gif";break;
    //         case 2:let img_type="jpg";break;
    //         case 3:let img_type="png";break;
    //     }

    //     let img="data:image/".img_type.";base64,".file_content;
    //     fclose(fp);
    //     return img;
    // }

    // static public function base64ToImg(string! str) {
    //     var result;
    //     if preg_match("/^(data:\s*image\/(\w+);base64,)/", str, result) {
    //         var extension;
    //         var content;
    //         let extension = result[2];
    //         let content = base64_decode(str_replace(result[1], "", str));
    //         return [
    //             "data" : content,
    //             "ext"  : extension,
    //         ];
    //     }
    //     return false;
    // }

    // static public function delPath(string! dir) {
    //     var dh;
    //     var file;
    //     let dh=opendir(dir);
    //     let file = readdir(dh);
    //     while file != FALSE {
    //         if file!="." && file!=".." {
    //             var fullpath;
    //             let fullpath=dir."/".file;
    //             if !is_dir(fullpath) {
    //                 unlink(fullpath);
    //             }
    //             else {
    //                 self::deldir(fullpath);
    //             }
    //         }
    //     }

    //     closedir(dh);
    //     if rmdir(dir)) {
    //         return true;
    //     }
    //     else {
    //         return false;
    //     }
    // }

    // public static function dump($vars, $label = '', $return = false) {
    //     if (ini_get('html_errors')) {
    //         $content = "<pre>\n";
    //         if ($label != '') {
    //             $content .= "<strong>{$label} :</strong>\n";
    //         }
    //         $content .= htmlspecialchars(print_r($vars, true));
    //         $content .= "\n</pre>\n";
    //     } else {
    //         $content = $label . " :\n" . print_r($vars, true);
    //     }
    //     if ($return) { return $content; }
    //     echo $content;
    //     return null;
    // }

    // public static function substr($str, $start=0, $length, $charset="utf-8", $suffix=true) {
    //     if(function_exists("mb_substr")){
    //         if($suffix) {
    //              return mb_substr($str, $start, $length, $charset)."...";
    //         }
    //         else {
    //              return mb_substr($str, $start, $length, $charset);
    //         }
    //     }
    //     elseif(function_exists('iconv_substr')) {
    //         if($suffix) {
    //             return iconv_substr($str,$start,$length,$charset)."...";
    //         }
    //         else {
    //             return iconv_substr($str,$start,$length,$charset);
    //         }
    //     }

    //     $re['utf-8']  = "/[x01-x7f]|[xc2-xdf][x80-xbf]|[xe0-xef][x80-xbf]{2}|[xf0-xff][x80-xbf]{3}/";
    //     $re['gb2312'] = "/[x01-x7f]|[xb0-xf7][xa0-xfe]/";
    //     $re['gbk']    = "/[x01-x7f]|[x81-xfe][x40-xfe]/";
    //     $re['big5']   = "/[x01-x7f]|[x81-xfe]([x40-x7e]|xa1-xfe])/";

    //     preg_match_all($re[$charset], $str, $match);
    //     $slice = join("",array_slice($match[0], $start, $length));
    //     if($suffix) return $slice."…";
    //     return $slice;
    // }

    // public static function getMicroTime() {
    //     list($t1, $t2) = explode(' ', microtime());
    //     return (float)sprintf('%.0f', (floatval($t1) + floatval($t2)) * 1000);
    // }

    // public static function filterEmoji($str) {
    //     if (!$str) {
    //         return '';
    //     }

    //     if (!function_exists('emoji_unified_to_html')) {
    //         $emojiExt = \Phalcon\DI::getDefault()->get('config')->paths->common.'Extensions/emoji.php';
    //         require $emojiExt;
    //     }

    //     $str = emoji_unified_to_html($str);
    //     return strip_tags($str);
    // }

    // public static function isAnimationGif($imageData) {
    //     return strpos($imageData,chr(0x21).chr(0xff).chr(0x0b).'NETSCAPE2.0') === FALSE ? true : false;
    // }

    // public static function gif2jpg($data,$extension = 'jpg'){
    //     $image = new \Imagick(); //[0] indicate the number of the wanted page
    //     $image->readImageBlob($data);
    //     $image->setImageFormat( $extension );
    //     $str = (string) $image;
    //     $image->destroy();
    //     return $str;
    // }

    // public static function webp2jpg($data) {
    //     $srcFile = tempnam('/tmp','webp');
    //     file_put_contents($srcFile,$data);
    //     $destFile = tempnam('/tmp','png');
    //     $bin = \Phalcon\DI::getDefault()->get('config')->bins->dwebp;
    //     $commond = "{$bin} {$srcFile} -o {$destFile}";
    //     exec($commond,$outout,$return);
    //     if($return != 0) {
    //         return false;
    //     }

    //     return $srcFile;
    // }

    // //用户认证
    // public static function authcode($string, $operation = 'DECODE', $key = '$oftw@re', $expiry = 0) {
    //     $ckey_length = 4;
    //     $key = md5($key);
    //     $keya = md5(substr($key, 0, 16));
    //     $keyb = md5(substr($key, 16, 16));
    //     $keyc = $ckey_length ? ($operation == 'DECODE' ? substr($string, 0, $ckey_length): substr(md5(microtime()), -$ckey_length)) : '';

    //     $cryptkey = $keya.md5($keya.$keyc);
    //     $key_length = strlen($cryptkey);
    //     $string = $operation == 'DECODE' ? base64_decode(substr($string, $ckey_length)) : sprintf('%010d', $expiry ? $expiry + time() : 0).substr(md5($string.$keyb), 0, 16).$string;
    //     $string_length = strlen($string);
    //     $result = '';
    //     $box = range(0, 255);

    //     $rndkey = array();
    //     for($i = 0; $i <= 255; $i++) {
    //         $rndkey[$i] = ord($cryptkey[$i % $key_length]);
    //     }

    //     for($j = $i = 0; $i < 256; $i++) {
    //         $j = ($j + $box[$i] + $rndkey[$i]) % 256;
    //         $tmp = $box[$i];
    //         $box[$i] = $box[$j];
    //         $box[$j] = $tmp;
    //     }

    //     for($a = $j = $i = 0; $i < $string_length; $i++) {
    //         $a = ($a + 1) % 256;
    //         $j = ($j + $box[$a]) % 256;
    //         $tmp = $box[$a];
    //         $box[$a] = $box[$j];
    //         $box[$j] = $tmp;
    //         $result .= chr(ord($string[$i]) ^ ($box[($box[$a] + $box[$j]) % 256]));
    //     }

    //     if($operation == 'DECODE') {
    //         if((substr($result, 0, 10) == 0 || substr($result, 0, 10) - time() > 0) && substr($result, 10, 16) == substr(md5(substr($result, 26).$keyb), 0, 16)) {
    //             return substr($result, 26);
    //         } else {
    //             return '';
    //         }
    //     } else {
    //         return $keyc.str_replace('=', '', base64_encode($result));
    //     }
    // }

    // public static function stripContent($content)
    // {
    //     $content = str_replace("\r\n", '', $content);
    //     $content = str_replace("\r", '', $content);
    //     $content = str_replace("\n", '', $content);
    //     $content = str_replace("\t", '', $content);
    //     $content = str_replace(chr(13), '', $content);
    //     //$content = str_replace(chr(34), '', $content);
    //     $content = str_replace(chr(10), '', $content);
    //     $content = str_replace(chr(32), '', $content);
    //     $content = str_replace(chr(11), '', $content);
    //     $content = str_replace('&nbsp;', '', $content);

    //     $pattern=array(
    //         "/> *([^ ]*) *</",//去掉注释标记
    //         // "/[\s]+/",
    //         "/<!--[^!]*-->/",
    //         "/\" /",
    //         "/ \"/",
    //         "'/\*[^*]*\*/'"
    //     );
    //     $replace=array(
    //         ">\\1<",
    //         // " ",
    //         "",
    //         "\"",
    //         "\"",
    //         ""
    //     );
    //     $content = preg_replace($pattern,$replace,$content);
    //     $content = htmlspecialchars_decode($content);
    //     return self::filterEmoji($content);
    // }
    // /**
    //  * html实体转换方法
    //  *
    //  * @param  string   $content
    //  * @param  boolean  $encode     // true:转换成html实体；false:转换成html实体对应的字符
    //  * @return void
    //  */
    // public static function htmlspecialchar($content,$encode = true) {
    
    //     $config = array(
    //         ' ' =>  '&nbsp;',
    //         '"' =>  '&quot;',
    //         '&' =>  '&amp;',
    //         '<' =>  '&lt;',
    //         '>' =>  '&gt;',
    //         '¡' =>  '&iexcl;',
    //         '¢' =>  '&cent;',
    //         '£' =>  '&pound;',
    //         '¤' =>  '&curren;',
    //         '¥' =>  '&yen;',
    //         '¦' =>  '&brvbar;',
    //         '§' =>  '&sect;',
    //         '¨' =>  '&uml;',
    //         '©' =>  '&copy;',
    //         'ª' =>  '&ordf;',
    //         '«' =>  '&laquo;',
    //         '¬' =>  '&not;',
    //         '®' =>  '&reg;',
    //         '¯' =>  '&macr;',
    //         '°' =>  '&deg;',
    //         '±' =>  '&plusmn;',
    //         '²' =>  '&sup2;',
    //         '³' =>  '&sup3;',
    //         '´' =>  '&acute;',
    //         'µ' =>  '&micro;',
    //         '¶' =>  '&para;',
    //         '·' =>  '&middot;',
    //         '¸' =>  '&cedil;',
    //         '¹' =>  '&sup1;',
    //         'º' =>  '&ordm;',
    //         '»' =>  '&raquo;',
    //         '¼' =>  '&frac14;',
    //         '½' =>  '&frac12;',
    //         '¾' =>  '&frac34;',
    //         '¿' =>  '&iquest;',
    //         'À' =>  '&Agrave;',
    //         'Á' =>  '&Aacute;',
    //         'Â' =>  '&Acirc;',
    //         'Ã' =>  '&Atilde;',
    //         'Ä' =>  '&Auml;',
    //         'Å' =>  '&Aring;',
    //         'Æ' =>  '&AElig;',
    //         'Ç' =>  '&Ccedil;',
    //         'È' =>  '&Egrave;',
    //         'É' =>  '&Eacute;',
    //         'Ê' =>  '&Ecirc;',
    //         'Ë' =>  '&Euml;',
    //         'Ì' =>  '&Igrave;',
    //         'Í' =>  '&Iacute;',
    //         'Î' =>  '&Icirc;',
    //         'Ï' =>  '&Iuml;',
    //         'Ð' =>  '&ETH;',
    //         'Ñ' =>  '&Ntilde;',
    //         'Ò' =>  '&Ograve;',
    //         'Ó' =>  '&Oacute;',
    //         'Ô' =>  '&Ocirc;',
    //         'Õ' =>  '&Otilde;',
    //         'Ö' =>  '&Ouml;',
    //         '×' =>  '&times;',
    //         'Ø' =>  '&Oslash;',
    //         'Ù' =>  '&Ugrave;',
    //         'Ú' =>  '&Uacute;',
    //         'Û' =>  '&Ucirc;',
    //         'Ü' =>  '&Uuml;',
    //         'Ý' =>  '&Yacute;',
    //         'Þ' =>  '&THORN;',
    //         'ß' =>  '&szlig;',
    //         'à' =>  '&agrave;',
    //         'á' =>  '&aacute;',
    //         'â' =>  '&acirc;',
    //         'ã' =>  '&atilde;',
    //         'ä' =>  '&auml;',
    //         'å' =>  '&aring;',
    //         'æ' =>  '&aelig;',
    //         'ç' =>  '&ccedil;',
    //         'è' =>  '&egrave;',
    //         'é' =>  '&eacute;',
    //         'ê' =>  '&ecirc;',
    //         'ë' =>  '&euml;',
    //         'ì' =>  '&igrave;',
    //         'í' =>  '&iacute;',
    //         'î' =>  '&icirc;',
    //         'ï' =>  '&iuml;',
    //         'ð' =>  '&eth;',
    //         'ñ' =>  '&ntilde;',
    //         'ò' =>  '&ograve;',
    //         'ó' =>  '&oacute;',
    //         'ô' =>  '&ocirc;',
    //         'õ' =>  '&otilde;',
    //         'ö' =>  '&ouml;',
    //         '÷' =>  '&divide;',
    //         'ø' =>  '&oslash;',
    //         'ù' =>  '&ugrave;',
    //         'ú' =>  '&uacute;',
    //         'û' =>  '&ucirc;',
    //         'ü' =>  '&uuml;',
    //         'ý' =>  '&yacute;',
    //         'þ' =>  '&thorn;',
    //         'ÿ' =>  '&yuml;',
    //         'ƒ' =>  '&fnof;',
    //         '←' =>  '&larr;',
    //         '↑' =>  '&uarr;',
    //         '→' =>  '&rarr;',
    //         '↓' =>  '&darr;',
    //         '↔' =>  '&harr;',
    //         '↵' =>  '&crarr;',
    //         '⇐' =>  '&lArr;',
    //         '⇑' =>  '&uArr;',
    //         '⇒' =>  '&rArr;',
    //         '⇓' =>  '&dArr;',
    //         '⇔' =>  '&hArr;',
    //         '∀' =>  '&forall;',
    //         '∂' =>  '&part;',
    //         '∃' =>  '&exist;',
    //         '∅' =>  '&empty;',
    //         '∇' =>  '&nabla;',
    //         '∈' =>  '&isin;',
    //         '∉' =>  '&notin;',
    //         '∋' =>  '&ni;',
    //         '∏' =>  '&prod;',
    //         '∑' =>  '&sum;',
    //         '−' =>  '&minus;',
    //         '∗' =>  '&lowast;',
    //         '√' =>  '&radic;',
    //         '∝' =>  '&prop;',
    //         '∞' =>  '&infin;',
    //         '∠' =>  '&ang;',
    //         '∧' =>  '&and;',
    //         '∨' =>  '&or;',
    //         '∩' =>  '&cap;',
    //         '∪' =>  '&cup;',
    //         '∫' =>  '&int;',
    //         '∴' =>  '&there4;',
    //         '∼' =>  '&sim;',
    //         '≅' =>  '&cong;',
    //         '≈' =>  '&asymp;',
    //         '≠' =>  '&ne;',
    //         '≡' =>  '&equiv;',
    //         '≤' =>  '&le;',
    //         '≥' =>  '&ge;',
    //         '⊂' =>  '&sub;',
    //         '⊃' =>  '&sup;',
    //         '⊄' =>  '&nsub;',
    //         '⊆' =>  '&sube;',
    //         '⊇' =>  '&supe;',
    //         '⊕' =>  '&oplus;',
    //         '⊗' =>  '&otimes;',
    //         '⊥' =>  '&perp;',
    //         '⋅' =>  '&sdot;',
    //         '•' =>  '&bull;',
    //         '…' =>  '&hellip;',
    //         '′' =>  '&prime;',
    //         '″' =>  '&Prime;',
    //         '‾' =>  '&oline;',
    //         '⁄' =>  '&frasl;',
    //         '⌈' =>  '&lceil;',
    //         '⌉' =>  '&rceil;',
    //         '⌊' =>  '&lfloor;',
    //         '⌋' =>  '&rfloor;',
    //         '⟨' =>  '&lang;',
    //         '⟩' =>  '&rang;',
    //         '◊' =>  '&loz;',
    //         '♠' =>  '&spades;',
    //         '♣' =>  '&clubs;',
    //         '♥' =>  '&hearts;',
    //         '♦' =>  '&diams;',
    //         '℘' =>  '&weierp;',
    //         'ℑ' =>  '&image;',
    //         'ℜ' =>  '&real;',
    //         '™' =>  '&trade;',
    //         'ℵ' =>  '&alefsym;',
    //         'Α' =>  '&Alpha;',
    //         'Β' =>  '&Beta;',
    //         'Γ' =>  '&Gamma;',
    //         'Δ' =>  '&Delta;',
    //         'Ε' =>  '&Epsilon;',
    //         'Ζ' =>  '&Zeta;',
    //         'Η' =>  '&Eta;',
    //         'Θ' =>  '&Theta;',
    //         'Ι' =>  '&Iota;',
    //         'Κ' =>  '&Kappa;',
    //         'Λ' =>  '&Lambda;',
    //         'Μ' =>  '&Mu;',
    //         'Ν' =>  '&Nu;',
    //         'Ξ' =>  '&Xi;',
    //         'Ο' =>  '&Omicron;',
    //         'Π' =>  '&Pi;',
    //         'Ρ' =>  '&Rho;',
    //         'Σ' =>  '&Sigma;',
    //         'Τ' =>  '&Tau;',
    //         'Υ' =>  '&Upsilon;',
    //         'Φ' =>  '&Phi;',
    //         'Χ' =>  '&Chi;',
    //         'Ψ' =>  '&Psi;',
    //         'Ω' =>  '&Omega;',
    //         'α' =>  '&alpha;',
    //         'β' =>  '&beta;',
    //         'γ' =>  '&gamma;',
    //         'δ' =>  '&delta;',
    //         'ε' =>  '&epsilon;',
    //         'ζ' =>  '&zeta;',
    //         'η' =>  '&eta;',
    //         'θ' =>  '&theta;',
    //         'ι' =>  '&iota;',
    //         'κ' =>  '&kappa;',
    //         'λ' =>  '&lambda;',
    //         'μ' =>  '&mu;',
    //         'ν' =>  '&nu;',
    //         'ξ' =>  '&xi;',
    //         'ο' =>  '&omicron;',
    //         'π' =>  '&pi;',
    //         'ρ' =>  '&rho;',
    //         'ς' =>  '&sigmaf;',
    //         'σ' =>  '&sigma;',
    //         'τ' =>  '&tau;',
    //         'υ' =>  '&upsilon;',
    //         'φ' =>  '&phi;',
    //         'χ' =>  '&chi;',
    //         'ψ' =>  '&psi;',
    //         'ω' =>  '&omega;',
    //         'ϑ' =>  '&thetasym;',
    //         'ϒ' =>  '&upsih;',
    //         'ϖ' =>  '&piv;',
    //         '"' =>  '&quot;',
    //         '&' =>  '&amp;',
    //         '<' =>  '&lt;',
    //         '>' =>  '&gt;',
    //         'Œ' =>  '&OElig;',
    //         'œ' =>  '&oelig;',
    //         'Š' =>  '&Scaron;',
    //         'š' =>  '&scaron;',
    //         'Ÿ' =>  '&Yuml;',
    //         'ˆ' =>  '&circ;',
    //         '˜' =>  '&tilde;',
    //         '–' =>  '&ndash;',
    //         '—' =>  '&mdash;',
    //         '‘' =>  '&lsquo;',
    //         '’' =>  '&rsquo;',
    //         '‚' =>  '&sbquo;',
    //         '“' =>  '&ldquo;',
    //         '”' =>  '&rdquo;',
    //         '„' =>  '&bdquo;',
    //         '†' =>  '&dagger;',
    //         '‡' =>  '&Dagger;',
    //         '‰' =>  '&permil;',
    //         '‹' =>  '&lsaquo;',
    //         '›' =>  '&rsaquo;',
    //         '€' =>  '&euro;',
    //     );
    //     if($encode ) {
    //         $find = array_keys($config);
    //         $replace = array_values($config);
    //     }else {
    //         $find = array_values($config);
    //         $replace = array_keys($config);
    //     }
    //     return str_replace($find,$replace,$content);
    // }

    // /*
    //  * 将16位的数据转换成字符串
    //  * 
    //  *
    //  */
    // public static function hex2String($string) {
    //     $conf = array(
    //         '\x20'  =>  '"',
    //         '\x21'  =>  '!',
    //         '\x22'  =>  '"',
    //         '\x23'  =>  '#',
    //         '\x24'  =>  '$',
    //         '\x25'  =>  '%',
    //         '\x26'  =>  '&',
    //         '\x27'  =>  '\'',
    //         '\x28'  =>  '(',
    //         '\x29'  =>  ')',
    //         '\x2A'  =>  '*',
    //         '\x2B'  =>  '+',
    //         '\x2C'  =>  ',',
    //         '\x2D'  =>  '-',
    //         '\x2E'  =>  '.',
    //         '\x2F'  =>  '/',
    //         '\x30'  =>  '0',
    //         '\x31'  =>  '1',
    //         '\x32'  =>  '2',
    //         '\x33'  =>  '3',
    //         '\x34'  =>  '4',
    //         '\x35'  =>  '5',
    //         '\x36'  =>  '6',
    //         '\x37'  =>  '7',
    //         '\x38'  =>  '8',
    //         '\x39'  =>  '9',
    //         '\x3A'  =>  ':',
    //         '\x3B'  =>  ';',
    //         '\x3C'  =>  '<',
    //         '\x3D'  =>  '=',
    //         '\x3E'  =>  '>',
    //         '\x3F'  =>  '?',
    //         '\x40'  =>  '@',
    //         '\x41'  =>  'A',
    //         '\x42'  =>  'B',
    //         '\x43'  =>  'C',
    //         '\x44'  =>  'D',
    //         '\x45'  =>  'E',
    //         '\x46'  =>  'F',
    //         '\x47'  =>  'G',
    //         '\x48'  =>  'H',
    //         '\x49'  =>  'I',
    //         '\x4A'  =>  'J',
    //         '\x4B'  =>  'K',
    //         '\x4C'  =>  'L',
    //         '\x4D'  =>  'M',
    //         '\x4E'  =>  'N',
    //         '\x4F'  =>  'O',
    //         '\x50'  =>  'P',
    //         '\x51'  =>  'Q',
    //         '\x52'  =>  'R',
    //         '\x53'  =>  'S',
    //         '\x54'  =>  'T',
    //         '\x55'  =>  'U',
    //         '\x56'  =>  'V',
    //         '\x57'  =>  'W',
    //         '\x58'  =>  'X',
    //         '\x59'  =>  'Y',
    //         '\x5A'  =>  'Z',
    //         '\x5B'  =>  '[',
    //         '\x5C'  =>  '\\',
    //         '\x5D'  =>  ']',
    //         '\x5E'  =>  '^',
    //         '\x5F'  =>  '_',
    //         '\x60'  =>  '`',
    //         '\x61'  =>  'a',
    //         '\x62'  =>  'b',
    //         '\x63'  =>  'c',
    //         '\x64'  =>  'd',
    //         '\x65'  =>  'e',
    //         '\x66'  =>  'f',
    //         '\x67'  =>  'g',
    //         '\x68'  =>  'h',
    //         '\x69'  =>  'i',
    //         '\x6A'  =>  'j',
    //         '\x6B'  =>  'k',
    //         '\x6C'  =>  'l',
    //         '\x6D'  =>  'm',
    //         '\x6E'  =>  'n',
    //         '\x6F'  =>  'o',
    //         '\x70'  =>  'p',
    //         '\x71'  =>  'q',
    //         '\x72'  =>  'r',
    //         '\x73'  =>  's',
    //         '\x74'  =>  't',
    //         '\x75'  =>  'u',
    //         '\x76'  =>  'v',
    //         '\x77'  =>  'w',
    //         '\x78'  =>  'x',
    //         '\x79'  =>  'y',
    //         '\x7A'  =>  'z',
    //         '\x7B'  =>  '{',
    //         '\x7C'  =>  '|',
    //         '\x7D'  =>  '}',
    //         '\x7E'  =>  '~',
    //     );
    //     $find = array_keys($conf);
    //     $replace = array_values($conf);
    //     return str_replace($find,$replace,$string);
    // }

    // static function array_sort($arr,$keys,$type='asc'){   
    //     $keysvalue = $new_array = array();  
    //     foreach ($arr as $k=>$v){  
    //         $keysvalue[$k] = $v[$keys];  
    //     }  
    //     if($type == 'asc'){  
    //         asort($keysvalue);  
    //     }else{  
    //         arsort($keysvalue);  
    //     }  
    //     reset($keysvalue);  
    //     foreach ($keysvalue as $k=>$v){  
    //         $new_array[$k] = $arr[$k];  
    //     }  
    //     return $new_array;   
    // }   

    // public static function xml2Array($xml)
    // {
    //     $data = simplexml_load_string($xml);
    //     return json_decode(json_encode($data),TRUE);;
    // }
}