#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
//---Shifts(LBS)---
#define SH_STRENGTH 26
#define SH_LIFE 18
#define SH_CLASS 15
#define SH_FLAGS 10
#define SH_LEVEL 3
#define SH_SKILLS 0
//----- Masks-----
#define MSK_STRENGTH 0b111111
#define MSK_LIFE 0b11111111
#define MSK_CLASS 0b111
#define MSK_FLAGS 0b11111
#define MSK_LEVEL 0b1111111
#define MSK_SKILLS 0b111

typedef struct Character
{
    unsigned strength;
    unsigned life;
    unsigned class;
    unsigned flags;
    unsigned level;
    unsigned skills;
} Character;
// Bitpacking
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
// File-Handling
void save_character_to_file(const char *filename, uint32_t packed)
{
    FILE *f = fopen(filename, "wb");
    if (!f)
    {
        printf("Error opening file for writing!!");
        return;
    }
    fwrite(&packed, sizeof(uint32_t), 1, f);
    fclose(f);
}

void save_character_list_to_file(const char *filename, int count, const uint32_t *characters_packed)
{
    FILE *f = fopen(filename, "wb");
    if (!f)
    {
        printf("Error opening file for writing!!");
        return;
    }
    fwrite(characters_packed, sizeof(uint32_t), count, f);
}

void load_character_from_file(const char *filename, uint32_t *packed)
{
    FILE *f = fopen(filename, "rb");
    if (!f)
    {
        printf("Error opening file for Reading!!");
        return;
    }
    fread(packed, sizeof(uint32_t), 1, f);
}

void load_character_list_from_file(const char *filename, int count, uint32_t *characters_packed)
{
    FILE *f = fopen(filename, "rb");
    if (!f)
    {
        printf("Error opening file for Reading!!");
        return;
    }
    fread(characters_packed, sizeof(uint32_t), count, f);
}
// Validation
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
// Attribute Functions
// set functions
struct Character set_strength_struct(int attributes, Character *c)
{
    if (attributes > 63)
    {
        attributes = 63;
    }
    else if (attributes < 0)
    {
        attributes = 0;
    }
    c->strength = attributes;
    return *c;
}

void set_strength_packed(int attributes, uint32_t *packed)
{
    if (attributes > 63)
    {
        attributes = 63;
    }
    else if (attributes < 0)
    {
        attributes = 0;
    }
    *packed &= ~(MSK_STRENGTH << SH_STRENGTH);
    *packed |= (attributes & MSK_STRENGTH) << SH_STRENGTH;
}

struct Character set_life_struct(int attributes, Character *c)
{
    if (attributes > 255)
    {
        attributes = 255;
    }
    else if (attributes < 0)
    {
        attributes = 0;
    }
    c->life = attributes;
    return *c;
}

void set_life_packed(int attributes, uint32_t *packed)
{
    if (attributes > 255)
    {
        attributes = 255;
    }
    else if (attributes < 0)
    {
        attributes = 0;
    }
    *packed &= ~(MSK_LIFE << SH_LIFE);
    *packed |= (attributes & MSK_LIFE) << SH_LIFE;
}

struct Character set_class_struct(int attributes, Character *c)
{
    if (attributes > 7)
    {
        attributes = 7;
    }
    else if (attributes < 0)
    {
        attributes = 0;
    }
    c->class = attributes;
    return *c;
}

void set_class_packed(int attributes, uint32_t *packed)
{
    if (attributes > 7)
    {
        attributes = 7;
    }
    else if (attributes < 0)
    {
        attributes = 0;
    }
    *packed &= ~(MSK_CLASS << SH_CLASS);
    *packed |= (attributes & MSK_CLASS) << SH_CLASS;
}

struct Character set_flags_struct(int attributes, Character *c)
{
    if (attributes > 31)
    {
        attributes = 31;
    }
    else if (attributes < 0)
    {
        attributes = 0;
    }
    c->flags = attributes;
    return *c;
}

void set_flag_bit_packed(int bitIndex, uint32_t *packed)
{
    if (bitIndex < 5 && bitIndex >= 0)
    {
        *packed |= (1u << (bitIndex + SH_FLAGS));
    }else{
        printf("Invalid BitIndex!");
    }
}

void clear_flags_packed(uint32_t *packed)
{
    *packed &= ~(MSK_FLAGS << SH_FLAGS);
}

void clear_flag_bit_packed(int bitIndex, uint32_t *packed)
{
    if (bitIndex < 5 && bitIndex >= 0)
    {
        *packed &= ~(1u << (bitIndex + SH_FLAGS));
    }
}

