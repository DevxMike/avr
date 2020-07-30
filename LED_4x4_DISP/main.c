#include "timer.h"
#include "LED_DISP.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


uint8_t states[] = {
    0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90 //values that are going to be written to PORT_KATHODE reg to set 0 on certain pins
};
uint8_t disp_val[] = { //dig1 ... dig4 display value
    1, 2, 3, 4
};
uint8_t seg = 0x01; //starting value for PORT_DIG (0x01 writes 1 to dig1 pin)

int main(void){
    

    init_led(); //initialize display
    init_timer(); //initialize timer
    sei(); //global interrupt enable
    while(1){
        
    }
    return 0;
}

ISR(TIMER2_COMP_vect){
    static uint8_t index = 0;
    PORT(PORT_KATHODES) = states[disp_val[index++]]; //set PORT(PORT_KATHODES) value for disp_val that is indexed by index
    if(index > 3) index = 0;
    PORT(PORT_DIG) &= 0xF0; //multiply by 0xF0 so we are not changing the values that segments are not connected with and at the same time, we are setting 
                            //all dig`s to 0 so none of `em is active
    PORT(PORT_DIG) |= seg; //set segment to 1
    seg = seg << 1; //shift seg to the right by one place (multiply by 2)
    if(seg > 8) seg = 0x01; //if seg > 8 that means it has reached place after the last pin that the digit is attached to so start again from 0x01
}