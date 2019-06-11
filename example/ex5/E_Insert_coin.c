#include "../../src/CED.h"
#include "ex5_VendingMachine2.h"
#include <stdio.h>

void E_Insert_coin()
{
	printf("new state S_COIN_INSERTED\n");
	state = S_COIN_INSERTED;
}

bool E_Insert_coin_Register()
{
	printf("E_Insert_coin_Register\n");
	return add2(&vender, E_Insert_coin, state == 1, event == 1);
}

bool E_Insert_coin_UnRegister()
{
	return del(&vender, E_Insert_coin);
}