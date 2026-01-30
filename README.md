# BitPack RPG System
## Ultra-compact character savefile system using bitwise packing + file serialization
This project demonstrates how to build a character savefile system using bit-packing, struct→packed conversion, unpacking, flags, skills, status effects, affinity multipliers, and a complete unit testing system.
Everything is stored in just one uint32_t file per character.

Objective: To create an extremely efficient storage system, typical of older games (Game Boy, PS1, SNES), using only bitwise operations to pack character attributes.

## Includes: 
- Character packing and unpacking
- Flags, status effects, class types
- Affinity system (strong/weak elements)
- Skills associated with each class
- Damage, healing, and attack calculation system
- Binary save/load system
- Unit tests for each module

## Technologies and Techniques:
- C99
- Bitwise operations (shift, mask, xor, toggles)
- Compact data modeling
- Binary savefiles
- Modular architecture
- Complete unit testing suite

## Naming Conventions:
- Constants/macros: UPPER_SNAKE_CASE
- Structs/Enums: PascalCase
- Functions: snake_case
- Variables: camelCase


 ![C](https://img.shields.io/badge/Language-C-blue)
 ![Tests](https://img.shields.io/badge/Unit%20Tests-Complete-success)
 ![Bitwise](https://img.shields.io/badge/Bitwise-Optimized-yellow)
 ![Author](https://img.shields.io/badge/author-vxtinzzz-black)

