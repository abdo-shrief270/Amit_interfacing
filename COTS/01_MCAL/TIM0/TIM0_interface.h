#ifndef _MCAL_TIM0_INTERFACE_H_
#define _MCAL_TIM0_INTERFACE_H_
#include "TYPES.h"


#define TIM0_CLK_OFF    0x00
#define TIM0_CLK_1      0x01
#define TIM0_CLK_8      0x02
#define TIM0_CLK_64     0x03 
#define TIM0_CLK_256    0x04
#define TIM0_CLK_1024   0x05
#define TIM0_EVENT_FE   0x06
#define TIM0_EVENT_RE   0x07


void    TIM0_vidInit(void);
void    TIM0_vidStart(u8 u8Prescaler);
void    TIM0_vidSetTCNT0(u8 u8InitValue);
u32     TIM0_u32ReadTIM0(void);
void    TIM0_vidSetNormalWithInterrupt(void (*CB)(void));
void    TIM0_vidSetOCR0(u8 u8InitValue);
void    TIM0_vidSetCTCWithInterrupt(void (*CB)(void));
void    TIM0_vidStopTIM0(void);
void    TIM0_vidDInit(void);
void    TIM0_GenerateFastPWM(u8 u8DutyCycle);
void    TIM0_GeneratePhaseCorrectPWM(u8 u8DutyCycle);

#endif