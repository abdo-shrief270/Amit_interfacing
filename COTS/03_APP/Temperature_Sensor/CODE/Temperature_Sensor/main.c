/*
 * Temperature_Sensor.c
 *
 * Created: 9/23/2022 4:08:36 PM
 * Author : AbdelRaHmaN ShRieF
 */ 

#include "TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "ADC_interface.h"
#include "LM35_interface.h"

#define F_CPU 8000000
#include "util/delay.h"

int main(void)
{
	LCD_vidInit();
	ADC_vidInit(ADC_CHANNEL4);
	u8 tempVal;
    while (1) 
    {
		LCD_vidSendCmd(LCD_CLEAR_SCREEN);
		tempVal = LM35_u8LM35Read();
		LCD_vidSendNumber(tempVal);
		LCD_vidSendString(" C");
		LCD_vidSendChar((char)223);
		while(LM35_u8LM35Read()==tempVal);
    }
}

