%{
#define YYSTYPE int
#include "calc.tab.h"
#include <stdlib.h>
%}

white [ \t]+
digit [0-9]
integer {digit}+
operator [-+()=/*\n]

%%

{white} { }
{integer} { yylval=atoi(yytext); 
 return NUMBER;
}
{operator} { return *yytext; }
