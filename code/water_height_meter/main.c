/*
 * water_height_meter.c
 *
 * Created: 20. 11. 2021 04:02:28
 * Author : gkaretka
 */ 

#include "main.h"

void test_screen();

// constant strings to be used to save some memory
const char *water_at_str = "Water at ";
const char *error = "Error";
const char *percentage = " %";

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
    char distance_str[4] = "0000";
    while (1) 
    {   
        // Tank Volume
        //**Enter values in cm !
        
        uint32_t tank_x = 100;
        uint32_t tank_y = 100;
        uint32_t tank_z = 80;       // height
        
        uint32_t tank_actual_volume;
        uint32_t tank_volume = tank_x * tank_y * tank_z * 0.001;                // in liters !
        uint32_t tank_max_height = tank_z * 0.90;                               // Main sensor is mounted 4cm above tank_max_height
        
        // Getting distance
        LCD_clear();                                                            // Clear lcd
        distance_val = (uint32_t) get_dist() - 40;                              // Get distance in mm //-40 lebo je to 4cm nad hladinou
        
        uint32_t float_p = distance_val % 10;                                   // Get decimal val in cm
        distance_val /= 10;                                                     // To cm
        itoa(distance_val, distance_str, 10);                                   // Convert to str
        LCD_write_english_string(0, 0, distance_str);                           // Display in cm
        itoa(float_p, distance_str, 10);                                        // Get char distance 
        LCD_write_english_string_continue(",");                                 // write comma (,)
        LCD_write_english_string_continue(distance_str);                        // write distance after decimal point (.xxx)
        LCD_write_english_string_continue(" cm");                               // write unit ( cm)

        _delay_ms(300);                                                         // refresh rate
        // Getting data from extra sensor 
        /* 
            <=100    = EMPTY/NORMAL
            >100     = DIRTY/ERROR                    
        */
        
        /*if (extra_sens >100 ){
            LCD_write_english_string(0, 0, "Dirty water or main sensor problem!");
            //vypise ERORR a ukaze znak water_lever_error
        }            
        else{          
        
            //Water level
        
            if ( (distance_val > 0) && (distance_val < tank_max_height*0.1) ) {
                //0 - 9 %
                //zobrazit na display %, objem
                tank_actual_volume = tank_x * tank_y * distance_val * 0.001;
            }
            else if ( (distance_val >= tank_max_height*0.1) && (distance_val < tank_max_height*0.2) ){
                //10 - 19 %
                //zobrazit na display %, objem
                tank_actual_volume = tank_x * tank_y * distance_val * 0.001;
            }
            else if ( (distance_val >= tank_max_height*0.2) && (distance_val < tank_max_height*0.3) ){
                //20 - 29 %
                //zobrazit na display %, objem
                tank_actual_volume = tank_x * tank_y * distance_val * 0.001;
            }
            else if ( (distance_val >= tank_max_height*0.3) && (distance_val < tank_max_height*0.4) ){
                //30 - 39 %
                //zobrazit na display %, objem
                tank_actual_volume = tank_x * tank_y * distance_val * 0.001;
            }
            else if ( (distance_val >= tank_max_height*0.4) && (distance_val < tank_max_height*0.5) ){
                //40 - 49 %
                //zobrazit na display %, objem
                tank_actual_volume = tank_x * tank_y * distance_val * 0.001;
            }
            else if ( (distance_val >= tank_max_height*0.5) && (distance_val < tank_max_height*0.6) ){
                //50 - 59 %
                //zobrazit na display %, objem
                tank_actual_volume = tank_x * tank_y * distance_val * 0.001;
            }
            else if ( (distance_val >= tank_max_height*0.6) && (distance_val < tank_max_height*0.7) ){
                //60 - 69 %
                //zobrazit na display %, objem
                tank_actual_volume = tank_x * tank_y * distance_val * 0.001;
            }
            else if ( (distance_val >= tank_max_height*0.7) && (distance_val < tank_max_height*0.8) ){
                //70 - 79 %
                //zobrazit na display %, objem
                tank_actual_volume = tank_x * tank_y * distance_val * 0.001;
            }
            else if ( (distance_val >= tank_max_height*0.8) && (distance_val < tank_max_height*0.9) ){
                //80 - 89 %
                //zobrazit na display %, objem
                tank_actual_volume = tank_x * tank_y * distance_val * 0.001;
            }
            else if (distance_val >= tank_max_height*0.9){
                //90 - 100 %
                //zobrazit na display %, objem
                tank_actual_volume = tank_x * tank_y * distance_val * 0.001;
            }
            else if (distance_val > tank_max_height){
                //vypise zle umiestneny sensor
                LCD_write_english_string(0, 0, "Sensor wrong calibration!");
                //
                //
            }
            else{
                // another ERROR message
                LCD_clear();
                LCD_write_english_string(0, 0, "ERROR: Check whole system!");
            }
        }    */
     }
}

void test_screen()
{
    LCD_clear();
    // X-Y coordinates of bucket
    uint16_t x = 84-15;
    uint16_t y = 1;
    
    // define array of images and their count
    #define water_signs_cnt 12
    #define TEST_SPEED_MS   100
    const char *all_water_states[water_signs_cnt] = {water_level_default, water_level_10, water_level_20, 
                                           water_level_30, water_level_40, water_level_50, 
                                           water_level_60, water_level_70, water_level_80,
                                           water_level_90, water_level_100, water_level_error};
    
    char water_level_perc_str[2] = "00";
    
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
        LCD_write_bytes_xy_defined_width((unsigned char*)all_water_states[i], 14, 70, x, y);
        _delay_ms(TEST_SPEED_MS);
        
        // some delay
        if (i == (water_signs_cnt - 1))
            _delay_ms(TEST_SPEED_MS); // longer delay on last msg
    }
    
    return;
}
