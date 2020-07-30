#ifndef LED_DISP_h_
#define LED_DISP_h_

#define PORT(x) SPORT(x) //those macros let us use some
#define SPORT(x) (PORT##x) //convenient stuff like i.e. PORT(PORT_RS) |= (1 << RS) 
#define DDR(x) SDDR(x) //instead of PORTx |= (1 << RS)
#define SDDR(x) (DDR##x)
#define PIN(x) SPIN(x)
#define SPIN(x) (PIN##x)

#define DIG4 0
#define PORT_DIG4 D //com anodes
#define DIG3 1
#define PORT_DIG3 D
#define DIG2 2
#define PORT_DIG2 D
#define DIG1 3
#define PORT_DIG1 D

#define A_PIN 6 //kathodes  
#define PORT_A_PIN  B
#define B_PIN  7
#define PORT_B_PIN  B
#define C_PIN  5
#define PORT_C_PIN  D
#define DOT 2
#define PORT_DOT B
#define D_PIN  6
#define PORT_D_PIN  D
#define E_PIN  7
#define PORT_E_PIN  D
#define F_PIN  0
#define PORT_F_PIN  B
#define G_PIN  1
#define PORT_G_PIN  B

void init_led(void);
void set_output(void);

#endif