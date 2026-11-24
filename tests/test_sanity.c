#include <stdint.h>

#include "test.h"

/* Prices and order IDs will be 64-bit integers, so confirm the sizes. */
static void test_int_sizes(void) {
    CHECK_EQ(sizeof(int64_t), 8);
    CHECK_EQ(sizeof(uint64_t), 8);
}

static void test_arithmetic(void) {
    CHECK_EQ(2 + 2, 4);
    CHECK(10 > 3);
}

int main(void) {
    RUN_TEST(test_int_sizes);
    RUN_TEST(test_arithmetic);
    return test_summary();
}
