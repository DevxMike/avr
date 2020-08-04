#ifndef spi_h
#define spi_h
#include "LED_DISP.h"
#define SCK 5
#define PORT_SCK B
#define MOSI 3
#define PORT_MOSI B
#define SS 2
#define PORT_SS B

void init_spi_MASTER(void);
void send_data(const uint8_t);
inline void set_OE(void){ //output  disable
    PORT(PORT_SS) |= (1 << SS);
}
inline void clr_OE(void){ //output enable
    PORT(PORT_SS) &= ~(1 << SS);
}
#endif