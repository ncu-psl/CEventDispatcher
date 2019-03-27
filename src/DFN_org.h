#ifndef DFN_H
#define DFN_H

#include <stdbool.h>
#include <stdio.h>
#include "../expression/src/calc.h"

#define max_size 10
/*
* run1：找出array中符合expr條件的元素，執行Handler
* Handler：包含一個int參數的function形成的Handler
* array：input陣列
*/
#define run1(Handler, array)                        \
	do{                                             \
		int size = sizeof(array) / sizeof *(array); \
		int i = 0;                                  \
		for (i = 0; i < size; i++)                  \
		{                                           \
			runE(Handler, array[i]);                \
			printf("  %d\n", array[i]);             \
		}                                           \
	} while (0)

#define fun_1(expr){if(expr){run()}}

#define add1(Handler1, DFN1, expr)             \
	do{												\
		add1_(Handler1, DFN1);						\
	}while(0)


typedef void (*DFN)();
typedef void (*DFN1)(int);

typedef struct Handler
{
	int n_pfn;
	DFN pfn[max_size];
	char cond[10];
} Handler;

typedef struct Handler1
{
	int n_pfn1;
	DFN1 pfn1[max_size];
	char cond[10];
} Handler1;

bool run0(Handler *Handler)
{
	int i;
	for (i = 0; i < Handler->n_pfn; i++)
	{
		Handler->pfn[i]();
	}
	return 1;
}

bool runE(Handler1 *Handler, int n)
{
	int i;
	//printf("here runE\n");
	for (i = 0; i < Handler->n_pfn1; i++)
	{
		Handler->pfn1[i](n);
	}
	return 1;
}

bool add(Handler *Handler, DFN fn)
{
	if ((Handler->n_pfn + 1) < max_size)
	{
		Handler->pfn[Handler->n_pfn] = fn;
		Handler->n_pfn++;
		printf("fn add %d\n", Handler->n_pfn);
		return 1;
	}
	else
	{
		printf("FULL\n");
		return 0;
	}
}

bool add1_(Handler1 *Handler, DFN1 fn)
{
	if ((Handler->n_pfn1 + 1) < max_size)
	{
		Handler->pfn1[Handler->n_pfn1] = fn;
		Handler->n_pfn1++;
		printf("fn add %d\n", Handler->n_pfn1);
		return 1;
	}
	else
	{
		printf("FULL\n");
		return 0;
	}
}

bool del(Handler *Handler, DFN fn)
{
	int i, n = Handler->n_pfn;
	bool finish = false;
	for (i = 0; i < n; i++)
	{
		if (finish)
		{
			Handler->pfn[i - 1] = Handler->pfn[i];
		}
		if (Handler->pfn[i] == fn)
		{
			Handler->pfn[i] = NULL;
			Handler->n_pfn--;
			finish = true;
			printf("fn del\n");
		}
	}
	return finish;
}

#endif