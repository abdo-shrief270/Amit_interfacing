#ifndef _MCAL_EXTI_CONFIG_H_
    #define _MCAL_EXTI_CONFIG_H_

    // Interrput Pins


		// General Flag Pin used to Enable the external Interrupt
	
		#define GI      7

		/*
			Interrupts Flag Pins used to execute the Interrupt when it is HIGH
			Located in GIFR
		*/
		 
		#define INTF0   6
		#define INTF1   7
		#define INTF2   5


		/*
			Interrupts Flag Pins used to Enable the Interrupt when it is HIGH
			Located in GICR
		*/

		#define INT0    6
		#define INT1    7
		#define INT2    5


		/*
			Interrupt Sense Control Pins used to define the edge or level that enable the Interrupt number 1
			Located in MCUCR
		*/

		#define ISC11   3
		#define ISC10   2


		/*
			Interrupt Sense Control Pins used to define the edge or level that enable the Interrupt number 0
			Located in MCUCR
		*/

		#define ISC01   1
		#define ISC00   0


		/*
			Interrupt Sense Control Pin used to define the edge that enable the Interrupt number 2
			Located in MCUCR
		*/

		#define ISC2    6

#endif