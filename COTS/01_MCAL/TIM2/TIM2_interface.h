#ifndef _MCAL_TIM2_INTERFACE_H_
#define _MCAL_TIM2_INTERFACE_H_
#include "TYPES.h"

#define TIM2_CLK_OFF    0x00
#define TIM2_CLK_1      0x01
#define TIM2_CLK_8      0x02
#define TIM2_CLK_32     0x03
#define TIM2_CLK_64     0x04
#define TIM2_CLK_128    0x05
#define TIM2_CLK_256    0x06
#define TIM2_CLK_1024   0x07


void  TIM2_vidInit(void);
void  TIM2_vidStart(u8 u8Prescaler);
void  TIM2_vidSetTCNT2(u8 u8InitValue);
u32   TIM2_u32ReadTIM2(void);
void  TIM2_vidSetNormalWithInterrupt(void (*CB)(void));
void  TIM2_vidSetOCR2(u8 u8InitValue);
void  TIM2_vidSetCTCWithInterrupt(void (*CB)(void));
void  TIM2_vidStopTIM2(void);
void  TIM2_vidDInit(void);
void  TIM2_GenerateFastPWM(u8 u8DutyCycle);
void  TIM2_GeneratePhaseCorrectPWM(u8 u8DutyCycle);

#endif