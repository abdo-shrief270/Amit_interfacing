#ifndef _MCAL_EEPROM_INTERFACE_H_
#define _MCAL_EEPROM_INTERFACE_H_
#include "TYPES.h"

void    EEPROM_vidWrite(u16 u16Address , u8 u8Data);
u8      EEPROM_vidRead(u16 u16Address);
#endif