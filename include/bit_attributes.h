#ifndef BIT_ATTRIBUTES_H
#define BIT_ATTRIBUTES_H

#include <stdint.h>
#include "character.h"
#include "config.h"

// setters
void set_strength_packed(int attrib, uint32_t *packed);
void set_life_packed(int attrib, uint32_t *packed);
void set_class_packed(int attrib, uint32_t *packed);
void set_level_packed(int attrib, uint32_t *packed);
void set_skills_packed(int attrib, uint32_t *packed);

// flags
void set_flag_bit_packed(int bitIndex, uint32_t *packed);
void toggle_flag_bit_packed(int bitIndex, uint32_t *packed);
void clear_flags_packed(uint32_t *packed);

// getters
uint32_t get_strength_packed(uint32_t *packed);
uint32_t get_life_packed(uint32_t *packed);
uint32_t get_class_bit_packed(uint32_t *packed);
uint32_t get_flag_bit_packed(int bitindex, uint32_t packed);
uint32_t get_level_packed(uint32_t *packed);
uint32_t get_skills_packed(uint32_t *packed);

#endif
