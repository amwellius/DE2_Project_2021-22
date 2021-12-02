#define LED PB5
#ifndef F_CPU
# define F_CPU 16000000     // CPU frequency in Hz required for delay
#endif
/* Includes ----------------------------------------------------------*/
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include <util/delay.h>
#include "timer.h"          // Timer library for AVR-GCC
#include <stdlib.h>         // C library. Needed for conversion function
#include "gpio.h"
#include "uart.h" 
/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Use Timer/Counter1 and start ADC conversion four times 
 *           per second. Send value to LCD and UART.
 * Returns:  none
 **********************************************************************/
int main(void)
{
    GPIO_config_output(&DDRB, LED);
    GPIO_write_low(&PORTB, LED);
    // Configure ADC to convert PC0[A0] analog value
    // Set ADC reference to AVcc
    ADMUX &= ~(1<<REFS1); ADMUX |= (1<<REFS0);
    // Set input channel to ADC0
    ADMUX &= ~((1<<MUX3) | (1<<MUX2) | (1<<MUX1) | (1<<MUX0));
    // Enable ADC module
    ADCSRA |= (1<<ADEN);
    // Enable conversion complete interrupt
    ADCSRA |= (1<<ADIE);
    // Set clock prescaler to 128
    ADCSRA |= (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);
    // Configure 16-bit Timer/Counter1 to start ADC conversion
    // Set prescaler to 262 ms and enable overflow interrupt
    TIM1_overflow_interrupt_enable();
    TIM1_overflow_262ms();
    uart_init(UART_BAUD_SELECT(9600, F_CPU));
    sei();

    // Infinite loop
    while (1)
    {
        /* Empty loop. All subsequent operations are performed exclusively 
         * inside interrupt service routines ISRs */
    }

    // Will never reach this
    return 0;
}

/* Interrupt service routines ----------------------------------------*/
/**********************************************************************
 * Function: Timer/Counter1 overflow interrupt
 * Purpose:  Use single conversion mode and start conversion four times
 *           per second.
 **********************************************************************/
ISR(TIMER1_OVF_vect)
{
    // Start ADC conversion
    ADCSRA |= (1<<ADSC);

}

/**********************************************************************
 * Function: ADC complete interrupt
 * Purpose:  Display value on LCD and send it to UART.
 **********************************************************************/
ISR(ADC_vect)
{
    // WRITE YOUR CODE HERE
    
    uint16_t value = 0;
    

    value = ADC;    // Copy ADC result to 16-bit variable 
    

    if(value >= 870){
        
        
        _delay_ms(500);
        GPIO_write_low(&PORTB, LED);
        
        }else{
        _delay_ms(500);
        GPIO_write_high(&PORTB, LED);
          
    
    }
}
