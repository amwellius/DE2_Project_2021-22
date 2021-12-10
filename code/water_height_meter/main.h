/*
 * main.h
 *
 * Created: 24. 11. 2021 11:43:41
 *  Author: gkaretka
 */ 

/**
 * @file 
 * @defgroup knob_kocum_karetka_kosik_main Main static <main.h>
 * @code #include "main.h" @endcode
 *
 * @brief Main file consists of functions and definitions for displaying data, water tank dimensions, calculations and other.  
 * @{
 */


#ifndef MAIN_H_
#define MAIN_H_

#ifndef F_CPU
#define F_CPU 16000000L
#endif

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#include "water_symbols.h"
#include "nokia_5110_lcd.h"
#include "HC-SR04.h"
#include "gpio.h"
#include "timer.h"
#include <string.h>

#endif /* MAIN_H_ */