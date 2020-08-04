#include "shift_register.h"

void init_register(void){
    DDR(PORT_LATCH) |= (1 << LATCH);
    clr_latch();
}
void send_byte_to_reg(uint8_t data){
    clr_latch(); //turn off latch
    set_OE(); //disable outputs
    send_data(data); //send data
    set_latch(); //transfer data from shift register to it`s storage
    clr_OE(); //turn on outputs
}