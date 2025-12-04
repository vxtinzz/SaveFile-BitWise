#include "../include/bit_attributes.h"
#include <stdio.h>

void set_strength_packed(int attributes, uint32_t *packed)
{
    if (attributes > 63)
    {
        attributes = 63;
    }
    else if (attributes < 0)
    {
        attributes = 0;
    }
    *packed &= ~(MSK_STRENGTH << SH_STRENGTH);
    *packed |= (attributes & MSK_STRENGTH) << SH_STRENGTH;
}

void set_life_packed(int attributes, uint32_t *packed)
{
    if (attributes > 255)
    {
        attributes = 255;
    }
    else if (attributes < 0)
    {
        attributes = 0;
    }
    *packed &= ~(MSK_LIFE << SH_LIFE);
    *packed |= (attributes & MSK_LIFE) << SH_LIFE;
}

void set_class_packed(int attributes, uint32_t *packed)
{
    if (attributes > 7)
    {
        attributes = 0;
    }
    else if (attributes < 0)
    {
        attributes = 0;
    }
    *packed &= ~(MSK_CLASS << SH_CLASS);
    *packed |= (attributes & MSK_CLASS) << SH_CLASS;
}

void set_flag_bit_packed(int bitIndex, uint32_t *packed)
{
    if (bitIndex < 5 && bitIndex >= 0)
    {
        *packed |= (1u << (bitIndex + SH_FLAGS));
    }
    else
    {
        fprintf(stderr, "Invalid BitIndex %d", bitIndex);
    }
}

void clear_flags_packed(uint32_t *packed)
{
    *packed &= ~(MSK_FLAGS << SH_FLAGS);
}

void toggle_flag_bit_packed(int bitIndex, uint32_t *packed)
{
    if (bitIndex >= 0 && bitIndex < 5)
    {
        *packed ^= (1u << (bitIndex + SH_FLAGS));
    }
}

void set_level_packed(int attributes, uint32_t *packed)
{
    if (attributes > 99)
    {
        attributes = 99;
    }
    else if (attributes < 0)
    {
        attributes = 0;
    }
    *packed &= ~(MSK_LEVEL << SH_LEVEL);
    *packed |= (attributes & MSK_LEVEL) << SH_LEVEL;
}

void set_skills_packed(int attributes, uint32_t *packed)
{
    if (attributes > 7)
    {
        attributes = 7;
    }
    else if (attributes < 0)
    {
        attributes = 0;
    }
    *packed &= ~(MSK_SKILLS << SH_SKILLS);
    *packed |= (attributes & MSK_SKILLS) << SH_SKILLS;
}

uint32_t get_strength_packed(uint32_t *packed)
{
    return (*packed >> SH_STRENGTH) & MSK_STRENGTH;
}

uint32_t get_life_packed(uint32_t *packed)
{
    return (*packed >> SH_LIFE) & MSK_LIFE;
}

uint32_t get_class_bit_packed(uint32_t *packed)
{
    return (*packed >> SH_CLASS) & MSK_CLASS;
}

uint32_t get_flag_bit_packed(int bitindex, uint32_t packed)
{
    if (bitindex > 0 && bitindex < 5)
    {
        return (packed >> (bitindex + SH_FLAGS)) & 1u;
    }
    else
    {
        fprintf(stderr, "Invalid BitIndex %d", bitindex);
        return 0;
    }
}

uint32_t get_level_packed(uint32_t *packed)
{
    return (*packed >> SH_LEVEL) & MSK_LEVEL;
}

uint32_t get_skills_packed(uint32_t *packed)
{
    return (*packed >> SH_SKILLS) & MSK_SKILLS;
}
