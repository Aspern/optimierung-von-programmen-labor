#include "./util/TypedArrayTest.cpp"
#include "../src/alogrithms/MinimumSearch.h"

const size_t SIZE = 8;

template<typename T>
class TypedMinimumSearchTest : public ::TypedArrayTest<T> {
public:

    std::array<T, SIZE> *const array_;

    TypedMinimumSearchTest() : array_(new std::array<T, SIZE>()) {}

    void SetUp() {}

    void TearDown() {}

    ~TypedMinimumSearchTest() { delete this->array_; }
};

typedef ::testing::Types<int, long, float, double> MyTypes;
TYPED_TEST_CASE(TypedMinimumSearchTest, MyTypes);


TYPED_TEST(TypedMinimumSearchTest, findMinimumAsc) {
    this->fillAsc(*this->array_);
    auto min = this->array_->at(0);

    ASSERT_EQ(opl::minimum(*this->array_), min);
    ASSERT_EQ(opl::minimumOptimized(*this->array_), min);
    ASSERT_EQ(opl::minimumWithPrefetch(*this->array_), min);
}

TYPED_TEST(TypedMinimumSearchTest, findMinimumDesc) {
    this->fillDesc(*this->array_);
    auto min = this->array_->at(SIZE - 1);



    ASSERT_EQ(opl::minimum(*this->array_), min);
    ASSERT_EQ(opl::minimumOptimized(*this->array_), min);
    ASSERT_EQ(opl::minimumWithPrefetch(*this->array_), min);
}

TYPED_TEST(TypedMinimumSearchTest, findMinimumRandom) {
    this->fillRandom(*this->array_);

    ASSERT_NO_THROW(opl::minimum(*this->array_));
    ASSERT_NO_THROW(opl::minimumOptimized(*this->array_));
    ASSERT_NO_THROW(opl::minimumWithPrefetch(*this->array_));
}

