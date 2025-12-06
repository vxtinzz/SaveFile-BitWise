#ifndef SKILLS_H
#define SKILLS_H
#define MAX_SKILLS 3
#include "character.h"
#include "status.h"

typedef enum {
    BF_SHIELD,
    BF_HEAL,
    BF_COUNT
}SkillAction;

typedef struct{
    const char *name;
    Class_Type character;
    float critical_chance;
    uint32_t effect_flag;
    SkillAction action;
    unsigned int duration;
}SkillData;

extern SkillData skills_db[];
extern const int SKILLS_COUNT;

#endif