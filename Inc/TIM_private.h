/*
 * TIM2_private.h
 *
 *  Created on: Apr 28, 2022
 *      Author: Tarek
 */

#ifndef TIM_PRIVATE_H_
#define TIM_PRIVATE_H_

#define TIM2_BASE_ADDRESS 0x40000000
#define TIM3_BASE_ADDRESS 0x40000400
#define TIM5_BASE_ADDRESS 0x40000C00
typedef struct {
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 SMCR;
	volatile u32 DIER;
	volatile u32 SR;
	volatile u32 EGR;
	volatile u32 CCMR1;
//volatile u32 CCM1 ;
	volatile u32 CCMR2;
// volatile u32 CCR2 ;
	volatile u32 CCER;
	volatile u32 CNT;
	volatile u32 PSC;
	volatile u32 ARR;
	volatile u32 Reserved1;
	volatile u32 CCR1;
	volatile u32 CCR2;
	volatile u32 CCR3;
	volatile u32 CCR4;
	volatile u32 Reserved2;
	volatile u32 DCR;
	volatile u32 DMAR;
	volatile u32 OR;
} TIMx_t;

#define  MTIM2   ((TIMx_t*)(TIM2_BASE_ADDRESS))
#define  MTIM3   ((TIMx_t*)(TIM3_BASE_ADDRESS))
#define  MTIM5   ((TIMx_t*)(TIM5_BASE_ADDRESS))
#endif /* TIM_PRIVATE_H_ */
