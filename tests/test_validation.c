#include "../include/validation.h"

int clamp_attributes(int attribute, int min, int max)
{
    if (attribute < min)
        return min;
    if (attribute > max)
        return max;
    return attribute;
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