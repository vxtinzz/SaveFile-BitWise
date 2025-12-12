#include <assert.h>
#include <stdio.h>

#include "../include/attributes.h"
#include "../include/character.h"

void test_attributes()
{
    printf("[TEST] attributes...\n");

    Character c = {0};

    // -----------------------------
    // strength
    // -----------------------------
    set_strength_struct(40, &c);
    assert(c.strength == 40);

    set_strength_struct(-10, &c);
    assert(c.strength == 0);

    set_strength_struct(500, &c);
    assert(c.strength == 63);

    // -----------------------------
    // life
    // -----------------------------
    set_life_struct(100, &c);
    assert(c.life == 100);

    set_life_struct(-5, &c);
    assert(c.life == 0);

    set_life_struct(999, &c);
    assert(c.life == 255);

    // -----------------------------
    // class
    // -----------------------------
    set_class_struct(3, &c);
    assert(c.class == 3);

    set_class_struct(-1, &c);
    assert(c.class == 0);

    set_class_struct(99, &c);
    assert(c.class == 0);

    // -----------------------------
    // flags
    // -----------------------------
    set_flags_struct(10, &c);
    assert(c.flags == 10);

    set_flags_struct(-2, &c);
    assert(c.flags == 0);

    set_flags_struct(999, &c);
    assert(c.flags == 31);

    // -----------------------------
    // level
    // -----------------------------
    set_level_struct(50, &c);
    assert(c.level == 50);

    set_level_struct(-1, &c);
    assert(c.level == 0);

    set_level_struct(500, &c);
    assert(c.level == 99);

    // -----------------------------
    // skills
    // -----------------------------
    set_skills_struct(3, &c);
    assert(c.skills == 3);

    set_skills_struct(-10, &c);
    assert(c.skills == 0);

    set_skills_struct(999, &c);
    assert(c.skills == 7);

    printf("[OK] attributes\n");
}
