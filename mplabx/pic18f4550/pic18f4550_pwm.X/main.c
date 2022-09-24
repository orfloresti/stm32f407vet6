/*
 * File:   main.c
 * Author: orlando_floresti
 *
 * Created on May 4, 2020, 9:19 PM
 */

// PWM PWM Period = [(PR2) + 1] ? 4 ? T OSC ? (TMR2 Prescale Value)
// 1/1KHz = (PR2 + 1) * 4 * ( 1/4MHz ) * 16
// PR2 = 61.5
// PR2 ~ 61 = 0x3D

// PWM Duty Cycle = (CCPRXL:CCPXCON<5:4>) ? T OSC ? (TMR2 Prescale Value)
// CCPRXL = PWM / Tosc * Prescaler
// CCPRXL = (1/1KHz) / ((1/4MHz) * 16) =  250 = 0xFA

// 250 =   100%
// x    =   50%     
// x = 125  To set CCPRXL use the 6 more significant and add 00 example:  0b 0011111 01
// x    =   80%
// x = 200 = 0b11001000


#include <xc.h>

void main(void) {
    
    PR2 = 0x3D;
    
    // CCPR1L = 0b00011111; // 50%
    // CCPR1L = 0b00110010; // 80%
    // CCPR1L = 0b00111000; // 90%
    // CCPR1L = 0b00000011; // 5%
    // CCPR1L = 0b00000001; // Min ~ 1.6%
    CCPR1L = 0b00111101; // Max ~ 98.39%
    

    // RC1 RC2 as output
    TRISCbits.RC1 = 0;
    TRISCbits.RC2 = 0;
    
    T2CON = 0x03; // Prescaler 16 timer 2 off
    CCP1CON = 0x0C;
    
    TMR2 = 0;
    T2CONbits.TMR2ON = 1;
    
    while(1) {}
    
    return;
}
