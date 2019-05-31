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
	int x[1] = {3};
	int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 'a'};

	printf("Here is test\n");

	Handler(handler);
	add(&handler, fn_A, x > 3);
	add(&handler, fn_B, x > 5 && x < 8);
	run0(&handler);

	Handler1(handler1);
	add1(&handler1, fn_C, x == 3 || x == 7);
	add1(&handler1, fn_D, x == 'a' || x == 9);
	run1(&handler1, x);
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