#include "../include/character_types.h"
#include "../include/skills_structs.h"

    const CharacterPreset CHARACTER_PRESET[CLASS_COUNT] = {
        [CLASS_TYPE_DEATH_K] = {
        .name = "Death Knight",
        .baseClass = 0,
        .baseLife = 120,
        .baseStrength = 18,
        .baseSkills = 0
    },
    [CLASS_TYPE_SHADOW_S] = {
        .name = "Shadow Stalker",
        .baseClass = 1,
        .baseLife = 90,
        .baseStrength = 22,
        .baseSkills = 0
    },
    [CLASS_TYPE_PYRO] = {
        .name = "Pyrotechnic",
        .baseClass = 2,
        .baseLife = 80,
        .baseStrength = 25,
        .baseSkills = 0
    },
    [CLASS_TYPE_FROST_W] = {
        .name = "Frost Warden",
        .baseClass = 3,
        .baseLife = 100,
        .baseStrength = 17,
        .baseSkills = 0
    },
    [CLASS_TYPE_MURDEROUS] = {
        .name = "Murderous",
        .baseClass = 4,
        .baseLife = 85,
        .baseStrength = 26,
        .baseSkills = 0
    },
    [CLASS_TYPE_COLOSSUS] = {
        .name = "Colossus",
        .baseClass = 5,
        .baseLife = 160,
        .baseStrength = 14,
        .baseSkills = 0
    },
    [CLASS_TYPE_DRUID] = {
        .name = "Verdanth",
        .baseClass = 6,
        .baseLife = 110,
        .baseStrength = 16,
        .baseSkills = 0
    }
    };
