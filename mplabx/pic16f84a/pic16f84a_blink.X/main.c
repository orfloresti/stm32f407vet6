/*
 * File:   newmain.c
 * Author: orlandofloresti
 *
 * Created on October 1, 2018, 8:29 PM
 */
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>

#define _XTAL_FREQ 4000000

// CONFIG
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (Power-up Timer is disabled)
#pragma config CP = OFF         // Code Protection bit (Code protection disabled)


void main(void) {
    return;
    
    TRISB = 0b00000000; //Puerto B como salidas
    PORTB = 0b00000000; //Limpio las salidas
    int state = 0b00000000;
            
    while(1){        
        __delay_ms(500);
        state = !state;
        PORTB = state;        
    }
    
    //return (EXIT_SUCCESS);
}
