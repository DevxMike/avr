#include "encoder.h"

volatile uint8_t ENC_STATE = 0x00; //contains previous state (before the interrupt) and flags: 
                                 //0bxyz0000 - x: decreasing rotation, y: increasing rotation, z: idle
const uint8_t enc_states[] = { //possible states
    0x3, 0x1, 0x0, 0x2, 0x3
}; 

void init_enc_int(void){ //init int0, int1 pins for interrupt
    MCUCR |= (1 << ISC10) | (1 << ISC00);
    GICR |= (1 << INT1) | (1 << INT0);
    ENC_STATE |= IDLE_MASK;
}
void init_encoder(){
    DDR(PORT_EN) &= ~((1 << EN_A) | (1 << EN_B)); //set as input
    init_enc_int(); //init interrupts
}
