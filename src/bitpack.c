#include "../include/bitpack.h"

uint32_t pack_character(struct Character c)
{
    uint32_t save = 0;
    save |= (c.strength & MSK_STRENGTH) << SH_STRENGTH;
    save |= (c.life & MSK_LIFE) << SH_LIFE;
    save |= (c.class & MSK_CLASS) << SH_CLASS;
    save |= (c.flags & MSK_FLAGS) << SH_FLAGS;
    save |= (c.level & MSK_LEVEL) << SH_LEVEL;
    save |= (c.skills & MSK_SKILLS) << SH_SKILLS;
    return save;
}

struct Character unpack_character(uint32_t save)
{
    Character c;
    c.strength = (save >> SH_STRENGTH) & MSK_STRENGTH;
    c.life = (save >> SH_LIFE) & MSK_LIFE;
    c.class = (save >> SH_CLASS) & MSK_CLASS;
    c.flags = (save >> SH_FLAGS) & MSK_FLAGS;
    c.level = (save >> SH_LEVEL) & MSK_LEVEL;
    c.skills = (save >> SH_SKILLS) & MSK_SKILLS;
    return c;
}