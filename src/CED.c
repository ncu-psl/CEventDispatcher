/*
C Event Dispatcher
*/
#include "CED.h"
#include "./expression/src/calc.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool add_(Handler_ *handler, DFN fn, char *expr)
{
	if ((handler->n_pfn + 1) < max_size)
	{
        int n = handler->n_pfn;
        handler->event[n].pfn = fn;
		strcpy(handler->event[n].cond, expr);
		handler->n_pfn++;
		//printf("fn add1 %d\n", handler->n_pfn1);
		return 1;
	}
	else
	{
		printf("FULL\n");
		return 0;
	}
}

bool del(Handler_ *handler, DFN fn)
{
	int i, n = handler->n_pfn;
	bool finish = false;
	for (i = 0; i < n; i++)
	{
		if (finish)
		{
			handler->event[i - 1] = handler->event[i];
		}
		if (handler->event[i].pfn == fn)
		{
			handler->event[i].pfn = NULL;
			handler->event[i].cond[0] = '\0';
			handler->n_pfn--;
			finish = true;
			// printf("fn del\n");
		}
	}
	return finish;
}

bool run(Handler_ *handler)
{
	int i;
	for (i = 0; i < handler->n_pfn; i++)
	{
		handler->event[i].pfn();
	}

	return 1;
}

bool run_(Handler_ *handler, int n)
{
	int i;
	for (i = 0; i < handler->n_pfn; i++)
	{
	    // printf("\teval %s = %d \n", handler->cond[i], eval1(handler->cond[i], n));
		if (eval1(handler->event[i].cond, n))
			handler->event[i].pfn(n);
	}

	return 1;
}

int testEval1(char *expr, int input){
	printf("Here is test\n");
    printf("expr=%s, input=%d\n", expr, input);
    return eval1(expr, input);
}