/*
 * HC_SR04.h
 *
 * Created: 24.11.2021 12:20:47
 *  Author: student
 */ 


#ifndef HC_SR04_H_
#define HC_SR04_H_

void init_ultrasonic_sensor();

float get_dist();
uint16_t get_cnt();



#endif /* HC-SR04_H_ */