#include "../include/attributes.h"
#include "../include/bitpack.h"
#include "../include/bit_attributes.h"
#include <stdio.h>


struct Character set_strength_struct(int attributes, Character *c)
{
    if (attributes > 63)
    {
        attributes = 63;
    }
    else if (attributes < 0)
    {
        attributes = 0;
    }
    c->strength = attributes;
    return *c;
}

struct Character set_life_struct(int attributes, Character *c)
{
    if (attributes > 255)
    {
        attributes = 255;
    }
    else if (attributes < 0)
    {
        attributes = 0;
    }
    c->life = attributes;
    return *c;
}

struct Character set_class_struct(int attributes, Character *c)
{
    if (attributes > 7)
    {
        attributes = 0;
    }
    else if (attributes < 0)
    {
        attributes = 0;
    }
    c->classId = attributes;
    return *c;
}

struct Character set_flags_struct(int attributes, Character *c)
{
    if (attributes > 31)
    {
        attributes = 31;
    }
    else if (attributes < 0)
    {
        attributes = 0;
    }
    c->flags = attributes;
    return *c;
}

struct Character set_level_struct(int attributes, Character *c)
{
    if (attributes > 99)
    {
        attributes = 99;
    }
    else if (attributes < 0)
    {
        attributes = 0;
    }
    c->level = attributes;
    return *c;
}

struct Character set_skills_struct(int attributes, Character *c)
{
    if (attributes > 7)
    {
        attributes = 7;
    }
    else if (attributes < 0)
    {
        attributes = 0;
    }
    c->skills = attributes;
    return *c;
}

void print_character(Character c)
{
    printf("=== CHARACTER ===\n");
    printf("Strength: %u\n", c.strength);
    printf("Life:     %u\n", c.life);
    printf("Class:    %u (%s)\n",
           c.classId,
           (c.classId < CLASS_COUNT ? CHARACTER_NAMES[c.classId] : "UNKNOWN"));
    printf("Flags:    %u\n", c.flags);
    printf("Level:    %u\n", c.level);
    printf("Skills:   %u\n", c.skills);

    // Print status effects
    printf("Status:   ");

    int hasStatus = 0;
    for (int i = 0; i < STS_COUNT; i++)
    {
        if (c.flags & (1u << i))
        {
            printf("%s ", STATUS_EFFECTS_NAMES[i]);
            hasStatus = 1;
        }
    }
    if (!hasStatus)
        printf("None");

    printf("\n");

    // Unlocked Skills
    printf("Unlocked Skills: ");

    SkillData classSkills[MAX_SKILLS];
    int count = get_skills_by_class(c.classId, classSkills);

    int printed = 0;

    for (int i = 0; i < count; i++)
    {
        if (c.skills & (1u << i))
        {
            printf("[%s] ", classSkills[i].name);
            printed = 1;
        }
    }

    if (!printed)
        printf("None");

    printf("\n");
}
