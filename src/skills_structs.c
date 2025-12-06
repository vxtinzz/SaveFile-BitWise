#include "../include/skills_structs.h"

SkillData skills_db[] = {
    {"Abyssal Strike", CLASS_TYPE_DEATH_K, 10, STS_WEAKEN, 1},
    {"Soul Drain", CLASS_TYPE_DEATH_K, 20, STS_POISON, BF_HEAL, 2},
    {"Shadow Armor", CLASS_TYPE_DEATH_K, 40, 0, BF_HEAL, 0},

    {"Sneak Attack", CLASS_TYPE_SHADOW_S, 10, STS_WEAKEN, 1},
    {"Poison Arrow", CLASS_TYPE_SHADOW_S, 20, STS_POISON, 2},
    {"Shadow Step", CLASS_TYPE_SHADOW_S, 0, 0, BF_SHIELD, 0},

    {"Fireball", CLASS_TYPE_PYRO, 10, STS_BURN, 2},
    {"Chaotic Blast", CLASS_TYPE_PYRO, 15, STS_STUN | STS_BURN, 2},
    {"Flame Mark", CLASS_TYPE_PYRO, 15, STS_BURN | STS_WEAKEN, 2},

    {"Frost Burst", CLASS_TYPE_FROST_W, 10, STS_FROZEN, 1},
    {"Ice Prison", CLASS_TYPE_FROST_W, 10, STS_FROZEN | STS_STUN, 1},
    {"Winter Storm", CLASS_TYPE_FROST_W, 20, STS_FROZEN | STS_WEAKEN, 1},

    {"Berserk", CLASS_TYPE_MURDEROUS, 20, STS_WEAKEN, 1},
    {"Rage Burst", CLASS_TYPE_MURDEROUS, 30, 0, 100},
    {"War Cry", CLASS_TYPE_MURDEROUS, 40, 0, 100},

    {"Seismic Strike", CLASS_TYPE_COLOSSUS, 20, STS_STUN, 1},
    {"Earthquake Punch", CLASS_TYPE_COLOSSUS, 15, STS_WEAKEN, 1},
    {"Granite Skin", CLASS_TYPE_COLOSSUS, 0, 0, BF_SHIELD, 0},

    {"Sap Drain", CLASS_TYPE_DRUID, 15, STS_POISON, BF_HEAL, 2},
    {"Hemorrhagic Thorns", CLASS_TYPE_DRUID, 25, STS_WEAKEN | STS_POISON, 2},
    {"Green Spirit's Call", CLASS_TYPE_DRUID, 60, 0, BF_HEAL, 0},

};

const int SKILLS_COUNT = sizeof(skills_db) / sizeof(SkillData);
