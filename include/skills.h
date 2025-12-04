#ifndef SKILLS_H
#define SKILLS_H
#include "character.h"
#include "status.h"

typedef struct{
    const char *name;
    Class_Type character;
    float critical_chance;
    uint32_t effect_flag;
    unsigned int duration;
}SkillData;

extern SkillData skills_db[];
extern const int SKILLS_COUNT;

#endif