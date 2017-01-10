#include <gtest/gtest.h>
#include "../src/algorithm/QuickSort.h"

class QuickSortTest : public ::testing::Test {
public:
    QuickSortTest() {}

    void SetUp() {}

    void TearDown() {}

    ~QuickSortTest() {}
};

TEST_F(QuickSortTest, sortWithNumber) {
    std::array<float, 6> a = {47.2, 50, -0.5, 0, 42, 50};

    opl::quickSort(a);

    ASSERT_FLOAT_EQ(a[0] , -0.5);
    ASSERT_FLOAT_EQ(a[1] , 0);
    ASSERT_FLOAT_EQ(a[2] , 42);
    ASSERT_FLOAT_EQ(a[3] , 47.2);
    ASSERT_FLOAT_EQ(a[4] , 50);
    ASSERT_FLOAT_EQ(a[5] , 50);
}

TEST_F(QuickSortTest, sortWithBool) {
    std::array<bool, 2> a = {true, false};

    opl::quickSort(a);

    ASSERT_EQ(a[0] , false);
    ASSERT_EQ(a[1] , true);
}

TEST_F(QuickSortTest, sortWithString) {
    std::array<std::string, 4> a = {"Z", "G", "K", "A"};

    opl::quickSort(a);

    ASSERT_EQ(a[0] , "A");
    ASSERT_EQ(a[1] , "G");
    ASSERT_EQ(a[2] , "K");
    ASSERT_EQ(a[3] , "Z");
}

TEST_F(QuickSortTest, sortHybridWithNumber) {
    std::array<float, 6> a = {47.2, 50, -0.5, 0, 42, 50};

    opl::quickSortHybrid(a);

    ASSERT_FLOAT_EQ(a[0] , -0.5);
    ASSERT_FLOAT_EQ(a[1] , 0);
    ASSERT_FLOAT_EQ(a[2] , 42);
    ASSERT_FLOAT_EQ(a[3] , 47.2);
    ASSERT_FLOAT_EQ(a[4] , 50);
    ASSERT_FLOAT_EQ(a[5] , 50);
}

TEST_F(QuickSortTest, sortHybridWithBool) {
    std::array<bool, 2> a = {true, false};

    opl::quickSortHybrid(a);

    ASSERT_EQ(a[0] , false);
    ASSERT_EQ(a[1] , true);
}

TEST_F(QuickSortTest, sortHybridWithString) {
    std::array<std::string, 4> a = {"Z", "G", "K", "A"};

    opl::quickSortHybrid(a);

    ASSERT_EQ(a[0] , "A");
    ASSERT_EQ(a[1] , "G");
    ASSERT_EQ(a[2] , "K");
    ASSERT_EQ(a[3] , "Z");
}