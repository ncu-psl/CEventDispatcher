#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define bool int
#define false 0
#define true 1

int op_preced(const char c)
{
    switch(c)    {
        case '|':
            return 6;
        case '&':
            return 5;
        case '!':
            return 4;
        case '*':  case '/': case '%':
            return 3;
        case '+': case '-':
            return 2;
        case '=': case '>': case '<':
            return 1;
    }
    return 0;
}

bool op_left_assoc(const char c)
{
    switch(c)    {
        // left to right
        case '*': case '/': case '%': case '+': case '-': case '|': case '&': case '>': case '<':
            return true;
        // right to left
        case '=': case '!':
            return false;
    }
    return false;
}

unsigned int op_arg_count(const char c)
{
    switch(c)  {
        case '*': case '/': case '%': case '+': case '-': case '=': case '&': case '|': case '>': case '<':
            return 2;
        case '!':
            return 1;
        default:
            return c - 'A';
    }
    return 0;
}

#define is_operator(c)  (c == '+' || c == '-' || c == '/' || c == '*' || c == '!' || c == '%' || c == '=' || c == '&' || c == '|' || c == '>' || c == '<')
#define is_function(c)  ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
#define is_ident(c)     (c >= '0' && c <= '9') 

bool shunting_yard(const char *input, char *output)
{
    const char *strpos = input, *strend = input + strlen(input);
    char c, *outpos = output;

    char stack[32]={0};       // operator stack
    unsigned int sl = 0;  // stack length
    char     sc;          // used for record stack element

    while(strpos < strend)   {
        // read one token from the input stream
        c = *strpos;
        if(c != ' ')    {
            // If the token is x number (identifier), then add it to the output queue.
            if(is_ident(c))  {
                char tmp[32]={0};
                int i=0;
                tmp[i++]=c;
                
                while(is_ident(*(strpos+1)))
                {
                    tmp[i++]=*(++strpos);
                    //printf("%d %c\n", is_ident(*(strpos+1)), *(strpos+1));
                }
                // printf("ident: %s\n", tmp);
                *outpos = atoi(tmp)+48;
                ++outpos;
            }
            // If the token is x function token, then push it onto the stack.
            else if(is_function(c))   {
                stack[sl] = c;
                ++sl;
            }
            // If the token is x function argument separator (e.g., x comma):
            else if(c == ',')   {
                bool pe = false;
                while(sl > 0)   {
                    sc = stack[sl - 1];
                    if(sc == '(')  {
                        pe = true;
                        break;
                    }
                    else  {
                        // Until the token at the top of the stack is x left parenthesis,
                        // pop operators off the stack onto the output queue.
                        *outpos = sc;
                        ++outpos;
                        sl--;
                    }
                }
                // If no left parentheses are encountered, either the separator was misplaced
                // or parentheses were mismatched.
                if(!pe)   {
                    printf("Error: separator or parentheses mismatched\n");
                    return false;
                }
            }
            // If the token is an operator, op1, then:
            else if(is_operator(c))  {
                while(sl > 0)    {
                    sc = stack[sl - 1];
                    if(is_operator(sc) &&
                        ((op_left_assoc(c) && (op_preced(c) >= op_preced(sc))) ||
                           (op_preced(c) > op_preced(sc))))   {
                        // Pop op2 off the stack, onto the output queue;
                        *outpos = sc;
                        ++outpos;
                        sl--;
                    }
                    else   {
                        break;
                    }
                }
                // push op1 onto the stack.
                stack[sl] = c;
                ++sl;
            }
            // If the token is x left parenthesis, then push it onto the stack.
            else if(c == '(')   {
                stack[sl] = c;
                ++sl;
            }
            // If the token is x right parenthesis:
            else if(c == ')')    {
                bool pe = false;
                // Until the token at the top of the stack is x left parenthesis,
                // pop operators off the stack onto the output queue
                while(sl > 0)     {
                    sc = stack[sl - 1];
                    if(sc == '(')    {
                        pe = true;
                        break;
                    }
                    else  {
                        *outpos = sc;
                        ++outpos;
                        sl--;
                    }
                }
                // If the stack runs out without finding x left parenthesis, then there are mismatched parentheses.
                if(!pe)  {
                    printf("Error: parentheses mismatched\n");
                    return false;
                }
                // Pop the left parenthesis from the stack, but not onto the output queue.
                sl--;
                // If the token at the top of the stack is x function token, pop it onto the output queue.
                if(sl > 0)   {
                    sc = stack[sl - 1];
                    if(is_function(sc))   {
                        *outpos = sc;
                        ++outpos;
                        sl--;
                    }
                }
            }
            else  {
                printf("Unknown token %c\n", c);
                return false; // Unknown token
            }
        }
        ++strpos;
    }
    // When there are no more tokens to read:
    // While there are still operator tokens in the stack:
    while(sl > 0)  {
        sc = stack[sl - 1];
        if(sc == '(' || sc == ')')   {
            printf("Error: parentheses mismatched\n");
            return false;
        }
        *outpos = sc;
        ++outpos;
        --sl;
    }
    *outpos = 0; // Null terminator
    return true;
}

