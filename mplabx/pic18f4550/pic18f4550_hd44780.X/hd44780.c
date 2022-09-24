#include <xc.h>
#include "hd44780.h"
#include "config.h"

void LCD_Init(void) {
    
    // 4 bits -> RD0 RD3 
    // Clean
    LCD_PORT = LCD_PORT & 0xF0;
    LCD_TRIS &= 0xF0;
    
    RW_TRIS = 0;
    RS_TRIS = 0;
    E_TRIS = 0;
    
    RW_PIN = 0;
    RS_PIN = 0;
    E_PIN = 0;
    
    __delay_ms(15);
    
    LCD_Command(0x30);
    __delay_ms(5);
    LCD_Command(0x30);
    __delay_us(100);
    LCD_Command(0x32);
    __delay_us(100);
    
    // 4 bits configuration
    __delay_us(100);
    LCD_Command(0x28); // Lines and chars
    __delay_us(100);
    LCD_Command(0x08); // Display cursor and blink off
    __delay_us(100);
    LCD_Command(0x0F); // Display cursor and blink on
    __delay_us(100);
    LCD_Command(0x01); // Clean LCD
    __delay_us(100);
    LCD_Command(0x04);
    __delay_us(100);
    
    __delay_us(100);
    LCD_Command(0x06); // Display
    LCD_Command(0x0C); // Increment and don't move
    
    return;
}

void LCD_Command(unsigned char cmd){
    // 30 = 0011 0000
    
    // Clean
    LCD_PORT &= 0xF0;
    LCD_TRIS &= 0xF0;
    
    // 30 -> send more significant
    LCD_PORT = LCD_PORT | ((cmd >> 4) & 0x0F ) ;
    
    RW_PIN = 0;     // Write mode
    RS_PIN = 0;     // Mode command
    __delay_us(5);  // 18TCY -> 20MHz : 18*TCY = 18*(4/20MHz)= 3.6us
    E_PIN = 1;      // Enable LCD
    __delay_us(5);  
    E_PIN = 0;      // Disable LCD
    
    // 0 -> less significant
    LCD_PORT &= 0xF0;
    LCD_PORT |= cmd & 0x0F;
    
    __delay_us(5);  // 18TCY -> 20MHz : 18*TCY = 18*(4/20MHz)= 3.6us
    E_PIN = 1;      // Enable LCD
    __delay_us(5);  
    E_PIN = 0;      // Disable LCD
    
    LCD_TRIS |= 0x0F;
    return;
}

void LCD_XY(int x, int y){
    if(x>0){
        LCD_Command(0xC0+y);
    }
    else{
        LCD_Command(0x80+y);
    }
}

void LCD_print(const char *data){
    while(*data){
        __delay_us(100);
        LCD_Data(*data);
        data++;
    }
    __delay_us(100);
}

void LCD_Data(char data){
    __delay_us(100);
    LCD_PORT &= 0xf0;
    LCD_TRIS &= 0xf0;
    
    LCD_PORT = LCD_PORT | ((data>>4)&0x0f);
    
    //Configuration
    RW_PIN = 0;     
    RS_PIN = 1;     
    __delay_us(5);  
    E_PIN = 1;      
    __delay_us(5);
    E_PIN = 0;      
    
    LCD_PORT &= 0xf0;
    LCD_PORT |= data&0x0f;
    
    __delay_us(5);  
    E_PIN = 1;      
    __delay_us(5);
    E_PIN = 0;      
    
    LCD_TRIS |= 0x0f;
    
    return;
}