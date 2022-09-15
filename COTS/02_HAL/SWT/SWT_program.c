#include "TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "SWT_interface.h"
#include "SWT_private.h"
#include "SWT_config.h"

void SWT_vidInitSWT(_enuGPIOx enuPortNum, _enuPinx enuPinNum)
{

    DIO_vidSetPinMode(enuPortNum, enuPinNum, INPUT);

    #if EN_PULLUP == ENABLE

        DIO_vidWritePin(enuPortNum,enuPinNum,HIGH);

    #endif

}

_enuOutPut SWT_enuReadSWT(_enuGPIOx enuPortNum, _enuPinx enuPinNum)
{
    _enuOutPut enuOutPut;
   enuOutPut = DIO_enuReadPin(enuPortNum, enuPinNum);
}
