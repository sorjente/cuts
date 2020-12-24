# cuts - C Unit Test Suite

Cuts is a header-only minimal unit test suite to be used with C/C++ programs.

Inspired by [minunit](http://www.jera.com/techinfo/jtns/jtn002.html) and Zed Shaw's test suite in Learn C The Hard Way.


# How to use cuts

Cuts is trivial to install; just include the (very small) `cuts.h` file in your project (either directly or via the
`-I` option).

A simple test file using cuts looks like this:

```c
#include "cuts.h"


char * simple_test ()
{
    CUTS_ASSERT(1 == 1, "Oh no, math is broken!");

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

    CUTS_RUN_TEST(simple_test);
    CUTS_RUN_TEST(array_equality);

    return NULL;
}


CUTS_RUN_SUITE(all_tests);
```

If you `make` and run this test file, you'll get:

```text
[CUTS] Running test suite from file `./build/other_test_file`
----------
[CUTS] Running test `some_more_math`
[CUTS] Running test `array_equality`
----------
[CUTS] All tests passed!
[CUTS] Tests run: 2
```

Let's now say we introduce an error in the test file, for example by changing the value of the last element of `array2`
from `5` to `6`. Now, our test (expectedly) fails like this:

```text
[CUTS] Running test suite from file `./build/other_test_file`
----------
[CUTS] Running test `some_more_math`
[CUTS] Running test `array_equality`
FAIL tests/other_test_file.c:17
    array2[i] == array1[i] + 1: Element mismatch for index 3
----------
[CUTS] Test failed: array_equality
[CUTS] Tests run: 2
```

Finally, if you want to disable colors in the terminal output, you can simply define the following symbol before
including cuts:

```c
#define CUTS_NO_COLOR
#include "cuts.h"

...

```
