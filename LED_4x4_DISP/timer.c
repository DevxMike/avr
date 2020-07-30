#include <avr/io.h>
#include "timer.h"

void init_timer(){
    TCCR2 |= (1 << WGM21); //CTC mode enable
    TCCR2 |= (1 << CS22) | (1 << CS21) | (1 << CS20); //set 1024 prescaler
    TIMSK |= (1 << OCIE2); //Compare Match Interrupt Enable
    OCR2 |= (0x00); //impulses before interrupt !!!TO BE MODIFIED!!!
}