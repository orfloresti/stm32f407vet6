
#include "stm32l4xx.h"                  // Device header

int main(void) {
	RCC->AHB2ENR |=4;							// Enable Port C 
	RCC->AHB2ENR |=1;							// Enable port A
	
	GPIOA->MODER = 0;
	GPIOA->MODER |= 0x400;
	
	while(1) {
		if(GPIOC->IDR & 0x2000){		// If PC13 is high
			GPIOA->BSRR = 0x2;
		} else {
			GPIOA->BSRR = 0x20;
		}
	}
	
}
