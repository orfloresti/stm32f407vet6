/*
 * File:   main.c
 * Author: Orlando
 *
 * Created on May 4, 2020, 12:01 PM
 */


#include <xc.h>
#include "config.h"
#include "hd44780.h"


void main(void) {
    LCD_Init();
    
    while(1) {
        LCD_XY(0,0);
        LCD_print("PIC18F4550");
        LCD_XY(1,0);
        LCD_print("MPLABX");
    }
}