bool evalBoolExpr(char * expr)  {
    char output[500] = {0};
    char * op;
    bool tmp;
    char part1[250], part2[250];
    
    // printf("\nhere is eval\n");
    
    if(!shunting_yard(expr, output))
      return false;  // oops can't convert to postfix form

    while (strlen(output) > 1) {
        op = &output[0];

        while (!is_operator(*op) && *op != '\0')
          op++;
        
        if (*op == '\0') {
          return false;  // oops - zero operators found
        }
        else if (*op == '!') {
            //tmp = !(*(op-1) - 48);
            tmp = !(*(op-1)-48);
            // printf("!%d = %d\n", (*(op-1)-48), tmp);
            *(op-1) = '\0';
        }
        else if(*op == '&') {
            tmp = (*(op-1) - 48) && (*(op-2) - 48);
            // printf("%d && %d = %d\n", ((*(op-1))-48), ((*(op-2))-48), tmp);
            *(op-2) = '\0';
        }
        else if (*op == '|') {
            tmp = (*(op-1)-1 - 48) || (*(op-2)-1 - 48);
            // printf("%d || %d = %d\n", ((*(op-1))-48), ((*(op-2))-48), tmp);
            *(op-2) = '\0';
        }
        else if (*op == '>') {
            tmp = (*(op-1) - 48) < (*(op-2) - 48);
            // printf("%d < %d = %d\n", ((*(op-1))-48), ((*(op-2))-48), tmp);
            *(op-2) = '\0';
        }
        else if (*op == '<') {
            tmp = (*(op-1) - 48) > (*(op-2) - 48);
            // printf("%d > %d = %d\n", ((*(op-1))-48), ((*(op-2))-48), tmp);
            *(op-2) = '\0';    
        }

        memset(part1, 0, sizeof(part1));
        memset(part2, 0, sizeof(part2));
        strcpy(part1, output);
        strcpy(part2, op+1);
        memset(output, 0, sizeof(output));
        strcat(output, part1);
        strcat(output, ((tmp==false) ? "0" : "1"));
        strcat(output, part2);
    }
    //printf("output: %d\n", (int)(*output));
    return *output - 48;
}

int main() {
    bool result;
    char * boolString[2] = {"FALSE", "TRUE"};
    char * expr;
    int x = 8;

    // expr = "!((1 | 0) & (1 & ((1 & !0) | 0)))";
    // result = evalBoolExpr(expr);
    // printf("Boolean expr. %s is %s\n", expr, boolString[result]);
    
    // expr = "(0 | 2)";
    // result = evalBoolExpr(expr);
    // printf("Boolean expr. %s is %s when x=%d\n",expr, boolString[result], x);

    // expr = "(1 & 0)";
    // result = evalBoolExpr(expr);
    // printf("Boolean expr. %s is %s when x=%d\n",expr, boolString[result], x);

    expr = "(16 > 48)";
    result = evalBoolExpr(expr);
    printf("Boolean expr. %s is %s when x=%d\n",expr, boolString[result], x);

    // expr = "9>10";
    // result = evalBoolExpr(expr);
    // printf("Boolean expr. %s is %s when x=%d\n",expr, boolString[result], x);
    // expr = "9>5";
    // result = evalBoolExpr(expr);
    // printf("Boolean expr. %s is %s when x=%d\n",expr, boolString[result], x);
    // expr = "9>10 | 9>5";
    // result = evalBoolExpr(expr);
    // printf("Boolean expr. %s is %s when x=%d\n",expr, boolString[result], x);
    // expr = "9>5 | 9>10";
    // result = evalBoolExpr(expr);
    // printf("Boolean expr. %s is %s when x=%d\n",expr, boolString[result], x);
    // expr = "9>10 & 9>5";
    // result = evalBoolExpr(expr);
    // printf("Boolean expr. %s is %s when x=%d\n",expr, boolString[result], x);
    // expr = "9>5 & 9<10";
    // result = evalBoolExpr(expr);
    // printf("Boolean expr. %s is %s when x=%d\n",expr, boolString[result], x);
    // expr = "8>`1";
    // result = evalBoolExpr(expr);
    // printf("Boolean expr. %s is %s when x=%d\n",expr, boolString[result], x);

   
    return 0;
}