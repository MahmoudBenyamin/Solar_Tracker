/*
 * TIM.c
 *
 *  Created on: Apr 28, 2022
 *      Author: Tarek
 *     Version: 1
 * Description:
 *
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIM_interface.h"
#include "TIM_private.h"
#include "TIM_config.h"

static void (*TIM2_CallBack)(void); //INT ID 28
static void (*TIM3_CallBack)(void); //INT ID 29
static void (*TIM5_CallBack)(void); //INT ID 50
	/*	Timer Intialization		*/
void TIM2_vInit(void) {
	CLR_BIT(MTIM2->CR1, 0);// Disable Timer2
	CLR_BIT(MTIM2->CR1, 4);//direction up count
	SET_BIT(MTIM2->CR1, 7);//Auto-reload
	SET_BIT(MTIM2->EGR, 0);//init after overflow
	SET_BIT(MTIM2->DIER, 0);
	MTIM2->PSC= PRESCALAR;
	SET_BIT(MTIM2->CR1, 0);
}

void TIM3_vInit(void) {
	CLR_BIT(MTIM3->CR1, 0);// Disable Timer2
	CLR_BIT(MTIM3->CR1, 4);//direction up count
	SET_BIT(MTIM3->CR1, 7);//Auto-reload
	SET_BIT(MTIM3->EGR, 0);//init after overflow
	SET_BIT(MTIM3->DIER, 0);
	MTIM3->PSC= PRESCALAR;
	SET_BIT(MTIM3->CR1, 0);
}

void TIM5_vInit(void) {
	CLR_BIT(MTIM5->CR1, 0);// Disable Timer2
	CLR_BIT(MTIM5->CR1, 4);//direction up count
	SET_BIT(MTIM5->CR1, 7);//Auto-reload
	SET_BIT(MTIM5->EGR, 0);//init after overflow
	SET_BIT(MTIM5->DIER, 0);
	MTIM5->PSC= PRESCALAR;
	SET_BIT(MTIM5->CR1, 0);
}

	/*	 Timer Enable 	*/
void TIM2_vEnableCount(u32 copy_u32ourARR) {
	MTIM2->ARR= copy_u32ourARR;


}

void TIM3_vEnableCount(u32 copy_u32ourARR) {
	MTIM3->ARR= copy_u32ourARR;


}

void TIM5_vEnableCount(u32 copy_u32ourARR) {
	MTIM5->ARR= copy_u32ourARR;


}

	/* 		Timer Disable 		*/
void TIM2_vDisableCount() {
	CLR_BIT(MTIM2->CR1, 0);
}

void TIM3_vDisableCount() {
	CLR_BIT(MTIM3->CR1, 0);
}

void TIM5_vDisableCount() {
	CLR_BIT(MTIM5->CR1, 0);
}




void TIM2_vSetCallBack(void (*ptr)(void)) {
	TIM2_CallBack = ptr;
}
void TIM3_vSetCallBack(void (*ptr)(void)) {
	TIM3_CallBack = ptr;
}
void TIM5_vSetCallBack(void (*ptr)(void)) {
	TIM5_CallBack = ptr;
}
	/*	Time handler 	*/
 void TIM2_IRQHandler(void) {			// this func count the day
	TIM2_CallBack();

	CLR_BIT(MTIM2->SR, 0);
}

 void TIM3_IRQHandler(void) {			//	This func count step
	TIM3_CallBack();

	CLR_BIT(MTIM3->SR, 0);
}

 void TIM5_IRQHandler(void) {			//	This func count sunrise and sunset
	TIM5_CallBack();

	CLR_BIT(MTIM5->SR, 0);
}






















