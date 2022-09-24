#include "counter.h"
#include <xc.h>
#include "config.h"


char iterator = 0;
char digit[10] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};

void up() {
    if ( iterator == 9 ) {
        iterator = 0;
    } else {
        iterator++;   
    }
}

void down() {
    if ( iterator == 0 ) {
        iterator = 9;
    } else {
        iterator--;
    }
    
}

char getDigit(char iterator) {
    return digit[iterator];
};