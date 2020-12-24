#include "cuts.h"

char * some_more_math ()
{
    CUTS_ASSERT(10 - 1 == 9, "There's a big problem with your machine.");

    return NULL;
}


char * array_equality ()
{
    int array1[] = { 1, 2, 3, 4 };
    int array2[] = { 2, 3, 4, 5 };

    for (int i = 0; i < 4; i++) {
        CUTS_ASSERT(array2[i] == array1[i] + 1, "Element mismatch for index %d", i);
    }

    return NULL;
}


char * all_tests ()
{
    CUTS_START();

    CUTS_RUN_TEST(some_more_math);
    CUTS_RUN_TEST(array_equality);

    return NULL;
}


CUTS_RUN_SUITE(all_tests);
