#include "encoder.h"

void init_encoder(){
    DDR(PORT_EN_A) &= ~(1 << EN_A);
    DDR(PORT_EN_B) &= ~(1 << EN_B);
    init_enc_int();
}
void init_enc_int(void){
    MCUCR |= (1 << ISC10) | (1 << ISC00);
    GICR |= (1 << INT1) | (1 << INT0);
}