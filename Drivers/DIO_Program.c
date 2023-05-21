#include"Std_Types.h"
#include"Macros.h"
#include"DIO_Private.h"
#include"DIO_Interface.h"
#include"DCMOTOR_Interface.h"
#include"EXTINT_Private.h"
#include"TR_Interface.h"


 void DIO_voidSetPinDirection(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8PinDir)
 {
	 if (Copy_u8PinDir==1)                                   //OUTPUT
	 {
	 switch (Copy_u8PortID)
	 {
		 
		 case (PORTA_ID):        Set_bit(DDRA_REG,Copy_u8PinID);        // Port A
		 break ;
		 case (PORTB_ID):        Set_bit(DDRB_REG,Copy_u8PinID);        //Port B
		 break ;
		 case (PORTC_ID):        Set_bit(DDRC_REG,Copy_u8PinID);        //Port C
		 break ;
		 case (PORTD_ID):        Set_bit(DDRD_REG,Copy_u8PinID);        //Port D
 		 break ;
		 
		
	 }
	 
	 }
	 else if (Copy_u8PinDir==0)                           //INPUT
	 {
		 switch (Copy_u8PortID)
	 {
		 
		 case (PORTA_ID):        Clear_bit(DDRA_REG,Copy_u8PinID);        // Port A
		 break ;
		 case (PORTB_ID):        Clear_bit(DDRB_REG,Copy_u8PinID);        //Port B
		 break ;
		 case (PORTC_ID):        Clear_bit(DDRC_REG,Copy_u8PinID);       //Port C
		 break ;
		 case (PORTD_ID):        Clear_bit(DDRD_REG,Copy_u8PinID);       //Port D
 		 break ;
		 
		
	 }
	 }
	 
 }
 
 void DIO_voidSetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8PinValue)
 {
	 
	  if (Copy_u8PinValue==1)                                   //OUTPUT
	 {
	 switch (Copy_u8PortID)
	 {
		 
		 case (PORTA_ID):        Set_bit(PORTA_REG,Copy_u8PinID);        // Port A
		 break ;
		 case (PORTB_ID):        Set_bit(PORTB_REG,Copy_u8PinID);        //Port B
		 break ;
		 case (PORTC_ID):        Set_bit(PORTC_REG,Copy_u8PinID);        //Port C
		 break ;
		 case (PORTD_ID):        Set_bit(PORTD_REG,Copy_u8PinID);        //Port D
 		 break ;
		 
		
	 }
	 
	 }
	 else if (Copy_u8PinValue==0)                           //INPUT
	 {
		 switch (Copy_u8PortID)
	 {
		 
		 case (PORTA_ID):        Clear_bit(PORTA_REG,Copy_u8PinID);        // Port A
		 break ;
		 case (PORTB_ID):        Clear_bit(PORTB_REG,Copy_u8PinID);        //Port B
		 break ;
		 case (PORTC_ID):        Clear_bit(PORTC_REG,Copy_u8PinID);       //Port C
		 break ;
		 case (PORTD_ID):        Clear_bit(PORTD_REG,Copy_u8PinID);       //Port D
 		 break ;
		 
		
	 }
	 }
	 
	 
	 
	 
 }

 void DIO_voidSetPortDirection(u8 Copy_u8PortID, u8 Copy_u8PortDir)
 {
 	switch(Copy_u8PortID)
 	{
 	case PORTA_ID: DDRA_REG= Copy_u8PortDir; break;
 	case PORTB_ID: DDRB_REG= Copy_u8PortDir; break;
 	case PORTC_ID: DDRC_REG= Copy_u8PortDir; break;
 	case PORTD_ID: DDRD_REG= Copy_u8PortDir; break;

 	}
 }
 void DIO_voidSetPortValue(u8 Copy_u8PortID, u8 Copy_u8PortValue)
 {
 	switch(Copy_u8PortID)
 		{
 		case PORTA_ID: PORTA_REG= Copy_u8PortValue; break;
 		case PORTB_ID: PORTB_REG= Copy_u8PortValue; break;
 		case PORTC_ID: PORTC_REG= Copy_u8PortValue; break;
 		case PORTD_ID: PORTD_REG= Copy_u8PortValue; break;

 		}

 }



u8 DIO_voidgetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID)
{


	u8 value ;


	switch(Copy_u8PortID)
	{


	case (PORTA_ID):value=Get_bit(PORTA_REG,Copy_u8PinID);
	break ;
	case (PORTB_ID):value=Get_bit(PORTB_REG,Copy_u8PinID);
	break ;
	case (PORTC_ID):value=Get_bit(PORTC_REG,Copy_u8PinID);
	break ;
	case (PORTD_ID) :value=Get_bit(PORTD_REG,Copy_u8PinID);
	break ;

	}
	return value ;

}

u8 DIO_voidGetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID)
{
	u8 value ;
	switch(Copy_u8PortID)


	{
	case (PORTA_ID) :  value=Get_bit(PINA_REG,Copy_u8PinID);break;
	case (PORTB_ID) :  value=Get_bit(PINB_REG,Copy_u8PinID);break;
	case (PORTC_ID) :  value=Get_bit(PINC_REG,Copy_u8PinID);break;
	case (PORTD_ID) :  value=Get_bit(PIND_REG,Copy_u8PinID);break;
	}
	return value ;
}

