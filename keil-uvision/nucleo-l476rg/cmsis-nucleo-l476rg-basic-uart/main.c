
// PA2 -> USART2_TX
// USART2 -> AHB/APB1
// GPIOA -> AHB1

// APB1 -> RCC_APB1ENR1 -> USART2EN(17)
// USARTx_BRR - Configure boud rate
// USARTx_CR1 - Configure RX, TX, UE(Preescaler)
// USARTx_CR2 - Configure signals properties 
// USARTx_CR3 - Configure flow control as NACK
// USARTx_DR - Data register 
// Alternative funtions datasheet page 87. 

#include "stm32l4xx.h"


void USART2_Init(void);
void USART_write(int ch);
void delayMs(int delay);

int main(void){
	
	USART2_Init();

	while(1){
		USART_write('h');
		delayMs(1000);
		USART_write('i');
		delayMs(1000);
		USART_write('\r');
		delayMs(1000);
		USART_write('\n');
		delayMs(1000);
	}
}

void USART2_Init(void){
	// initializations before the usuart module
	RCC->APB1ENR1 |= 0x20000;
	RCC->AHB2ENR |= 1; // PA2 
	GPIOA->AFR[0] = 0x0700;
	GPIOA->MODER &= (unsigned int)~0x30; // reset PA2
	//GPIOA->MODER = 0;
	GPIOA->MODER |= 0x0020; // set PA2 to alternate function
	// initiatilzati usart2
	// USART2->BRR = 0x0683; //9600 @16MHZ
		/* 
	* USART_BRR = [BUS_FREQUENCY_in_Hz] / [BOUD_RATE]
	* USART_BRR = 3,964,800 / 9600 =  413 to hex 0x19D 
	*/
	USART2->BRR = 0x19D;
	
	USART2->CR1 = 0x0008; // enable Tx
	USART2->CR1 |= 1; // enable UART
}

void USART_write(int ch){
	while((USART2->ISR & 0x0080)) {  // wait while tx buffer is empty
		USART2->TDR = (ch & 0xFF);
	}
}

void delayMs(int delay) {
	int i;
	for(; delay>0; delay--)	{
		for(i=0; i<100000000;i++);
	}
}
