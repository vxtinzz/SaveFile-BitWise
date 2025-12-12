#include <assert.h>
#include <stdio.h>
#include <stdint.h>

#include "../include/bitpack.h"
#include "../include/bit_attributes.h"
#include "../include/character.h"
#include "../include/validation.h"

void test_bitpack()
{
    printf("[TEST] bitpack...\n");

    Character c;
    c.strength = 45;
    c.life     = 120;
    c.class    = 3;
    c.flags    = 0b10101;
    c.level    = 55;
    c.skills   = 0b011;

    // ---- PACK ----
    uint32_t packed = pack_character(c);
    assert(packed != 0);

    // Check individual bits using getters
    assert(get_strength_packed(&packed) == 45);
    assert(get_life_packed(&packed) == 120);
    assert(get_class_bit_packed(&packed) == 3);
    assert(get_level_packed(&packed) == 55);
    assert(get_skills_packed(&packed) == 0b011);

    // Flags are the reserved bits 10..14
    assert(get_flag_bit_packed(0, packed) == 1);
    assert(get_flag_bit_packed(2, packed) == 1);
    assert(get_flag_bit_packed(4, packed) == 1);

    // ---- UNPACK ----
    Character u = unpack_character(packed);

    assert(u.strength == c.strength);
    assert(u.life     == c.life);
    assert(u.class    == c.class);
    assert(u.flags    == c.flags);
    assert(u.level    == c.level);
    assert(u.skills   == c.skills);

    // ---- LIMIT TESTS ----
    Character c2 = {200, 999, 10, 999, 200, 999};  // everything out of range
    Character c3;
    c3 = clamp_all(c2);
    uint32_t packed2 = pack_character(c3);
    Character u2 = unpack_character(packed2);
    assert(u2.strength == 63);  // 6 bits = 0–63
    assert(u2.life     == 255); // 8 bits = 0–255
    assert(u2.class    == 0);   // invalid class to be 0
    assert(u2.level    == 99);  // 7 bits = 0–99
    assert(u2.skills   == 0b111); // 3 bits = 0 to 7 (0b111)

    printf("[OK] bitpack\n");
}
