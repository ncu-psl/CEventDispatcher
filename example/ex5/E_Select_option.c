#include "../../src/CED.h"
#include "ex5_VendingMachine2.h"
#include <stdio.h>

void E_Select_option()
{
	printf("new state S_OPTION_SELECTED\n");
	state = S_OPTION_SELECTED;
}

bool E_Select_option_Register()
{
	printf("E_Select_option_Register\n");
	return add2(&vender, E_Select_option, state == 2, event == 2);
}

bool E_Select_option_UnRegister()
{
	return del(&vender, E_Select_option);
}