#ifndef VALIDATION_H
#define VALIDATION_H

#include "character.h"

int clamp_attributes(int attribute, int min, int max);
Character clamp_all(Character c);
int validate_attributes(Character c);

#endif