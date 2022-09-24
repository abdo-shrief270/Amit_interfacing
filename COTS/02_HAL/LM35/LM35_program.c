#include "TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "LM35_interface.h"
#include "LM35_private.h"
#include "LM35_config.h"

void LM35_vidInit(_enuADCChannelNum enuChannelNum)
{
    ADC_vidInit(enuChannelNum);
}


u8 LM35_vidLM35Read(void)
{

    u8 temp;
    temp = (ADC_u16Read()*ADC_Vref)/(10240);
    return temp;
    
}