#ifndef spi_h
#define spi_h
#define SCK 5
#define PORT_SCK B
#define MOSI 3
#define PORT_MOSI B
#define SS 2
#define PORT_SS B
#include <avr/io.h>

#define PORT(x) SPORT(x) //those macros let us use some
#define SPORT(x) (PORT##x) //convenient stuff like i.e. PORT(PORT_DIG1) |= (1 << DIG1) 
#define DDR(x) SDDR(x) //instead of PORTx |= (1 << y)
#define SDDR(x) (DDR##x)
#define PIN(x) SPIN(x)
#define SPIN(x) (PIN##x)

void init_spi_MASTER(void);
void send_data(const uint8_t);
inline void set_OE(void){ //output  disable
    PORT(PORT_SS) |= (1 << SS);
}
inline void clr_OE(void){ //output enable
    PORT(PORT_SS) &= ~(1 << SS);
}
#endif