#include "TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "TIM0_interface.h"
#include "TIM0_private.h"
#include "TIM0_config.h"
#include "avr/interrupt.h"

u8 flag1=0;
u8 flag2=0;
u8 TOV_counter=0;

void (*CBCTC)(void);
void (*CBTOV)(void);


void TIM0_vidInit(void){

    SET_BIT(SREG,7);

    // Set timer mode

    #if TIM0_MODE == 0
        CLR_BIT(TCCR0,WGM00);
        CLR_BIT(TCCR0,WGM01);
    #elif TIM0_MODE == 1
        SET_BIT(TCCR0,WGM00);
        CLR_BIT(TCCR0,WGM01);
    #elif TIM0_MODE == 2 || TIM0_MODE == 4
        CLR_BIT(TCCR0,WGM00);
        SET_BIT(TCCR0,WGM01);
    #elif TIM0_MODE == 3
        SET_BIT(TCCR0,WGM00);
        SET_BIT(TCCR0,WGM01);
    #endif

    // Adjust PWM Mode


    TCCR0 &= 0xCF;
	#if    TIM0_COM_NONPWM  != 0x00
		TCCR0 |= TIM0_COM_NONPWM ;
	#elif  TIM0_COM_FASTPWM != 0x00
		TCCR0 |= TIM0_COM_FASTPWM ;
	#elif  TIM0_COM_PCPWM   != 0x00
		TCCR0 |= TIM0_COM_PCPWM ;
	#endif


    #if  TIM0_FOC0 == 0
		CLR_BIT(TCCR0, FOC0); // Disable FOC0
	#else
		SET_BIT(TCCR0, FOC0); // Enable FOC0
	#endif


	#if  TIM0_TOVINTERRUPT == 0
		CLR_BIT(TIMASK, TOIE0); // Disable TOV Interrupt
	#else
		SET_BIT(TIMASK, TOIE0); // Enable TOV Interrupt
	#endif



	#if  TIM0_TOCINTERRUPT == 0
		CLR_BIT(TIMASK, OCIE0); // Disable OCF Interrupt
	#else
		SET_BIT(TIMASK, OCIE0);    // Enable OCF Interrupt
	#endif


}


void  TIM0_vidStart(u8 u8Prescaler){

    flag1=0;
    flag2=0;
    TOV_counter=0;
	TCCR0 &= 0xF8;
	TCCR0 |=u8Prescaler;
}


void  TIM0_vidSetTCNT0(u8 u8InitValue){

    TCNT0=u8InitValue;

}


u32   TIM0_u32ReadTIM0(void){

    u32 Return_Val;
	Return_Val = (TOV_counter * 256)+ TCNT0;
	return Return_Val;

}


void  TIM0_vidSetNormalWithInterrupt(void (*CB)(void)){

    if(CB != 0)
	{
		flag1 =1;
		CBTOV = CB;
	}

}


void  TIM0_vidSetOCR0(u8 u8InitValue){

    OCR0=u8InitValue;

}


void  TIM0_vidSetCTCWithInterrupt(void (*CB)(void)){

    if(CB != 0)
	{
		flag2 =1;
		CBCTC = CB;
	}

}


void  TIM0_vidStopTIM0(void){


    TCCR0 &= 0xF8;


}


void  TIM0_vidDInit(void){

    TCCR0=0x00;

}


void TIM0_GenerateFastPWM(u8 u8DutyCycle){

    DIO_vidSetPinMode(GPIOD,PIN3,OUTPUT);

    volatile u8 u8OCRValue;
    #if TIM0_COM_FASTPWM == 0x20
        u8OCRValue  = (u8DutyCycle*256)/100;
        TIM0_vidSetOCR0(u8OCRValue);
    #elif TIM0_COM_FASTPWM == 0x30
        u8OCRValue  = 255 - ((u8DutyCycle*256)/100);
        TIM0_vidSetOCR0(u8OCRValue);
    #endif

}


void TIM0_GeneratePhaseCorrectPWM(u8 u8DutyCycle){

    DIO_vidSetPinMode(GPIOD,PIN3,OUTPUT);

    volatile u8 u8OCRValue;

    #if TIM0_COM_PCPWM == 0x20
        u8OCRValue  = (u8DutyCycle*255)/100;
        TIM0_vidSetOCR0(u8OCRValue);
    #elif TIM0_COM_PCPWM == 0x30
        u8OCRValue  = 255 - ((u8DutyCycle*255)/100);
        TIM0_vidSetOCR0(u8OCRValue);
    #endif
}

ISR(TIMER0_OVF_vect)
{
	TOV_counter++;
	if(flag1 !=0)
	{
		(*CBTOV)();
	}
}

ISR(TIMER0_COMP_vect)
{
    if(flag2 !=0)
	{
	    (*CBCTC)();
    }
	SET_BIT(TIFR,OCF0);
}