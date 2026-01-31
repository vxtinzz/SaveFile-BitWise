#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/affinity.h"
#include "../include/attributes.h"
#include "../include/bit_attributes.h"
#include "../include/bitpack.h"
#include "../include/savefile.h"
#include "../include/character.h"
#include "../include/combat.h"
#include "../include/skills_structs.h"
#include "../include/status.h"
#include "../include/validation.h"

int main()
{
    //----Time-Variation--
    srand(time(NULL));
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
    printf("=== CHA ===\n");
    printf("Strength: %u\n", p.strength);
    printf("Life:     %u\n", p.life);
    printf("Class:    %u\n", p.class);
    printf("Flags:    %u\n", p.flags);
    printf("Level:    %u\n", p.level);
    printf("Skills:   %u\n", p.skills);
    printf("Personagem e valido:(1)SIM(0)NAO:%d\n", !validate_attributes(p));
    // Pack
    uint32_t packed = pack_character(p);
    printf("\nPacked Decimal: %u\n", packed);
    set_life_packed(5, &packed);
    set_strength_packed(50, &packed);
    set_class_packed(CLASS_TYPE_DRUID, &packed);
    // set_flag_bit_packed(2, &packed);
    // set_flag_bit_packed(3, &packed);
    set_level_packed(30, &packed);
    toggle_flag_bit_packed(0, &packed);
    toggle_skills_packed(1, &packed);
    set_skills_bit_packed(0,&packed);
    set_skills_bit_packed(1,&packed);
    set_skills_bit_packed(2,&packed);
    set_skills_bit_packed(3,&packed);
    printf("\nForca Decimal: %d\n", get_strength_packed(&packed));
    toggle_flag_bit_packed(4, &packed);
    remove_status_effect_packed(&packed, 4);
    printf("\nFLAGS GET FLAGS: %u\n", get_flag_bit_packed(40, packed));
    printf("\nFLAGS STATUS: %s\n", has_status_effect(&packed));
    printf("\nCLASSE: %s\n", has_class_packed(&packed));
    printf("\nCLASSE BIT: %d\n", get_class_bit_packed(&packed));
    // Salvar no arquivo
    save_character_to_file("data/char.bin", packed);

    // Zerar variável
    packed = 0;

    // Carregar
    load_character_from_file("data/char.bin", &packed);
    printf("\nPacked Decimal carregado: %u\n", packed);
    apply_damage_packed(&packed, 50);
    apply_heal_packed(&packed, 45);
    // Unpack
    Character u = unpack_character(packed);
    printf("\n=== PERSONAGEM DESCOMPACTADO ===\n");
    printf("Strength: %u\n", u.strength);
    printf("Life:     %u\n", u.life);
    printf("Class:    %u\n", u.class);
    printf("Flags:    %u\n", u.flags);
    printf("Level:    %u\n", u.level);
    printf("Skills:   %u\n", u.skills);
    printf("Attack:   %d\n", calculate_basic_attack(&packed, &packed));
    printf("Skills Ativas:   %u %u %u\n", get_unlocked_skills_packed(0, &packed), get_unlocked_skills_packed(1, &packed), get_unlocked_skills_packed(2, &packed));

    print_unlocked_skills(&packed);
    return 0;
}