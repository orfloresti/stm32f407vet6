/*
 * File:   main.c
 * Author: orflores
 *
 * Created on April 14, 2020, 2:29 AM
 */


#include <xc.h>
#include "configuration.h"
#include "pic18f4550.h"

#define _XTAL_FREQ 20000000

void InitPort() {
    ADCON1bits.PCFG = 0x0F;
    LATD=0;
    LATA=0;
    LATB=0;
    LATC=0;
    LATE=0;
    TRISDbits.RD1=0; //PORTD = output 0, input 1
    TRISAbits.RA1=0;
    TRISBbits.RB1=0;
    TRISCbits.RC1=0;
    TRISEbits.RE1=0;
}

void main(void) {
    InitPort();
    
    while(1) {
        
        PORTAbits.RA1 = 1;
        __delay_ms(1000);
        PORTAbits.RA1 = 0;
        
        PORTBbits.RB1 = 1;
        __delay_ms(1000);
        PORTBbits.RB1 = 0;
        
        PORTCbits.RC1 = 1;
        __delay_ms(1000);
        PORTCbits.RC1 = 0;
        
        PORTDbits.RD1 = 1;
        __delay_ms(1000);
        PORTDbits.RD1 = 0;
        
        PORTEbits.RE1 = 1;
        __delay_ms(1000);
        PORTEbits.RE1 = 0;       
        
    }
    // return;
}
