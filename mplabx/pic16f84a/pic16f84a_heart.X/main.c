/*
 * File:   main.c
 * Author: Orlando Flores Teomitzi
 *
 * Created on March 8, 2018, 8:06 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>

#define _XTAL_FREQ 4000000
//#define _XTAL_FREQ 16000000

// CONFIG
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (Power-up Timer is disabled)
#pragma config CP = OFF         // Code Protection bit (Code protection disabled)

void main(void) {
    
    //Set all pins to outs
    TRISA = 0b00000;
    TRISB = 0b00000000;
        
    while(1){
        //Clean all outputs 
        PORTA = 0b00000;
        PORTB = 0b00000000;    
        
        //Step one
        PORTA = 0b00000;
        PORTB = 0b00000000;
        
        PORTA = 0b10100;
        __delay_ms(150);
        
        //Step two
        
        PORTA = 0b00000;
        PORTB = 0b00000000;
        
        PORTA = 0b11110;
        PORTB = 0b00000001;
        __delay_ms(850);
        
        //Step three
        
        PORTA = 0b00000;
        PORTB = 0b00000000;
        
        PORTA = 0b00001;
        PORTB = 0b11111110;
        __delay_ms(1000);
        
    }   
    //return (EXIT_SUCCESS);
}
