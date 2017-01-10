#include <gtest/gtest.h>
#include "../src/algorithm/MergeSort.h"

class MergeSortTest : public ::testing::Test {
public:
    MergeSortTest() {}

    void SetUp() {}

    void TearDown() {}

    ~MergeSortTest() {}
};

TEST_F(MergeSortTest, sortWithNumber) {
    std::array<float, 6> a = {47.2, 50, -0.5, 0, 42, 50};

    opl::bottomUpMergeSort(a);

    ASSERT_FLOAT_EQ(a[0] , -0.5);
    ASSERT_FLOAT_EQ(a[1] , 0);
    ASSERT_FLOAT_EQ(a[2] , 42);
    ASSERT_FLOAT_EQ(a[3] , 47.2);
    ASSERT_FLOAT_EQ(a[4] , 50);
    ASSERT_FLOAT_EQ(a[5] , 50);
}

TEST_F(MergeSortTest, sortWithBool) {
    std::array<bool, 2> a = {true, false};

    opl::bottomUpMergeSort(a);

    ASSERT_EQ(a[0] , false);
    ASSERT_EQ(a[1] , true);
}

TEST_F(MergeSortTest, sortWithString) {
    std::array<std::string, 4> a = {"Z", "G", "K", "A"};

    opl::bottomUpMergeSort(a);

    ASSERT_EQ(a[0] , "A");
    ASSERT_EQ(a[1] , "G");
    ASSERT_EQ(a[2] , "K");
    ASSERT_EQ(a[3] , "Z");
}