#ifndef _HAL_LCD_CONFIG_H_
#define _HAL_LCD_CONFIG_H_


/*
    This Macro used to define the Mode number of LCD 
    0 for 4-BIT mode ,  1 for 8-BIT mode
*/
#define LCD_Mode            0

/*
    This Macro used to define the Mode number of Nibble 
    LOWNIBBLE for LOW Nibble mode ,  HIGHNIBBLE for HIGH Nibble mode
*/
#define LCD_NIBBLE_MODE     LOWNIBBLE


/*

    Options for pin numbers :
        PIN0
        PIN1
        PIN2
        PIN3
        PIN4
        PIN5
        PIN6
        PIN7



    Options for port numbers :

        GPIOA  =>>> PORT A
        GPIOB  =>>> PORT B
        GPIOC  =>>> PORT C
        GPIOD  =>>> PORT D

*/




// This Macro used to define the port number of Data Pins
#define LCD_DATA_PORT       GPIOD




// This Macro used to define the port number of RS pin 
#define LCD_RS_PORT         GPIOD
// This Macro used to define the PIN number of RS
#define LCD_RS_PIN          PIN5





// This Macro used to define the port number of RW pin 
#define LCD_RW_PORT         GPIOD
// This Macro used to define the PIN number of RW
#define LCD_RW_PIN          PIN2



// This Macro used to define the port number of enable pin 
#define LCD_EN_PORT         GPIOD
// This Macro used to define the PIN number of Enable
#define LCD_EN_PIN          PIN6

#define LCD_REAL_NUMBER_DIGITS_AFTER_DOT 0

#endif