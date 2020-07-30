#ifndef LED_DISP_h_
#define LED_DISP_h_
#include <avr/io.h>
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
void demo(void);

inline void set_a(void){ //helpful inline functions to set or clear output (set 1 or 0)
    PORT(PORT_A_PIN) |= (1 << A_PIN);
}
inline void set_b(void){
    PORT(PORT_B_PIN) |= (1 << B_PIN);
}
inline void set_c(void){
    PORT(PORT_C_PIN) |= (1 << C_PIN);
}
inline void set_d(void){
    PORT(PORT_D_PIN) |= (1 << D_PIN);
}
inline void set_e(void){
    PORT(PORT_E_PIN) |= (1 << E_PIN);
}
inline void set_f(void){
    PORT(PORT_F_PIN) |= (1 << F_PIN);
}
inline void set_g(void){
    PORT(PORT_G_PIN) |= (1 << G_PIN);
}
inline void set_dot(void){
    PORT(PORT_DOT) |= (1 << DOT);
}
inline void set_dig1(void){
    PORT(PORT_DIG1) |= (1 << DIG1);
}
inline void set_dig2(void){
    PORT(PORT_DIG2) |= (1 << DIG2);
}
inline void set_dig3(void){
    PORT(PORT_DIG3) |= (1 << DIG3);
}
inline void set_dig4(void){
    PORT(PORT_DIG4) |= (1 << DIG4);
}

inline void clr_a(void){
    PORT(PORT_A_PIN) &= ~(1 << A_PIN);
}
inline void clr_b(void){
    PORT(PORT_B_PIN) &= ~(1 << B_PIN);
}
inline void clr_c(void){
    PORT(PORT_C_PIN) &= ~(1 << C_PIN);
}
inline void clr_d(void){
    PORT(PORT_D_PIN) &= ~(1 << D_PIN);
}
inline void clr_e(void){
    PORT(PORT_E_PIN) &= ~(1 << E_PIN);
}
inline void clr_f(void){
    PORT(PORT_F_PIN) &= ~(1 << F_PIN);
}
inline void clr_g(void){
    PORT(PORT_G_PIN) &= ~(1 << G_PIN);
}
inline void clr_dot(void){
    PORT(PORT_DOT) &= ~(1 << DOT);
}
inline void clr_dig1(void){
    PORT(PORT_DIG1) &= ~(1 << DIG1);
}
inline void clr_dig2(void){
    PORT(PORT_DIG2) &= ~(1 << DIG2);
}
inline void clr_dig3(void){
    PORT(PORT_DIG3) &= ~(1 << DIG3);
}
inline void clr_dig4(void){
    PORT(PORT_DIG4) &= ~(1 << DIG4);
}
#endif