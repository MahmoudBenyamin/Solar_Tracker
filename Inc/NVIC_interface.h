#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H



#define GROUP3 0x05FA0300 /*4 bits for group*/
#define GROUP4 0x05FA0400 /*3 bits for group and 1 bit for sub*/
#define GROUP5 0x05FA0500 /*2 bits for group and 2 bit for sub*/
#define GROUP6 0x05FA0600 /*1 bits for group and 3 bit for sub*/
#define GROUP7 0x05FA0700 /*0 bits for group and 4 bit for sub*/





void MNVIC_vEnableINT(u8 Copy_u8IntNUM);
void MNVIC_vDisableINT(u8 Copy_u8IntNUM);
void MNVIC_vSetPendingFlag(u8 Copy_u8IntNUM);
void MNVIC_vClearPendingFlag(u8 Copy_u8IntNUM);
u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNUM);
void MNVIC_VidSetPriority( s8 Copy_u8INTID , u8 Copy_u8GroupPriority , u8 Copy_u8SubPriority , u32 Copy_u8Group );

void MNVIC_VEnablePeripheral(u8 Copy_u8IntNUM);
void MNVIC_VDisablePeripheral(u8 Copy_u8IntNUM);








#endif
