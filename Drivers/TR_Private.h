#ifndef  _TR_CONFIG_
#define  _TR_CONFIG_

//Timer0
#define TCCR0  *((volatile u8*) 0x53)
#define TIMSK  *((volatile u8*) 0x59)
#define TCNT0  *((volatile u8*) 0x52)
#define TIFR   *((volatile u8*) 0x58)
#define OCR0   *((volatile u8*) 0x5C)


//Timer1
#define TCCR1A   *((volatile u8*) 0x4f)
#define TCCR1B   *((volatile u8*) 0x4E)
#define ICR1H    *((volatile u8*) 0x47)
#define ICR1L    *((volatile u8*) 0x46)
#define ICR1     *((volatile u16*) 0x46)
#define OCR1AH   *((volatile u8*) 0x4B)
#define OCR1AL   *((volatile u8*) 0x4A)
#define OCR1A    *((volatile u16*) 0x4A)
#define OCR1BH   *((volatile u8*) 0x49)
#define OCR1BL   *((volatile u8*) 0x48)
#define OCR1B    *((volatile u16*) 0x48)
#define ICR1H    *((volatile u8*) 0x47)
#define ICR1L    *((volatile u8*) 0x46)
#define ICR1     *((volatile u16*) 0x46)
#define TCNT1H   *((volatile u8*) 0x47)
#define TCNT1L   *((volatile u8*) 0x47)
#define TCNT1    *((volatile u16*) 0x47)






//Timer 2
#define TCCR2   *((volatile u8*) 0x45)
#define TCNT2   *((volatile u8*) 0x44)
#define OCR2    *((volatile u8*) 0x43)



//WatchDog
#define WDTCR   *((volatile u8*) 0x41)
#define TCCR2   *((volatile u8*) 0x45)
#define TCCR2   *((volatile u8*) 0x45)










#endif 
