#ifndef  _DIO_INTERFACE_H
#define  _DIO_INTERFACE_H


/* Port Macros */
#define PORTA_ID (0X00)
#define PORTB_ID (0X01)
#define PORTC_ID (0X02)
#define PORTD_ID (0X03)


/* pin ID Macros */

#define PIN0_ID (0x00)
#define PIN1_ID (0x01)
#define PIN2_ID (0x02)
#define PIN3_ID (0x03)
#define PIN4_ID (0x04)
#define PIN5_ID (0x05)
#define PIN6_ID (0x06)
#define PIN7_ID (0x07)


/* Direction Macros */

#define PIN_OUTPUT_ID (0x01)
#define PIN_INPUT_ID  (0x00)


/*Set values */
#define PIN_HIGH (0x01)
#define PIN_LOW  (0x00)



void DIO_voidSetPinDirection(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8PinDir);
void DIO_voidSetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8PinValue);
void DIO_voidSetPortDirection(u8 Copy_u8PortID,u8 Copy_u8PortDir);
void DIO_voidSetPortValue(u8 Copy_u8PortID,u8 Copy_u8PinValue);
u8 DIO_voidgetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID);
u8 DIO_voidGetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID);


#endif
