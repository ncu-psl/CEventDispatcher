#include "CED.h"
#include <stdbool.h>
#include <stdio.h>

void fn_A(void);
void fn_B(void);
void fn_C(int);
void fn_D(int);

int main(void)
{
	int x[10] = {3};
	int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 'a'};

	printf("Here is test\n");

    // test handler add fn_A, fn_B
	Handler(handler);
	add(&handler, fn_A,);
	add(&handler, fn_B,);
	printf("test handler add fn_A, fn_B\n");
	run(&handler);
	
    // test handler del fn_A
    printf("test handler del fn_A\n");
    del(&handler, fn_A);
    run(&handler);

    // test handler with condition expression
    Handler(handler1);
	add(&handler1, fn_C, x == 3 || x == 7);
	add(&handler1, fn_D, x == 'a' || x == 3);
	printf("test handler with condition expression input x=3 \n");
	run1(&handler1, x);
	printf("test handler with condition expression input array={0, 1, 2, 3, 4, 5, 6, 7, 8, 'a'} \n");
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