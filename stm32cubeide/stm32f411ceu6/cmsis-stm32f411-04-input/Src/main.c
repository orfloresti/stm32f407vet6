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

#define PINA1		(1U<<0)
#define BTN_PIN		PINA1

#define PINA5 		(1U<<5)
#define LED_PINA	PIN5

#define PINC13 		(1U<<13)
#define LED_PINC	PINC13



int main(void) {

	// Enable clock for GPIOC
	RCC->AHB1ENR |= GPIOAEN;
	RCC->AHB1ENR |= GPIOCEN;

	// Set GPIOC mode as general output
	GPIOC->MODER |= (1U<<26);
	GPIOC->MODER &=~ (1U<<27);

	// Set GPIOA as input pin
	GPIOA->MODER &=~ (1U<<0);
	GPIOA->MODER &=~ (1U<<1);

	while(1) {
		// Check if the button is pressed
		if(GPIOA->IDR & BTN_PIN) {
			// Turn on if is GND
			GPIOC->BSRR = LED_PINC;
		} else {
			// Turn off if VCC
			GPIOC->BSRR = (1U<<29);
		}
	}
}
