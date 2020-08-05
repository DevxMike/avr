#ifndef cm_m_h
#define cm_m_h
#include <avr/io.h>
#define PORT(x) SPORT(x) //those macros let us use some
#define SPORT(x) (PORT##x) //convenient stuff like i.e. PORT(PORT_DIG1) |= (1 << DIG1) 
#define DDR(x) SDDR(x) //instead of PORTx |= (1 << y)
#define SDDR(x) (DDR##x)
#define PIN(x) SPIN(x)
#define SPIN(x) (PIN##x)
#endif