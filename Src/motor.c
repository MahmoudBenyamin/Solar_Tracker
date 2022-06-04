/*
 * motor.c
 *
 *  Created on: Apr 30, 2022
 *      Author: mahmo
 */

#include "STD_TYPES.h"
#include "GPIO_interface.h"
#include "motor_interface.h"
void MOTOR_vSetXPostion (u32 step)
{
	switch(step)
	{
	case 1:

		MGPIO_vSetPinValueDirect(GPIOA, 8,SET);
		MGPIO_vSetPinValueDirect(GPIOA,9,RESET);
		MGPIO_vSetPinValueDirect(GPIOA, 10,RESET);
		MGPIO_vSetPinValueDirect(GPIOA, 11,RESET);
		break;


	case 2:
		MGPIO_vSetPinValueDirect(GPIOA, 8,SET);
		MGPIO_vSetPinValueDirect(GPIOA, 9,RESET);
		MGPIO_vSetPinValueDirect(GPIOA, 10,SET);
		MGPIO_vSetPinValueDirect(GPIOA, 11,RESET);
		break;


	case 3:
		MGPIO_vSetPinValueDirect(GPIOA, 8,RESET);
		MGPIO_vSetPinValueDirect(GPIOA, 9,RESET);
		MGPIO_vSetPinValueDirect(GPIOA, 10,SET);
		MGPIO_vSetPinValueDirect(GPIOA, 11,RESET);
	    break;


	case 4:
		MGPIO_vSetPinValueDirect(GPIOA, 8,SET);
		MGPIO_vSetPinValueDirect(GPIOA, 9,RESET);
		MGPIO_vSetPinValueDirect(GPIOA, 10,SET);
		MGPIO_vSetPinValueDirect(GPIOA, 11,RESET);
		break;
	}
}

void MOTOR_vSetYPostion (u32 step)
{
	switch(step)
	{
	case 1:

		MGPIO_vSetPinValueDirect(GPIOA, 12,SET);
		MGPIO_vSetPinValueDirect(GPIOA,13,RESET);
		MGPIO_vSetPinValueDirect(GPIOA, 14,RESET);
		MGPIO_vSetPinValueDirect(GPIOA, 15,RESET);
		break;


	case 2:
		MGPIO_vSetPinValueDirect(GPIOA, 12,SET);
		MGPIO_vSetPinValueDirect(GPIOA, 13,RESET);
		MGPIO_vSetPinValueDirect(GPIOA, 14,SET);
		MGPIO_vSetPinValueDirect(GPIOA, 15,RESET);
		break;


	case 3:
		MGPIO_vSetPinValueDirect(GPIOA, 12,RESET);
		MGPIO_vSetPinValueDirect(GPIOA, 13,RESET);
		MGPIO_vSetPinValueDirect(GPIOA, 14,SET);
		MGPIO_vSetPinValueDirect(GPIOA, 15,RESET);
	    break;


	case 4:
		MGPIO_vSetPinValueDirect(GPIOA, 12,SET);
		MGPIO_vSetPinValueDirect(GPIOA, 13,RESET);
		MGPIO_vSetPinValueDirect(GPIOA, 14,SET);
		MGPIO_vSetPinValueDirect(GPIOA, 15,RESET);
		break;
	}
}
