#include "../../src/CED.h"
#include "ex5_VendingMachine2.h"
#include <stdio.h>

void E_Coffee_ready()
{
	printf("new state S_IDLE\n");
	state = S_IDLE;
}

bool E_Coffee_readyRegister()
{
	printf("E_Coffee_readyRegister\n");
	return add2(&vender, E_Coffee_ready, state == 3, event == 3);
}

bool E_Coffee_readyUnRegister()
{
	return del(&vender, E_Coffee_ready);
}