/*
 * main.h
 *
 * Created: 24. 11. 2021 12:00:06
 *  Author: filip
 */ 


#ifndef HC_SR04_H_
#define HC_SR04_H_

void init_ultrasonic_sensor();

uint32_t get_dist();
uint32_t get_dist_avg();
uint32_t get_cnt();

#endif /* HC-SR04_H_ */