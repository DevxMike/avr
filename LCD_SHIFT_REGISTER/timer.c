#include "timer.h"
void init_timer(){
    TCCR2 |= (1 << CS22); //set 64 prescaler
    TCCR2 |= (1 << WGM21) | (1 << COM21); //CTC mode enable
    TIMSK |= (1 << OCIE2); //Compare Match Interrupt Enable
    OCR2 |= (0x4F); //impulses before interrupt
}   