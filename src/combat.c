#include "../include/config.h"
#include "../include/character.h"
#include "../include/combat.h"
#include "../include/bit_attributes.h"
#include "../include/skills_structs.h"
#include "../include/status.h"
#include "../include/affinity.h"
#include <string.h>
#include <time.h>
#include <stdlib.h>

void apply_damage_packed(uint32_t *packed, int damage)
{
    int life = (*packed >> SH_LIFE) & MSK_LIFE;
    life -= damage;
    if (life <= 0)
    {
        life = 0;
    }
    *packed &= ~(MSK_LIFE << SH_LIFE);
    *packed |= (life & MSK_LIFE) << SH_LIFE;
}

struct Character apply_damage_struct(Character *c, int damage)
{
    c->life -= damage;
    if (c->life <= 0)
    {
        c->life = 0;
    }
    return *c;
}

void apply_heal_packed(uint32_t *packed, int heal)
{
    int life = (*packed >> SH_LIFE) & MSK_LIFE;
    life += heal;
    if (life > 255)
    {
        life = 255;
    }
    *packed &= ~(MSK_LIFE << SH_LIFE);
    *packed |= (life & MSK_LIFE) << SH_LIFE;
}

struct Character apply_heal_struct(Character *c, int heal)
{
    c->life += heal;
    if (c->life > 255)
    {
        c->life = 255;
    }
    return *c;
}

void remove_status_effect_packed(uint32_t *packed, int status_target)
{
    if (status_target < 5 && status_target >= 0)
    {
        *packed &= ~(1u << (status_target + SH_FLAGS));
    }
}

const char *has_status_effect(uint32_t *packed)
{
    static char STATUS_RETURN[100];
    STATUS_RETURN[0] = "\0";
    int count = 0;
    for (int i = 0; i < 5; i++)
    {
        if (((*packed >> (i + SH_FLAGS)) & 1u) == 1)
        {
            if (count > 0)
            {
                strcat(STATUS_RETURN, ", ");
            }
            strcat(STATUS_RETURN, STATUS_EFFECTS_NAMES[i]);
            count++;
        }
    }
    if (count == 0)
        strcpy(STATUS_RETURN, "None");

    return STATUS_RETURN;
}

const char *has_class_packed(uint32_t *packed)
{
    uint32_t index_class = get_class_bit_packed(packed);
    if (index_class >= CLASS_COUNT)
    {
        return "Type Unknown";
    }
    return CHARACTER_NAMES[index_class];
}

float get_affinity_multiplier(uint32_t attacker, uint32_t target)
{
    for (int i = 0; i < AFFINITY_COUNT; i++)
    {
        if (AFFINITYRULES[i].attacker == attacker && AFFINITYRULES[i].target == target)
        {
            return AFFINITYRULES[i].multiplier;
        }
    }
    return 1.0f;
}

int calculate_basic_attack(uint32_t *attacker, uint32_t *target)
{
    int strength = get_strength_packed(attacker);
    int level = get_level_packed(attacker);
    float attack = strength + (level * 0.3f);

    // verification affinityrules
    float bonusDmg = get_affinity_multiplier(get_class_bit_packed(attacker), get_class_bit_packed(target));
    attack *= bonusDmg;
    // verification debuffs on attacker
    if (*attacker & STS_WEAKEN)
        attack *= 0.7f;
    // verification debuffs on target
    if (*target & STS_BURN || *target & STS_FROZEN || *target & STS_POISON)
    {
        if ((rand() % 100) < 20)
            attack *= 2;
    }
    if (attack < 1)
        attack = 1;

    return (int)attack;
}

int calculate_skill_attack(uint32_t *attacker, uint32_t *target, SkillData *skill)
{
    if (skill == NULL)
    {
        return calculate_basic_attack(attacker, target);
    }
    int strength = get_strength_packed(attacker);
    int level = get_level_packed(attacker);
    float attack = strength + (level * 0.3f);

    // verification affinityrules
    float bonusDmg = get_affinity_multiplier(get_class_bit_packed(attacker), get_class_bit_packed(target));
    attack *= bonusDmg;
    // verification debuffs on attacker
    if (*attacker & STS_WEAKEN)
        attack *= 0.7f;
    // verification debuffs on target
    if (*target & STS_BURN || *target & STS_FROZEN || *target & STS_POISON)
    {
        if ((rand() % 100) < 20)
            attack *= 1.5;
    }

    if ((rand() % 100) < skill->critical_chance)
    {
        attack *= 1.5;
    }

    apply_status_packed(STS_POISON, target);
    if (attack < 1)
        attack = 1;

    if (skill->action == BF_HEAL)
    {
        if (skill->name == "Soul Drain")
        {
            float heal = (attack / 100) * skill->critical_chance;
            apply_heal_packed(attacker, heal);
        }
        else
        {
            float heal = skill->critical_chance;
            apply_heal_packed(attacker, heal);
        }
    }
    else if (skill->action == BF_SHIELD)
    {
        for (int i = 0; i < STS_COUNT; i++)
        {
            remove_status_effect_packed(attacker, i);
        }
    }
    return (int)attack;
}