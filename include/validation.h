#ifndef VALIDATION_H
#define VALIDATION_H

#include "character.h"

int clamp_attributes(int attribute, int min, int max);
int validate_attributes(Character c);

#endif