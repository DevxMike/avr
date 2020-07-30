#include <avr/io.h>
#include <stdbool.h>

#ifndef LED_DISP_h
#define LED_DISP_h

#define PORT_DIG4 D //com anodes
#define DIG4 0
#define PORT_DIG3 D
#define DIG3 1
#define PORT_DIG2 D
#define DIG2 2
#define PORT_DIG1 D
#define DIG1 3

#define A 6 //kathodes  
#define PORT_A B
#define B 7
#define PORT_B B
#define C 5
#define PORT_C D
#define DOT 2
#define PORT_DOT B
#define D 6
#define PORT_D D
#define E 7
#define PORT_E D
#define F 0
#define PORT_F B
#define G 1
#define PORT_G B

#define PORT(x) SPORT(x) 
#define SPORT(x) (PORT##x)
#define DDR(x) SDDR(x)
#define SDDR(x) (DDR##x)
#define PIN(x) SPIN(x)
#define SPIN(x) (PIN##x)


#endif