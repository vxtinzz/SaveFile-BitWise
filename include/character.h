#ifndef CHARACTER_H
#define CHARACTER_H
#include "config.h"
#include <stdint.h>

typedef enum
{
    CLASS_TYPE_DEATH_K,
    CLASS_TYPE_SHADOW_S,
    CLASS_TYPE_PYRO,
    CLASS_TYPE_FROST_W,
    CLASS_TYPE_MURDEROUS,
    CLASS_TYPE_COLOSSUS,
    CLASS_TYPE_DRUID,
    CLASS_COUNT
} Class_Type;

extern const char *CHARACTER_NAMES[];

typedef struct Character
{
    unsigned strength;
    unsigned life;
    unsigned class;
    unsigned flags;
    unsigned level;
    unsigned skills;
} Character;
#endif