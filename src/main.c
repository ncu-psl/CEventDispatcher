#include "DFN.h"
#include <stdbool.h>
#include <stdio.h>
#include <../expression2/src/calc.h>

void fn_A(void);
void fn_B(void);
void fn_C(int);
int fn_D(void);

int main(void)
{
	bool a, b, c, check;
	int x;
	
	printf("Here is main\n");

	// Handler1 handler1;
	// handler1.n_pfn1 = 0;
	// int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // add1(&handler1, fn_A, x>3);
    // add1(&handler1, fn_B, x>3);
    // add1(&handler1, fn_C, x>5);
    // add1(&handler1, fn_D, x>5);
    // add1(&handler1, fn_E, x>1);
	// run1(&handler1, array);

	char string1[] = "1+2+3";
    eval(string1);

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

int fn_D(void)
{
	return 1;
}