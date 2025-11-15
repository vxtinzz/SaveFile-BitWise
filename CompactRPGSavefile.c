#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
//---Shifts(LBS)---
#define SH_STRENGTH    26
#define SH_LIFE    18
#define SH_CLASS  15
#define SH_FLAGS   10
#define SH_LEVEL    3
#define SH_SKILLS   0
//----- Máscaras-----
#define MSK_STRENGTH   0b111111      
#define MSK_LIFE    0b11111111      
#define MSK_CLASS  0b111      
#define MSK_FLAGS   0b11111      
#define MSK_LEVEL   0b1111111      
#define MSK_SKILLS  0b111      

typedef struct Character
{
    unsigned strength;
    unsigned life;
    unsigned class;
    unsigned flags;
    unsigned level;
    unsigned skills;
}Character;
//Bitpacking
uint32_t pack_character(struct Character c){
        uint32_t save = 0;
        save |= (c.strength & MSK_STRENGTH) << SH_STRENGTH;
        save |= (c.life & MSK_LIFE) << SH_LIFE;
        save |= (c.class & MSK_CLASS) << SH_CLASS;
        save |= (c.flags & MSK_FLAGS) << SH_FLAGS;
        save |= (c.level & MSK_LEVEL) << SH_LEVEL;
        save |= (c.skills & MSK_SKILLS) << SH_SKILLS;
        return save;
}

struct Character unpack_character(uint32_t save){
    Character c;
    c.strength = (save >> SH_STRENGTH) & MSK_STRENGTH;
    c.life = (save >> SH_LIFE) & MSK_LIFE;
    c.class = (save >> SH_CLASS) & MSK_CLASS;
    c.flags = (save >> SH_FLAGS) & MSK_FLAGS;
    c.level = (save >> SH_LEVEL) & MSK_LEVEL;
    c.skills = (save >> SH_SKILLS) & MSK_SKILLS;
    return c;
}
//File-Handling
void save_character_to_file(const char *filename, uint32_t packed){
    FILE *f = fopen(filename, "wb");
    if(!f){
        printf("Error opening file for writing!!");
        return;
    }
    fwrite(&packed, sizeof(uint32_t), 1, f);
    fclose(f);
}

void save_character_list_to_file(const char *filename, int count, const uint32_t *characters_packed){
    FILE *f = fopen(filename,"wb");
    if(!f){
        printf("Error opening file for writing!!");
        return;
    }
    fwrite(characters_packed, sizeof(uint32_t), count, f);
}

void load_character_from_file(const char *filename, uint32_t *packed){
    FILE *f = fopen(filename,"rb");
    if(!f){
        printf("Error opening file for Reading!!");
        return;
    }
    fread(packed, sizeof(uint32_t), 1, f);
}

void load_character_list_from_file(const char *filename, int count, uint32_t *characters_packed){
    FILE *f = fopen(filename,"rb");
    if(!f){
        printf("Error opening file for Reading!!");
        return;
    }
    fread(characters_packed, sizeof(uint32_t), count, f);
}

int main() {
    // Criar personagem manualmente
    Character p;
    p.strength = 50;
    p.life     = 200;
    p.class    = 3;
    p.flags    = 1;
    p.level    = 30;
    p.skills   = 3;

    printf("=== PERSONAGEM ORIGINAL ===\n");
    printf("Strength: %u\n", p.strength);
    printf("Life:     %u\n", p.life);
    printf("Class:    %u\n", p.class);
    printf("Flags:    %u\n", p.flags);
    printf("Level:    %u\n", p.level);
    printf("Skills:   %u\n", p.skills);

    // Pack
    uint32_t packed = pack_character(p);
    printf("\nPacked Decimal: %u\n", packed);

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
