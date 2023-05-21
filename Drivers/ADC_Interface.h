#ifndef  _ADC_INTERFACE_
#define  _ADC_INTERFACE_






                            // default i choose ADC0  // prescaler /64
void ADC_voidInit();
u16 ADC_u16GetResult();
void ADC_voidSingleRead();
void ADC_voidSelectChannel(u8 Copy_u8ChannelNUM);
void ADC_voidSelectPreScaler(u8 Copy_u8ClkDiv);


#endif
