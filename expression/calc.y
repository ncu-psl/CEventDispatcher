%{
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define YYSTYPE int
%}

%token NUMBER
%token '+' '-' '*' '/' '^'
%token '(' ')'
%token '\n'

%left '+' '-'
%left '*' '/'
%left NEG
%right '^'

%start Input
%%

Input:
    
     | Input Line
;

Line:
     '\n'
     | Expression '\n' { printf("Result: %d\n", $1); }
;

Expression:
     NUMBER { $$=$1; }
| Expression '+' Expression { $$=$1+$3; }
| Expression '-' Expression { $$=$1-$3; }
| Expression '*' Expression { $$=$1*$3; }
| Expression '/' Expression { $$=$1/$3; }
| '-' Expression %prec NEG { $$=-$2; }
| Expression '^' Expression { $$=pow($1,$3); }
| '(' Expression ')' { $$=$2; }
;

%%

int yyerror(char *s) {
  printf("%s\n", s);
}

int main() {
  if (yyparse())
     fprintf(stderr, "Successful parsing.\n");
  else
     fprintf(stderr, "error found.\n");
}