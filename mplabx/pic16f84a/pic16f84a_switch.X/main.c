/*
 * File:   main.c
 * Author: orlando_floresti
 *
 * Created on July 26, 2020, 4:51 PM
 */


#include <xc.h>

void main(void) {
    TRISBbits.TRISB0 = 1;
    TRISBbits.TRISB1 = 0;
    
    for(;;) {
        if(PORTBbits.RB0) {
            PORTBbits.RB1 = 1;
        }
    }
    
    return;
}
