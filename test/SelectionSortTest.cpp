#include <gtest/gtest.h>
#include "../src/alogrithms/SelectionSort.h"
#include "../src/measurement/ArrayUtilities.h"

const size_t TEST_ARR_SIZE = 1024;

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

template <typename T, size_t SIZE>
void assert_array_sorted( std::array<T, SIZE> & a) {
    T v1 = a[0];
    T v2 = a[1];

    for(size_t i = 2; i < TEST_ARR_SIZE; i++) {
        GTEST_ASSERT_LE(v1, v2);
        v2 = v1;
        v2 = a[i];
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
    assert_array_sorted(*a);

    fillArrayAsc(*a);
    selectionSort_v1(*a);
    assert_array_sorted(*a);

    fillArrayRandom(*a);
    selectionSort_v1(*a);
    assert_array_sorted(*a);
}

TEST_F(SelectionSortTest, testSelectionSort_v2WithGeneratedValues) {
    std::array<int, TEST_ARR_SIZE> *a = new std::array<int, TEST_ARR_SIZE>();

    fillArrayDesc(*a);
    selectionSort_v2(*a);
    assert_array_sorted(*a);

    fillArrayAsc(*a);
    selectionSort_v2(*a);
    assert_array_sorted(*a);

    fillArrayRandom(*a);
    selectionSort_v2(*a);
    assert_array_sorted(*a);
}

TEST_F(SelectionSortTest, testSelectionSort_v3WithGeneratedValues) {
    std::array<int, TEST_ARR_SIZE> *a = new std::array<int, TEST_ARR_SIZE>();

    fillArrayDesc(*a);
    selectionSort_v3(*a);
    assert_array_sorted(*a);

    fillArrayAsc(*a);
    selectionSort_v3(*a);
    assert_array_sorted(*a);

    fillArrayRandom(*a);
    selectionSort_v3(*a);
    assert_array_sorted(*a);
}

