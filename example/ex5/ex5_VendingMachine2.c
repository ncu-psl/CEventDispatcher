/*
Example 5
Using CED to make FSM of vending machine
將各個狀態分開訂閱
*/
#include "ex5_VendingMachine2.h"
#include "../../src/CED.h"
#include <stdio.h>

void Default();
void Vender();
Dispatcher(vender);

enum STATE state = 3;
enum EVENT event = 3;

int main()
{
    VenderSubscribe();
	Vender();
	return 0;
}

void Vender()
{
	int input = 3;
	enum STATE pre_state = 0;

	do
	{
		if (input != '\n' - '0')
		{
			printf("\tINSERT_COIN   = 1 \n\tSELECT_OPTION = 2 \n\tCOFFEE_READY  = 3 \n");
			printf("state = %d -> ", state);
			event = input;
			run2(&vender, state, event);
			if (pre_state == state)
			{
				Default();
			}
			else
			{
				pre_state = state;
			}
		}
		if (input == 's')
		{
			printf("INSERT_COIN   = 1 \nSELECT_OPTION = 2 \nCOFFEE_READY  = 3 \n");
			printf("state = %d event = %d\n", state, input);
		}
	} while ((input = getchar() - '0'));
}

void Default()
{
	printf("    Do Nothing\n");
}