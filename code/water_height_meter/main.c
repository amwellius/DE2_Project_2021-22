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
    //LCD_write_whole_screen((unsigned char *)init_msg_1, 504, 0);
    //_delay_ms(2000);
    LCD_clear();
    
    /* Replace with your application code */
    uint32_t distance_val = 0;
    char distance_str[4];
    while (1) 
    {
        LCD_clear();                                    // Clear lcd
        distance_val = (uint32_t) get_dist();           // Get distance in mm
        
        uint32_t float_p = distance_val % 10;           // Get decimal val in cm
        distance_val /= 10;                             // To cm
        itoa(distance_val, distance_str, 10);           // Convert to str
        uint16_t str_length = strlen(distance_str);     // Get str len
        LCD_write_english_string(0, 0, distance_str);   // Display in cm
        itoa(float_p, distance_str, 10);                
        LCD_write_english_string(6*str_length, 0, ",");
        LCD_write_english_string(6*(str_length+1), 0, distance_str);
        uint16_t str_2_length = strlen(distance_str);     // Get str len
        LCD_write_english_string(6*(str_length+str_2_length+1), 0, " cm");
        
        LCD_write_whole_screen((unsigned char*)water_level_img, 44, 40, 2);
        
        _delay_ms(300);
    }
}

