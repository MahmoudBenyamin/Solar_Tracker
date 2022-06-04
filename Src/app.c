/*
 * app.c
 *
 *  Created on: Apr 28, 2022
 *      Author: mahmo
 */

#include "ECU.h"
#include "NVIC_interface.h"
#include  "STK_interface.h"
int main()
{
	SysInit();
	setCallBacks();
	//setPending flags

	while (1)
	{
		MNVIC_vSetPendingFlag(28);
		MSTK_voidSetBusyWait( 1000);
		MNVIC_vSetPendingFlag(50);
		MSTK_voidSetBusyWait( 1000);
		MNVIC_vSetPendingFlag(29);
		MSTK_voidSetBusyWait( 1000);
		ECU_start();
	}

	return 0;
}

