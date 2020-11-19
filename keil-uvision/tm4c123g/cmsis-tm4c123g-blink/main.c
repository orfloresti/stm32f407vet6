#include "TM4C123.h"                    // Device header

#define GREEN (1U<<3)

void delay(int time);

int main() {
	SYSCTL->RCGCGPIO |= (1U<<5);
	GPIOF->DIR |=GREEN;
	GPIOF->DEN |=GREEN;
	
	while(1) {
		GPIOF->DATA ^=GREEN;
		delay(2000000);
	}
	
}

void delay(int time) {
	int delay = 0;
	while( delay < time) {
		delay ++;
	}
}