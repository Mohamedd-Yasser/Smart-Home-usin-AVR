#include <util/delay.h>
#include "Std_Types.h"
#include "Macros.h"
#include "DIO_PRIVATE.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "LCD_Private.h"
#include "ADC_Private.h"
#include "ADC_Interface.h"





void LCD_voidInit(void)
{ 


    /* Set Pin Direction*/ 
    DIO_voidSetPinDirection(LCD_CONT,PIN0_ID, PIN_OUTPUT_ID);
    DIO_voidSetPinDirection(LCD_CONT,PIN1_ID, PIN_OUTPUT_ID);
    DIO_voidSetPinDirection(LCD_CONT,PIN2_ID, PIN_OUTPUT_ID);

    /*Set Port Direction*/
    DIO_voidSetPortDirection(LCD_OUT,ALL_OUTPUT);
    /*Delay 30*/
	_delay_ms(30);
    /* Send Command Function Set*/
	LCD_voidWriteCommand(SEND);
    /*Delay2*/
	_delay_ms(2);
    /*Send Command Display on/off*/
	LCD_voidWriteCommand(DISPLAY);
    /*Delay 2ms*/
	_delay_ms(2);
    /*Send Command Clear Display*/
	LCD_voidWriteCommand(CLEAR);

}



void LCD_voidWriteCommand( u8 Copy_u8Command)
{
	/*RS=0--->pin0*/
    DIO_voidSetPinValue(LCD_CONT, PIN0_ID,PIN_LOW);
	/*RW=0--->pin1*/
    DIO_voidSetPinValue(LCD_CONT, PIN1_ID,PIN_LOW);
    /*Send Data*/
   DIO_voidSetPortValue(LCD_OUT,Copy_u8Command);
   /*Enable Pulse*/
   DIO_voidSetPinValue(LCD_CONT, PIN2_ID,PIN_OUTPUT_ID);
	_delay_ms(2); //1 second delay
   DIO_voidSetPinValue(LCD_CONT, PIN2_ID,PIN_LOW);


	
}
void  LCD_voidWriteDATA( u8 Copy_u8DATA)
{
	/*RS=1--->pin0*/
    DIO_voidSetPinValue(LCD_CONT, PIN0_ID,PIN_HIGH);
 	/*RW=0--->pin1*/
    DIO_voidSetPinValue(LCD_CONT, PIN1_ID,PIN_LOW);
    /*Send Data*/
    DIO_voidSetPortValue(LCD_OUT,Copy_u8DATA);
    /*Enable Pulse*/
    DIO_voidSetPinValue(LCD_CONT, PIN2_ID,PIN_OUTPUT_ID);
	_delay_ms(2); //1 second delay
    DIO_voidSetPinValue(LCD_CONT, PIN2_ID,PIN_LOW);
}

void LCD_GoToXY(u8 Copy_u8X, u8 Copy_u8Y)
{

	u8 LOC_Default=128;
if (Copy_u8X==1)
{
	LOC_Default= LOC_Default+Copy_u8Y;
	LCD_voidWriteCommand(LOC_Default);
}
else
{
	LOC_Default= LOC_Default+Copy_u8Y+0X40;

	LCD_voidWriteCommand(LOC_Default);
}
}

void LCD_voidWriteSting(u8 *Copy_u8string)
{
	u8 i=0 ;
	while (Copy_u8string[i]!='\0')
	{
		LCD_GoToXY(1,i);
		LCD_voidWriteDATA(Copy_u8string[i]);
		i++;
	}

}
void LCD_WriteStringXY(u8 *str, u8 Copy_u8X, u8 Copy_u8Y)
{


	u8 i=0 ;
		while (str[i]!='\0')
		{
			LCD_GoToXY(Copy_u8X, Copy_u8Y+i);
			LCD_voidWriteDATA(str[i]);
			i++;
		}

}


void LCD_voidDisplayNumber(u32 Copy_u8DATA)
{
	s8 count=0 ,cont=0;
	u32 arr[100];

	while (Copy_u8DATA != 0)
	{
		cont=Copy_u8DATA %10 ;
		Copy_u8DATA=Copy_u8DATA/10 ;
		arr[count]=cont;
		count++ ;
	}

	for (s8 i=count-1;i>=0;i--)
	{
		LCD_voidWriteDATA(arr[i]+48);
	}


}


void LCD_voidWriteSpecialCharacter(u32 Copy_u32arr[8])
{
	LCD_voidWriteCommand(64);
	for (u8 i=0;i<8;i++)
	{LCD_voidWriteDATA(Copy_u32arr[i]);
	}
	LCD_GoToXY(0,1);
	LCD_voidWriteDATA(0);


}

void LCD_voidClear()
{
	LCD_voidWriteCommand(CLR_LCD);

}
