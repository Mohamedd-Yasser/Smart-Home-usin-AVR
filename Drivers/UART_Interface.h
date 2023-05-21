#ifndef  UART_INTERFACE
#define  UART_INTERFACE


void UART_voidInialize();
void UART_SendData(u8 Copy_u8Value);
void UART_SendNumber(u16 Copy_u8Value);
u8 UART_ReceiveData();

#endif
