#ifndef encoder_h_
#define encoder_h_
#include "common_macros.h"
#define EN_A 2
#define PORT_EN D
#define EN_B 3
#define DECREASE_MASK 0x80
#define INCREASE_MASK 0x40
#define IDLE_MASK 0x20

extern const uint8_t enc_states[];
extern volatile uint8_t ENC_STATE;
void init_encoder(void);
void init_enc_int(void);
#endif