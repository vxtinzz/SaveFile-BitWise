#ifndef ATTRIBUTES_H
#define ATTRIBUTES_H

#include "character_types.h"

Character set_strength_struct(int value, Character *c);
Character set_life_struct(int value, Character *c);
Character set_class_struct(int value, Character *c);
Character set_level_struct(int value, Character *c);
Character set_flags_struct(int attributes, Character *c);
Character set_skills_struct(int value, Character *c);
void print_character(Character c);
#endif
