#include "../include/bit_attributes.h"
#include "../include/bit_config.h"
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

void clear_skills_bit_packed(int bitIndex, uint32_t *packed)
{
    if (bitIndex < 5 && bitIndex >= 0)
    {
        *packed &= ~(1u << (bitIndex + SH_SKILLS));
    }
    else
    {
        fprintf(stderr, "Invalid BitIndex %d", bitIndex);
    }
}

void toggle_skills_packed(int bitIndex, uint32_t *packed)
{
    if (bitIndex < 0 || bitIndex >= MAX_SKILLS)
        return;
    uint32_t skills = get_skills_packed(packed);

    skills ^= (1u << bitIndex);

    *packed &= ~(MSK_SKILLS << SH_SKILLS);
    *packed |= (skills & MSK_SKILLS) << SH_SKILLS;
}

void set_skills_bit_packed(int bitIndex, uint32_t *packed)
{
    if (bitIndex < 0 || bitIndex >= MAX_SKILLS)
        return;

    uint32_t skills = get_skills_packed(packed);

    skills |= (1u << bitIndex);

    *packed &= ~(MSK_SKILLS << SH_SKILLS);
    *packed |= (skills & MSK_SKILLS) << SH_SKILLS;
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
    if (bitindex >= 0 && bitindex < 5)
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

uint32_t get_unlocked_skills_packed(int bitIndex, uint32_t *packed)
{
    uint32_t unlocked = get_skills_packed(packed);
    return (unlocked & (1u << bitIndex)) ? 1 : 0;
}

uint32_t apply_status_packed(uint32_t status, uint32_t *packed)
{
    return *packed |= status;
}

const char *has_class_name_packed(uint32_t *packed)
{
    uint32_t index_class = get_class_bit_packed(packed);
    if (index_class >= CLASS_COUNT)
    {
        return "Type Unknown";
    }
    return CHARACTER_NAMES[index_class];
}

int get_skills_by_class(uint32_t classType, SkillData *skills_out)
{
    int count = 0;

    for (int i = 0; i < SKILLS_COUNT; i++)
    {
        if (skills_db[i].character == classType)
        {
            skills_out[count++] = skills_db[i];
            if (count >= MAX_SKILLS)
                break;
        }
    }
    return count;
}

void print_unlocked_skills(uint32_t *packed){
    SkillData skills[MAX_SKILLS];

    int count = get_skills_by_class(get_class_bit_packed(packed), skills);
    const char *className = has_class_name_packed(packed);
    int unlocked_count = 0;
    
    for (int i = 0; i < count; i++)
    {
        int unlocked = get_unlocked_skills_packed(i, packed);
        if (unlocked)
        {
            unlocked_count++;
        }
    }
    if(unlocked_count != 1)
    printf("%d Skills da classe %s encontradas:\n", unlocked_count, className);
    else
    printf("%d Skill da classe %s encontrada:\n", unlocked_count, className);
    for (int i = 0; i < count; i++)
    {
        int unlocked = get_unlocked_skills_packed(i, packed);
        if (unlocked)
        {
            printf("[%d] Name: %s | Critical Chance: %.2f | Duration:%u\n",
                   i+1, skills[i].name, skills[i].critical_chance, skills[i].duration);
        }
    }
}