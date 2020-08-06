#ifndef shift_register_h
#define shift_register_h
#define LATCH 1
#define PORT_LATCH B
#include "common_macros.h"
#include "spi.h"

void init_register(void);
void init_enc_int(void);
inline void set_latch(void){ //set latch
    PORT(PORT_LATCH) |= (1 << LATCH);
}
inline void clr_latch(void){ //clear latch
    PORT(PORT_LATCH) &= ~(1 << LATCH);
}
void send_byte_to_reg(uint8_t);
#endif