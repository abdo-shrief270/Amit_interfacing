#include "TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"




// This Function Used to Init ADC
void ADC_vidInit(_enuADCChannelNum enuADCChannelNum)
{
    // 1- Make Channel selected I/p 
    DIO_vidSetPinMode(DDRA,enuADCChannelNum,INPUT);

    // 2- Select Conversion Speed of ADC
    ADCSRA &=0xF8;
    #if ADC_PRESCALER == 2
        ADCSRA |=0x02;
    #elif ADC_PRESCALER == 3
        ADCSRA |=0x03;
    #elif ADC_PRESCALER == 4
        ADCSRA |=0x04;
    #elif ADC_PRESCALER == 5
        ADCSRA |=0x05;
    #elif ADC_PRESCALER == 6
        ADCSRA |=0x06;
    #elif ADC_PRESCALER == 7
        ADCSRA |=0x07;
    #endif


    // 3- Select Voltage reference for ADC 
    ADMUX &=0x3F;
    #if ADC_VOLT_REF == 1
        SET_BIT(ADMUX,REFS0);
        CLR_BIT(ADMUX,REFS1);
    #elif ADC_VOLT_REF ==3
        SET_BIT(ADMUX,REFS0);
        SET_BIT(ADMUX,REFS1);

    #endif



    // 4- Select Type of Storing of the output

    #if ADC_STORE_MODE ==0
        CLR_BIT(ADMUX,ADLAR);
    #elif ADC_STORE_MODE==1
        SET_BIT(ADMUX,ADLAR);
    #endif
       


    // 5- Turn on ADC

    SET_BIT(ADCSRA,ADEN);

}



// This Function to read a value from ADC
u16 ADC_u16Read(void)
{
    u16 u16ReturnValue;
    // 1- Activate Start of Conversion 

     SET_BIT(ADCSRA,ADSC);
    // 2- Wait until conversion Ended
    while (GET_BIT(ADCSRA,ADIF)==0);
    
    // 3- Clear Interrupt Flag after Ended 

    SET_BIT(ADCSRA,ADIF);
    // 4- Read ADCL then ADCH in order 
    u16ReturnValue  = ADCL;
    u16ReturnValue |= (u16) (ADCH<<8);
    return u16ReturnValue;
}