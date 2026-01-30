#include "../include/character.h"
#include "../include/skills_structs.h"

const char *CHARACTER_NAMES[] = {
    "Death Knight",
    "Shadow Stalker",
    "Pyrotechnic",
    "Frost Warden",
    "Murderous",
    "Colossus",
    "Verdanth"};

    const CharacterPreset CHARACTER_PRESET[CLASS_COUNT] = {
        [CLASS_TYPE_DEATH_K] = {
        .name = "Death Knight",
        .base_class = 0;
        .life = 120,
        .strength = 18,
        .skills = 0
    },
    [CLASS_TYPE_SHADOW_S] = {
        .name = "Shadow Stalker",
        .base_class = 1;
        .base_life = 90,
        .base_strength = 22,
        .base_skills = 0
    },
    [CLASS_TYPE_PYRO] = {
        .name = "Pyrotechnic",
        .base_class = 2;
        .base_life = 80,
        .base_strength = 25,
        .base_skills = 0
    },
    [CLASS_TYPE_FROST_W] = {
        .name = "Frost Warden",
        .base_class = 3;
        .base_life = 100,
        .base_strength = 17,
        .base_skills = 0
    },
    [CLASS_TYPE_MURDEROUS] = {
        .name = "Murderous",
        .base_class = 4;
        .base_life = 85,
        .base_strength = 26,
        .base_skills = 0
    },
    [CLASS_TYPE_COLOSSUS] = {
        .name = "Colossus",
        .base_class = 5;
        .base_life = 160,
        .base_strength = 14,
        .base_skills = 0
    },
    [CLASS_TYPE_DRUID] = {
        .name = "Verdanth",
        .base_class = 6,
        .base_life = 110,
        .base_strength = 16,
        .base_skills = 0
    }
    };
