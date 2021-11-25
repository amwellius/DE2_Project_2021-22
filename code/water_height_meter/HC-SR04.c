#ifndef F_CPU
#define F_CPU 16000000L
#endif

#include <avr/io.h>
#include <stdlib.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define HCSR_TRIGGER        PD7
#define HCSR_TRIGGER_PORT   PORTD
#define HCSR_TRIGGER_DDR    DDRD
#define TRIG                PD7
#define ECHO                PB0

// CPU-speed / Prescale = cycles/sec. 1sec/ freq./sec. = 4 (t= 4us/cycle)
#define US_PER_COUNT        ((uint32_t)4)

uint16_t counts;
uint32_t dist;

ISR(TIMER1_COMPA_vect)
{
    //Generate a 12us pulse to trigger the HC-SR04
    HCSR_TRIGGER_PORT ^= (1 << HCSR_TRIGGER);
    _delay_us(10);
    HCSR_TRIGGER_PORT ^= (1 << HCSR_TRIGGER);
}

/************************************************************************/
/** When a capture is triggered according to the ICES1 setting, the counter value is copied into the input capture register
*  (ICR1). The event will also set the input capture flag (ICF1), and this can be used to cause an input capture interrupt, if this
*  interrupt is enabled.
*/
/************************************************************************/

ISR(TIMER1_CAPT_vect)
{
    static uint16_t rising = 0, falling = 0;                        // For storing of rising/falling data
    
    if (TCCR1B & (1 << ICES1))                                      // Check input capture reg PB0
    {
        TCCR1B &= ~(1 << ICES1);                                    // Set to falling edge
        rising = ICR1;                                              // Read value ticks
    } else {
        TCCR1B |= (1 << ICES1);                                     // Rest to rising edge
        falling = ICR1;                                             // Read value ticks
        counts = falling - rising;                                  // Calc. difference between start and stop of the pulse
        dist = ((US_PER_COUNT * (uint32_t)counts) * 340) / 2000;    // Distance in mm
    }
}

void init_ultrasonic_sensor()
{
    // Setup trigger output
    HCSR_TRIGGER_DDR |= (1 << HCSR_TRIGGER);

    //****TIMER1 INIT Input capture init ****//
    TCCR1B |= (1 << ICNC1);                     // Noice reduction enable
    TCCR1B |= (1 << CS10) | (1 << CS11);        // Prescale to 64
    TCCR1B |= (1 << WGM12);                     // CTC
    TIMSK1 |= (1 << ICIE1) | (1 << OCIE1A);     // Enable timer 1 interrupt + enable OC interrupt
    TCCR1B |= (1 << ICES1);                     

    OCR1A = 17500;                              // Calculate TOP (70ms runtime for one cycle): 16MHz/64 = 250 kcount/sec. = 250k/1k = 250 count/us / 100*70 = 17500 count/70ms    

    sei();                                      //activate global interrupt
}

uint32_t get_dist()
{
    return dist;                                // return distance in mm
}

uint16_t get_cnt()
{
    return counts;                              // return counts difference (debug)
}