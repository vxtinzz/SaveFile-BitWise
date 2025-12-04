#ifndef CONFIG_H
#define CONFIG_H
#include <stdint.h>
//---Shifts(LBS)---
#define SH_STRENGTH 26
#define SH_LIFE 18
#define SH_CLASS 15
#define SH_FLAGS 10
#define SH_LEVEL 3
#define SH_SKILLS 0
//-----Masks-----
#define MSK_STRENGTH 0b111111
#define MSK_LIFE 0b11111111
#define MSK_CLASS 0b111
#define MSK_FLAGS 0b11111
#define MSK_LEVEL 0b1111111
#define MSK_SKILLS 0b111

#endif