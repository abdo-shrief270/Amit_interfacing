#ifndef _HAL_LED_INTERFACE_H_
#define _HAL_LED_INTERFACE_H_

#include "DIO_interface.h"

void SWT_vidInitSWT(_enuGPIOx enuPortNum, _enuPinx enuPinNum);
_enuOutPut SWT_enuReadSWT(_enuGPIOx enuPortNum, _enuPinx enuPinNum);

#endif