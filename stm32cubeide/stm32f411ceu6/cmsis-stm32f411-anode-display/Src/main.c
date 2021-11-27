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

void timer() {
	for(int i=0; i<0xffffU; i++){}
	for(int i=0; i<0xffffU; i++){}
	for(int i=0; i<0xffffU; i++){}
	for(int i=0; i<0xffffU; i++){}
	for(int i=0; i<0xffffU; i++){}
	for(int i=0; i<0xffffU; i++){}
	for(int i=0; i<0xffffU; i++){}
	for(int i=0; i<0xffffU; i++){}
	for(int i=0; i<0xffffU; i++){}
	for(int i=0; i<0xffffU; i++){}
	for(int i=0; i<0xffffU; i++){}
	for(int i=0; i<0xffffU; i++){}
}

int main(void) {

	// Enable clock for GPIOC
	RCC->AHB1ENR |= GPIOAEN;

	// Mode GPIOA 0-15 as general output
	GPIOA->MODER |= (0x5555U << 0);

	while(1) {

		// Set 0
		GPIOA->ODR = (0x0U << 0);
		GPIOA->ODR |= ~(0x3fU << 0);
		timer();

		// Set 1
		GPIOA->ODR = (0x0U << 0);
		GPIOA->ODR |= ~(0x6U << 0);
		timer();

		// Set 2
		GPIOA->ODR = (0x0U << 0);
		GPIOA->ODR |= ~(0x5bU << 0);
		timer();

		// Set 3
		GPIOA->ODR = (0x0U << 0);
		GPIOA->ODR |= ~(0x4fU << 0);
		timer();

		// Set 4
		GPIOA->ODR = (0x0U << 0);
		GPIOA->ODR |= ~(0x66U << 0);
		timer();

		// Set 5
		GPIOA->ODR = (0x0U << 0);
		GPIOA->ODR |= ~(0x6dU << 0);
		timer();

		// Set 6
		GPIOA->ODR = (0x0U << 0);
		GPIOA->ODR |= ~(0x7dU << 0);
		timer();

		// Set 7
		GPIOA->ODR = (0x0U << 0);
		GPIOA->ODR |= ~(0x7U << 0);
		timer();

		// Set 7
		GPIOA->ODR = (0x0U << 0);
		GPIOA->ODR |= ~(0x7fU << 0);
		timer();

		// Set 7
		GPIOA->ODR = (0x0U << 0);
		GPIOA->ODR |= ~(0x6fU << 0);
		timer();
	}
}

