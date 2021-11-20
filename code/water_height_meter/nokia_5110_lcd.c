/*
 * nokia_5110_lcd.c
 *
 * Created: 20. 11. 2021 14:52:11
 *  Author: gkaretka
 */ 

#include "nokia_5110_lcd.h"
#include "english_font.h"
#include "water_symbols.h"

void LCD_init() 
{
    // Setup all pins to out
    LCD_RST_DDR |= (1 << LCD_RST_PIN);
    LCD_CE_DDR  |= (1 << LCD_CE_PIN);
    LCD_DC_DDR  |= (1 << LCD_DC_PIN);
    SDIN_DDR    |= (1 << SDIN_PIN);
    SCLK_DDR    |= (1 << SCLK_PIN);
    
    // Set CE to low, this bus is reserved for display
    LCD_CE_PORT &= ~(1 << LCD_DC_PIN);
    
    // Set other pins high
    LCD_RST_PORT    |= (1 << LCD_RST_PIN);
    LCD_DC_PORT     |= (1 << LCD_DC_PIN);
    SDIN_PORT       |= (1 << SDIN_PIN);
    SCLK_PORT       |= (1 << SCLK_PIN);
    _delay_ms(1);
    
    // Reset and setup
    LCD_RST_clr;
    _delay_us(1);
    LCD_RST_set;

    _delay_us(1);

    LCD_write_byte(0x21, 1); // set LCD mode
    LCD_write_byte(0xc8, 1); // set bias voltage
    LCD_write_byte(0x06, 1); // temperature correction
    LCD_write_byte(0x13, 1); // 1:48
    LCD_write_byte(0x20, 1); // use bias command, vertical
    LCD_write_byte(0x0c, 1); // set LCD mode,display normally
    LCD_clear();             // clear the LCD
}

void LCD_clear()
{
    LCD_write_byte(0x0c, 1);
    LCD_write_byte(0x80, 1);

    for (unsigned int i = 0; i < NUM_OF_CELLS; i++)
    {
        LCD_write_byte(0, 0);
    }
}

void LCD_write_byte(unsigned char dat, unsigned char command)
{
    unsigned char i;

    if (command == 1)
    LCD_DC_clr;
    else
    LCD_DC_set;

    for(i = 0; i < 8; i++)
    {
        if(dat&0x80)
            SDIN_set;
        else
            SDIN_clr;
               
        SCLK_clr;
        dat = dat << 1;
        SCLK_set;
    }
}

void LCD_set_XY(unsigned char X, unsigned char Y)
{
    LCD_write_byte(0x40 | Y, 1);    // column
    LCD_write_byte(0x80 | X, 1);    // row
}

void LCD_write_char(unsigned char c)
{
    unsigned char line;
    c -= 32;

    for (line = 0; line < 6; line++)
        LCD_write_byte(font6x8[c][line], 0);
}

void LCD_write_english_string(unsigned char X, unsigned char Y, char *s)
{
    LCD_set_XY(X,Y);
    while (*s)
    {
        LCD_write_char(*s);
        s++;
    }
}

void LCD_write_whole_screen(unsigned char *cells, uint16_t cells_n, uint16_t start_y) {
    LCD_set_XY(0, (unsigned char) start_y);
    for (uint16_t i = 0; i < cells_n; i++)
        LCD_write_byte(cells[i], 0);
}

void LCD_write_init()
{
    LCD_clear();
    _delay_ms(1000);
    LCD_write_whole_screen((unsigned char*) init_msg_2, NUM_OF_CELLS, 0);    
}