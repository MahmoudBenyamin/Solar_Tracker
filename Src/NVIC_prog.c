 #include "STD_TYPES.h"
 #include "BIT_MATH.h"

 #include "NVIC_interface.h"
 #include "NVIC_config.h"
 #include "NVIC_private.h"






void MNVIC_vEnableINT(u8 Copy_u8IntNUM)
{

	MNVIC->ISER[ Copy_u8IntNUM / 32 ] = 1 << ( Copy_u8IntNUM % 32 ) ;




    // if (Copy_u8IntNUM <= 31U){
    //     NVIC_ISER_0 = (1U<<Copy_u8IntNUM);
    // }
    // else if (Copy_u8IntNUM <= 63U)
    // {
    //     Copy_u8IntNUM -= 32;
    //     NVIC_ISER_1 = (1U<<Copy_u8IntNUM);

    // }
    // else if (Copy_u8IntNUM <= 85U){
    //     Copy_u8IntNUM -= 64;
    //     NVIC_ISER_2 = (1U<<Copy_u8IntNUM);
    // }
    // else{
    //     /*ERROR*/
    // }
}

void MNVIC_vDisableINT(u8 Copy_u8IntNUM){

	MNVIC->ICER[ Copy_u8IntNUM / 32 ] = 1 << ( Copy_u8IntNUM % 32 ) ;

    // if (Copy_u8IntNUM <= 31U){
    //     NVIC_ICER_0 = (1U<<Copy_u8IntNUM);
    // }
    // else if (Copy_u8IntNUM <= 63U)
    // {   Copy_u8IntNUM -= 32;
    //     NVIC_ICER_1 = (1U<<Copy_u8IntNUM);

    // }
    // else if (Copy_u8IntNUM <= 85U){
    //     Copy_u8IntNUM -= 64;
    //     NVIC_ICER_2 = (1U<<Copy_u8IntNUM);
    // }
    // else{
    //     /*ERROR*/
    // }
}

void MNVIC_vSetPendingFlag(u8 Copy_u8IntNUM){

   	MNVIC->ISPR[ Copy_u8IntNUM / 32 ] = 1 << ( Copy_u8IntNUM % 32 ) ;


    // if (Copy_u8IntNUM <= 31U){
    //     NVIC_ISPR_0 = (1U<<Copy_u8IntNUM);
    // }
    // else if (Copy_u8IntNUM <= 63U)
    // {   Copy_u8IntNUM -= 32;
    //     NVIC_ISPR_1 = (1U<<Copy_u8IntNUM);

    // }
    // else if (Copy_u8IntNUM <= 85U){
    //     Copy_u8IntNUM -= 64;
    //     NVIC_ISPR_2 = (1U<<Copy_u8IntNUM);
    // }
    // else{
    //     /*ERROR*/
    // }
}

void MNVIC_vClearPendingFlag(u8 Copy_u8IntNUM){

    	MNVIC->ICPR[ Copy_u8IntNUM / 32 ] = 1 << ( Copy_u8IntNUM % 32 ) ;

    // if (Copy_u8IntNUM <= 31U){
    //     NVIC_ICPR_0 = (1U<<Copy_u8IntNUM);
    // }
    // else if (Copy_u8IntNUM <= 63U)
    // {
    //     Copy_u8IntNUM -= 32;
    //     NVIC_ICPR_1 = (1U<<Copy_u8IntNUM);

    // }
    // else if (Copy_u8IntNUM <= 85U){
    //     Copy_u8IntNUM -= 64;
    //     NVIC_ICPR_2 = (1U<<Copy_u8IntNUM);
    // }
    // else{
    //     /*ERROR*/
    // }
}

u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNUM){
    u8 LOC_u8Active = GET_BIT( (MNVIC->IAPR[ Copy_u8IntNUM/32 ]) , ( Copy_u8IntNUM % 32 ) );
	return LOC_u8Active ;

    // u8 L_u8ActiveFlag;
    // if (Copy_u8IntNUM <= 31U){
    //     L_u8ActiveFlag = GET_BIT(NVIC_IABR_0,Copy_u8IntNUM);

    // }
    // else if (Copy_u8IntNUM <= 63U)
    // {
    //     Copy_u8IntNUM -= 32;
    //     L_u8ActiveFlag = GET_BIT(NVIC_IABR_1,Copy_u8IntNUM);

    // }
    // else if (Copy_u8IntNUM <= 85U){
    //     Copy_u8IntNUM -= 64;
    //     L_u8ActiveFlag = GET_BIT(NVIC_IABR_2,Copy_u8IntNUM);
    // }
    // else{
    //     /*ERROR*/
    // }
}
void MNVIC_VidSetPriority( s8 Copy_u8IntNUM , u8 Copy_u8GroupPriority , u8 Copy_u8SubPriority , u32 Copy_u8Group ){
	u8 Priority =  Copy_u8SubPriority | Copy_u8GroupPriority << ( (Copy_u8Group - 0x05FA0300) / 256 )  ;
	//Core Peripheral
	/*if( Copy_u8IntNUM < 0  ){
		if( Copy_u8IntNUM == MEMORY_MANAGE || Copy_u8IntNUM == BUS_FAULT || Copy_u8IntNUM == USAGE_FAULT ){
			Copy_u8IntNUM += 3;
			SCB->SHPR1 = ( Priority ) << ( (8 * Copy_u8IntNUM) + 4 );
		}
		else if ( Copy_u8IntNUM == SV_CALL ){
			Copy_u8IntNUM += 7;
			SCB->SHPR2 = ( Priority ) << ( (8 * Copy_u8IntNUM) + 4 );
		}
		else if( Copy_u8IntNUM == PEND_SV || Copy_u8IntNUM == SYSTICK ){
			Copy_u8IntNUM += 8;
			SCB->SHPR3 = ( Priority ) << ( (8 * Copy_u8IntNUM) + 4 );
		}
	}*/
    //External Peripheral
	if( Copy_u8IntNUM >= 0 ){
		MNVIC->IPR[ Copy_u8IntNUM ] = Priority << 4 ;

			}

			SCB->AIRCR = Copy_u8Group ;
}

void MNVIC_VEnablePeripheral(u8 Copy_u8IntNUM){

    P_ISER[Copy_u8IntNUM/32]=(1U<<(Copy_u8IntNUM % 32));
}

void MNVIC_VDisablePeripheral(u8 Copy_u8IntNUM){

    P_ICER[Copy_u8IntNUM/32]=(1U<<(Copy_u8IntNUM % 32));
}















