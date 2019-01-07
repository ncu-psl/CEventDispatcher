// typedef struct yy_buffer_state * YY_BUFFER_STATE;
// extern int yyparse();
// extern YY_BUFFER_STATE yy_scan_string(char * str);
// extern void yy_delete_buffer(YY_BUFFER_STATE buffer);
#include "calc.h"

int main(){
    char string1[] = "(8>5) && (3>5)";
    char string2[] = "(8>5) || (3>5)";
    char string3[] = "1+2+3";
    eval(string1);
    eval(string2);
    eval(string3);

    // YY_BUFFER_STATE buffer = yy_scan_string(string);
    // yyparse();
    // yy_delete_buffer(buffer);
    return 0;
}