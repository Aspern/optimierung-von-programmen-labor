#include <gtest/gtest.h>
#include <random>

#include "../src/alogrithms/MinimumSearch.h"

const size_t TEST_ARR_SIZE = 1024;

class MinimumSearchTest : public ::testing::Test {

public:
    template<typename T, size_t TEST_ARR_SIZE>
    void fillTestArray(std::array<T, TEST_ARR_SIZE> &a);

    MinimumSearchTest() {
    }

    void SetUp() {
    }

    void TearDown() {
    }

    ~MinimumSearchTest() {
    }

};

template<typename T, size_t TEST_ARR_SIZE>
void MinimumSearchTest::fillTestArray(std::array<T, TEST_ARR_SIZE> &a) {
    std::mt19937 generator;
    generator.seed(std::random_device{}());
    std::uniform_int_distribution<int> dis(0, (TEST_ARR_SIZE - 1));

    for (size_t i = 0; i < TEST_ARR_SIZE; i++) {
        a.at(i) = generator();
    }
    a.at(dis(generator)) = std::numeric_limits<int>::min();
}

TEST_F(MinimumSearchTest, testMinimumSearch_v1WithRandomValues) {
    std::array<int, TEST_ARR_SIZE> *a = new std::array<int, TEST_ARR_SIZE>();

    fillTestArray(*a);
    int min = minimumSearch_v1(*a);
    GTEST_ASSERT_EQ(min, std::numeric_limits<int>::min());

    delete a;
}


TEST_F(MinimumSearchTest, testMinimumSearch_v2WithRandomValues) {
    std::array<int, TEST_ARR_SIZE> *a = new std::array<int, TEST_ARR_SIZE>();

    fillTestArray(*a);
    int min = minimumSearch_v2(*a);
    GTEST_ASSERT_EQ(min, std::numeric_limits<int>::min());

    delete a;
}

TEST_F(MinimumSearchTest, testMinimumSearch_v3WithRandomValues) {
    std::array<int, TEST_ARR_SIZE> *a = new std::array<int, TEST_ARR_SIZE>();

    fillTestArray(*a);
    int min = minimumSearch_v3(*a);
    GTEST_ASSERT_EQ(min, std::numeric_limits<int>::min());

    delete a;
}

TEST_F(MinimumSearchTest, testAndCompareMinimumSearchVariants) {
    std::array<int, TEST_ARR_SIZE> *a = new std::array<int, TEST_ARR_SIZE>();

    fillTestArray(*a);
    int min1 = minimumSearch_v1(*a);
    int min2 = minimumSearch_v2(*a);
    int min3 = minimumSearch_v3(*a);
    GTEST_ASSERT_EQ(min1, min2);
    GTEST_ASSERT_EQ(min1, min3);
    GTEST_ASSERT_EQ(min2, min3);

    delete a;
}

TEST_F(MinimumSearchTest, testMinimumSearchWithDouble) {
    std::array<double, 8> a = {1.7, 2.0, 3.0, 4.0, 1.5, 6.0, 7.0, 8.0};

    GTEST_ASSERT_EQ(minimumSearch_v1(a), 1.5);
    GTEST_ASSERT_EQ(minimumSearch_v2(a), 1.5);
    GTEST_ASSERT_EQ(minimumSearch_v3(a), 1.5);
}

TEST_F(MinimumSearchTest, testMinimumSearchWithInteger) {
    std::array<int, 8> a = {1, 7, 6, 5, 4, 3, 2, 0};

    GTEST_ASSERT_EQ(minimumSearch_v1(a), 0);
    GTEST_ASSERT_EQ(minimumSearch_v2(a), 0);
    GTEST_ASSERT_EQ(minimumSearch_v3(a), 0);
}

TEST_F(MinimumSearchTest, testMinimumSearchWithChar) {
    std::array<char, 8> arr = {'a', 'b', 'c', 'e', 'z', 'h', 'i', 'A'};

    GTEST_ASSERT_EQ(minimumSearch_v1(arr), 'A');
    GTEST_ASSERT_EQ(minimumSearch_v2(arr), 'A');
    GTEST_ASSERT_EQ(minimumSearch_v3(arr), 'A');
}

TEST_F(MinimumSearchTest, testMinimumSearchWithBoolean) {
    std::array<bool, 8> a = {true, false, true, false, false, true, true, true};

    GTEST_ASSERT_EQ(minimumSearch_v1(a), false);
    GTEST_ASSERT_EQ(minimumSearch_v2(a), false);
    GTEST_ASSERT_EQ(minimumSearch_v3(a), false);
}


TEST_F(MinimumSearchTest, testMinimumSearchWithString) {
    std::array<std::string, 8> a = {"Hello", "World", "Zero", "Mega", "Test", "Alpha", "Seven", "Nine"};

    GTEST_ASSERT_EQ(minimumSearch_v1(a), "Alpha");
    GTEST_ASSERT_EQ(minimumSearch_v2(a), "Alpha");
    GTEST_ASSERT_EQ(minimumSearch_v3(a), "Alpha");
}

TEST_F(MinimumSearchTest, testMinimumSearch_v1WithIndex) {
    std::array<double, 8> a = {4, 8, 7, 7, 2, 1, 0, 41};

    double min = minimumSearch_v1(a, 0);

    ASSERT_EQ(min, 6);

    std::swap(a[0], a[min]);

    ASSERT_EQ(a[0], 0);
    ASSERT_EQ(a[6], 4);
}


