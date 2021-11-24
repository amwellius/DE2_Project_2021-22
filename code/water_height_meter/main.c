/*
 * water_height_meter.c
 *
 * Created: 20. 11. 2021 14:02:28
 * Author : gkaretka
 */ 

#include "main.h"

int main(void)
{
    LCD_init();                 // LCD initialization
    init_ultrasonic_sensor();   // Ultrasonic init
    
    // show init screen, sleep 5s
    LCD_write_init();  
    LCD_write_whole_screen((unsigned char *)init_msg_1, 504, 0);
    _delay_ms(2000);
    LCD_clear();
    
    /* Replace with your application code */
    uint32_t distance_val = 0;
    char distance_str[5];
    while (1) 
    {
        LCD_clear();                                    // Clear lcd
        distance_val = (uint32_t) get_dist();           // Get distance in mm
        itoa(distance_val, distance_str, 10);           // Convert to str
        LCD_write_english_string(0, 0, distance_str);   // Display
        LCD_write_english_string(6, 0, "mm");
        
        _delay_ms(1000);
    }
}

