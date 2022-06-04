#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H



typedef struct{

	volatile u32 ISER    [ 32 ];
	volatile u32 ICER    [ 32 ];
	volatile u32 ISPR    [ 32 ];
	volatile u32 ICPR    [ 32 ];
	volatile u32 IAPR    [ 32 ];
	volatile u32 RESERVED[ 32 ];
	volatile u8 IPR      [ 128];

}NVIC_t;



#define MNVIC      ( ( volatile NVIC_t *)0xE000E100 )
#define MNVIC_STIR ( ( volatile u32  *)0xE000EF00 )




typedef struct{

	volatile u32 CPUID;
	volatile u32 ICSR;
	volatile u32 VTOR;
	volatile u32 AIRCR;
	volatile u32 SCR;
	volatile u32 CCR;
	volatile u32 SHPR1;
	volatile u32 SHPR2;
	volatile u32 SHPR3;
	volatile u32 SHCSR;
	volatile u32 CFSR;
	volatile u32 HFSR;
	volatile u32 RESERVED;
	volatile u32 MMFAR;
	volatile u32 BFAR;

}SCB_Type;

#define SCB ((volatile SCB_Type *) 0xE000ED00 )










#define _NVIC_BASE_ADDRESS  0xE000E100
/*Enable for External*/
#define P_ISER              ((volatile u32*)(0xE000E100))
#define NVIC_ISER_0         (*((volatile u32*)(0xE000E100))) /*Enable External Interuppt from 0  to 31 */ 
#define NVIC_ISER_1         (*((volatile u32*)(0xE000E104))) /*Enable External Interuppt from 32 to 63 */ 
#define NVIC_ISER_2         (*((volatile u32*)(0xE000E108))) /*Enable External Interuppt from 64 to 85 */  
/*Disable for External*/
#define P_ICER              ((volatile u32*)(0xE000E180))
#define NVIC_ICER_0         (*((volatile u32*)(0xE000E180))) /*Enable External Interuppt from 0  to 31 */ 
#define NVIC_ICER_1         (*((volatile u32*)(0xE000E184))) /*Enable External Interuppt from 32 to 63 */ 
#define NVIC_ICER_2         (*((volatile u32*)(0xE000E188))) /*Enable External Interuppt from 64 to 85 */  
/*Set Pending External*/
#define P_ISPR              ((volatile u32*)(0xE000E200))
#define NVIC_ISPR_0         (*((volatile u32*)(0xE000E200))) /*Enable External Interuppt from 32 to 63 */ 
#define NVIC_ISPR_1         (*((volatile u32*)(0xE000E204))) /*Enable External Interuppt from 32 to 63 */ 
#define NVIC_ISPR_2         (*((volatile u32*)(0xE000E208))) /*Enable External Interuppt from 32 to 63 */ 
/**/

#define NVIC_ICPR_0         (*((volatile u32*)(0xE000E280)))
#define NVIC_ICPR_1         (*((volatile u32*)(0xE000E284)))
#define NVIC_ICPR_2         (*((volatile u32*)(0xE000E288)))
/**/

#define NVIC_IABR_0         (*((volatile u32*)(0xE000E300)))
#define NVIC_IABR_1         (*((volatile u32*)(0xE000E304)))
#define NVIC_IABR_2         (*((volatile u32*)(0xE000E308)))

#define NVIC_IPR               (( u8 * )0xE000E400)
#define SCB_AIRCR          (*((volatile u32*)(0xE000ED00+0x0C)))

#endif
