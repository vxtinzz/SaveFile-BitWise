#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "../include/skills_structs.h"
#include "../include/status.h"
#include "../include/character.h"

void test_skills_structs()
{
    printf("[TEST] skills_structs...\n");

    // ---------------------------------------
    // 1. Test SKILLS_COUNT integrity
    // ---------------------------------------
    assert(SKILLS_COUNT > 0 && SKILLS_COUNT < 200);

    // ---------------------------------------
    // 2. Validate every skill entry
    // ---------------------------------------
    for (int i = 0; i < SKILLS_COUNT; i++)
    {
        SkillData *s = &skills_db[i];

        // Name not null
        assert(strlen(s->name) > 0);

        // Class between 0 and CLASS_COUNT-1
        assert(s->character >= 0 && s->character < CLASS_COUNT);

        // non-negative Critical Chance 
        assert(s->critical_chance >= 0);

        // effect_flag should only use valid status bits
        assert((s->effect_flag & ~((1u << (SH_FLAGS+5)) - 1)) == 0);

        // action to be 0, BF_HEAL or BF_SHIELD
        assert(s->action == 0 || s->action == BF_HEAL || s->action == BF_SHIELD);

        // non-negative duration
        assert(s->duration >= 0);
    }

    // ---------------------------------------
    // 3. Check if all Death Knight skills have correct class
    // ---------------------------------------
    for (int i = 0; i < SKILLS_COUNT; i++)
    {
        if (skills_db[i].character == CLASS_TYPE_DEATH_K)
        {
            assert(
                strcmp(skills_db[i].name, "Abyssal Strike") == 0 ||
                strcmp(skills_db[i].name, "Soul Drain") == 0 ||
                strcmp(skills_db[i].name, "Shadow Armor") == 0
            );
        }
    }

    printf("skills_structs OK\n");
}
