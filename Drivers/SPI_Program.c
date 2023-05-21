#include"Std_Types.h"
#include"Macros.h"
#include"DIO_Private.h"
#include"DIO_Interface.h"
#include"DCMOTOR_Interface.h"
#include"EXTINT_Private.h"
#include"TR_Interface.h"
#include"UART_Private.h"
#include"UART_Interface.h"
#include"SPI_Private.h"
#include"SPI_Config.h"


void SPI_voidInialize(u8 Copy_u8ProtocaloType)
{
	//SPI Enable
	Set_bit(SPCR,6);
	//The LSB trasnmit first 
	Set_bit(SPCR,5);
	Clear_bit(SPCR,7);

	
	switch(Copy_u8ProtocaloType)
	{
		
		
		case Master: Set_bit(SPCR,4); break ;
		case Slave :Clear_bit(SPCR,4); break ;
	}
	
	//Clock Polarity
	Clear_bit(SPCR,3);
	Set_bit(SPCR,2);
	
	//SPI Clock Rate Select(div by 8)
	Set_bit(SPCR,0);
	Clear_bit(SPCR,1);
	Set_bit(SPSR,0);
	
}



u8 SPI_u8Transceiver(u8 Copy_u8Data)
{
	
	
	SPDR=Copy_u8Data ;
	
	while((Get_bit(SPSR,7))==0);
	
	return SPDR ;
}
