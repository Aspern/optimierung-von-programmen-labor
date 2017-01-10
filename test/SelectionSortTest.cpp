#include <gtest/gtest.h>
#include "../src/algorithm/SelectionSort.h"

class SelectionSortTest : public ::testing::Test {
public:
    SelectionSortTest() {}

    void SetUp() {}

    void TearDown() {}

    ~SelectionSortTest() {}
};

TEST_F(SelectionSortTest, sortWithNumber) {
    std::array<float, 6> a = {47.2, 50, -0.5, 0, 42, 50};

    opl::selectionSort(a);

    ASSERT_FLOAT_EQ(a[0] , -0.5);
    ASSERT_FLOAT_EQ(a[1] , 0);
    ASSERT_FLOAT_EQ(a[2] , 42);
    ASSERT_FLOAT_EQ(a[3] , 47.2);
    ASSERT_FLOAT_EQ(a[4] , 50);
    ASSERT_FLOAT_EQ(a[5] , 50);
}

TEST_F(SelectionSortTest, sortWithBool) {
    std::array<bool, 2> a = {true, false};

    opl::selectionSort(a);

    ASSERT_EQ(a[0] , false);
    ASSERT_EQ(a[1] , true);
}

TEST_F(SelectionSortTest, sortWithString) {
    std::array<std::string, 4> a = {"Z", "G", "K", "A"};

    opl::selectionSort(a);

    ASSERT_EQ(a[0] , "A");
    ASSERT_EQ(a[1] , "G");
    ASSERT_EQ(a[2] , "K");
    ASSERT_EQ(a[3] , "Z");
}

TEST_F(SelectionSortTest, sortOptimizedWithNumber) {
    std::array<float, 6> a = {47.2, 50, -0.5, 0, 42, 50};

    opl::selectionSortOptimized(a);

    ASSERT_FLOAT_EQ(a[0] , -0.5);
    ASSERT_FLOAT_EQ(a[1] , 0);
    ASSERT_FLOAT_EQ(a[2] , 42);
    ASSERT_FLOAT_EQ(a[3] , 47.2);
    ASSERT_FLOAT_EQ(a[4] , 50);
    ASSERT_FLOAT_EQ(a[5] , 50);
}

TEST_F(SelectionSortTest, sortOptimizedWithBool) {
    std::array<bool, 2> a = {true, false};

    opl::selectionSortOptimized(a);

    ASSERT_EQ(a[0] , false);
    ASSERT_EQ(a[1] , true);
}

TEST_F(SelectionSortTest, sortOptimizedWithString) {
    std::array<std::string, 4> a = {"Z", "G", "K", "A"};

    opl::selectionSortOptimized(a);

    ASSERT_EQ(a[0] , "A");
    ASSERT_EQ(a[1] , "G");
    ASSERT_EQ(a[2] , "K");
    ASSERT_EQ(a[3] , "Z");
}

TEST_F(SelectionSortTest, sortWithPrefetchWithNumber) {
    std::array<float, 6> a = {47.2, 50, -0.5, 0, 42, 50};

    opl::selectionSortOptimized(a);

    ASSERT_FLOAT_EQ(a[0] , -0.5);
    ASSERT_FLOAT_EQ(a[1] , 0);
    ASSERT_FLOAT_EQ(a[2] , 42);
    ASSERT_FLOAT_EQ(a[3] , 47.2);
    ASSERT_FLOAT_EQ(a[4] , 50);
    ASSERT_FLOAT_EQ(a[5] , 50);
}

TEST_F(SelectionSortTest,  sortWithPrefetchWithBool) {
    std::array<bool, 2> a = {true, false};

    opl::selectionSortOptimized(a);

    ASSERT_EQ(a[0] , false);
    ASSERT_EQ(a[1] , true);
}

TEST_F(SelectionSortTest,  sortWithPrefetchString) {
    std::array<std::string, 4> a = {"Z", "G", "K", "A"};

    opl::selectionSortOptimized(a);

    ASSERT_EQ(a[0] , "A");
    ASSERT_EQ(a[1] , "G");
    ASSERT_EQ(a[2] , "K");
    ASSERT_EQ(a[3] , "Z");
}