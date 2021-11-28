/* To add customs headers go to
 * Project properties > C/C++ Generals > Paths and symbols > Includes
 * And add the paths to CMSIS (Core and STM32F4xx)
 * */

/*
 * To set a target in compilation using stm32f44xx.h
 * Project properties > C/C++ Generals > Paths and symbols > Symbols
 * And add the definition for example STM32F411xE for stm32f411xe.h
 * */

#include "stm32f4xx.h"
#include "./anode/anode.h"

int main(void) {

	anodeInitPort();

	while(1) {
		setDisplay(8, 1);
		setDisplay(7, 2);
		setDisplay(2, 3);
		setDisplay(4, 4);
	}
}

