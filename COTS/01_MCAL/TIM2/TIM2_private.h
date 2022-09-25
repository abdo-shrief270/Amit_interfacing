#ifndef  _MCAL_TIM0_PRIVATE_H_
    #define _MCAL_TIM0_PRIVATE_H_

//  TIM0 Registers
    #define TCNT2    (*(volatile u8*)0x44)
    #define TCCR2    (*(volatile u8*)0x43)
    #define TIFR     (*(volatile u8*)0x58)
    #define TIMASK   (*(volatile u8*)0x59)
    #define OCR2     (*(volatile u8*)0x43)
    #define SREG     (*(volatile u8*)0x5F)
    #define ASSR     *((volatile u8*)0x42)


 // PINS of ASSR   
	#define AS2  3


// PINS of TCCR2
	#define CS20  0
	#define CS21  1
	#define CS22  2
	#define WGM21 3
	#define COM20 4
	#define COM21 5
	#define WGM20 6
	#define FOC2  7



// PINS of TIMASK
	#define TOIE2 6
	#define OCIE2 7




// PINS Of SREG
	#define TOV2  6
	#define OCF2  7


#endif