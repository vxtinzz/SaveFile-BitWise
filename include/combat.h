#ifndef COMBAT_H
#define COMBAT_H
#include "../include/character_types.h"
#include "../include/skills_structs.h"
#include <stdint.h>

void apply_damage_packed(uint32_t *packed, int damage);
struct Character apply_damage_struct(Character *c, int damage);
void apply_heal_packed(uint32_t *packed, int heal);
struct Character apply_heal_struct(Character *c, int heal);
void remove_status_effect_packed(uint32_t *packed, int status_target);
const char *has_status_effect(uint32_t *packed);
float get_affinity_multiplier(uint32_t attacker, uint32_t target);
int calculate_basic_attack(uint32_t *attacker, uint32_t *target);
int calculate_skill_attack(uint32_t *attacker, uint32_t *target, SkillData *skill);

#endif