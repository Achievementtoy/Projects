grammar KXI;
parameter : r_type | IDENTIFIER;
start
    : PUBLIC | PRIVATE
;
r_type : VOID | INT | CHAR | BOOL | IDENTIFIER;

ATOI                : 'atoi' ;
BOOL                : 'bool' ;
BLOCK               : 'block';
BREAK               : 'break';
CASE                : 'case';
CLASS               : 'class';
CHAR                : 'char';
CIN                 : 'cin';
COUT                : 'cout';
DEFAULT             : 'default';
ELSE                : 'else';
FALSE               : 'false';
IF                  : 'if';
INT                 : 'int';
ITOA                : 'itoa';
KXI2022             : 'kxi2022';
LOCK                : 'lock';
MAIN                : 'main';
NEW                 : 'new';
NULL                : 'null';
OBJECT              : 'object';
PUBLIC              : 'public';
PRIVATE             : 'private';
PROTECTED           : 'protected';
RETURN              : 'return';
RELEASE             : 'release';
STRING              : 'string';
SPAWN               : 'spawn';
SYM                 : 'sym';
SET                 : 'set';
SWITCH              : 'switch';
THIS                : 'this';
TRUE                : 'true';
THREAD              : 'thread';
UNPROTECTED         : 'unprotected';
UNLOCK              : 'unlock';
VOID                : 'void';
WHILE               : 'while';
WAIT                : 'wait';
WHITESPACE          : (' '|'t')+ -> skip ;
COLON               : ':' ;
SEMI                : ';' ;
LEFTBRACE           : '{' ;
RIGHTBRACE          : '}' ;
LEFTPARAN           : '(' ;
RIGHTPARAN          : ')' ;
LEFTBRACKET         : '[' ;
RIGHTBRACKET        : ']' ;
EQUALS              : '=' ;
ISEQUALTO           : '==';
NOTEQUAL            : '!=';
GREATEREQUAL        : '>=';
LESSEQUAL           : '<=';
GREATERTHAN         : '>' ;
LESSTHAN            : '<' ;
AND                 : '&&';
OR                  : '||';
ADD                 : '+';
SUB                 : '-';
MUL                 : '*';
DIV                 : '/';
PLUSEQ              : '+=';
SUBEQ               : '-=';
MULEQ               : '*=';
DIVEQ               : '/=';
INPUTSTREAM         : '>>';
OUTPUTSTREAM        : '<<';
PERIOD              : '.';
COMMA               : ',';
LETTER              : [A-Z] | [a-z];
DIGIT               : [0-9];
IDENTIFIER          : (LETTER | '_') | (LETTER | '_' | DIGIT)+;
LINEENDING          : '\r' | '\n' | '\r\n';
COMMENT             : ('//' | '.*' | LINEENDING)+ -> skip;
CHARL               : ['\u0020'..'\u0026'] | ['\u0028'..'\u005B'] | ['\u005D'..'\u007D'];
NUMLITERAL          : (DIGIT)+;







