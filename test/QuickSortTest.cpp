#include <gtest/gtest.h>
#include "../src/alogrithms/QuickSort.h"
#include "ArrayTests.h"

class QuickSortTest : public ::testing::Test {

public:

    QuickSortTest() {
    }

    void SetUp() {
    }

    void TearDown() {
    }

    ~QuickSortTest() {
    }
};

TEST_F(QuickSortTest, testQuickSortWithStaticValues) {
    std::array<int, 8> a = {77, 5, 1, 6, 49, 87444, -4, 0};

    quickSort(a);

    ASSERT_EQ(a[0], -4);
    ASSERT_EQ(a[1], 0);
    ASSERT_EQ(a[2], 1);
    ASSERT_EQ(a[3], 5);
    ASSERT_EQ(a[4], 6);
    ASSERT_EQ(a[5], 49);
    ASSERT_EQ(a[6], 77);
    ASSERT_EQ(a[7], 87444);
}

TEST_F(QuickSortTest, testQuickSortWithGeneratedValues) {
    std::array<int, TEST_ARR_SIZE> *a = new std::array<int, TEST_ARR_SIZE>();

    fillArrayDesc(*a);
    quickSort(*a);
    ASSERT_ARRAY_SORTED(*a);

    fillArrayAsc(*a);
    quickSort(*a);
    ASSERT_ARRAY_SORTED(*a);

    fillArrayRandom(*a);
    quickSort(*a);
    ASSERT_ARRAY_SORTED(*a);
}

TEST_F(QuickSortTest, testQuickSortHybridWithGeneratedValues) {
    std::array<int, 8> a = {77, 5, 1, 6, 49, 87444, -4, 0};

    quickSort_v2(a);

    ASSERT_EQ(a[0], -4);
    ASSERT_EQ(a[1], 0);
    ASSERT_EQ(a[2], 1);
    ASSERT_EQ(a[3], 5);
    ASSERT_EQ(a[4], 6);
    ASSERT_EQ(a[5], 49);
    ASSERT_EQ(a[6], 77);
    ASSERT_EQ(a[7], 87444);
}


