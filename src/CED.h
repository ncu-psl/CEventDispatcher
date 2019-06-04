/*
C Event Dispatcher
*/
#include <stdbool.h>
#include <stdio.h>

#ifndef CED_H
#define CED_H

#define max_size 10
#define max_cond 50

typedef void (*DFN)();

typedef struct
{
	DFN pfn;
	char cond1[max_cond];
	char cond2[max_cond];
} EventProcessor_;
typedef struct
{
	int n_pfn;
	EventProcessor_ EP[max_size];
} Dispatcher_;
#define Dispatcher(name) Dispatcher_ name = {.n_pfn = 0}

/*
* run：找出array中符合expr條件的元素，執行Dispatcher
* Dispatcher：包含一個int參數的function形成的Dispatcher
* array：input陣列
* add_, add1_：將 expr 轉換為string儲存
*/
bool del(Dispatcher_ *dispatcher, DFN fn);
bool add(Dispatcher_ *dispatcher, DFN fn, char *expr);
bool add_(Dispatcher_ *dispatcher, DFN fn, char *expr);
bool run(Dispatcher_ *dispatcher, int array[]);
bool run_(Dispatcher_ *dispatcher, int n);
bool add2(Dispatcher_ *dispatcher, DFN fn, char *expr1, char *expr2);
bool add2_(Dispatcher_ *dispatcher, DFN fn, char *expr1, char *expr2);
bool run2(Dispatcher_ *dispatcher, int arg1, int arg2);
int testEval1(char *expr, int input);

#define run(Dispatcher, array)                      \
	do                                              \
	{                                               \
		int size = sizeof(array) / sizeof *(array); \
		int i = 0;                                  \
		for (i = 0; i < size; i++)                  \
		{                                           \
			run_(Dispatcher, array[i]);             \
		}                                           \
	} while (0)

#define add(Dispatcher, DFN, expr) add_(Dispatcher, DFN, #expr)
#define add2(Dispatcher, DFN, expr1, expr2) add2_(Dispatcher, DFN, #expr1, #expr2)

#endif