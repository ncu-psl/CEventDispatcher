#include "ex5_VendingMachine2.h"
#include <stdbool.h>
#include <stdio.h>

void VenderSubscribe()
{
	if (!E_Insert_coin_Register())
		printf("E_Insert_coin_Register not success");
	if(!E_Select_option_Register())
		printf("E_Select_option_Register not success");
	if(!E_Coffee_readyRegister())
		printf("E_Coffee_readyRegister not success");
}