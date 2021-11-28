/*
 * water_height_meter.c
 *
 * Created: 20. 11. 2021 04:02:28
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
    uint32_t extra_sens = 0;
    char distance_str[4];
    char errors[10];
    while (1) 
    {   
        // Tank Volume
        //**Enter values in cm !
        
        uint32_t tank_x = 100;
        uint32_t tank_y = 100;
        uint32_t tank_z = 80;       // height
        
        uint32_t tank_actual_volume;
        uint32_t tank_volume = tank_x * tank_y * tank_z * 0.001;    // in liters !
        uint32_t tank_max_height = tank_z * 0.90        // Main sensor is mounted 4cm above tank_max_height
        
        
        
        // Getting distance
        LCD_clear();                                    // Clear lcd
        distance_val = (uint32_t) get_dist() - 40;           // Get distance in mm //-40 lebo je to 4cm nad hladinou
        
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
        
        // Getting data from extra sensor 
        /* 
            <=100    = EMPTY/NORMAL
            >100     = DIRTY/ERROR                    
        */
        
        if (extra_sens >100 ){
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
        }    
     }
        }
}

