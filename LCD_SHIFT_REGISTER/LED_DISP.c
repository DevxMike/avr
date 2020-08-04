#include "LED_DISP.h"
//74HC595 register
void init_led(void){
    PORT(PORT_DIG) |= (1 << DIG1) | (1 << DIG2) | (1 << DIG3) | (1 << DIG4);
}