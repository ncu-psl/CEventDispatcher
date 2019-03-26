// typedef struct yy_buffer_state * YY_BUFFER_STATE;
// extern int yyparse();
// extern YY_BUFFER_STATE yy_scan_string(char * str);
// extern void yy_delete_buffer(YY_BUFFER_STATE buffer);
#include "calc.h"
#include <stdio.h>

int main(){
    char string1[] = "(8>5) && (3>5)";
    char string2[] = "(8>5) || (3>5)";
    char string3[] = "1+2+3";
    printf("%d\n", eval(string1));
    printf("%d\n", eval(string2));
    printf("%d\n", eval(string3));

    int x=6;
    char string4[] = "x>5";
    printf("%s,x=%d,result=%d\n", string4, x, eval1(string4, x) );

    // YY_BUFFER_STATE buffer = yy_scan_string(string);
    // yyparse();
    // yy_delete_buffer(buffer);
    return 0;
}