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
    std::array<float, 16> a = {47.2, 50, -0.5, 0, 42, 50, -1856, -78, 0.2654, 0, 42.5, 188, 33, 1000, 76.35425, 47.2};

    opl::quickSortHybrid(a);

    ASSERT_FLOAT_EQ(a[0] , -1856);
    ASSERT_FLOAT_EQ(a[1] , -78);
    ASSERT_FLOAT_EQ(a[2] , -0.5);
    ASSERT_FLOAT_EQ(a[3] , 0);
    ASSERT_FLOAT_EQ(a[4] , 0);
    ASSERT_FLOAT_EQ(a[5] , 0.2654);
    ASSERT_FLOAT_EQ(a[6] , 33);
    ASSERT_FLOAT_EQ(a[7] , 42);
    ASSERT_FLOAT_EQ(a[8] , 42.5);
    ASSERT_FLOAT_EQ(a[9] , 47.2);
    ASSERT_FLOAT_EQ(a[10] , 47.2);
    ASSERT_FLOAT_EQ(a[11] , 50);
    ASSERT_FLOAT_EQ(a[12] , 50);
    ASSERT_FLOAT_EQ(a[13] , 76.35425);
    ASSERT_FLOAT_EQ(a[14] , 188);
    ASSERT_FLOAT_EQ(a[15] , 1000);
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