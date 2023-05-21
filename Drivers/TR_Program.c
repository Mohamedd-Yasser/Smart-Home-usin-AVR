#include"Std_Types.h"
#include"Macros.h"
#include"DIO_Private.h"
#include"DIO_Interface.h"
#include"DCMOTOR_Interface.h"
#include"EXTINT_Private.h"
#include"TR_Private.h"
#include"TR_Interface.h"
#include"TR_Config.h"

void (*GPTF_TR2)(void)='\0';
void (*GPTF_TR1)(void)='\0';

void TR0_voidTR0Normal_Init()
{
	//Normal Mode
	Clear_bit(TCCR0,3);
	Clear_bit(TCCR0,6);
	
	//Prescaler
	Clear_bit(TCCR0,0);
	Set_bit(TCCR0,1);
	Clear_bit(TCCR0,2);
	
	//Over flow interupt enable
	Set_bit(TIMSK,0);
	
}


void TR0_voidTR0Normal_Preload(u8 Copy_u8Value)

{
	
	TCNT0=Copy_u8Value;
	
}



void TR0_voidTR0CTC_Init()
{
	//CTC Mode(toggleOCOPB3)
	Set_bit(TCCR0,3);
	Clear_bit(TCCR0,6);
	
	//Pre-scaler
	Clear_bit(TCCR0,0);
	Set_bit(TCCR0,1);
	Clear_bit(TCCR0,2);
	
	//Compare Match Interrupt Enable
	Set_bit(TIMSK,1);
	
	
}


void TR0_voidTR0CTC_Preload(u8 Copy_u8StartCount)
{
 //Number in which the overflow occur at
 OCR0=Copy_u8StartCount;
	
}
void TR0_voidTR0FastPwm_Init()
{

	//PWM Mode
	Set_bit(TCCR0,3);
	Set_bit(TCCR0,6);


	//Non-inverting mode
	Clear_bit(TCCR0,4);
	Set_bit(TCCR0,5);


    //Pre-scaler
	Clear_bit(TCCR0,0);
	Set_bit(TCCR0,1);
	Clear_bit(TCCR0,2);



}

void TR0_voidTR0FastPwm_Preload(u8 Copy_u8Value)
{

	OCR0=Copy_u8Value;
}

u8 TR0__u8Return_TCNT()
{
	return TCNT0 ;
}


//Timer1
void TR1_voidTR1Normal_Init()
{
	// Clear OC1A/OC1B on compare match, set OC1A/OC1B at BOTTOM,(non-inverting mode)

	/*Clear_bit(TCCR1A,7);
	Clear_bit(TCCR1A,6);
	Clear_bit(TCCR1A,5);
	Clear_bit(TCCR1A,4);*/


	//Normal Mode
	Clear_bit(TCCR1A,0);
	Clear_bit(TCCR1A,1);
	Clear_bit(TCCR1B,3);
	Clear_bit(TCCR1B,4);


	//prescaler
	Clear_bit(TCCR1B,0);
	Set_bit(TCCR1B,1);
    Clear_bit(TCCR1B,2);
}

void TR1_voidTR1_Preload(u8 Copy_u8OCR1AValue)
{
	TCNT1=Copy_u8OCR1AValue;
}



void TR1_voidTR1FastPwmICR1_Init()
{
	// Clear OC1A/OC1B on compare match, set OC1A/OC1B at BOTTOM,(non-inverting mode)

	Set_bit(TCCR1A,7);
	Clear_bit(TCCR1A,6);
	Set_bit(TCCR1A,5);
	Clear_bit(TCCR1A,4);


	//Fast PWM
	Clear_bit(TCCR1A,0);
	Set_bit(TCCR1A,1);
	Set_bit(TCCR1B,3);
	Set_bit(TCCR1B,4);


	//prescaler
	Clear_bit(TCCR1B,0);
	Set_bit(TCCR1B,1);
    Clear_bit(TCCR1B,2);


}

void TR1_voidTR1FastPwmICR1_Preload(u16 Copy_u8OCR1AValue)
{
	ICR1=20000;
	OCR1A=Copy_u8OCR1AValue;
}

void TR1_voidTR1FastPwmICR1OCR1B_Preload(u16 Copy_u8OCR1AValue)
{
	ICR1=20000;
	OCR1B=Copy_u8OCR1AValue;

}
void TR1_voidServo_GetAngle(u8 Copy_u8Angle)
{
	u32 timer ;
	f32 slope ;

	 TR1_voidTR1Normal_Init();
	/* the below equation : range value from the stepper to go from 0 to 180  is from 999 to 1999 by trails
		and the range of angles from  Servo is from 0 to 180 then make equation of straight line and that will appear*/
	slope=50.0/9 ;
	timer=slope*Copy_u8Angle+999 ;
	TR1_voidTR1_Preload(timer);

}


