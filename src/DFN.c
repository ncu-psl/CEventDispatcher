#include "DFN.h"
#include "./expression/src/calc.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool add_(Handler *handler, DFN fn, char *expr)
{
	if ((handler->n_pfn + 1) < max_size)
	{
		handler->pfn[handler->n_pfn] = fn;
		strcpy(handler->cond[handler->n_pfn], expr);
		handler->n_pfn++;
		//printf("fn add %d\n", handler->n_pfn);
		return 1;
	}
	else
	{
		printf("FULL\n");
		return 0;
	}
}

bool add1_(Handler1 *handler, DFN1 fn, char *expr)
{
	if ((handler->n_pfn1 + 1) < max_size)
	{
		handler->pfn1[handler->n_pfn1] = fn;
		strcpy(handler->cond[handler->n_pfn1], expr);
		handler->n_pfn1++;
		//printf("fn add1 %d\n", handler->n_pfn1);
		return 1;
	}
	else
	{
		printf("FULL\n");
		return 0;
	}
}

bool del(Handler *handler, DFN fn)
{
	int i, n = handler->n_pfn;
	bool finish = false;
	for (i = 0; i < n; i++)
	{
		if (finish)
		{
			handler->pfn[i - 1] = handler->pfn[i];
		}
		if (handler->pfn[i] == fn)
		{
			handler->pfn[i] = NULL;
			handler->n_pfn--;
			finish = true;
			printf("fn del\n");
		}
	}
	return finish;
}

bool run0(Handler *handler)
{
	int i;
	for (i = 0; i < handler->n_pfn; i++)
	{
		handler->pfn[i]();
	}
	return 1;
}

bool run_(Handler1 *handler, int n)
{
	int i;
	//printf("eval %s = %d \n", handler->cond, eval1(handler->cond, n));
	for (i = 0; i < handler->n_pfn1; i++)
	{
		if (eval1(handler->cond[i], n))
			handler->pfn1[i](n);
	}

	return 1;
}