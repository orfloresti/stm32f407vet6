#include "stm32l4xx.h"                  // Device header

void systickDelayMs( int ms );

int main(void) {

	RCC->AHB2ENR |= 1;
	GPIOA->MODER =0;
	GPIOA->MODER |= 0x400;

	while(1) {
			systickDelayMs(1000);
			GPIOA->ODR ^=0x20;
	}
}

void systickDelayMs( int ms ) {

	// Clock seems to be 2Mhz
	SysTick->LOAD = 2000; // Reload with number of clocks per milliseconds
	SysTick->VAL = 0;		// Clean current value
	SysTick->CTRL = 5; 	// Enable SysTick

	for( int i= 0; i < ms; i++ ) {
		// Wait until the counter flag is set
		while((SysTick->CTRL & 0x10000) == 0) {	}
	}

	SysTick->CTRL = 0;

}

