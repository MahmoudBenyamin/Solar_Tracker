/*
 * TIM2_interface.h
 *
 *  Created on: Apr 28, 2022
 *      Author: Tarek
 *     Version: 1
 * Description:
 *
 */

#ifndef TIM_INTERFACE_H_
#define TIM_INTERFACE_H_

#define PRESCALAR   64000
#define ARR_DAY     10800000
#define STEP_ARR	54000
#define NO      0
#define YES     1

/*  Time  Init  */
void TIM2_vInit(void);
void TIM3_vInit(void);
void TIM5_vInit(void);

/*  Timer Entable   */
void TIM2_vEnableCount(u32 copy_u32ourARR);
void TIM3_vEnableCount(u32 copy_u32ourARR);
void TIM5_vEnableCount(u32 copy_u32ourARR);

/*  Time Disable    */
void TIM2_vDisableCount(void);
void TIM3_vDisableCount(void);
void TIM5_vDisableCount(void);

/*  Time CallBack   */
void TIM2_vSetCallBack(void (*ptr)(void));
void TIM3_vSetCallBack(void (*ptr)(void));
void TIM5_vSetCallBack(void (*ptr)(void));


#endif /* TIM_INTERFACE_H_ */
