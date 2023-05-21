#ifndef _LCD_INTERFACE_H
#define _LCD_INTERFACE_H

#define CLR_LCD 0x01


#define LCD_CONT  PORTD_ID
#define LCD_OUT    PORTC_ID
#define ALL_OUTPUT 0b11111111



#define SEND    0b00111000
#define DISPLAY  0b00001100
#define CLEAR    0b00000001

#define Led_Port PORTA_ID




void LCD_voidInit(void);
void LCD_voidWriteCommand(u8 Copy_u8Command);
void LCD_voidWriteDATA(u8 Copy_u8DATA);
void LCD_GoToXY(u8 X, u8 Y);
void LCD_voidWriteSting(u8 *Copy_u8string);
void LCD_voidDisplayNumber(u32 Copy_u8DATA);
void LCD_voidWriteSpecialCharacter(u32 Copy_u32arr[8]);
void LCD_voidClear();
void LCD_WriteStringXY(u8 *str, u8 Copy_u8X, u8 Copy_u8Y);


#endif
