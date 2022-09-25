#ifndef  _MCAL_TIM0_PRIVATE_H_
    #define _MCAL_TIM0_PRIVATE_H_

//  TIM0 Registers
    #define TCNT0    (*(volatile u8*)0x52)
    #define TCCR0    (*(volatile u8*)0x53)
    #define TIFR     (*(volatile u8*)0x58)
    #define TIMASK   (*(volatile u8*)0x59)
    #define OCR0     (*(volatile u8*)0x5C)
    #define SREG     (*(volatile u8*)0x5F)



// PINS of TCCR0
    #define CS00  0
	#define CS01  1
	#define CS02  2
	#define WGM01 3
	#define COM00 4
	#define COM01 5
	#define WGM00 6
	#define FOC0  7



// PINS of TIMASK
    #define TOIE0 0
	#define OCIE0 1




// PINS Of SREG
    #define TOV0  0
	#define OCF0  1


#endif