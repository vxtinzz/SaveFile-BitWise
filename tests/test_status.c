#include <assert.h>
#include <string.h>
#include <stdio.h>

#include "../include/status.h"

void test_status()
{
    printf("[TEST] status...\n");

    // 1. Check if the status number is correct.
    assert(STS_COUNT == 5);

    // 2. Check if each name is in the correct index.
    assert(strcmp(STATUS_EFFECTS_NAMES[0], "Poisoned") == 0);
    assert(strcmp(STATUS_EFFECTS_NAMES[1], "Burning") == 0);
    assert(strcmp(STATUS_EFFECTS_NAMES[2], "Frozen") == 0);
    assert(strcmp(STATUS_EFFECTS_NAMES[3], "Stunned") == 0);
    assert(strcmp(STATUS_EFFECTS_NAMES[4], "Weakened") == 0);

    // 3. Defensive test: the array must not be NULL
    for (int i = 0; i < STS_COUNT; i++)
        assert(STATUS_EFFECTS_NAMES[i] != NULL);

    printf("[OK] status\n");
}
