#include "stm32l4xx.h"                  // Device header

int main() {
	RCC->AHB2ENR |= 1;
	
	GPIOA->MODER = 0;
	GPIOA->MODER |=  0x400;
	
	// Configure Systic
	SysTick->LOAD = 2000000;
	SysTick->VAL = 0;
	SysTick->CTRL = 5;
	
	while(1) {
		
		// Check if the counter flasg is set
		if(SysTick->CTRL & 0x10000) {
			GPIOA->ODR ^= 0x20;
		}
		
	}
	
	
	
}
