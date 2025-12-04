#ifndef SAVEFILE_H
#define SAVEFILE_H

#include <stdint.h>

void save_character_to_file(const char *filename, uint32_t packed);
void save_character_list_to_file(const char *filename, int count, const uint32_t *characters_packed);
void load_character_from_file(const char *filename, uint32_t *packed);
void load_character_list_from_file(const char *filename, int count, uint32_t *characters_packed);

#endif
