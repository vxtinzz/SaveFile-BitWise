#ifndef STATUS_CONFIG_H
#define STATUS_CONFIG_H
#include <stdint.h>
#include "../include/bit_config.h"

#define STS_POISON (1u << (0 + SH_FLAGS))
#define STS_BURN (1u << (1 + SH_FLAGS))
#define STS_FROZEN (1u << (2 + SH_FLAGS))
#define STS_STUN (1u << (3 + SH_FLAGS))
#define STS_WEAKEN (1u << (4 + SH_FLAGS))
#define STS_COUNT 5

extern const char *STATUS_EFFECTS_NAMES[];

#endif