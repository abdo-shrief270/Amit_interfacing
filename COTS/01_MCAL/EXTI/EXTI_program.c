#include "TYPES.h"
#include "BIT_MATH.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"
#include "avr/interrupt.h"

void (* CBInt0)(void);
void (* CBInt1)(void);
void (* CBInt2)(void);


void EXTI_vidInit(_enuINT_PIN enuIntPinNum,_enuMODE_INT enuModeNum)
{
    DIO_vidWritePin(SREG,GI,HIGH);  
    DIO_vidSetPinMode(GICR,INT0,OUTPUT);  
    switch (enuIntPinNum)
    {
    case INT0_PIN:
        DIO_vidSetPinMode(MCUCR,ISC00,INPUT);  
        DIO_vidSetPinMode(MCUCR,ISC01,INPUT);  

        if(enuModeNum==LOW_LEVEL){
            CLR_BIT(MCUCR,ISC00);  
            CLR_BIT(MCUCR,ISC01);  
        }else if(enuModeNum==LOGICAL_CHANGE){

            SET_BIT(MCUCR,ISC00);  
            CLR_BIT(MCUCR,ISC01);  

        }else if(enuModeNum==FALLING_EDGE){

            CLR_BIT(MCUCR,ISC00);  
            SET_BIT(MCUCR,ISC01); 

        }else{

            SET_BIT(MCUCR,ISC00);  
            SET_BIT(MCUCR,ISC01);  

        }
        break;
    case INT1_PIN:

        DIO_vidSetPinMode(MCUCR,ISC10,INPUT);  
        DIO_vidSetPinMode(MCUCR,ISC11,INPUT);  

        if(enuModeNum==LOW_LEVEL){

            CLR_BIT(MCUCR,ISC10);  
            CLR_BIT(MCUCR,ISC11);  

        }else if(enuModeNum==LOGICAL_CHANGE){

            SET_BIT(MCUCR,ISC10);  
            CLR_BIT(MCUCR,ISC11);  

        }else if(enuModeNum==FALLING_EDGE){

            CLR_BIT(MCUCR,ISC10);  
            SET_BIT(MCUCR,ISC11);  

        }else{

            SET_BIT(MCUCR,ISC10);  
            SET_BIT(MCUCR,ISC11);  

        }
        break;
    case INT2_PIN:
        DIO_vidSetPinMode(MCUCSR,ISC2,INPUT);  

        if(enuModeNum==FALLING_EDGE){
            CLR_BIT(MCUCSR,ISC2);  
        }else{
            SET_BIT(MCUCSR,ISC2);  
        }
        break;
    default:
        break;
    }


}
void EXTI_vidSetCB(_enuINT_PIN enuIntPinNum,void (*CBFun)(void))
{
    switch (enuIntPinNum)
    {
    case INT0_PIN:
        CBInt0=CBFun;
        break;
    case INT1_PIN:
        CBInt1=CBFun;
        break;
    case INT2_PIN:
        CBInt2=CBFun;
        break;
    default:
        break;
    }
}
ISR(INT0_vect){
    (* CBInt0)();
}

ISR(INT1_vect){
    (* CBInt1)();
}

ISR(INT2_vect){
    (* CBInt2)();
}