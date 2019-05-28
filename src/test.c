#include "CED.h"
#include <stdbool.h>
#include <stdio.h>

void fn_A(void);
void fn_B(void);
void fn_C(int);
void fn_D(int);

int main(void)
{
	bool a, b, c, check;
	int x=5;
	int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	
	printf("Here is test\n");

	Handler handler;
	handler.n_pfn = 0;
    add(&handler, fn_A, x>3);
    add(&handler, fn_B, x>5 && x<8);
	run0(&handler);
    

    Handler1 handler1;
    handler1.n_pfn1 = 0;
    add1(&handler1, fn_C, x>3 && x<7);
    add1(&handler1, fn_D, x>2 && x<9);
    run1(&handler1, array);

	return 0;
}

void fn_A(void)
{
	printf("Here is fn_A\n");
}

void fn_B(void)
{
	printf("Here is fn_B\n");
}

void fn_C(int n)
{
	printf("fn_C get %d\n", n);
}

void fn_D(int n)
{
	printf("fn_D get %d\n", n);
}