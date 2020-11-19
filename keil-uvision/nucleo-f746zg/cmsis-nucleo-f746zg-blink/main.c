#include "stm32f7xx.h"                  // Device header
// PB14
// RCC->AHB1ENR

int main(void){
	// Enable clock to GPIOB
	RCC->AHB1ENR |= 4;
	RCC->AHB1ENR |= ( 1 << 1 );
	
	//GPIOB->MODER |= 0x10000000; // 0b  0001 0000 0000 0000 0000 0000 0000 0000
	GPIOB->MODER |= ( 1 << 28 ); // set output to GPIOB 14 
	
	
	while (1) {
		// GPIOB->BSRR = 0x4000;
		GPIOB->BSRR = (1 << 14); // Set output

		// GPIOB->BSRR = 0x40000000;	
		GPIOB->BSRR = (1 << 30); // Reset output
	}

}
