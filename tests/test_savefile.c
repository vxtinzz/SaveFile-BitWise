#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include "../include/savefile.h"
#include "../include/bitpack.h"   // pack_character, unpack_character
#include "../include/character.h" // struct Character

// temp file for tests
#define TEST_FILE "test_char.bin"
#define TEST_FILE_LIST "test_char_list.bin"

void test_savefile()
{
    printf("[TEST] savefile...\n");

    // ---------------------------
    // Test 1 — save and load
    // ---------------------------
    Character c = { 50, 80, 3, 1, 25, 5 };
    uint32_t packed = pack_character(c);

    save_character_to_file(TEST_FILE, packed);

    uint32_t loaded = 0;
    load_character_from_file(TEST_FILE, &loaded);

    assert(loaded == packed);

    Character u = unpack_character(loaded);
    assert(u.strength == c.strength);
    assert(u.life == c.life);
    assert(u.class == c.class);
    assert(u.flags == c.flags);
    assert(u.level == c.level);
    assert(u.skills == c.skills);

    // ---------------------------
    // Test 2 — save and load List
    // ---------------------------
    uint32_t list_original[3];

    Character a = { 10, 20, 1, 0, 5, 1 };
    Character b = { 44, 99, 2, 3, 50, 7 };
    Character d = { 63, 255, 6, 15, 99, 7 };

    list_original[0] = pack_character(a);
    list_original[1] = pack_character(b);
    list_original[2] = pack_character(d);

    save_character_list_to_file(TEST_FILE_LIST, 3, list_original);

    uint32_t list_loaded[3] = {0};

    load_character_list_from_file(TEST_FILE_LIST, 3, list_loaded);

    assert(list_loaded[0] == list_original[0]);
    assert(list_loaded[1] == list_original[1]);
    assert(list_loaded[2] == list_original[2]);

    // ---------------------------
    // Test 3 — Verify integrity after unpacking.
    // ---------------------------
    Character ua = unpack_character(list_loaded[0]);
    Character ub = unpack_character(list_loaded[1]);
    Character ud = unpack_character(list_loaded[2]);

    assert(ua.strength == a.strength);
    assert(ub.strength == b.strength);
    assert(ud.strength == d.strength);

    assert(ua.life == a.life);
    assert(ub.life == b.life);
    assert(ud.life == d.life);

    assert(ua.level == a.level);
    assert(ub.level == b.level);
    assert(ud.level == d.level);

    printf("[OK] savefile\n");
}
