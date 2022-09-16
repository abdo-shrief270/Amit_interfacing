#ifndef  _MCAL_EXTI_PRIVATE_H_
    #define _MCAL_EXTI_PRIVATE_H_
#include "DIO_interface.h"

	// Interrupt Registers

		// Status I/O Register

		#define  SREG     *((volatile u8*)0x5F)



		// General Interrupt Control Register

		#define  GICR     *((volatile u8*)0x5B)



		// MCU Control Register
		
		#define  MCUCR    *((volatile u8*)0x55)


		// General Interrupt Flag Register 

		#define  GIFR     *((volatile u8*)0x5A)


		// MCU Control and Status Register 

		#define  MCUCSR   *((volatile u8*)0x54)
	
 	// Interrput Pins


		// General Flag Pin used to Enable the external Interrupt
	
		#define GI      PIN7

		/*
			Interrupts Flag Pins used to execute the Interrupt when it is HIGH
			Located in GIFR
		*/
		 
		#define INTF0   PIN6
		#define INTF1   PIN7
		#define INTF2   PIN5


		/*
			Interrupts Flag Pins used to Enable the Interrupt when it is HIGH
			Located in GICR
		*/

		#define INT0    PIN6
		#define INT1    PIN7
		#define INT2    PIN5


		/*
			Interrupt Sense Control Pins used to define the edge or level that enable the Interrupt number 1
			Located in MCUCR
		*/

		#define ISC11   PIN3
		#define ISC10   PIN2


		/*
			Interrupt Sense Control Pins used to define the edge or level that enable the Interrupt number 0
			Located in MCUCR
		*/

		#define ISC01   PIN1
		#define ISC00   PIN0


		/*
			Interrupt Sense Control Pin used to define the edge that enable the Interrupt number 2
			Located in MCUCR
		*/

		#define ISC2    PIN6
	
		

	

#endif