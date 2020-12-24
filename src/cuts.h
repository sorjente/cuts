#ifndef __cuts_c_unit_test_suite_h__
#define __cuts_c_unit_test_suite_h__

#include <stdio.h>
#include <stdlib.h>


int tests_run;


#ifdef CUTS_NO_COLOR
#   define log_info(message, ...) fprintf(stderr, message "\n", ##__VA_ARGS__);
#   define log_fail(message, ...) log_info(message, ##__VA_ARGS__)
#   define log_pass(message, ...) log_info(message, ##__VA_ARGS__)
#else
#   define log_info(message, ...) fprintf(stderr, "\e[33m" message "\e[0m\n", ##__VA_ARGS__);
#   define log_fail(message, ...) fprintf(stderr, "\e[31m" message "\e[0m\n", ##__VA_ARGS__);
#   define log_pass(message, ...) fprintf(stderr, "\e[32m" message "\e[0m\n", ##__VA_ARGS__);
#endif


#define CUTS_START() char * message = NULL;


#define CUTS_ASSERT(test, message, ...) if (!(test)) { \
    log_fail("FAIL %s:%d", __FILE__, __LINE__); \
    log_fail("\t" #test ": " message, ##__VA_ARGS__); \
    return message; \
}


#define CUTS_RUN_TEST(test) log_info("[CUTS] Running test `%s`", #test) \
message = test(); tests_run++; if (message) return #test;


#define CUTS_RUN_SUITE(name) int main (int argc, char * argv[]) { \
    (void) argc; \
    char * result = NULL; \
    log_info("[CUTS] Running test suite from file `%s`\n----------", argv[0]); \
    result = name(); \
    log_info("----------"); \
    if (result) { \
        log_fail("[CUTS] Test failed: %s", result); \
    } else { \
        log_pass("[CUTS] All tests passed!"); \
    } \
    log_info("[CUTS] Tests run: %d", tests_run); \
    exit(result != NULL); \
}


#endif
