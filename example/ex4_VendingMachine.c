/*
Example 4
Using CED to make FSM of vending machine
*/
#include "../src/CED.h"
#include <stdbool.h>
#include <stdio.h>

void Idle();
void Coin_Inserted();
void Option_Selected();
void Default();

void Vender();

Dispatcher(vender);

enum STATE
{
	OPTION_SELECTED = 1,
	COIN_INSERTED = 2,
	IDLE = 3,
};

enum EVENT
{
	INSERT_COIN = 1,
	SELECT_OPTION = 2,
	COFFEE_READY = 3,
};

enum STATE state = 1;
enum STATE pre_state = 0;
enum EVENT event = 3;

int main()
{
	add2(&vender, Idle, status == 1, event == 3);
	add2(&vender, Coin_Inserted, status == 3, event == 1);
	add2(&vender, Option_Selected, status == 2, event == 2);
	Vender();
	return 0;
}

void Vender()
{
	int input = 3;
	do
	{
		if (input != '\n' - '0')
		{
			printf("INSERT_COIN   = 1 \nSELECT_OPTION = 2 \nCOFFEE_READY  = 3 \n");
			printf("now state = %d\n", state);
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

void Idle()
{
	printf("new state Idle\n");
	state = IDLE;
}
void Coin_Inserted()
{
	printf("new state Coin_Inserted\n");
	state = COIN_INSERTED;
}
void Option_Selected()
{
	printf("new state Option_Selected\n");
	state = OPTION_SELECTED;
}
void Default()
{
	printf("    Do Nothing\n");
}