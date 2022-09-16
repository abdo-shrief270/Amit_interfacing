#ifndef _MCAL_EXTI_INTERFACE_H_
#define _MCAL_EXTI_INTERFACE_H_

typedef enum {
    INT0_PIN=0,
    INT1_PIN,
    INT2_PIN
} _enuINT_PIN;

typedef enum {
    LOW_LEVEL=0,
    LOGICAL_CHANGE,
    FALLING_EDGE,
    RISING_EDGE
} _enuMODE_INT;

void EXTI_vidInit(_enuINT_PIN enuIntPinNum,_enuMODE_INT enuModeNum);
void EXTI_vidSetCB(_enuINT_PIN enuIntPinNum,void (*CBFun)(void));

#endif