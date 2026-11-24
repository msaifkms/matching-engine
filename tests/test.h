#ifndef TEST_H
#define TEST_H

#include <stdio.h>

static int test_failures = 0;

/* Fail the current test if cond is false, but keep running. */
#define CHECK(cond)                                                   \
    do {                                                              \
        if (!(cond)) {                                                \
            fprintf(stderr, "%s:%d: CHECK failed: %s\n",              \
                    __FILE__, __LINE__, #cond);                       \
            test_failures++;                                          \
        }                                                             \
    } while (0)

/* Compare two integers and print both values on failure. */
#define CHECK_EQ(a, b)                                                \
    do {                                                              \
        long long a_ = (long long)(a);                                \
        long long b_ = (long long)(b);                                \
        if (a_ != b_) {                                               \
            fprintf(stderr, "%s:%d: CHECK_EQ failed: %s == %s "       \
                    "(%lld vs %lld)\n",                               \
                    __FILE__, __LINE__, #a, #b, a_, b_);              \
            test_failures++;                                          \
        }                                                             \
    } while (0)

/* Run one test function and print PASS or FAIL for it. */
#define RUN_TEST(fn)                                                  \
    do {                                                              \
        int before_ = test_failures;                                  \
        fn();                                                         \
        printf("%s %s\n", test_failures == before_ ? "PASS" : "FAIL", \
               #fn);                                                  \
    } while (0)

/* Exit code for main: 0 if everything passed, 1 otherwise. */
static inline int test_summary(void) {
    if (test_failures == 0) {
        printf("All tests passed\n");
        return 0;
    }
    printf("%d check(s) failed\n", test_failures);
    return 1;
}

#endif
