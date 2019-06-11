#include "../../src/CED.h"

#ifndef ex5_VendingMachine2
#define ex5_VendingMachine2

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

extern enum STATE state;
extern enum EVENT event;
extern Dispatcher_ vender;

void VenderSubscribe();
bool E_Insert_coin_Register();
bool E_Insert_coin_UnRegister();
bool E_Select_option_Register();
bool E_Select_option_UnRegister();
bool E_Coffee_readyRegister();
bool E_Coffee_readyUnRegister();

#endif