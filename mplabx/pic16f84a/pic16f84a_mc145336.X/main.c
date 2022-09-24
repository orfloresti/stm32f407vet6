#include <stdio.h>
#include <stdlib.h>
#include <xc.h>

#define _XTAL_FREQ 4000000

// CONFIG
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (Power-up Timer is disabled)
#pragma config CP = OFF         // Code Protection bit (Code protection disabled)


int main() {

    TRISA = 0b11111; //Puerto A como entradas
    TRISB = 0b00000000; //Puerto B como salidas
    PORTB = 0b00000000; //Limpio las salidas
    int out = 0b00000000;

    __delay_ms(500);

    //Ciclo infinito
    while(1){
        if(PORTA == 0b00001){
            out = 0b00000001;
            PORTB = out;
        }
        if(PORTA == 0b00010){
            out = 0b00000010;
            PORTB = out;
        }

        if(PORTA == 0b00011){
            out = 0b00000100;
            PORTB = out;
        }

        if(PORTA == 0b00100){
            out = 0b00001000;
            PORTB = out;
        }

        //Apaga todo
        if(PORTA == 0b01010){
            out = 0b00000000;
            PORTB = out;
        }
        if(PORTA == 0b01011){
            out = 0b11111111;
            PORTB = out;
        }
    }

    return (EXIT_SUCCESS);
}
