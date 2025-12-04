#ifndef BITPACK_H
#define BITPACK_H

#include <stdint.h>
#include "character.h"

uint32_t pack_character(Character c);
Character unpack_character(uint32_t save);

#endif
