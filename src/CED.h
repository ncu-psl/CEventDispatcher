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
} Event_;
typedef struct
{
	int n_pfn;
	Event_ event[max_size];
} Handler_;
#define Handler(name) Handler_ name = {.n_pfn = 0}

/*
* run1：找出array中符合expr條件的元素，執行Handler
* Handler：包含一個int參數的function形成的Handler
* array：input陣列
* add_, add1_：將 expr 轉換為string儲存
*/
bool del(Handler_ *Handler, DFN fn);
bool add(Handler_ *Handler, DFN fn, char *expr);
bool run(Handler_ *Handler);
bool run1(Handler_ *Handler, int array[]);
bool add_(Handler_ *Handler, DFN fn, char *expr);
bool run_(Handler_ *Handler, int n);
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

#define add(Handler, DFN, expr) add_(Handler, DFN, #expr)

#endif