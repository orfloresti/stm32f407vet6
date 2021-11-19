/* To add customs headers go to
 * Project properties > C/C++ Generals > Paths and symbols > Includes
 * And add the paths to CMSIS (Core and STM32F4xx)
 * */

/*
 * To set a target in compilation using stm32f44xx.h
 * Project properties > C/C++ Generals > Paths and symbols > Symbols
 * And add the definition for example STM32F411xE for stm32f411xe.h
 * */


#include "stm32f4xx.h"


#define GPIOAEN		(1U<<0)
#define GPIOCEN 	(1U<<2)

#define PINA5 		(1U<<5)
#define LED_PINA	PIN5

#define PINC13 		(1U<<13)
#define LED_PINC	PINC13

int main(void) {

	// Enable clock for GPIOC
	RCC->AHB1ENR |= GPIOCEN;

	// Mode GPIO as general output
	GPIOC->MODER |= (1U<<26);
	GPIOC->MODER &=~ (1U<<27);

	while(1) {
		// Toggle PINC13
		GPIOC->BSRR = LED_PINC;
		// Generic delay
		for(int i=0; i<200000; i++){}

		// Toggle PINC13
		GPIOC->BSRR = (1U<<29);
		// Generic delay
		for(int i=0; i<200000; i++){}
	}
}
