#ifndef DFN_H
#define DFN_H

#include <stdbool.h>
#include <stdio.h>

#define max_size 10
#define max_cond 20

typedef void (*DFN)();
typedef void (*DFN1)(int);

typedef struct Handler
{
	int n_pfn;
	DFN pfn[max_size];
	char cond[max_size][max_cond];
} Handler;

typedef struct Handler1
{
	int n_pfn1;
	DFN1 pfn1[max_size];
	char cond[max_size][max_cond];
} Handler1;

/*
* run1：找出array中符合expr條件的元素，執行Handler
* Handler：包含一個int參數的function形成的Handler
* array：input陣列
*/
bool del(Handler *handler, DFN fn);
bool add(Handler *handler, DFN fn, char *expr);
bool add_(Handler *handler, DFN fn, char *expr);
bool add1(Handler1 *handler1, DFN1 fn, char *expr);
bool add1_(Handler1 *handler1, DFN1 fn, char *expr);
bool run0(Handler *handler);
bool run1(Handler1 *handler1, int array[]);
bool run_(Handler1 *handler, int n);
void test(void);

#define run1(Handler, array)                        \
	do                                              \
	{                                               \
		int size = sizeof(array) / sizeof *(array); \
		int i = 0;                                  \
		for (i = 0; i < size; i++)                  \
		{                                           \
			printf("  input=  %d\n", array[i]);     \
			run_(Handler, array[i]);                \
		}                                           \
	} while (0)

#define add(Handler, DFN1, expr) add_(Handler, DFN1, #expr)
#define add1(Handler1, DFN1, expr) add1_(Handler1, DFN1, #expr)

#endif