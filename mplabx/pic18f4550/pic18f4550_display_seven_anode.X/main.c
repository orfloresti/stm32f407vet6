/*
 * File:   main.c
 * Author: Orlando Flores Teomitzi
 *
 * Created on April 29, 2020, 7:50 PM
 */

#include <xc.h>
#include "config.h"
#include "counter.h"

char count = 0x01;

void initPort(void) {
    ADCON1bits.PCFG = 0x0f;
    // Set register D as output
    TRISD = 0; 
    
    // Inputs and pull up
    TRISBbits.RB0 = 1;
    TRISBbits.RB1 = 1;
    INTCON2bits.RBPU = 0;
    
    // Set display off
    LATD = 0xFF;
}

void main(void) {

    initPort();
    
    while(1) {
        
        if ( PORTBbits.RB0 == 0) {
            // UP
            count = 0x01;
        }
        if ( PORTBbits.RB1 == 0 ) {
            // Down
            count = 0x00;
        }
                
        if ( count == 0x01 ) {
            up();
            LATD = getDigit(iterator);
            __delay_ms(1000);
        } 
        if ( count == 0x00 ) {
            down();
            LATD = getDigit(iterator);
            __delay_ms(1000);
        }
        
        
    }

}
