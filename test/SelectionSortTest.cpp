#include <gtest/gtest.h>
#include "../src/alogrithms/SelectionSort.h"
#include "ArrayTests.h"

class SelectionSortTest: public ::testing::Test {

public:

    SelectionSortTest() {
    }

    void SetUp() {
    }

    void TearDown() {
    }

    ~SelectionSortTest()  {
    }
};

TEST_F(SelectionSortTest, testSelectionSort_v1WithStaticValues) {
    std::array<int, 8> a = {77, 5, 1, 6, 49, 87444, -4, 0};

    selectionSort_v1(a);

    ASSERT_EQ(a[0], -4);
    ASSERT_EQ(a[1], 0);
    ASSERT_EQ(a[2], 1);
    ASSERT_EQ(a[3], 5);
    ASSERT_EQ(a[4], 6);
    ASSERT_EQ(a[5], 49);
    ASSERT_EQ(a[6], 77);
    ASSERT_EQ(a[7], 87444);
}

TEST_F(SelectionSortTest, testSelectionSort_v2WithStaticValues) {
    std::array<int, 8> a = {77, 5, 1, 6, 49, 87444, -4, 0};

    selectionSort_v2(a);

    ASSERT_EQ(a[0], -4);
    ASSERT_EQ(a[1], 0);
    ASSERT_EQ(a[2], 1);
    ASSERT_EQ(a[3], 5);
    ASSERT_EQ(a[4], 6);
    ASSERT_EQ(a[5], 49);
    ASSERT_EQ(a[6], 77);
    ASSERT_EQ(a[7], 87444);
}

TEST_F(SelectionSortTest, testSelectionSort_v3WithStaticValues) {
    std::array<int, 8> a = {77, 5, 1, 6, 49, 87444, -4, 0};

    selectionSort_v3(a);

    ASSERT_EQ(a[0], -4);
    ASSERT_EQ(a[1], 0);
    ASSERT_EQ(a[2], 1);
    ASSERT_EQ(a[3], 5);
    ASSERT_EQ(a[4], 6);
    ASSERT_EQ(a[5], 49);
    ASSERT_EQ(a[6], 77);
    ASSERT_EQ(a[7], 87444);
}

TEST_F(SelectionSortTest, testSelectionSort_v1WithGeneratedValues) {
    std::array<int, TEST_ARR_SIZE> *a = new std::array<int, TEST_ARR_SIZE>();

    fillArrayDesc(*a);
    selectionSort_v1(*a);
    ASSERT_ARRAY_SORTED(*a);

    fillArrayAsc(*a);
    selectionSort_v1(*a);
    ASSERT_ARRAY_SORTED(*a);

    fillArrayRandom(*a);
    selectionSort_v1(*a);
    ASSERT_ARRAY_SORTED(*a);
}

TEST_F(SelectionSortTest, testSelectionSort_v2WithGeneratedValues) {
    std::array<int, TEST_ARR_SIZE> *a = new std::array<int, TEST_ARR_SIZE>();

    fillArrayDesc(*a);
    selectionSort_v2(*a);
    ASSERT_ARRAY_SORTED(*a);

    fillArrayAsc(*a);
    selectionSort_v2(*a);
    ASSERT_ARRAY_SORTED(*a);

    fillArrayRandom(*a);
    selectionSort_v2(*a);
    ASSERT_ARRAY_SORTED(*a);
}

TEST_F(SelectionSortTest, testSelectionSort_v3WithGeneratedValues) {
    std::array<int, TEST_ARR_SIZE> *a = new std::array<int, TEST_ARR_SIZE>();

    fillArrayDesc(*a);
    selectionSort_v3(*a);
    ASSERT_ARRAY_SORTED(*a);

    fillArrayAsc(*a);
    selectionSort_v3(*a);
    ASSERT_ARRAY_SORTED(*a);

    fillArrayRandom(*a);
    selectionSort_v3(*a);
    ASSERT_ARRAY_SORTED(*a);
}

