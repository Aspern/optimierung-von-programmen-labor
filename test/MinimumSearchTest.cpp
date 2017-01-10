#include <gtest/gtest.h>
#include "./util/SimpleArrays.h"
#include "../src/alogrithms/MinimumSearch.h"

class MinimumSearchTest : public ::testing::Test {
public:
    MinimumSearchTest() {}

    void SetUp() {}

    void TearDown() {}

    ~MinimumSearchTest() {}
};

TEST_F(MinimumSearchTest, findBoolMinimum) {
    ASSERT_EQ(opl::minimum(opl::array::bool_), opl::min::bool_);
    ASSERT_EQ(opl::minimumOptimized(opl::array::bool_), opl::min::bool_);
    ASSERT_EQ(opl::minimumWithPrefetch(opl::array::bool_), opl::min::bool_);
}

TEST_F(MinimumSearchTest, findIntegerMinimum) {
    ASSERT_EQ(opl::minimum(opl::array::int_), opl::min::int_);
    ASSERT_EQ(opl::minimumOptimized(opl::array::int_), opl::min::int_);
    ASSERT_EQ(opl::minimumWithPrefetch(opl::array::int_), opl::min::int_);
}

TEST_F(MinimumSearchTest, findLongMinimum) {
    ASSERT_EQ(opl::minimum(opl::array::long_), opl::min::long_);
    ASSERT_EQ(opl::minimumOptimized(opl::array::long_), opl::min::long_);
    ASSERT_EQ(opl::minimumWithPrefetch(opl::array::long_), opl::min::long_);
}

TEST_F(MinimumSearchTest, findFloatMinimum) {
    ASSERT_EQ(opl::minimum(opl::array::float_), opl::min::float_);
    ASSERT_EQ(opl::minimumOptimized(opl::array::float_), opl::min::float_);
    ASSERT_EQ(opl::minimumWithPrefetch(opl::array::float_), opl::min::float_);
}


TEST_F(MinimumSearchTest, findDoubleMinimum) {
    ASSERT_EQ(opl::minimum(opl::array::double_), opl::min::double_);
    ASSERT_EQ(opl::minimumOptimized(opl::array::double_), opl::min::double_);
    ASSERT_EQ(opl::minimumWithPrefetch(opl::array::double_), opl::min::double_);
}

TEST_F(MinimumSearchTest, findStringMinimum) {
    ASSERT_EQ(opl::minimum(opl::array::string_), opl::min::string_);
    ASSERT_EQ(opl::minimumOptimized(opl::array::string_), opl::min::string_);
    ASSERT_EQ(opl::minimumWithPrefetch(opl::array::string_), opl::min::string_);
}