void TR1_voidTR1ICU_Init()
{
	//Set_bit(TCCR1B,6);

	//Timer/Counter1, Input Capture Interrupt Enable
	Set_bit(TIMSK,5);

}

u16 TR1_u16TR1ICU_ReturnICR1()
{
	return ICR1 ;
}


void TR1_u8TR1ICU_ReturnTCCR1B(u8 Copy_u8Value)
{
	 switch(Copy_u8Value)
	 {

	 case(Rising):Set_bit(TCCR1B,6);break ;
	 case(Failling):Set_bit(TCCR1B,6);break ;
	 }
}


//Timer2
void TR2_voidTR2Normal_Init()
{
	//Normal Mode
	Clear_bit(TCCR2,3);
	Clear_bit(TCCR2,6);

	//Prescaler
	Clear_bit(TCCR2,0);
	Set_bit(TCCR2,1);
	Clear_bit(TCCR2,2);

	//Timer/Counter2 Overflow Interrupt Enable
	Set_bit(TIMSK,6);
}

void TR2_voidTR2Normal_Preload(u8 Copy_u8Value)
{

	TCNT2=Copy_u8Value ;
}

void TR2_voidTR2CTC_Init()

{
	//Normal Mode
	Clear_bit(TCCR2,6);
	Set_bit(TCCR2,3);

	//Prescaler
	Clear_bit(TCCR2,0);
	Set_bit(TCCR2,1);
	Clear_bit(TCCR2,2);

	//Timer/Counter2 Output Compare Match Interrupt Enable
	Set_bit(TIMSK,7);

}

void TR2_voidTR2CTC_Preload(u8 Copy_u8StartCount)
{
 //Number in which the overflow occur at
	OCR2=Copy_u8StartCount;

}

void TR2_voidTR2FastPwm_Init()
{
	//PWM Mode
	Set_bit(TCCR2,3);
	Set_bit(TCCR2,6);


	//Non-inverting mode
	Clear_bit(TCCR2,4);
	Set_bit(TCCR2,5);


	//Pre-scaler
	Clear_bit(TCCR2,0);
	Set_bit(TCCR2,1);
	Clear_bit(TCCR2,2);


}
void TR2_voidTR2FastPwm_Preload(u8 Copy_u8Value)
{
	OCR2=Copy_u8Value;

}


void TR2_voidTR2PhaseCorrect_Init()
{
	//Phase Correct  Mode
	Set_bit(TCCR2,6);
	Clear_bit(TCCR2,3);


    //Non-inverting mode
	Clear_bit(TCCR2,4);
	Set_bit(TCCR2,5);


	//Pre-scaler
	Clear_bit(TCCR2,0);
	Set_bit(TCCR2,1);
	Clear_bit(TCCR2,2);

}

void TR2_voidTR2PhaseCorrect_Preload(u8 Copy_u8Value)
{
	OCR2=Copy_u8Value;
}


//Watch Dog
void WD_voidWDF_Enable()
{
	Set_bit(WDTCR,3);

}
void WD_voidWDF_Sleep()
{
	//16.3ms
	Clear_bit(WDTCR,3);
	Clear_bit(WDTCR,3);
	Clear_bit(WDTCR,3);
}

void WD_voidWDF_Disable()
{
WDTCR=(1<<4)|(1<<3);
}






//Timer 0 Compare
void __vector_10()__attribute__((signal));
void __vector_10()
{
	u16 static TR_Count=0 ;
	if (TR_Count==3907)
	{
		TR_Count=0 ;
		Toggle_bit(PORTA_REG,PIN0_ID);  
	}	
	else
	{
		TR_Count ++ ;
	}	
		
	
}

//Timer 0 Overflow
void __vector_11()__attribute__((signal));
void __vector_11()
{
	u16 static TR_Count=0 ;

	if (TR_Count==3907)
	{
		TR_Count=0;
		Toggle_bit(PORTA_REG,PIN0_ID);  
	}	
	else
	{
		TR_Count ++ ;
	}	
		
	
}


//Timer1 ICU
void TR1_ICUSetCallBack(void(*ptr)(void))
{

	GPTF_TR1=ptr;
}
void __vector_6()__attribute__((signal));
void __vector_6()
{

	if (GPTF_TR1!='\0')
	{
		GPTF_TR1();
	}

}



//Timer 2 overflow
void TR2_OFSetCallBack(void(*ptr)(void))
{

	GPTF_TR2=ptr;
}

void __vector_5()__attribute__((signal));
void __vector_5()
{

	if (GPTF_TR2!='\0')
	{
		GPTF_TR2();
	}

}

//Timer 2 CTC

void TR2_CTCSetCallBack(void(*ptr)(void))
{

	GPTF_TR2=ptr;
}

void __vector_4()__attribute__((signal));
void __vector_4()
{

	if (GPTF_TR2!='\0')
	{
		GPTF_TR2();
	}

}

