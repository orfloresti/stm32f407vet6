#include "stm32f7xx.h"                  // Device header
// #include "customs.h"
// PB14
// RCC->AHB1ENR


void systickDelayMs( int ms );

int main(void){
	// Enable clock to GPIOB
	// RCC->AHB1ENR |= 4;
	RCC->AHB1ENR |= ( 1 << 1 );
	
	//GPIOB->MODER |= 0x10000000; // 0b  0001 0000 0000 0000 0000 0000 0000 0000
	GPIOB->MODER |= ( 1 << 28 ); // set output to GPIOB 14 
	
	
	while (1) {
		// GPIOB->BSRR = 0x4000;
		// GPIOB->BSRR = (1 << 14); // Set output
		// GPIOB->BSRR = 0x40000000;	
		// GPIOB->BSRR = (1 << 30); // Reset output
		systickDelayMs(1000);
		GPIOB->ODR ^= (1<<14);

	}
}

void systickDelayMs( int ms ) {
	
	// Clock seems to be 2000Mhz
	SysTick->LOAD = 8000; // Reload with number of clocks per milliseconds
	SysTick->VAL = 0;		// Cleat current value
	SysTick->CTRL = 5; 	// Enable Systick
	
	for( int i= 0; i < ms; i++ ) {
		// Wait until the counter flag is set
		while((SysTick->CTRL & 0x10000) == 0) {	}
	}
	
	SysTick->CTRL = 0;
	
} 


