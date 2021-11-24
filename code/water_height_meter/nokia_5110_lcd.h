/*
 * nokia_5110_lcd.h
 *
 * Created: 20. 11. 2021 14:53:09
 *  Author: gkaretka
 */ 


#ifndef NOKIA_5110_LCD_H_
#define NOKIA_5110_LCD_H_

#ifndef F_CPU
    #define F_CPU 16000000L
#endif

#include <avr/io.h>
#include <util/delay.h>
#include "water_symbols.h"

//#define ARDUINO_MEGA
#define ARDUINO_UNO

/* Arduino Mega
 * E5 - RST
 * G5 - CE - can be asserted low
 * E3 - DC - data/command
 * H3 - DIN - data in
 * H4 - CLK - SPI clk
 */

/* Arduino Uno
 * B5 - RST
 * B4 - CE - can be asserted low
 * B3 - DC - data/command
 * B2 - DIN - data in
 * B1 - CLK - SPI clk
*/
#ifdef ARDUINO_MEGA
#define LCD_RST_PORT    PORTE
#define LCD_RST_DDR     DDRE
#define LCD_RST_PIN     5

#define LCD_CE_PORT     PORTG
#define LCD_CE_DDR      DDRG
#define LCD_CE_PIN      5

#define LCD_DC_PORT     PORTE
#define LCD_DC_DDR      DDRE
#define LCD_DC_PIN      3

#define SDIN_PORT       PORTH  
#define SDIN_DDR        DDRH
#define SDIN_PIN        3

#define SCLK_PORT       PORTH
#define SCLK_DDR        DDRH
#define SCLK_PIN        4

#else

#define LCD_RST_PORT    PORTB
#define LCD_RST_DDR     DDRB
#define LCD_RST_PIN     5

#define LCD_CE_PORT     PORTB
#define LCD_CE_DDR      DDRB
#define LCD_CE_PIN      4

#define LCD_DC_PORT     PORTB
#define LCD_DC_DDR      DDRB
#define LCD_DC_PIN      3

#define SDIN_PORT       PORTB
#define SDIN_DDR        DDRB
#define SDIN_PIN        2

#define SCLK_PORT       PORTB
#define SCLK_DDR        DDRD
#define SCLK_PIN        1

#endif

/*
 *
 *  DO NOT EDIT ANYTHING BELOW
 *
 */

/* Macros to ease the work */

#define LCD_RST_set  LCD_RST_PORT   |=  (1 << LCD_RST_PIN)
#define LCD_RST_clr  LCD_RST_PORT   &= ~(1 << LCD_RST_PIN)

#define LCD_DC_set   LCD_DC_PORT    |=  (1 << LCD_DC_PIN)
#define LCD_DC_clr   LCD_DC_PORT    &= ~(1 << LCD_DC_PIN)

#define SDIN_set     SDIN_PORT      |=  (1 << SDIN_PIN)    
#define SDIN_clr     SDIN_PORT      &= ~(1 << SDIN_PIN)

#define SCLK_set     SCLK_PORT      |=  (1 << SCLK_PIN)
#define SCLK_clr     SCLK_PORT      &= ~(1 << SCLK_PIN)

void LCD_clear();
void LCD_init();
void LCD_write_byte(unsigned char dat, unsigned char command);
void LCD_write_english_string(unsigned char X,unsigned char Y,char *s);
void LCD_write_char(unsigned char c);
void LCD_set_XY(unsigned char X, unsigned char Y);
void LCD_write_init();
void LCD_write_whole_screen(unsigned char *cells, uint16_t cells_n, uint16_t start_y);

/* Defines */

#define NUM_OF_CELLS    504

#endif /* NOKIA_5110_LCD_H_ */