#include "cuts.h"


char * simple_prints ()
{
    log_info("This is an info message");
    log_fail("This is a fail message");
    log_pass("This is a pass message");

    return NULL;
}


char * simple_arithmetic ()
{
    CUTS_ASSERT(1 == 1, "Math is broken.");

    return NULL;
}


char * all_tests ()
{
    CUTS_START();

    CUTS_RUN_TEST(simple_prints);
    CUTS_RUN_TEST(simple_arithmetic);

    return NULL;
}


CUTS_RUN_SUITE(all_tests);
