#include "TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "TIM2_interface.h"
#include "TIM2_private.h"
#include "TIM2_config.h"
#include "avr/interrupt.h"


u8 flag1=0;
u8 flag2=0;
u8 TOV_counter=0;

void (*CBTOV)(void);
void (*CBCTC)(void);


void TIM2_vidInit(void){

    SET_BIT(SREG,7);

    // Set timer mode

    #if TIM2_MODE == 0
        CLR_BIT(TCCR2,WGM20);
        CLR_BIT(TCCR2,WGM21);
    #elif TIM2_MODE == 1
        SET_BIT(TCCR2,WGM20);
        CLR_BIT(TCCR2,WGM21);
    #elif TIM2_MODE == 2 || TIM2_MODE == 4
        CLR_BIT(TCCR2,WGM20);
        SET_BIT(TCCR2,WGM21);
    #elif TIM2_MODE == 3
        SET_BIT(TCCR2,WGM20);
        SET_BIT(TCCR2,WGM21);
    #endif

    // Adjust PWM Mode


    TCCR2 &= 0xCF;
	#if    TIM2_COM_NONPWM  != 0x00
		TCCR2 |= TIM2_COM_NONPWM ;
	#elif  TIM2_COM_FASTPWM != 0x00
		TCCR2 |= TIM2_COM_FASTPWM ;
	#elif  TIM2_COM_PCPWM   != 0x00
		TCCR2 |= TIM2_COM_PCPWM ;
	#endif


    #if  TIM2_FOC2 == 0
		CLR_BIT(TCCR2, FOC2); // Disable FOC2
	#else
		SET_BIT(TCCR2, FOC2); // Enable FOC2
	#endif


	#if  TIM2_TOVINTERRUPT == 0
		CLR_BIT(TIMASK, TOIE2); // Disable TOV Interrupt
	#else
		SET_BIT(TIMASK, TOIE2); // Enable TOV Interrupt
	#endif



	#if  TIM2_TOCINTERRUPT == 0
		CLR_BIT(TIMASK, OCIE2); // Disable OCF Interrupt
	#else
		SET_BIT(TIMASK, OCIE2);    // Enable OCF Interrupt
	#endif

    #if  TMR2_TRCCTRL ==0
		CLR_BIT(ASSR, AS2); // Disable RTC
	#else 
		SET_BIT(ASSR, AS2); // Enable RTC
	#endif

}


void  TIM2_vidStart(u8 u8Prescaler){

    flag1=0;
    flag2=0;
    TOV_counter=0;
	TCCR2 &= 0xF8;
	TCCR2 |=u8Prescaler;
}


void  TIM2_vidSetTCNT2(u8 u8InitValue){

    TCNT2=u8InitValue;

}


u32   TIM2_u32ReadTIM2(void){

    u32 Return_Val;
	Return_Val = (TOV_counter * 256)+ TCNT2;
	return Return_Val;

}


void  TIM2_vidSetNormalWithInterrupt(void (*CB)(void)){

    if(CB != 0)
	{
		flag1 =1;
		CBTOV = CB;
	}

}


void  TIM2_vidSetOCR2(u8 u8InitValue){

    OCR2=u8InitValue;

}


void  TIM2_vidSetCTCWithInterrupt(void (*CB)(void)){

    if(CB != 0)
	{
		flag2 =1;
		CBCTC = CB;
	}

}


void  TIM2_vidStopTIM2(void){


    TCCR2 &= 0xF8;


}


void  TIM2_vidDInit(void){

    TCCR2=0x00;

}


void TIM2_GenerateFastPWM(u8 u8DutyCycle){

    DIO_vidSetPinMode(GPIOD,PIN7,OUTPUT);

    volatile u8 u8OCRValue;
    #if TIM2_COM_FASTPWM == 0x20
        u8OCRValue  = (u8DutyCycle  *   256) /   100;
        TIM2_vidSetOCR2(u8OCRValue);
    #elif TIM2_COM_FASTPWM == 0x30
        u8OCRValue  = 255 - ((u8DutyCycle   *   256)  /   100);
        TIM2_vidSetOCR2(u8OCRValue);
    #endif

}


void TIM2_GeneratePhaseCorrectPWM(u8 u8DutyCycle){

    DIO_vidSetPinMode(GPIOD,PIN3,OUTPUT);

    volatile u8 u8OCRValue;

    #if TIM2_COM_PCPWM == 0x20
        u8OCRValue  = (u8DutyCycle  * 255) /   100;
        TIM2_vidSetOCR2(u8OCRValue);
    #elif TIM2_COM_PCPWM == 0x30
        u8OCRValue  = 255 - ((u8DutyCycle   *   255)  /   100);
        TIM2_vidSetOCR2(u8OCRValue);
    #endif
}

ISR(TIMER2_OVF_vect)
{
	TOV_counter++;
	if(flag1 !=0)
	{
		(*CBTOV)();
	}
}

ISR(TIMER2_COMP_vect)
{
    if(flag2 !=0)
	{
	    (*CBCTC)();
    }
	SET_BIT(TIFR,OCF2);
}