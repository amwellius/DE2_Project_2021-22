/*
 * water_height_meter.c
 *
 * Created: 20. 11. 2021 14:02:28
 * Author : gkaretka
 */ 

#ifndef F_CPU
    #define F_CPU 16000000L
#endif

#include "main.h"

int main(void)
{
    LCD_init();       //LCD initialization
    
    // show init screen, sleep 5s
    LCD_write_init();  
    _delay_ms(2000);
    LCD_clear();
    
    LCD_write_english_string(0, 0, "Hello World !");
    #ifdef ARDUINO_MEGA
    LCD_write_english_string(0, 1, "Communicating with AVR 2560 ");
    #else
    LCD_write_english_string(0, 1, "Communicating with AVR 328p ");
    #endif
    
    /* Replace with your application code */
    uint8_t i = 0;
    
    while (1) 
    {
        LCD_clear();
        LCD_write_whole_screen(water_level_img, 84, i/10);
        //itoa(i, transmit_char, 10);
        //LCD_write_english_string(0, 0, transmit_char);
        _delay_ms(100);
        i++;
    }
}

