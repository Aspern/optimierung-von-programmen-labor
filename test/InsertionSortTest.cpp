#include <gtest/gtest.h>
#include "../src/algorithm/InsertionSort.h"

class InsertionSortTest : public ::testing::Test {
public:
    InsertionSortTest() {}

    void SetUp() {}

    void TearDown() {}

    ~InsertionSortTest() {}
};

TEST_F(InsertionSortTest, sortWithNumber) {
    std::array<float, 6> a = {47.2, 50, -0.5, 0, 42, 50};

    opl::insertionSort(a);

    ASSERT_FLOAT_EQ(a[0] , -0.5);
    ASSERT_FLOAT_EQ(a[1] , 0);
    ASSERT_FLOAT_EQ(a[2] , 42);
    ASSERT_FLOAT_EQ(a[3] , 47.2);
    ASSERT_FLOAT_EQ(a[4] , 50);
    ASSERT_FLOAT_EQ(a[5] , 50);
}

TEST_F(InsertionSortTest, sortWithBool) {
    std::array<bool, 2> a = {true, false};

    opl::insertionSort(a);

    ASSERT_EQ(a[0] , false);
    ASSERT_EQ(a[1] , true);
}

TEST_F(InsertionSortTest, sortWithString) {
    std::array<std::string, 4> a = {"Z", "G", "K", "A"};

    opl::insertionSort(a);

    ASSERT_EQ(a[0] , "A");
    ASSERT_EQ(a[1] , "G");
    ASSERT_EQ(a[2] , "K");
    ASSERT_EQ(a[3] , "Z");
}

TEST_F(InsertionSortTest, sortWithPrefetchWithNumber) {
    std::array<float, 6> a = {47.2, 50, -0.5, 0, 42, 50};

    opl::insertionSortWithPrefetch(a);

    ASSERT_FLOAT_EQ(a[0] , -0.5);
    ASSERT_FLOAT_EQ(a[1] , 0);
    ASSERT_FLOAT_EQ(a[2] , 42);
    ASSERT_FLOAT_EQ(a[3] , 47.2);
    ASSERT_FLOAT_EQ(a[4] , 50);
    ASSERT_FLOAT_EQ(a[5] , 50);
}

TEST_F(InsertionSortTest,  sortWithPrefetchWithBool) {
    std::array<bool, 2> a = {true, false};

    opl::insertionSortWithPrefetch(a);

    ASSERT_EQ(a[0] , false);
    ASSERT_EQ(a[1] , true);
}

TEST_F(InsertionSortTest,  sortWithPrefetchString) {
    std::array<std::string, 4> a = {"Z", "G", "K", "A"};

    opl::insertionSortWithPrefetch(a);

    ASSERT_EQ(a[0] , "A");
    ASSERT_EQ(a[1] , "G");
    ASSERT_EQ(a[2] , "K");
    ASSERT_EQ(a[3] , "Z");
}