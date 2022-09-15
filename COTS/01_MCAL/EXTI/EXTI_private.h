#ifndef  _MCAL_EXTI_PRIVATE_H_
    #define _MCAL_EXTI_PRIVATE_H_


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
	

	
		

	

#endif