// 4 bits  -> RD0, RD1, RD2, RD3

#define LCD_PORT PORTD
#define LCD_TRIS TRISD

// Configuration variables
#define RW_PIN LATDbits.LATD6
#define RW_TRIS TRISDbits.RD6

#define RS_PIN LATDbits.LATD5
#define RS_TRIS TRISDbits.RD5

#define E_PIN LATDbits.LATD4
#define E_TRIS TRISDbits.RD4

// Functions
void LCD_Init(void);
void LCD_Command(unsigned char cmd);
void LCD_XY(int x, int y);
void LCD_print(const char *);
void LCD_Data(char data);