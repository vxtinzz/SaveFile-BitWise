#ifndef VALIDATION_H
#define VALIDATION_H

#include "character_types.h"

int clamp_attributes(int attribute, int min, int max);
Character clamp_all(Character c);
int validate_attributes(Character c);

#endif