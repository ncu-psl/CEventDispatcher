#ifndef DFN_H
#define DFN_H

#include <stdbool.h>
#include <stdio.h>

#define max_size 10

typedef void (*DFN)();
typedef void (*DFN1)(int);

typedef struct Handler
{
	int n_pfn;
	DFN pfn[max_size];
	char cond[max_size];
} Handler;

typedef struct Handler1
{
	int n_pfn1;
	DFN1 pfn1[max_size];
	char cond[max_size];
} Handler1;

bool del(Handler *Handler, DFN fn);
bool add(Handler *Handler, DFN fn, char *expr);
bool add1(Handler1 *Handler1, DFN1 fn, char *expr);
bool run0(Handler *Handler);
bool run1(Handler1 *Handler1, int array[]);
bool runE(Handler1 *Handler, int n);
void test(void);
#endif