#include "./util/TypedArrayTest.cpp"
#include "../src/algorithm/InsertionSort.h"

template<typename T>
class TypedInsertionSortTest : public ::TypedArrayTest<T> {
public:

    std::array<T, SIZE> *const array_;

    TypedInsertionSortTest() : array_(new std::array<T, SIZE>()) {}

    void SetUp() {}

    void TearDown() {}

    ~TypedInsertionSortTest() { delete this->array_; }
};

typedef ::testing::Types<int, long, float, double> MyTypes;
TYPED_TEST_CASE(TypedInsertionSortTest, MyTypes);


TYPED_TEST(TypedInsertionSortTest, sortAsc) {
    this->fillAsc(*this->array_);
    opl::insertionSort(*this->array_);
    ASSERT_TRUE(this->isSorted(*this->array_));
}

TYPED_TEST(TypedInsertionSortTest, sortDesc) {
    this->fillDesc(*this->array_);
    opl::insertionSort(*this->array_);
    ASSERT_TRUE(this->isSorted(*this->array_));
}

TYPED_TEST(TypedInsertionSortTest, sortRandom) {
    this->fillRandom(*this->array_);
    opl::insertionSort(*this->array_);
    ASSERT_TRUE(this->isSorted(*this->array_));
}

TYPED_TEST(TypedInsertionSortTest, sortWithPrfetchAsc) {
    this->fillAsc(*this->array_);
    opl::insertionSortWithPrefetch(*this->array_);
    ASSERT_TRUE(this->isSorted(*this->array_));
}

TYPED_TEST(TypedInsertionSortTest, sortWithPrfetchDesc) {
    this->fillDesc(*this->array_);
    opl::insertionSortWithPrefetch(*this->array_);
    ASSERT_TRUE(this->isSorted(*this->array_));
}

TYPED_TEST(TypedInsertionSortTest, sortWithPrfetchRandom) {
    this->fillRandom(*this->array_);
    opl::insertionSortWithPrefetch(*this->array_);
    ASSERT_TRUE(this->isSorted(*this->array_));
}