void toggle_flag_bit_packed(int bitIndex, uint32_t *packed)
{
    if (bitIndex >= 0 && bitIndex < 5)
    {
        *packed ^= (1u << (bitIndex + SH_FLAGS));
    }
}
struct Character set_level_struct(int attributes, Character *c)
{
    if (attributes > 99)
    {
        attributes = 99;
    }
    else if (attributes < 0)
    {
        attributes = 0;
    }
    c->level = attributes;
    return *c;
}

void set_level_packed(int attributes, uint32_t *packed)
{
    if (attributes > 99)
    {
        attributes = 99;
    }
    else if (attributes < 0)
    {
        attributes = 0;
    }
    *packed &= ~(MSK_LEVEL << SH_LEVEL);
    *packed |= (attributes & MSK_LEVEL) << SH_LEVEL;
}

struct Character set_skills_struct(int attributes, Character *c)
{
    if (attributes > 7)
    {
        attributes = 7;
    }
    else if (attributes < 0)
    {
        attributes = 0;
    }
    c->skills = attributes;
    return *c;
}

void set_skills_packed(int attributes, uint32_t *packed)
{
    if (attributes > 7)
    {
        attributes = 7;
    }
    else if (attributes < 0)
    {
        attributes = 0;
    }
    *packed &= ~(MSK_SKILLS << SH_SKILLS);
    *packed |= (attributes & MSK_SKILLS) << SH_SKILLS;
}

uint32_t get_strength_packed(uint32_t *packed)
{
    return (*packed >> SH_STRENGTH) & MSK_STRENGTH;
}

uint32_t get_life_packed(uint32_t *packed)
{
    return (*packed >> SH_LIFE) & MSK_LIFE;
}

uint32_t get_class_packed(uint32_t *packed)
{
    return (*packed >> SH_CLASS) & MSK_CLASS;
}

uint32_t get_flag_bit_packed(int bitindex, uint32_t *packed)
{
    if(bitindex >= 0 && bitindex < 5){
        return (*packed >> (bitindex + SH_FLAGS)) & 1u;
    }else{
        printf("Invalid BitIndex");
        return 0;
    }
}

uint32_t get_level_packed(uint32_t *packed)
{
    return (*packed >> SH_LEVEL) & MSK_LEVEL;
}

uint32_t get_skills_packed(uint32_t *packed)
{
    return (*packed >> SH_SKILLS) & MSK_SKILLS;
}
//Combat Functions


int main()
{
    /*
    unsigned strength;
    unsigned life;
    unsigned class;
    unsigned flags;
    unsigned level;
    unsigned skills;*/
    // Make a character manually
    Character p;
    p.class = 0;
    p.flags = 0;
    p.level = 0;
    p.life = 0;
    p.skills = 0;
    p.strength = 0;
    printf("=== PERSONAGEM ORIGINAL ===\n");
    printf("Strength: %u\n", p.strength);
    printf("Life:     %u\n", p.life);
    printf("Class:    %u\n", p.class);
    printf("Flags:    %u\n", p.flags);
    printf("Level:    %u\n", p.level);
    printf("Skills:   %u\n", p.skills);
    printf("Personagem eh valido:(1)SIM(0)NAO:%d\n", !validate_attributes(p));
    // Pack
    uint32_t packed = pack_character(p);
    printf("\nPacked Decimal: %u\n", packed);
    set_life_packed(145, &packed);
    set_strength_packed(50, &packed);
    set_class_packed(5, &packed);
    set_flag_bit_packed(4, &packed);
    set_level_packed(30, &packed);
    set_skills_packed(7, &packed);
    printf("\nForca Decimal: %d\n", get_strength_packed(&packed));
    toggle_flag_bit_packed(4,&packed);
    printf("\nFLAGS GET FLAGS: %u\n", get_flag_bit_packed(4,&packed));
    // Salvar no arquivo
    save_character_to_file("char.bin", packed);

    // Zerar variável
    packed = 0;

    // Carregar
    load_character_from_file("char.bin", &packed);
    printf("\nPacked Decimal carregado: %u\n", packed);

    // Unpack
    Character u = unpack_character(packed);

    printf("\n=== PERSONAGEM DESCOMPACTADO ===\n");
    printf("Strength: %u\n", u.strength);
    printf("Life:     %u\n", u.life);
    printf("Class:    %u\n", u.class);
    printf("Flags:    %u\n", u.flags);
    printf("Level:    %u\n", u.level);
    printf("Skills:   %u\n", u.skills);

    return 0;
}
