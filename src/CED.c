/*
C Event Dispatcher
*/
#include "CED.h"
#include "./expression/src/calc.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool add_(Dispatcher_ *dispatcher, DFN fn, char *expr)
{
	if ((dispatcher->n_pfn + 1) < max_size)
	{
		int n = dispatcher->n_pfn;
		dispatcher->EP[n].pfn = fn;
		strcpy(dispatcher->EP[n].cond1, expr);
		dispatcher->n_pfn++;
		//printf("fn add1 %d\n", dispatcher->n_pfn1);
		return 1;
	}
	else
	{
		printf("FULL\n");
		return 0;
	}
}

bool del(Dispatcher_ *dispatcher, DFN fn)
{
	int i, n = dispatcher->n_pfn;
	bool finish = false;
	for (i = 0; i < n; i++)
	{
		if (finish)
		{
			dispatcher->EP[i - 1] = dispatcher->EP[i];
		}
		if (dispatcher->EP[i].pfn == fn)
		{
			dispatcher->EP[i].pfn = NULL;
			dispatcher->EP[i].cond1[0] = '\0';
			dispatcher->n_pfn--;
			finish = true;
			// printf("fn del\n");
		}
	}
	return finish;
}

bool run_(Dispatcher_ *dispatcher, int n)
{
	int i;
	for (i = 0; i < dispatcher->n_pfn; i++)
	{
		// printf("\teval %s = %d \n", dispatcher->cond[i], eval1(dispatcher->cond[i], n));
		if (eval1(dispatcher->EP[i].cond1, n))
			dispatcher->EP[i].pfn(n);
	}

	return 1;
}

bool add2_(Dispatcher_ *dispatcher, DFN fn, char *expr1, char *expr2)
{
	if ((dispatcher->n_pfn + 1) < max_size)
	{
		int n = dispatcher->n_pfn;
		dispatcher->EP[n].pfn = fn;
		strcpy(dispatcher->EP[n].cond1, expr1);
		strcpy(dispatcher->EP[n].cond2, expr2);
		dispatcher->n_pfn++;
		//printf("fn add1 %d\n", dispatcher->n_pfn1);
		return 1;
	}
	else
	{
		printf("FULL\n");
		return 0;
	}
}

bool run2(Dispatcher_ *dispatcher, int arg1, int arg2)
{
	int i;
	for (i = 0; i < dispatcher->n_pfn; i++)
	{
		// printf("\teval %s = %d \n", dispatcher->cond[i], eval1(dispatcher->cond[i], n));
		if (eval1(dispatcher->EP[i].cond1, arg1) && eval1(dispatcher->EP[i].cond2, arg2))
			dispatcher->EP[i].pfn();
	}

	return 1;
}

int testEval1(char *expr, int input)
{
	printf("Here is test\n");
	printf("expr=%s, input=%d\n", expr, input);
	return eval1(expr, input);
}