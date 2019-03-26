%{
#include <stdlib.h>
#include "calc.h"
#include "calc.tab.h"
void yyerror(char *);
%}

%%

[a-z]       { 
                yylval.sIndex = *yytext - 'a';
                return VARIABLE;
            }

0           {
                yylval.iValue = atoi(yytext);
                return INTEGER;
            }

[1-9][0-9]* {
                yylval.iValue = atoi(yytext);
                return INTEGER;
            }

[-()<>=+*/;{}.!\n] {
                return *yytext;
             }

"||"            return OR;
"&&"            return AND;
">="            return GE;
"<="            return LE;
"=="            return EQ;
"!="            return NE;
"while"         return WHILE;
"if"            return IF;
"else"          return ELSE;
"print"         return PRINT;

[ \t]+        ;       /* ignore whitespace */

.               {
                    ECHO;
                    yyerror("  Unknown character");
                }
%%
int yywrap(void) {
    return 1;
}

int eval(char input[]){
    yy_scan_string(input);
    if(!yyparse()){
        return result;
    }
}