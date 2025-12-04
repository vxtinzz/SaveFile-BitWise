#include "../include/attributes.h"

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
    c->class = attributes;
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