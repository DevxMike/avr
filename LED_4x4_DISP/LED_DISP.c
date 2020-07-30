#include <avr/io.h>
#include "LED_DISP.h"



void init_led(void){
    DDR(PORT_DIG1) |= (1 << DIG1);
    DDR(PORT_DIG2) |= (1 << DIG2);
    DDR(PORT_DIG3) |= (1 << DIG3);
    DDR(PORT_DIG4) |= (1 << DIG4);

    DDR(PORT_A_PIN) |= (1 << A_PIN);
    DDR(PORT_B_PIN) |= (1 << B_PIN);
    DDR(PORT_C_PIN) |= (1 << C_PIN);
    DDR(PORT_D_PIN) |= (1 << D_PIN);
    DDR(PORT_E_PIN) |= (1 << E_PIN);
    DDR(PORT_F_PIN) |= (1 << F_PIN);
    DDR(PORT_G_PIN) |= (1 << G_PIN);
    DDR(PORT_DOT) |= (1 << DOT);
}