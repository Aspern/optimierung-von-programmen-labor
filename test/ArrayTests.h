#include "../src/measurement/ArrayUtilities.h"

#ifndef OPL_ARRAYTESTS_H
#define OPL_ARRAYTESTS_H

const size_t TEST_ARR_SIZE = 1024;

template<typename T, size_t SIZE>
void ASSERT_ARRAY_SORTED(std::array <T, SIZE> &a) {
    T v1 = a[0];
    T v2 = a[1];

    for (size_t i = 2; i < SIZE; i++) {
        GTEST_ASSERT_LE(v1, v2);
        v2 = v1;
        v2 = a[i];
    }
}

#endif //OPL_ARRAYTESTS_H
