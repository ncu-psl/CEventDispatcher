%{
#include <stdlib.h>
#include "calc.h"
#include "calc.tab.h"
void yyerror(char *);
int result=0;                    //eval回傳值
int arg1=0;                      //eval參數，取代未知變數
%}

%%

[a-z]       { 
                yylval.iValue = arg1;
                return INTEGER;
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

int eval1(char input[], int arg){
    // printf("eval1\n");
    arg1 = arg;
    yy_scan_string(input);
    if(!yyparse()){
        return result;
    }
}