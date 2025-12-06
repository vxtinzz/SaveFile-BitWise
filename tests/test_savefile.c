#include "../include/savefile.h"
#include <stdio.h>

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