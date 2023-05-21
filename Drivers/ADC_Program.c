#include"Std_Types.h"
#include"Macros.h"
#include"DIO_Private.h"
#include"DIO_Interface.h"
#include"DCMOTOR_Interface.h"
#include"EXTINT_Private.h"
#include "ADC_Private.h"
#include"ADC_Interface.h"
#include"ADC_Congif.h"




void ADC_voidInit()
{
	//AVCC with external capacitor at AREF pin
	Set_bit(ADMUX,6);
	Set_bit(ADMUX,7);

	//Right Adjust
	Clear_bit(ADMUX,5);

	// To choose ADC0 (select channel)
	Clear_bit(ADMUX,0);
	Clear_bit(ADMUX,1);
	Clear_bit(ADMUX,2);
	Clear_bit(ADMUX,3);
	Clear_bit(ADMUX,4);

	//Single Conversion
	Set_bit(ADCSRA,6);

	//Prescaler 
	Clear_bit(ADCSRA,0);
	Set_bit(ADCSRA,1);
	Set_bit(ADCSRA,2);

	//Enable ADC
	Set_bit(ADCSRA,7);

	//ADLAR=0
	Clear_bit(ADMUX,5);

}


u16 ADC_u16GetResult()
{
	return ADC ;


}

void ADC_voidSingleRead()
{
	//Single Conversion
	Set_bit(ADCSRA,6);
}

void ADC_voidSelectChannel(u8 Copy_u8ChannelNUM)
{
	switch(Copy_u8ChannelNUM)
	{
	case ADC0 :
		Clear_bit(ADMUX,0);
		Clear_bit(ADMUX,1);
		Clear_bit(ADMUX,2);
		Clear_bit(ADMUX,3);
		Clear_bit(ADMUX,4);
		break ;
	case ADC1 :
		Set_bit(ADMUX,0);
		Clear_bit(ADMUX,1);
		Clear_bit(ADMUX,2);
		Clear_bit(ADMUX,3);
		Clear_bit(ADMUX,4);
		break ;
	case ADC2 :
		Clear_bit(ADMUX,0);
		Set_bit(ADMUX,1);
		Clear_bit(ADMUX,2);
		Clear_bit(ADMUX,3);
		Clear_bit(ADMUX,4);
		break ;
	case ADC3 :
		Set_bit(ADMUX,0);
		Set_bit(ADMUX,1);
		Clear_bit(ADMUX,2);
		Clear_bit(ADMUX,3);
		Clear_bit(ADMUX,4);
		break ;
	case ADC4 :
		Clear_bit(ADMUX,0);
		Clear_bit(ADMUX,1);
		Set_bit(ADMUX,2);
		Clear_bit(ADMUX,3);
		Clear_bit(ADMUX,4);
		break ;
	case ADC5 :
		Set_bit(ADMUX,0);
		Clear_bit(ADMUX,1);
		Set_bit(ADMUX,2);
		Clear_bit(ADMUX,3);
		Clear_bit(ADMUX,4);
		break ;
	case ADC6 :
		Clear_bit(ADMUX,0);
		Set_bit(ADMUX,1);
		Set_bit(ADMUX,2);
		Clear_bit(ADMUX,3);
		Clear_bit(ADMUX,4);
		break ;
	case ADC7 :
		Set_bit(ADMUX,0);
		Set_bit(ADMUX,1);
		Set_bit(ADMUX,2);
		Clear_bit(ADMUX,3);
		Clear_bit(ADMUX,4);
		break ;


    }


}


void ADC_voidSelectPreScaler(u8 Copy_u8ClkDiv)
{
	switch(Copy_u8ClkDiv)
	{


	case(Div2) :

	Clear_bit(ADCSRA,0);
	Clear_bit(ADCSRA,1);
	Clear_bit(ADCSRA,2);
	break ;

	case(Div4) :

	Clear_bit(ADCSRA,0);
	Set_bit(ADCSRA,1);
	Clear_bit(ADCSRA,2);
	break ;

	case(Div8) :

	Set_bit(ADCSRA,0);
	Set_bit(ADCSRA,1);
	Clear_bit(ADCSRA,2);
	break ;

	case(Div16) :

	Clear_bit(ADCSRA,0);
	Clear_bit(ADCSRA,1);
	Set_bit(ADCSRA,2);
	break ;

	case(Div32) :

	Set_bit(ADCSRA,0);
	Clear_bit(ADCSRA,1);
	Set_bit(ADCSRA,2);
	break ;

	case(Div64) :

	Clear_bit(ADCSRA,0);
	Set_bit(ADCSRA,1);
	Set_bit(ADCSRA,2);
	break ;

	case(Div128) :

	Set_bit(ADCSRA,0);
	Set_bit(ADCSRA,1);
	Set_bit(ADCSRA,2);
	break ;

	}





}
