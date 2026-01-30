#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "../include/character.h"
#include "../include/bitpack.h"
#include "../include/attributes.h"

void test_character()
{
    printf("[TEST] character...\n");

    // ---------------------------------------------------------
    // Test 1: Create Character via Struct
    // ---------------------------------------------------------
    Character c;
    c.strength = 10;
    c.life     = 50;
    c.class    = 3;
    c.flags    = 1;
    c.level    = 12;
    c.skills   = 1;

    assert(c.strength == 10);
    assert(c.life     == 50);
    assert(c.class    == 3);
    assert(c.level    == 12);
    assert(c.skills   == 1);

    // ---------------------------------------------------------
    // Test 2: Return Class Name correctly
    // ---------------------------------------------------------
    const char* name = CHARACTER_NAMES[3];
    assert(name != NULL);
    assert(strcmp(name, "Frost Warden") == 0);
    // ---------------------------------------------------------
    // Test 3: print_character 
    // ---------------------------------------------------------
    //print_character(c);

    printf("[OK] character\n");
}
