/*
 * File:   main.c
 * Author: orlando_floresti
 *
 * Created on June 4, 2020, 12:31 AM
 */


#define F_CPU 16000000L

#include <avr/io.h>
#include <util/delay.h>

int main() {
	DDRB = 0xFF;

	while(1) {
		PORTB = 0xFF;
		_delay_ms(3000);
		PORTB = 0x00;
		_delay_ms(3000);
	}
}

