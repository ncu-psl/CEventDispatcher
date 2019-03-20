#include <stdbool.h>
#include <stdio.h>

#define max_size 10

typedef void (*DFN)();
typedef void (*DFN1)(int);
typedef int (*COND)(int);

#define run1(Handler, array)                        \
	do                                              \
	{                                               \
		int size = sizeof(array) / sizeof *(array); \
		int i = 0;                                  \
		for (i = 0; i < size; i++)                  \
		{                                           \
			runE(Handler, array[i]);                \
			printf("  %d\n", array[i]);             \
		}                                           \
	} while (0)

#define condfn(expr, num)             \
	int condfn##num()              \
	{                                 \
		if (expr)                     \
		{                             \
			printf("Here is condfn"); \
		}                             \
	}

#define add1(Handler1, DFN1, expr)                           \
	do                                                       \
	{                                                        \
		*Handler1.cond[*Handler1.n_pfn1] = &condfn(expr, 1); \
		add11(Handler1, DFN1);                               \
	} while (0)

typedef struct Handler1
{
	int n_pfn1;
	DFN1 pfn1[max_size];
	COND cond[max_size];
} Handler1;

bool add11(Handler1 *Handler, DFN1 fn)
{
	return 0;
}

void fn_A(int input) { printf("in fn_A, input is %d", input); }

int x=2;
condfn(x>3, 1);

int main()
{
	Handler1 handler1;
	handler1.n_pfn1 = 0;
	//add1(&handler1, fn_A, x > 3);
	return 0;
}
