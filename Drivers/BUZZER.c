#include"Std_Types.h"
#include"Macros.h"
#include"DIO_Private.h"
#include"DIO_Interface.h"
#include "BUZZER.h"


void BUZZER_Initialize()
{
	DIO_voidSetPinDirection(BUZZER_PORT,BUZZER_PIN,PIN_OUTPUT_ID);
}
void BUZZER_ON()
{
	DIO_voidSetPinValue(BUZZER_PORT,BUZZER_PIN,PIN_HIGH);
}

void BUZZER_OFF()
{
	DIO_voidSetPinValue(BUZZER_PORT,BUZZER_PIN,PIN_LOW);
}
