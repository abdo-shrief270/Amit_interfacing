#ifndef _MCAL_ADC_INTERFACE_H_
#define _MCAL_ADC_INTERFACE_H_

// This enum used for the ADC PINS
typedef enum
{
    ADC0 =0,
    ADC1 =1,
    ADC2 =2,
    ADC3 =3,
    ADC4 =4,
    ADC5 =5,
    ADC6 =6,
    ADC7 =7
} _enuChannelNum;

// This Function Used to Init ADC
void ADC_vidInit(_enuChannelNum enuChannelNum);

#endif