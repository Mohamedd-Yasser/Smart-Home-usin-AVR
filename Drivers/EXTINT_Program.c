#include"Std_Types.h"
#include"Macros.h"
#include"DIO_Private.h"
#include"DIO_Interface.h"
#include"DCMOTOR_Interface.h"
#include"EXTINT_Private.h"

// global pointer to function to can use it inside the ISR
void (*GPTF_EXT0)(void)='\0';

void EXTINT_voidGloblaIniazlize()
{
	Set_bit(S_REG,PIN7_ID);                                   // Enable global Intereput

}
void EXTINT_voidGlobalDisable()
{
	Clear_bit(S_REG,PIN7_ID);                                   // Enable global Intereput


}
void EXTINT_voidIntIialize(u8 Copy_u8IntNum)
{


	switch(Copy_u8IntNum)
	{
	case (0):
	DIO_voidSetPinDirection(PORTD_ID,PIN2_ID,PIN_INPUT_ID);
	DIO_voidSetPinValue(PORTD_ID,PIN2_ID,PIN_HIGH);
	Set_bit(GICR_REG ,PIN6_ID);
	break ;

	case(1):
	DIO_voidSetPinDirection(PORTD_ID,PIN3_ID,PIN_INPUT_ID);
	DIO_voidSetPinValue(PORTD_ID,PIN3_ID,PIN_HIGH);
	Set_bit(GICR_REG ,PIN7_ID);
	break;

	case(2):
	DIO_voidSetPinDirection(PORTB_ID,PIN2_ID,PIN_INPUT_ID);
	DIO_voidSetPinValue(PORTB_ID,PIN2_ID,PIN_HIGH);
	Set_bit(GICR_REG ,PIN5_ID);
	break;
	}



}

void EXTINT_voidInt0(u8 Copy_u8IntNum,u8 Copy_u8SenseMode)
{



EXTINT_voidIntIialize(Copy_u8IntNum);

if (Copy_u8IntNum==0)
{
switch(Copy_u8SenseMode)
	{
case ('R'):                                                      // raising
		Set_bit(MCUCR_REG ,PIN0_ID);
        Set_bit(MCUCR_REG ,PIN1_ID);
        break ;
case('F'):                                                       //falling
	   Clear_bit(MCUCR_REG ,PIN0_ID);
	   Set_bit(MCUCR_REG ,PIN1_ID);
	   break;
case('L'):                                                        // low level
		Clear_bit(MCUCR_REG ,PIN0_ID);
		Clear_bit(MCUCR_REG ,PIN1_ID);
		break;

	}
}


else if (Copy_u8IntNum==1)

{
	switch(Copy_u8SenseMode)
		{
	case ('R'):                                                      // rasing
			Set_bit(MCUCR_REG ,PIN2_ID);
	        Set_bit(MCUCR_REG ,PIN3_ID);
	        break ;
	case('F'):                                                       //failling
		   Clear_bit(MCUCR_REG ,PIN2_ID);
		   Set_bit(MCUCR_REG ,PIN3_ID);
		   break;
	case('L'):                                                        // low level
			Clear_bit(MCUCR_REG ,PIN2_ID);
			Clear_bit(MCUCR_REG ,PIN3_ID);
			break;

		}
}



else if (Copy_u8IntNum==2)
{
	switch(Copy_u8SenseMode)
		{
	case ('R'):                                                      // rasing
			Set_bit(MCUCSR_REG ,PIN6_ID);
	        break ;
	case('F'):                                                       //failling
		   Clear_bit(MCUCSR_REG ,PIN6_ID);
		   break;

		}

}


}

void EXTINT0_SetCallBack(void(*ptr)(void))
{

	GPTF_EXT0=ptr;
}

void __vector_1()__attribute__((signal));
void __vector_1()
{
	//DIO_voidSetPinValue(PORTA_ID,PIN0_ID,PIN_HIGH);
	if (GPTF_EXT0!='\0')
	{
		GPTF_EXT0();
	}

}

void __vector_2()__attribute__((signal));
void __vector_2()
{
	DIO_voidSetPinValue(PORTA_ID,PIN0_ID,PIN_HIGH);

}

void __vector_3()__attribute__((signal));
void __vector_3()
{
	DIO_voidSetPinValue(PORTA_ID,PIN0_ID,PIN_HIGH);

}




