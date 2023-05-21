#include"Std_Types.h"
#include"Macros.h"
#include"DIO_Private.h"
#include"DIO_Interface.h"
#include"DCMOTOR_Interface.h"
#include"EXTINT_Private.h"
#include"TR_Interface.h"
#include"UART_Private.h"
#include <util/delay.h>
#include"UART_Interface.h"





void UART_voidInialize()
{
	u8 Copy_u8Value=0b00000000;

	//Enable Tx and Rx 
	Set_bit(UCSRB,3);
	Set_bit(UCSRB,4);
	
	//Register Enable
	Set_bit(Copy_u8Value,7);
	//Asychronus
	Clear_bit(Copy_u8Value,6);
	//No parity
	Clear_bit(Copy_u8Value,4);
	Clear_bit(Copy_u8Value,5);
	//Number of stop bits
	Clear_bit(Copy_u8Value,3);
	//Character size (the third bit is 0 by default)
	Set_bit(Copy_u8Value,1);
	Set_bit(Copy_u8Value,2);
	UCSRC_UBRRH=Copy_u8Value;
//	UCSRC_UBRRH=0b10000110;
	
	//To set BaudRate
	//Clear_bit(UCSRC_UBRRH,7);
	UBRRL=51 ; 
	
	
}


void UART_SendData(u8 Copy_u8Value)
{
	
	UDR=Copy_u8Value;
	while ((Get_bit(UCSRA,5))==0);
	Set_bit(UCSRA,5);
	
	
}


u8 UART_ReceiveData()
{
	while ((Get_bit(UCSRA,7))==0);
	Set_bit(UCSRA,7);
	return UDR ;
}

void UART_SendNumber(u16 Copy_u8Value)
{

	u8 count=0 ;
	u16 arr[20]={0};
	for (u8 i=0;Copy_u8Value!=0;i++)
	{

		arr[i]=Copy_u8Value%10 ;
		Copy_u8Value=Copy_u8Value/10 ;
		count ++ ;
	}
	for (u8 i=count-1;i>=0;i--)
	{

		UART_SendData(arr[i]+48);
		_delay_ms(10);
	}

}
