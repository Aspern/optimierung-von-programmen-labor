#include <gtest/gtest.h>
#include "../src/alogrithms/InsertionSort.h"
#include "ArrayTests.h"

class InsertionSortTest: public ::testing::Test {

public:

    InsertionSortTest() {
    }

    void SetUp() {
    }

    void TearDown() {
    }

    ~InsertionSortTest()  {
    }
};

TEST_F(InsertionSortTest, testInsertionSort_v1WithStaticValues) {
    std::array<int, 8> a = {77, 5, 1, 6, 49, 87444, -4, 0};

    insertionSort_v1(a);

    ASSERT_EQ(a[0], -4);
    ASSERT_EQ(a[1], 0);
    ASSERT_EQ(a[2], 1);
    ASSERT_EQ(a[3], 5);
    ASSERT_EQ(a[4], 6);
    ASSERT_EQ(a[5], 49);
    ASSERT_EQ(a[6], 77);
    ASSERT_EQ(a[7], 87444);
}

TEST_F(InsertionSortTest, testInsertionSort_v1WithGeneratedValues) {
    std::array<int, TEST_ARR_SIZE> *a = new std::array<int, TEST_ARR_SIZE>();

    fillArrayDesc(*a);
    insertionSort_v1(*a);
    ASSERT_ARRAY_SORTED(*a);

    fillArrayAsc(*a);
    insertionSort_v1(*a);
    ASSERT_ARRAY_SORTED(*a);

    fillArrayRandom(*a);
    insertionSort_v1(*a);
    ASSERT_ARRAY_SORTED(*a);
}

TEST_F(InsertionSortTest, testInsertionSOrt_v2WithStaticValues) {
    std::array<int, 8> a = {77, 5, 1, 6, 49, 87444, -4, 0};

    insertionSort_v2(a);

    ASSERT_EQ(a[0], -4);
    ASSERT_EQ(a[1], 0);
    ASSERT_EQ(a[2], 1);
    ASSERT_EQ(a[3], 5);
    ASSERT_EQ(a[4], 6);
    ASSERT_EQ(a[5], 49);
    ASSERT_EQ(a[6], 77);
    ASSERT_EQ(a[7], 87444);
}

TEST_F(InsertionSortTest, testInsertionSOrt_v2WWithGeneratedValues) {
    std::array<int, TEST_ARR_SIZE> *a = new std::array<int, TEST_ARR_SIZE>();

    fillArrayDesc(*a);
    insertionSort_v2(*a);
    ASSERT_ARRAY_SORTED(*a);

    fillArrayAsc(*a);
    insertionSort_v2(*a);
    ASSERT_ARRAY_SORTED(*a);

    fillArrayRandom(*a);
    insertionSort_v2(*a);
    ASSERT_ARRAY_SORTED(*a);
}