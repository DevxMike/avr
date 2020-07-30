#include "LED_DISP.h"

void init_led(){ 
    DDR(PORT_DIG) |= (1 << DIG1) | (1 << DIG2) | (1 << DIG3) | (1 << DIG4);
    DDR(PORT_KATHODES) |= (1 << A_PIN) | (1 << B_PIN) | (1 << C_PIN) | (1 << D_PIN);
    DDR(PORT_KATHODES) |= (1 << E_PIN) | (1 << F_PIN) | (1 << G_PIN) | (1 << DOT); //set outputs connected to led display
}