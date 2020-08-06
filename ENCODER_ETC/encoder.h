#ifndef encoder_h_
#define encoder_h_
#include "common_macros.h"
#define EN_A 2
#define PORT_EN D
#define EN_B 3
extern const uint8_t enc_states[];
void init_encoder(void);
void init_enc_int(void);
#endif