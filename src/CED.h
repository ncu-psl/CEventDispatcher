/*
C Event Dispatcher
*/
#ifndef CED_H
#define CED_H

#include <stdbool.h>
#include <stdio.h>

#define max_size 10
#define max_cond 50

typedef void (*DFN)();
typedef void (*DFN1)(int);

typedef struct
{
	int n_pfn;
	DFN pfn[max_size];
	char cond[max_size][max_cond];
} Handler_;
#define Handler(name) Handler_ name = {.n_pfn=0}

typedef struct
{
	int n_pfn1;
	DFN1 pfn1[max_size];
	char cond[max_size][max_cond];
} Handler1_;
#define Handler1(name) Handler1_ name = {.n_pfn1=0}

/*
* run1：找出array中符合expr條件的元素，執行Handler
* Handler：包含一個int參數的function形成的Handler
* array：input陣列
* add_, add1_：將 expr 轉換為string儲存
*/
bool del(Handler_ *Handler, DFN fn);
bool add(Handler_ *Handler, DFN fn, char *expr);
bool add_(Handler_ *Handler, DFN fn, char *expr);
bool add1(Handler1_ *Handler1_, DFN1 fn, char *expr);
bool add1_(Handler1_ *Handler1_, DFN1 fn, char *expr);
bool run0(Handler_ *Handler);
bool run1(Handler1_ *Handler1_, int array[]);
bool run_(Handler1_ *Handler, int n);
int testEval1(char *expr, int input);

#define run1(Handler, array)                        \
	do                                              \
	{                                               \
		int size = sizeof(array) / sizeof *(array); \
		int i = 0;                                  \
		for (i = 0; i < size; i++)                  \
		{                                           \
			run_(Handler, array[i]);                \
		}                                           \
	} while (0)

#define add(Handler, CED1, expr) add_(Handler, CED1, #expr)
#define add1(Handler1, CED1, expr) add1_(Handler1, CED1, #expr)

#endif