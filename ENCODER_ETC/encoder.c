#include "encoder.h"

void init_encoder(){
    DDR(PORT_EN_A) &= (1 << EN_A);
    DDR(PORT_EN_B) &= (1 << EN_B);
    PORT(PORT_EN_A) |= (1 << EN_A);
    PORT(PORT_EN_B) |= (1 << EN_B);
}