#include "ctest.h"
#include "../src/bitarray.h"

#define SIZE 1024

CTEST_DATA(bitarray) {
    bitarray ba;
};

CTEST_SETUP(bitarray) {
    bitarray_init(&data->ba, SIZE);
};

// Set each second bit as 1
CTEST2(bitarray, set_get) {
    for (int i = 0; i < SIZE; i++) {
        ASSERT_FALSE(bitarray_set(&data->ba, (size_t)i, i%2));
    }

    for (int i = 0; i < SIZE; i++) {
        ASSERT_TRUE(
            bitarray_get(&data->ba, (size_t)i) == i%2
        );
    }
}
