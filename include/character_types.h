#ifndef CHARACTER_TYPES_H
#define CHARACTER_TYPES_H

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

typedef struct Character
{
    unsigned strength;
    unsigned life;
    unsigned classId;
    unsigned flags;
    unsigned level;
    unsigned skills;
} Character;

typedef struct CharacterPreset
{
    const char *name;
    unsigned baseClass;
    unsigned baseLife;
    unsigned baseStrength;
    unsigned baseSkills;
}CharacterPreset;

extern const char *CHARACTER_NAMES[];
extern const CharacterPreset CHARACTER_PRESET[];
#endif