#ifndef LED_DISP_h_
#define LED_DISP_h_
#include <avr/io.h>
#include <stdbool.h>
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

#define A_PIN 0 //kathodes  
#define PORT_KATHODES  D
#define B_PIN  1
#define C_PIN  2
#define D_PIN  3
#define E_PIN  4
#define F_PIN  5
#define G_PIN  6
#define DOT 7

void init_led(void); //initialize led display
#endif