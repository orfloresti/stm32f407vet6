/*
 * 2021-11-28
 * Project to use the display 4*7 segments using CMSIS
 * Reference: Instec SKU MODDISP
 *
 *	uC	Display
 *	A1	A
 *	A2	B
 *	A3	C
 *	A4	D
 *	A5	E
 *	A6	F
 *	A7	G
 *	A8	PD
 *	A9	Display1
 *	A10	Display2
 *	A11	Display3
 *	A13	Display4
 *
 */

#include "stm32f4xx.h"
#include "./anode/anode.h"

int main(void) {

	anodeInitPort();

	while(1) {
		// Number to show
		for(int i = 0; i<9999 ; i++) {
			// Random delay
			for(int j=0; j<9999;j++) {
				// Show the number in the display
				displayPrint(i);
			}
		}

	}
}

