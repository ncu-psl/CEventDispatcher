#include <stdbool.h>
#include <stdio.h>
#include "CED.h"

void fn_A(void);
void fn_B(void);
void fn_C(int);
void fn_D(int);

int main(void)
{
	int x[10] = {3};
	int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 'a'};

	printf("Here is test\n");

    // test dispatcher add fn_A, fn_B
	Dispatcher(dispatcher);
	add(&dispatcher, fn_A, x == 5);
	add(&dispatcher, fn_B, x > 5);
	printf("test dispatcher fn_A, fn_B with condition\n");
	run(&dispatcher, array);
	

    // test dispatcher del fn_A
    printf("test dispatcher del fn_A\n");
    del(&dispatcher, fn_A);
    run(&dispatcher, array);

    // test dispatcher with condition expression
    Dispatcher(dispatcher1);
	add(&dispatcher1, fn_C, x == 3 || x == 7);
	add(&dispatcher1, fn_D, x == 'a' || x == 3);
	printf("test dispatcher with condition expression input x=3 \n");
	run(&dispatcher1, x);
	printf("test dispatcher with condition expression input array={0, 1, 2, 3, 4, 5, 6, 7, 8, 'a'} \n");
	run(&dispatcher1, array);

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