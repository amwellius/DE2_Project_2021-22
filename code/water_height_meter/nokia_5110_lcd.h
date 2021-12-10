/**
 * @file 
 * @defgroup karetka_lcd Nokia 5110 LCD Library <nokia_5110_lcd.h>
 * @code #include "nokia_5110_lcd.h" @endcode
 *
 * @note to modify this code to work with any pinout, modify pin definitions in nokia_5110_lcd.h
 *
 * @brief LCD Nokia 5110 library for AVR-GCC.
 *
 * The library contains functions for controlling Nokia 5110 LCD screen via software SPI. With small adjustments it should work with any micrcontroller.
 *
 * @{
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
#define SCLK_DDR        DDRB
#define SCLK_PIN        1

#endif

#define NUM_OF_CELLS    504

/*
 *
 *  DO NOT EDIT ANYTHING BELOW
 *
 */

/* Macros to ease the work */

/**
 * @name  Definitions LCD
 */

/** @brief Set RST pin to 1 */
#define LCD_RST_set  LCD_RST_PORT   |=  (1 << LCD_RST_PIN)
/** @brief Set RST pin to 0 */
#define LCD_RST_clr  LCD_RST_PORT   &= ~(1 << LCD_RST_PIN)

/** @brief Set DC pin to 1 */
#define LCD_DC_set   LCD_DC_PORT    |=  (1 << LCD_DC_PIN)
/** @brief Set RST pin to 0 */
#define LCD_DC_clr   LCD_DC_PORT    &= ~(1 << LCD_DC_PIN)

/** @brief Set SDIN (serial data in) pin to 1 */
#define SDIN_set     SDIN_PORT      |=  (1 << SDIN_PIN)    
/** @brief Set SDIN (serial data in) pin to 0 */
#define SDIN_clr     SDIN_PORT      &= ~(1 << SDIN_PIN)

/** @brief Set SCLK (serial clock) pin to 1 */
#define SCLK_set     SCLK_PORT      |=  (1 << SCLK_PIN)
/** @brief Set SCLK (serial clock) pin to 0 */
#define SCLK_clr     SCLK_PORT      &= ~(1 << SCLK_PIN)

/* Function prototypes -----------------------------------------------*/

/**
 * @name Functions
 */

/**
 * @brief  Clears LCD
 * @return none
 */
void LCD_clear(void);

/**
 * @brief  Displays init message defined init_msg_1
 * @return none
 */
void LCD_write_init(void);

/**
 * @brief  Initializes LCD pins and LCD with default settings
 * @return none
 */
void LCD_init(void);

/**
 * @brief  Write byte using software SPI to LCD
 * @param  dat  8bit value of byte
 * @param  commad  1 bit value (1 if 8bits are command, 0 if 8bits are data)
 * @return none
 */
void LCD_write_byte(unsigned char dat, unsigned char command);

/**
 * @brief  Write english string to display at specific location
 * @param  X  x coordinate on screen (0-84, columns)
 * @param  Y  y coordinate on screen (0-6, rows)
 * @param  *s  string
 * @return none
 */
void LCD_write_english_string(unsigned char X, unsigned char Y, char *s);

/**
 * @brief  Write string to next location 
 * @param  *s  string
 * @return none
 */
void LCD_write_english_string_continue(char *s);

/**
 * @brief  Write string to next location with precise length
 * @param  *s  string
 * @param  data_len  number of chars
 * @return none
 */
void LCD_write_english_string_continue_precise(char *s, uint16_t data_len);

/**
 * @brief  Write single char to display (using english_font.h)
 * @param  c  char to be displayed
 * @return none
 */
void LCD_write_char(unsigned char c);

/**
 * @brief  Set cursor on the screen to precise location
 * @param  X  x coordinate on screen (0-84, columns)
 * @param  Y  y coordinate on screen (0-6, rows)
 * @return none
 */
void LCD_set_XY(unsigned char X, unsigned char Y);

/**
 * @brief  Display image consisting of bytes
 * @param  cells  *char containing image bytes
 * @param  cells_n number of bytes
 * @param  start_x  start x coordinate on screen (0-84, columns)
 * @param  start_y  start y coordinate on screen (0-6, rows)
 * @return none
 */
void LCD_write_whole_screen(unsigned char *cells, uint16_t cells_n, uint16_t start_x, uint16_t start_y);

/**
 * @brief  Display image consisting of bytes with defined length
 * after every n*length bytes new line is sent
 * @param  cells  *char containing image bytes
 * @param  width  width in bytes (pixels)
 * @param  size  number of bytes
 * @param  start_x  start x coordinate on screen (0-84, columns)
 * @param  start_y  start y coordinate on screen (0-6, rows)
 * @return none
 */
void LCD_write_bytes_xy_defined_width(unsigned char *cells, uint16_t width, uint16_t size, uint16_t x, uint16_t y);


#endif /* NOKIA_5110_LCD_H_ */