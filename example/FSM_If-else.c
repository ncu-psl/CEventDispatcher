/*
使用 if-else 實現 FSM 模型
*/
#include "../src/CED.h"
#include <stdio.h>

void VenderFSM();
void E_Insert_coin();
void E_Select_option();
void E_Coffee_ready();

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

enum STATE state = S_IDLE;
enum STATE pre_state = 0;
enum EVENT event = 0;

int main()
{
	VenderFSM();
	return 0;
}

void VenderFSM()
{
	int input = 0;
	do
	{
		if (input != '\n' - '0')
		{
			printf("\tINSERT_COIN   = 1 \n\tSELECT_OPTION = 2 \n\tCOFFEE_READY  = 3 \n");
			printf("state = %d -> ", state);
			event = input;
			if (state == S_IDLE)
			{
				if (event == E_INSERT_COIN)
				{
					E_Insert_coin();
				}
			}else if (state == S_COIN_INSERTED)
			{
				if (event == E_SELECT_OPTION)
				{
					E_Select_option();
				}
			}else if (state == S_OPTION_SELECTED)
			{
				if (event == E_COFFEE_READY)
				{
					E_Coffee_ready();
				}
			}
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