/*
 * File:   main.c
 * Author: Orlando Flores Teomitzi
 *
 * Created on April 29, 2020, 7:50 PM
 */


#include <xc.h>
#include "config.h"


void initPort(void) {
    ADCON1bits.PCFG = 0x0f;
    // Set register B as output
    TRISB = 0;
    
    // Set lights as off
    LATB = 0xFF;
    
    // Set Port D Bits 0,1,2 as input
    TRISDbits.RD0 = 1;
    TRISDbits.RD1 = 1;
    TRISDbits.RD2 = 1;
}

void main(void) {

    initPort();
    
    while(1) {
        if( PORTDbits.RD0 == 0) {
            LATB = 0x00;
        }
        if( PORTDbits.RD1 == 0) {
            LATB = 0xff;
        }
        if( PORTDbits.RD2 == 0) {
            __delay_ms(20);
            LATB = ~LATB;
        }
    }


}
