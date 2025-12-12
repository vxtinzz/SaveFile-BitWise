#include <stdio.h>

    void test_bit_attributes();
    void test_bitpack();
    void test_character();
    void test_combat();
    void test_savefile();
    void test_skills_structs();
    void test_status();
    void test_validation();
    void test_affinity();
    void test_attributes();

int main()
{
    printf("\n=========== RUNNING UNIT TESTS ==========\n");

    test_bit_attributes();
    test_bitpack();
    test_character();
    test_combat();
    test_savefile();
    test_skills_structs();
    test_status();
    test_validation();
    test_affinity();
    test_attributes();

    printf("=========== ALL TESTS FINISHED ==========\n");
    return 0;
}