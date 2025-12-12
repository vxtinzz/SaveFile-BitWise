#include <assert.h>
#include <stdio.h>
#include <stdint.h>

#include "../include/bit_attributes.h"

void test_bit_attributes()
{
    printf("[TEST] bit_attributes...\n");

    // -----------------------------------------
    // Test: set_strength_packed + get_strength
    // -----------------------------------------
    uint32_t p = 0;
    set_strength_packed(50, &p);
    assert(get_strength_packed(&p) == 50);

    set_strength_packed(999, &p); // cut for 63
    assert(get_strength_packed(&p) == 63);

    set_strength_packed(-10, &p); // minimum limit
    assert(get_strength_packed(&p) == 0);

    // -----------------------------------------
    // Teste: set_life_packed + get_life
    // -----------------------------------------
    set_life_packed(200, &p);
    assert(get_life_packed(&p) == 200);

    set_life_packed(500, &p); // limit 255
    assert(get_life_packed(&p) == 255);

    // -----------------------------------------
    // Teste: class
    // -----------------------------------------
    set_class_packed(3, &p);
    assert(get_class_bit_packed(&p) == 3);

    set_class_packed(999, &p); // to be 0
    assert(get_class_bit_packed(&p) == 0);

    // -----------------------------------------
    // Teste: flags
    // -----------------------------------------
    clear_flags_packed(&p);
    set_flag_bit_packed(2, &p);
    assert(get_flag_bit_packed(2, p) == 1);

    toggle_flag_bit_packed(2, &p);
    assert(get_flag_bit_packed(2, p) == 0);

    toggle_flag_bit_packed(1, &p);
    assert(get_flag_bit_packed(1, p) == 1);
    toggle_flag_bit_packed(1, &p);
    assert(get_flag_bit_packed(1, p) == 0);

    // -----------------------------------------
    // Teste: level
    // -----------------------------------------
    set_level_packed(30, &p);
    assert(get_level_packed(&p) == 30);

    set_level_packed(200, &p); // limit 99
    assert(get_level_packed(&p) == 99);

    // -----------------------------------------
    // Teste de SKILLS
    // -----------------------------------------
    p = 0;

    // valid toggle skill
    toggle_skills_packed(1, &p);
    assert(get_unlocked_skills_packed(1, &p) == 1);

    // toggle again → turn off
    toggle_skills_packed(1, &p);
    assert(get_unlocked_skills_packed(1, &p) == 0);

    // invalid toggle (out of range)
    toggle_skills_packed(4, &p);

    // skills remain 0
    assert(get_skills_packed(&p) == 0);

    // -----------------------------------------
    // Teste: apply_status_packed
    // -----------------------------------------
    p = 0;
    apply_status_packed(STS_POISON, &p);
    assert(p & STS_POISON);

    printf("[OK] bit_attributes\n");
}
