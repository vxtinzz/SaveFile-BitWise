#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/character.h"
#include "../include/combat.h"
#include "../include/bit_attributes.h"
#include "../include/status.h"
#include "../include/skills_structs.h"
#include "../include/affinity.h"

// Force rand() to be predictable
static void force_rand(int value)
{
    srand(1);
    for (int i = 0; i < value; i++)
        rand();
}

void test_combat()
{
    printf("[TEST] combat...\n");

    uint32_t attacker = 0;
    uint32_t target = 0;

    // ----------------------------
    // Test apply_damage_packed
    // ----------------------------
    set_life_packed(50, &target);
    apply_damage_packed(&target, 20);
    assert(get_life_packed(&target) == 30);

    apply_damage_packed(&target, 1000);
    assert(get_life_packed(&target) == 0);

    // ----------------------------
    // Test apply_heal_packed
    // ----------------------------
    set_life_packed(10, &target);
    apply_heal_packed(&target, 20);
    assert(get_life_packed(&target) == 30);

    apply_heal_packed(&target, 500);
    assert(get_life_packed(&target) == 255);

    // ----------------------------
    // Test remove_status_effect_packed
    // ----------------------------
    toggle_flag_bit_packed(1, &attacker); // add FROZEN
    assert(get_flag_bit_packed(1, attacker) == 1);

    remove_status_effect_packed(&attacker, 1);
    assert(get_flag_bit_packed(1, attacker) == 0);

    // ----------------------------
    // Test has_status_effect
    // ----------------------------
    toggle_flag_bit_packed(0, &attacker); // STS_POISON
    const char *s = has_status_effect(&attacker);
    assert(strcmp(s, "Poisoned") == 0);

    // ----------------------------
    // Test calculate_basic_attack
    // ----------------------------
    attacker = target = 0;
    set_strength_packed(40, &attacker);
    set_level_packed(10, &attacker);

    force_rand(0); // rand previsível

    int dmg = calculate_basic_attack(&attacker, &target);
    assert(dmg == 43); // 40 + 10*0.3 = 43

    // ----------------------------
    // Test calculate_skill_attack
    // ----------------------------
    attacker = target = 0;
    set_strength_packed(20, &attacker);
    set_level_packed(10, &attacker);

    SkillData fireball = {
        "Fireball",
        2,  // class pyro
        10, // critical chance
        STS_BURN,
        1,
        0};

    force_rand(0);
    int dmg2 = calculate_skill_attack(&attacker, &target, &fireball);
    assert(dmg2 >= 20); // no weaken, no critical 

    // Check if target received poison (your current mechanic)
    assert(get_flag_bit_packed(0, target) == 0); // FLAGS start from offset 10
    assert((target & STS_POISON) == 0);

    printf("[OK] combat\n");
}
