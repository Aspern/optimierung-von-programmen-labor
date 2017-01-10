#include "./util/TypedArrayTest.cpp"
#include "../src/algorithm/SelectionSort.h"

template<typename T>
class TypedSelectionSortTest : public ::TypedArrayTest<T> {
public:

    std::array<T, SIZE> *const array_;

    TypedSelectionSortTest() : array_(new std::array<T, SIZE>()) {}

    void SetUp() {}

    void TearDown() {}

    ~TypedSelectionSortTest() { delete this->array_; }
};

typedef ::testing::Types<int, long, float, double> MyTypes;
TYPED_TEST_CASE(TypedSelectionSortTest, MyTypes);


TYPED_TEST(TypedSelectionSortTest, sortAsc) {
    this->fillAsc(*this->array_);
    opl::selectionSort(*this->array_);
    ASSERT_TRUE(this->isSorted(*this->array_));
}

TYPED_TEST(TypedSelectionSortTest, sortDesc) {
    this->fillDesc(*this->array_);
    opl::selectionSort(*this->array_);
    ASSERT_TRUE(this->isSorted(*this->array_));
}

TYPED_TEST(TypedSelectionSortTest, sortRandom) {
    this->fillRandom(*this->array_);
    opl::selectionSort(*this->array_);
    ASSERT_TRUE(this->isSorted(*this->array_));
}

TYPED_TEST(TypedSelectionSortTest, sortOptimizedAsc) {
    this->fillAsc(*this->array_);
    opl::selectionSortOptimized(*this->array_);
    ASSERT_TRUE(this->isSorted(*this->array_));
}

TYPED_TEST(TypedSelectionSortTest, sortOptimizedDesc) {
    this->fillDesc(*this->array_);
    opl::selectionSortOptimized(*this->array_);
    ASSERT_TRUE(this->isSorted(*this->array_));
}

TYPED_TEST(TypedSelectionSortTest, sortOptimizedRandom) {
    this->fillRandom(*this->array_);
    opl::selectionSortOptimized(*this->array_);
    ASSERT_TRUE(this->isSorted(*this->array_));
}

TYPED_TEST(TypedSelectionSortTest, sortWithPrfetchAsc) {
    this->fillAsc(*this->array_);
    opl::selectionSortWithPrefetch(*this->array_);
    ASSERT_TRUE(this->isSorted(*this->array_));
}

TYPED_TEST(TypedSelectionSortTest, sortWithPrfetchDesc) {
    this->fillDesc(*this->array_);
    opl::selectionSortWithPrefetch(*this->array_);
    ASSERT_TRUE(this->isSorted(*this->array_));
}

TYPED_TEST(TypedSelectionSortTest, sortWithPrfetchRandom) {
    this->fillRandom(*this->array_);
    opl::selectionSortWithPrefetch(*this->array_);
    ASSERT_TRUE(this->isSorted(*this->array_));
}



