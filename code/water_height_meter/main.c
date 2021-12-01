/*
 * water_height_meter.c
 *
 * Created: 20. 11. 2021 04:02:28
 * Author : gkaretka
 */ 

#include "main.h"

// Tank Volume
//**Enter values in cm !
#define TANK_X  ((uint32_t)50)
#define TANK_Y  ((uint32_t)50)
#define TANK_Z  ((uint32_t)100)

#define TANK_MAX_PERCENTAGE_NUM     ((uint32_t)9)
#define TANK_MAX_PERCENTAGE_DENUM   ((uint32_t)10)

// define array of images and their count
#define water_signs_cnt 12
#define TEST_SPEED_MS   100
// constant strings to be used to save some memory
const char *water_at_str = "Water at ";
const char *error = "Error";
const char *percentage = " %";

// X-Y coordinates of bucket
const uint16_t bucket_x = 84-15;
const uint16_t bucket_y = 1;
    
const char *all_water_states[] = {water_level_default, water_level_10, water_level_20,
                                  water_level_30, water_level_40, water_level_50,
                                  water_level_60, water_level_70, water_level_80,
                                  water_level_90, water_level_100, water_level_error};
    
char water_level_perc_str[] = "00";

void test_screen();

int main(void)
{
    LCD_init();                 // LCD initialization
    init_ultrasonic_sensor();   // Ultrasonic init
    
    // show init screen, sleep 5s
    LCD_write_init();
    
    // Test controlls like in car
    test_screen();
    
    /* Replace with your application code */
    uint32_t distance_val = 0;
    char distance_str[] = "0000";
    
    // in liters !
    // Main sensor is mounted 4cm above tank_max_height
    uint16_t tank_actual_volume;
    uint16_t tank_volume = (TANK_X * TANK_Y * TANK_Z) / 1000;
    uint16_t tank_max_height = (TANK_Z * TANK_MAX_PERCENTAGE_NUM) / TANK_MAX_PERCENTAGE_DENUM;
    uint32_t promile = 0;
    uint32_t percentage = 0;
    
    while (1) 
    {   
        // Getting distance
        LCD_clear();                                                            // Clear lcd
        distance_val = ((uint32_t) get_dist());                                 // Get distance in mm //-40 lebo je to 4cm nad hladinou
        distance_val -= 40;
        distance_val /= 10;
        tank_actual_volume = ((TANK_Z - distance_val) * TANK_X * TANK_Y) / 1000;
        
        if (tank_actual_volume > 1000 || tank_actual_volume < 0) {
            // display error
            itoa(tank_volume, distance_str, 10);
            LCD_write_english_string(0, 0, "Vmax:");
            LCD_write_english_string_continue("error");
                        
            // display error
            itoa(tank_actual_volume, distance_str, 10);
            LCD_write_english_string(0, 1, "Vact:");
            LCD_write_english_string_continue("error");
            
            // display percentage
            itoa(percentage, distance_str, 10);
            LCD_write_english_string(0, 2, "Vact:");
            LCD_write_english_string_continue("error");
            
            // display state
            itoa(percentage, distance_str, 10);
            LCD_write_english_string(0, 3, "System:");
            LCD_write_english_string(0, 4, "Error");
            
            LCD_write_bytes_xy_defined_width((unsigned char*)all_water_states[11], 14, 70, bucket_x, bucket_y);
        } else {
            promile = ((uint32_t)tank_actual_volume * 1000) / (uint32_t)tank_volume;    // promile
            percentage = promile / 10;
                        
            uint16_t selector = 11;
            uint16_t cnt = 0;
            for (uint32_t i = 0; i <= 90; i+=10) {
                if (percentage >= i && percentage <= i+9) {
                    selector = cnt;
                }
                cnt++;
            }
                        
            if (percentage == 100) selector = 10;
            if (selector == 0) {            
                LCD_write_bytes_xy_defined_width((unsigned char*)water_level_default, 14, 70, bucket_x, bucket_y);
            } else {
                LCD_write_bytes_xy_defined_width((unsigned char*)all_water_states[selector], 14, 70, bucket_x, bucket_y);
            }            
            
            // display maximum
            itoa(tank_volume, distance_str, 10);
            LCD_write_english_string(0, 0, "Vmax:");
            LCD_write_english_string_continue(distance_str);
            LCD_write_english_string_continue(" L");
        
            // display actual
            itoa(tank_actual_volume, distance_str, 10);
            LCD_write_english_string(0, 1, "Vact:");
            LCD_write_english_string_continue(distance_str);
            LCD_write_english_string_continue(" L");
            
            // display percentage
            itoa(percentage, distance_str, 10);
            LCD_write_english_string(0, 2, "Vact:");
            LCD_write_english_string_continue(distance_str);
            LCD_write_english_string_continue(" %");
            
            // display state
            itoa(percentage, distance_str, 10);
            LCD_write_english_string(0, 3, "System:");
            LCD_write_english_string(0, 4, "OK");
        }
        
        //all_water_states;
        _delay_ms(300);                                                         // refresh rate
     }
}

void test_screen()
{
    LCD_clear();

    
    // show all images    
    for (uint8_t i = 0; i < water_signs_cnt; i++) {
        LCD_clear();
        
        // display string in top row displaying percentage/error
        LCD_write_english_string(0, 0, (char*)water_at_str);
        if (i <= 10) {
            itoa(i*10, water_level_perc_str, 10);
            LCD_write_english_string_continue((char*)water_level_perc_str);
            LCD_write_english_string_continue((char*)percentage);
        } else {
            LCD_write_english_string_continue((char*)error);
        }
                   
        // write bucket
        LCD_write_bytes_xy_defined_width((unsigned char*)all_water_states[i], 14, 70, bucket_x, bucket_y);
        _delay_ms(TEST_SPEED_MS);
        
        // some delay
        if (i == (water_signs_cnt - 1))
            _delay_ms(TEST_SPEED_MS); // longer delay on last msg
    }
    LCD_clear();
    return;
}
