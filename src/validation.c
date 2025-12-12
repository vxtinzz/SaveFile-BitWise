#include "../include/validation.h"

int clamp_attributes(int attribute, int min, int max)
{
    if (attribute < min)
        return min;
    if (attribute > max)
        return max;
    return attribute;
}

Character clamp_all(Character c)
{
    if (c.strength > 63) c.strength = 63;
    if (c.life > 255) c.life = 255;
    if (c.class > 7) c.class = 0;
    if (c.flags > 31) c.flags = c.flags & 31;
    if (c.level > 99) c.level = 99;
    if (c.skills > 7) c.skills = c.skills & 7;
    return c;
}


int validate_attributes(struct Character c)
{
    if (c.strength > 63)
        return 1;
    if (c.life > 255)
        return 1;
    if (c.class > 7)
        return 1;
    if (c.flags > 31)
        return 1;
    if (c.level > 99)
        return 1;
    if (c.skills > 7)
        return 1;
    return 0;
}