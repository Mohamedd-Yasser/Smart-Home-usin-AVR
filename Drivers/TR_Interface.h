#ifndef  TR_INTERFACE
#define  TR_INTERFACE


//Timer0
void TR0_voidTR0Normal_Init();
void TR0_voidTR0Normal_Preload(u8 Copy_u8Value);
void TR0_voidTR0CTC_Init();
void TR0_voidTR0CTC_Preload(u8 Copy_u8StartCount);
void TR0_voidTR0FastPwm_Init();
void TR0_voidTR0FastPwm_Preload(u8 Copy_u8Value);
u8 TR0__u8Return_TCNT();


//Timer1(Used for Servo Motor)
void TR1_voidTR1Normal_Init();
void TR1_voidTR1_Preload(u8 Copy_u8OCR1AValue);
void TR1_voidTR1FastPwmICR1_Init();
void TR1_voidTR1FastPwmICR1_Preload(u16 Copy_u8OCR1AValue);
void TR1_voidTR1FastPwmICR1OCR1B_Preload(u16 Copy_u8OCR1AValue);

void TR1_voidServo_GetAngle(u8 Copy_u8Angle);
//Hardware way to measure pwm
void TR1_voidTR1ICU_Init();
u16 TR1_u16TR1ICU_ReturnICR1();
void TR1_u8TR1ICU_ReturnTCCR1B(u8 Copy_u8Value);
void TR1_ICUSetCallBack(void(*ptr)(void));



//Timer2
void TR2_voidTR2Normal_Init();
void TR2_voidTR2Normal_Preload(u8 Copy_u8Value);
void TR2_voidTR2CTC_Init();
void TR2_voidTR2CTC_Preload(u8 Copy_u8StartCount);
void TR2_voidTR2FastPwm_Init();
void TR2_voidTR2FastPwm_Preload(u8 Copy_u8Value);
void TR2_voidTR2PhaseCorrect_Init();
void TR2_voidTR2PhaseCorrect_Preload(u8 Copy_u8Value);
void TR2_OFSetCallBack(void(*ptr)(void));
void TR2_CTCSetCallBack(void(*ptr)(void));


//WatchDog
void WD_voidWDF_Enable();
void WD_voidWDF_Disable();




#endif
