#include"Std_Types.h"
#include"Macros.h"
#include"DIO_Private.h"
#include"DIO_Interface.h"
#include "DCMOTOR_Config.h"
#include "DCMOTOR_Interface.h"


void DCMOTOR_voidintialize ()
{
	
	DIO_voidSetPinDirection(MOTOR_PORT, MOTOR_PIN0,PIN_OUTPUT_ID);
	DIO_voidSetPinDirection(MOTOR_PORT, MOTOR_PIN1,PIN_OUTPUT_ID);
	
}

void DCMOTOR_voidDirection (u8 Copy_u8Direction )
{
	DCMOTOR_voidintialize ();
	switch (Copy_u8Direction)
	{
		
		case 'R' :     DIO_voidSetPinValue(MOTOR_PORT,MOTOR_PIN0,PIN_HIGH);
		               DIO_voidSetPinValue(MOTOR_PORT,MOTOR_PIN1,PIN_LOW);
					   break ;
		
		case 'L'  :   DIO_voidSetPinValue(MOTOR_PORT,MOTOR_PIN0,PIN_LOW);
		              DIO_voidSetPinValue(MOTOR_PORT,MOTOR_PIN1,PIN_HIGH);
					  break ;
		
		case 'S'  :   DIO_voidSetPinValue(MOTOR_PORT,MOTOR_PIN0,PIN_LOW);
		              DIO_voidSetPinValue(MOTOR_PORT,MOTOR_PIN1,PIN_LOW);
		              break ;
	}
}

