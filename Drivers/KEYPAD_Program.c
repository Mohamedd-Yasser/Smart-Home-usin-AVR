#include"Std_Types.h"
#include"Macros.h"
#include"DIO_Private.h"
#include"DIO_Interface.h"
#include <util/delay.h>
#include"KeyPad_Interface.h"
#include"KeyPad_Config.h"
#include"LCD_Interface.h"

 u8 sw_val[4][4]={{7,8,9,'/'},           // Key Pad array
	              {4,5,6,'*'},
				  {1,2,3,'-'},
                  {10,0,'=','+'}};


void KeyPad_voidInit()
{
	DIO_voidSetPortDirection(PORTB_ID,OUT_PORT);          //MSF is rows , lSP col
	DIO_voidSetPortValue(PORTB_ID, Pull_UP );              // Pull up activation

}

u8 KeyPad_u8GetPressedKey()
{
	u8 col ,row,check_press=1 ;
	u8 val =0xff;                                      // store the value of switch
	                                                   // if the value change so there is switch pressed
	KeyPad_voidInit();



	for (col=col_start;col<col_end;col++)
	{DIO_voidSetPinValue(PORTB_ID,col ,PIN_LOW);              // Activate switch

		for (row=row_start;row<row_end;row++)                 //Rows start from 4 as the row is input start from pin 4
		{
			check_press=DIO_voidGetPinValue(PORTB_ID,row);    // try to get the switch who is pressed
		    if (check_press==0)                               //Switch pressed
			{

			 val=sw_val[row-row_start][col];
			 check_press=DIO_voidGetPinValue(PORTB_ID,row);
			while (check_press)
			{
				check_press=DIO_voidGetPinValue(PORTB_ID,row);
			}
			_delay_ms(50);
			return val;
			}
		}
		DIO_voidSetPinValue(PORTB_ID,col ,PIN_HIGH);  // return col again to low
	}

	return val;
}


void KeyPad_u8Calculator()
{
	u8 result,keypad_press ;
	u8 num1 ;
	u8 operator;
	u8 num2;
	u8 c=0 ;
	while (1){
				 keypad_press=KeyPad_u8GetPressedKey();
				if (keypad_press!=0xff)
				{  c++ ;
				if (c==4)
				{
					LCD_voidClear();
					switch (operator)
					{c=0 ;
					case (43):   result =num1+num2; LCD_voidDisplayNumber(result); break ; // +
					case (45):   result =num1-num2; LCD_voidDisplayNumber(result); break ; // -
					case (42):   result =num1*num2; LCD_voidDisplayNumber(result); break ; // *
					case (47):   result =num1/num2; LCD_voidDisplayNumber(result); break ; // /

					}

				}

					switch(keypad_press){
					case (43):  operator= keypad_press; LCD_voidWriteDATA(43);   break ; // +
					case (45):  operator= keypad_press; LCD_voidWriteDATA(45);   break ; // -
					case (42):  operator= keypad_press; LCD_voidWriteDATA(42);   break ; // *
					case (47):  operator= keypad_press; LCD_voidWriteDATA(47);   break ; // /
					case (61):  operator= keypad_press;                          break ; // =
					default :
						if (c==1){
						num1 = keypad_press;
						LCD_voidDisplayNumber(keypad_press);}
						else if (c==3){
							num2 =keypad_press;
							LCD_voidDisplayNumber(keypad_press);}

						break ;
					}


				}

				}

}
