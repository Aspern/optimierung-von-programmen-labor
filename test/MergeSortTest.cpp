#include <gtest/gtest.h>
#include "../src/alogrithms/MergeSort.h"
#include "ArrayTests.h"

class MergeSortTest: public ::testing::Test {

public:

    MergeSortTest() {
    }

    void SetUp() {
    }

    void TearDown() {
    }

    ~MergeSortTest()  {
    }
};

TEST_F(MergeSortTest, testMergeSortWithStaticValues) {
    std::array<int, 8> a = {77, 5, 1, 6, 49, 87444, -4, 0};

    bottomUpMergeSort(a);

    ASSERT_EQ(a[0], -4);
    ASSERT_EQ(a[1], 0);
    ASSERT_EQ(a[2], 1);
    ASSERT_EQ(a[3], 5);
    ASSERT_EQ(a[4], 6);
    ASSERT_EQ(a[5], 49);
    ASSERT_EQ(a[6], 77);
    ASSERT_EQ(a[7], 87444);
}

TEST_F(MergeSortTest, testMergeSortWithGeneratedValues) {
//    std::array<int, TEST_ARR_SIZE> *a = new std::array<int, TEST_ARR_SIZE>();
//
//    fillArrayDesc(*a);
//    bottomUpMergeSort(*a);
//    ASSERT_ARRAY_SORTED(*a);
//
//    fillArrayAsc(*a);
//    bottomUpMergeSort(*a);
//    ASSERT_ARRAY_SORTED(*a);
//
//    fillArrayRandom(*a);
//    fillArrayRandom(*a);
//    bottomUpMergeSort(*a);
//    ASSERT_ARRAY_SORTED(*a);
}


