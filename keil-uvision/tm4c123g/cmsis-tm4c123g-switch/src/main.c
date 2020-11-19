#include "TM4C123.h"                    // Device header
#include <stdint.h>

#define GREEN (1U<<3)
#define SW1 (1U<<4)
#define SW1_PRESSED 0x00

int main() {
	uint32_t btn_state;
	SYSCTL->RCGCGPIO |=(1U<<5);
	GPIOF->DIR |= GREEN;
	GPIOF->PUR |= SW1;
	GPIOF->DEN |= GREEN | SW1;
	
	while(1) {
		btn_state = GPIOF->DATA & 0x10;
		if(btn_state == SW1_PRESSED) {
			// GPIOF->DATA ^= GREEN;
			GPIOF->DATA |= GREEN;
		} else {
			GPIOF->DATA &=(~GREEN);
		}
	}

}
