#include <assert.h>
#include <stdio.h>
#include "../include/validation.h"
#include "../include/character.h"

void test_validation()
{
    printf("[TEST] validation...\n");

    // ======================================================
    // Test 1 — clamp_attributes()
    // ======================================================
    assert(clamp_attributes(10, 0, 20) == 10);  // on range
    assert(clamp_attributes(-5, 0, 20) == 0);   // less than minimum
    assert(clamp_attributes(99, 0, 20) == 20);  // greater than max


    // ======================================================
    // Test 2 — clamp_all()
    // ======================================================

    Character c = {80, 500, 10, 999, 150, 20}; 
    // strength, life, class, flags, level, skills

    Character c2 = clamp_all(c);

    assert(c2.strength == 63);     // max 63
    assert(c2.life     == 255);    // max 255
    assert(c2.class    == 0);      // >7 becomes 0
    assert(c2.flags    == (999 & 31)); // apply mask 0b11111
    assert(c2.level    == 99);     // max 99
    assert(c2.skills   == (20 & 7)); // aplica máscara 0b111


    // ======================================================
    // Teste 3 — validate_attributes()
    // ======================================================

    Character valid_ok = {50, 200, 3, 10, 30, 5};
    assert(validate_attributes(valid_ok) == 0);  // OK

    Character invalid_strength = {70, 10, 1, 0, 0, 0};
    assert(validate_attributes(invalid_strength) == 1);

    Character invalid_life = {10, 300, 1, 0, 0, 0};
    assert(validate_attributes(invalid_life) == 1);

    Character invalid_class = {10, 10, 10, 0, 0, 0};
    assert(validate_attributes(invalid_class) == 1);

    Character invalid_flags = {10, 10, 1, 50, 0, 0};
    assert(validate_attributes(invalid_flags) == 1);

    Character invalid_level = {10, 10, 1, 0, 150, 0};
    assert(validate_attributes(invalid_level) == 1);

    Character invalid_skills = {10, 10, 1, 0, 0, 10};
    assert(validate_attributes(invalid_skills) == 1);

    printf("[OK] validation\n");
}
