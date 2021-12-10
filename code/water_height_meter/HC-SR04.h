/**
 * @file 
 * @defgroup filip_ul Ultrasound sensor Library <HC-SR04.h>
 * @code #include "HC-SR04.h" @endcode
 * @brief HC-SR04 for AVR-GCC.
 *
 * The library contains functions for controlling HC-SR04 and getting distance, ticks and average distance.
 *
 * @{
 */
#ifndef HC_SR04_H_
#define HC_SR04_H_

/* Function prototypes -----------------------------------------------*/

/**
 * @name Functions
 */

/**
 * @brief  Init ultrasound sensor. Setup pins.
 * @return none
 */
void init_ultrasonic_sensor(void);

/**
 * @brief  Return last measured distance in mm
 * @return distance in mm
 */
uint32_t get_dist();

/**
 * @brief  Return average of 10 most recent measured distances in mm
 * @return distance in mm
 */
uint32_t get_dist_avg();

/**
 * @brief  Return counts of timer of input pulse
 * @return distance in mm
 */
uint32_t get_cnt();

#endif /* HC-SR04_H_ */