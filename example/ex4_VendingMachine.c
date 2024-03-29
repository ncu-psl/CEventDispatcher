/*
Example 4
Using CED to make FSM of vending machine
*/
#include "../src/CED.h"
#include <stdbool.h>
#include <stdio.h>

void E_Insert_coin();
void E_Select_option();
void E_Coffee_ready();
void Default();

void Vender();

Dispatcher(vender);

enum STATE
{
	S_IDLE = 1,
	S_COIN_INSERTED = 2,
	S_OPTION_SELECTED = 3,
};

enum EVENT
{
	E_INSERT_COIN = 1,
	E_SELECT_OPTION = 2,
	E_COFFEE_READY = 3,
};

enum STATE state = 3;
enum STATE pre_state = 0;
enum EVENT event = 3;

int main()
{
	add2(&vender, E_Insert_coin, state == 1, event == 1);
	add2(&vender, E_Select_option, state == 2, event == 2);
	add2(&vender, E_Coffee_ready, state == 3, event == 3);
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
			printf("state = %d\n", state);
		}
		if (input == 's')
		{
			printf("INSERT_COIN   = 1 \nSELECT_OPTION = 2 \nCOFFEE_READY  = 3 \n");
			printf("state = %d event = %d\n", state, input);
		}
	} while ((input = getchar() - '0'));
}

void E_Coffee_ready()
{
	printf("new state S_IDLE\n");
	state = S_IDLE;
}
void E_Insert_coin()
{
	printf("new state S_COIN_INSERTED\n");
	state = S_COIN_INSERTED;
}
void E_Select_option()
{
	printf("new state S_OPTION_SELECTED\n");
	state = S_OPTION_SELECTED;
}
void Default()
{
	printf("    Do Nothing\n");
}