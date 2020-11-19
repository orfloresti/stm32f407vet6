#include "stm32l4xx.h"                  // Device header

/*
Clock Sources:
	Crystall oscilator
	The RC oscillator
	The PLL (Phase locked loop)
*/

void delayMs(int delay);
char USART2_read(void);
void USART2_Init(void);
void LED_play(int value);

int main()
{
	RCC->AHB2ENR |= 1;                  	// Enable clock
  GPIOA->MODER = 0x0;									// Set all values to 0 - Not mencioned on the course
  GPIOA->MODER |= 0x400;	
	
	USART2_Init();
	char ch;
	while(1)
	{
		ch = USART2_read();
		LED_play(ch);
	}
}

void USART2_Init(void)
{
	// initializations before the usuart module
	RCC->APB1ENR1 |= 0x20000;
	RCC->AHB2ENR |= 1;
	
	// Configure PA3  as USART2 RX
	GPIOA->AFR[0] |= 0x07000;		// Alt7 for USART2
	GPIOA->MODER |= 0x0080;			// Enable Alternate funciton at PA3
	
	// USART2->BRR = 0x0022; // 115200 baudrate @3,964,800hz
	USART2->BRR = 0x19D;
	
	USART2->CR1 |= ( 1 << 2 ); // Enable Rx
	// USART2->CR1 |= 0x2000; 	
	USART2->CR1 |= ( 1 << 0 ); // enable UART
	
}

char USART2_read(void)
{
	while( !( USART2->ISR & (1 << 5) )) {} //Wait until char arrives
	// LED_play(5);
	return USART2->RDR;
}

void LED_play(int value)
{
	value %= 16;
	for(; value > 0; value--)
	{
		GPIOA->BSRR = 0x20; //Turn on LED
		delayMs(100);
		GPIOA->BSRR = 0x200000; // Turn LED off
		delayMs(100);
	}
}

void delayMs(int delay)
{
	int i;
	for(; delay > 0; delay --)
	{
		for( i=0; i< 3195; i++); 
	}
}


