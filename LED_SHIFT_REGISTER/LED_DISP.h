#ifndef led_disp_h
#define led_disp_h
#include <avr/io.h>

#define PORT(x) SPORT(x) //those macros let us use some
#define SPORT(x) (PORT##x) //convenient stuff like i.e. PORT(PORT_DIG1) |= (1 << DIG1) 
#define DDR(x) SDDR(x) //instead of PORTx |= (1 << y)
#define SDDR(x) (DDR##x)
#define PIN(x) SPIN(x)
#define SPIN(x) (PIN##x)

#define DIG4 3
#define DIG3 2
#define DIG2 1
#define DIG1 0
#define PORT_DIG C
void init_led(void);
#endif