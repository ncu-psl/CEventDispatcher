/*
C Event Dispatcher
*/
#ifndef CED_H
#define CED_H

#include <stdbool.h>
#include <stdio.h>

#define max_size 10
#define max_cond 50

// typedef union {
// 	void (*DFN0)();
//  void (*DFN1)(int);
// } DFN;
typedef void (*DFN)();

typedef struct{
    DFN pfn;
	char cond[max_cond];
} EventProcessor_;
typedef struct
{
	int n_pfn;
	EventProcessor_ EP[max_size];
} Dispatcher_;
#define Dispatcher(name) Dispatcher_ name = {.n_pfn = 0}

/*
* run1：找出array中符合expr條件的元素，執行Dispatcher
* Dispatcher：包含一個int參數的function形成的Dispatcher
* array：input陣列
* add_, add1_：將 expr 轉換為string儲存
*/
bool del(Dispatcher_ *dispatcher, DFN fn);
bool add(Dispatcher_ *dispatcher, DFN fn, char *expr);
bool run(Dispatcher_ *dispatcher);
bool run1(Dispatcher_ *dispatcher, int array[]);
bool add_(Dispatcher_ *dispatcher, DFN fn, char *expr);
bool run_(Dispatcher_ *dispatcher, int n);
int testEval1(char *expr, int input);

#define run1(Dispatcher, array)                        \
	do                                              \
	{                                               \
		int size = sizeof(array) / sizeof *(array); \
		int i = 0;                                  \
		for (i = 0; i < size; i++)                  \
		{                                           \
			run_(Dispatcher, array[i]);                \
		}                                           \
	} while (0)

#define add(Dispatcher, DFN, expr) add_(Dispatcher, DFN, #expr)

#endif