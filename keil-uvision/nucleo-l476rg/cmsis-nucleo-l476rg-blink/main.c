// PA5 LED
// AHB2
// RCC->AHB2ENR
// GPIOx_MODER
// GPIOx_ODR

#include "stm32l4xx.h"                  // Device header
void delayMs(int delay);

int main(void)
{
  RCC->AHB2ENR |=  1;                  	// Enable clock

  GPIOA->MODER   = 0x0;									// Set all values to 0 - Not mencioned on the course
  GPIOA->MODER   |=  0x400;							// Set RA5 as output
	
	while(1) {
		
		GPIOA->ODR = 0x20; 			// 0b 0010 0000
		// delayMs(100);
		GPIOA->ODR &=~0x20;
		// delayMs(100);
	}
}

// Taking into account 
void delayMs( int delay)
{
	int i;
	
	for(; delay>0; delay--){
		for( i = 0; i<3195; i++ );
	}
}
