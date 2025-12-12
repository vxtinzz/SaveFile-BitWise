#include <assert.h>
#include <stdio.h>
#include <math.h>
#include "../include/affinity.h"
#include "../include/combat.h"
#include "../include/config.h"
#include "../include/character.h"

void test_affinity()
{
    printf("[TEST] affinity...\n");

    // ======================================================
    // Test 1 — Known Simple Rules
    // ======================================================
    float v;

    v = get_affinity_multiplier(CLASS_TYPE_DEATH_K, CLASS_TYPE_PYRO);
    assert(fabs(v - 0.90f) < 0.0001f);

    v = get_affinity_multiplier(CLASS_TYPE_PYRO, CLASS_TYPE_FROST_W);
    assert(fabs(v - 1.25f) < 0.0001f);

    v = get_affinity_multiplier(CLASS_TYPE_FROST_W, CLASS_TYPE_COLOSSUS);
    assert(fabs(v - 1.40f) < 0.0001f);

    v = get_affinity_multiplier(CLASS_TYPE_DRUID, CLASS_TYPE_PYRO);
    assert(fabs(v - 0.55f) < 0.0001f);
    // ======================================================
    // Test 2 — No rules Case → should return 1.0
    // ======================================================
    // Example: Pyro vs Pyro does not exist in the table.
    assert(get_affinity_multiplier(CLASS_TYPE_PYRO, CLASS_TYPE_PYRO) == 1.0f);

    // another example:
    assert(get_affinity_multiplier(CLASS_TYPE_MURDEROUS, CLASS_TYPE_MURDEROUS) == 1.0f);

    // ======================================================
    // Test 3 — Check ALL TABLE ENTRIES
    // (ensures nothing is messed up)
    // ======================================================
    for (int i = 0; i < AFFINITY_COUNT; i++)
    {
        AffinityRules r = AFFINITYRULES[i];
        float found = get_affinity_multiplier(r.attacker, r.target);

        // compare floats with a small tolerance
        float diff = found - r.multiplier;
        if (diff < 0)
            diff = -diff;

        assert(diff < 0.0001);
    }

    printf("[OK] affinity\n");
}