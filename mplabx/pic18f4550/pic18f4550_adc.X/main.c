/*
 * File:   main.c
 * Author: Orlando Flores Teomitzi
 *
 * Created on July 25, 2020, 5:39 PM
 */


#include <xc.h>
#include "bits_config.h"

#define _XTAL_FREQ 20000000

void main(void) {
    
    TRISA = 0xFF;
    TRISD = 0;
    ADCON1bits.PCFG = 0;
    ADCON1bits.VCFG = 0;
    ADCON0 = 0;
    
    ADCON2bits.ACQT = 3;
    ADCON2bits.ADCS = 5;
    ADCON2bits.ADFM = 1;
    ADCON0bits.ADON = 1;
    
    for(;;){
        ADCON0bits.GO_DONE = 1;
        while(ADCON0bits.GO_DONE == 1);
        PORTD = ADRESL;
    }
    
}
