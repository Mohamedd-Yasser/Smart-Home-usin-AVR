#ifndef  EXT_INT_INTERFACE 
#define  EXT_INT_INTERFACE 


// TO set Sreg to enable the interput
void EXTINT_voidGloblaIniazlize();
void EXTINT_voidInt0(u8 Copy_u8IntNum,u8 Copy_u8SenseMode);
void EXTINT_voidIntIialize(u8 Copy_u8IntNum);
void EXTINT_voidGlobalDisable();
void EXTINT0_SetCallBack(void(*ptr)(void));
#endif 
