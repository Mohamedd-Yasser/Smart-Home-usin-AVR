
#include <stdio.h>
#include <string.h>
#include <util/delay.h>
#include "Std_Types.h"
#include "Macros.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "KeyPad_Interface.h"
#include"EXTINT_Config.h"
#include"EXTINT_Interface.h"
#include "ADC_Interface.h"
#include "ADC_Congif.h"
#include"TR_Interface.h"
#include"TR_Config.h"
#include "BUZZER.h"
#include "avr/io.h"


#define password      1234
#define password_Size  4


u8 Return_Password();
void Drivers_Intialize();
void Open_Door();
void LED_ON();
void Fan_Control();
void Bulb_Control();

int main ()
{

	u8 keypad_press=0,flagg=0 ;
	u8 check ;
	Drivers_Intialize();



	LCD_voidWriteSting("   Welcome ITI");
	_delay_ms(700);
	LCD_voidClear();

	LCD_voidWriteSting("Password:");
	 check=Return_Password();

	///////////////////

	while (1){


			keypad_press=KeyPad_u8GetPressedKey();

				if (check==1)
				{

					LCD_voidWriteSting("welcome home");
					Open_Door();
					LED_ON();
					flagg=1 ;
					_delay_ms(800);
					LCD_voidClear();
					LCD_voidWriteSting("Current Temp : ");
					_delay_ms(800);


					while (flagg==1)

					{
						Fan_Control();
						Bulb_Control();

					}


				}

		}

  }



void Drivers_Intialize()
{

	KeyPad_voidInit();
	LCD_voidInit();
	ADC_voidInit();
	TR1_voidTR1FastPwmICR1_Init();
	TR2_voidTR2PhaseCorrect_Init();
	TR1_voidTR1Normal_Init();
	EXTINT_voidGloblaIniazlize();
	BUZZER_Initialize();

}

u8  Return_Password()
{

	u8 keypad_press;
    u8 arr[password_Size]={1,2,3,4} ;
	u8 arr2[password_Size];
	u8 i=0,flag=1 ;

	while (flag<=password_Size)
	{
		keypad_press=KeyPad_u8GetPressedKey();

	if (keypad_press!=0xff)

	{

	switch(keypad_press)
	{
	case (1): arr2[i]=keypad_press ;
	         _delay_ms(400);
	          i++ ;
	          flag++ ;
	          break ;
	case (2): arr2[i]=keypad_press ;
	         _delay_ms(400);
	          i++ ;
	          flag++ ;
	          break ;
	case (3): arr2[i]=keypad_press ;
	         _delay_ms(400);
	          i++ ;
	          flag++ ;
	          break ;
	case (4): arr2[i]=keypad_press ;
	         _delay_ms(400);
	          i++ ;
	          flag++ ;
	          break ;
	case (5): arr2[i]=keypad_press ;
	         _delay_ms(400);
	          i++ ;
	          flag++ ;
	          break ;
	case (6): arr2[i]=keypad_press ;
	         _delay_ms(400);
               i++ ;
	          flag++ ;
	          break ;
	case (7): arr2[i]=keypad_press ;
	          _delay_ms(400);
	          i++ ;
	          flag++ ;
	          break ;
	case (8): arr2[i]=keypad_press ;
	         _delay_ms(400);
	          i++ ;
	          flag++ ;
	          break ;
	case (9): arr2[i]=keypad_press ;
	         _delay_ms(400);
              i++ ;
	          flag++ ;
	          break ;




      }

	// Refer to #
	LCD_voidWriteDATA(35);
	_delay_ms(250);
}

	}



	for (u8 i=0;i<password_Size;i++)
	{
		if (arr[i] != arr2[i])
		{
			LCD_voidWriteSting("Wrong Password ");
			BUZZER_ON();

			return 0 ;
			break ;

		}

	}

	LCD_voidClear();
	return 1 ;


}

/*void BUZZER_Initialize()
{
	DIO_voidSetPinDirection(PORTD_ID,PIN3_ID,PIN_OUTPUT_ID);

}*/



void Open_Door()
{
	DIO_voidSetPinDirection(PORTD_ID,PIN5_ID,PIN_OUTPUT_ID);
	TR1_voidTR1FastPwmICR1_Preload(1999);

}



void LED_ON()
{
	DIO_voidSetPinDirection(Led_Port,PIN2_ID,PIN_OUTPUT_ID);
	DIO_voidSetPinDirection(Led_Port,PIN3_ID,PIN_OUTPUT_ID);
	DIO_voidSetPinDirection(Led_Port,PIN4_ID,PIN_OUTPUT_ID);
	DIO_voidSetPinDirection(Led_Port,PIN5_ID,PIN_OUTPUT_ID);
	DIO_voidSetPinValue(Led_Port,PIN2_ID,PIN_HIGH);
	DIO_voidSetPinValue(Led_Port,PIN3_ID,PIN_HIGH);
	DIO_voidSetPinValue(Led_Port,PIN4_ID,PIN_HIGH);
	DIO_voidSetPinValue(Led_Port,PIN5_ID,PIN_HIGH);

}


void Fan_Control()
{
	u16 analog ,result ;
	DIO_voidSetPinDirection(PORTD_ID,PIN7_ID,PIN_OUTPUT_ID);
	ADC_voidSelectChannel(ADC0);
	ADC_voidSelectPreScaler(Div64);

	//Temprature Sensor with Dc Motor
	ADC_voidSingleRead();
	result=ADC_u16GetResult();
	analog=(u16)(((u32) result * 5000)/(u16) 1023 );
	analog=analog/10 ;
	analog=(analog/2)+1 ;
    LCD_GoToXY(0,1);
	LCD_voidDisplayNumber(analog);
	LCD_WriteStringXY("          ",0,4);
	BUZZER_OFF();
	if (analog<21)
	{
		TR2_voidTR2PhaseCorrect_Preload(0);

		ADC_voidSingleRead();

	}
	else if (analog>=21 && analog<28 )
	{
		TR2_voidTR2PhaseCorrect_Preload(153);

		ADC_voidSingleRead();
	}

	else if (analog>=28 && analog<38 )
	{
		TR2_voidTR2PhaseCorrect_Preload(255);
		ADC_voidSingleRead();

	}
	else if (analog>=50 )
	{
	BUZZER_ON();
	LCD_WriteStringXY("WARNING!!!",0,4);
	//LCD_voidWriteSting();

	ADC_voidSingleRead();

	}
	ADC_voidSingleRead();


}

	void Bulb_Control()
	{
		u16 result,Lux ;
		ADC_voidSelectChannel(ADC1);
		ADC_voidSelectPreScaler(Div64);
		ADC_voidSingleRead();
		result=ADC_u16GetResult();
		Lux=(u16)(((u32)result*5000*2)/1023);
		DIO_voidSetPinDirection(PORTA_ID,PIN7_ID,PIN_OUTPUT_ID);


		if (Lux<5000)
		{
			DIO_voidSetPinValue(PORTA_ID,PIN7_ID,PIN_LOW);
			ADC_voidSingleRead();

		}
		else if (Lux>=5000)
		{
			DIO_voidSetPinValue(PORTA_ID,PIN7_ID,PIN_HIGH);
			ADC_voidSingleRead();

		}

		ADC_voidSingleRead();



	}




