#include "./util/TypedArrayTest.cpp"
#include "../src/algorithm/QuickSort.h"

template<typename T>
class TypedQuickSortTest : public ::TypedArrayTest<T> {
public:

    std::array<T, SIZE> *const array_;

    TypedQuickSortTest() : array_(new std::array<T, SIZE>()) {}

    void SetUp() {}

    void TearDown() {}

    ~TypedQuickSortTest() { delete this->array_; }
};

typedef ::testing::Types<int, long, float, double> MyTypes;
TYPED_TEST_CASE(TypedQuickSortTest, MyTypes);


TYPED_TEST(TypedQuickSortTest, sortAsc) {
    this->fillAsc(*this->array_);
    opl::quickSort(*this->array_);
    ASSERT_TRUE(this->isSorted(*this->array_));
}

TYPED_TEST(TypedQuickSortTest, sortDesc) {
    this->fillDesc(*this->array_);
    opl::quickSort(*this->array_);
    ASSERT_TRUE(this->isSorted(*this->array_));
}

TYPED_TEST(TypedQuickSortTest, sortRandom) {
    this->fillRandom(*this->array_);
    opl::quickSort(*this->array_);
    ASSERT_TRUE(this->isSorted(*this->array_));
}

TYPED_TEST(TypedQuickSortTest, sortHybridAsc) {
    this->fillAsc(*this->array_);
    opl::quickSortHybrid(*this->array_);
    ASSERT_TRUE(this->isSorted(*this->array_));
}

TYPED_TEST(TypedQuickSortTest, sortHybridDesc) {
    this->fillDesc(*this->array_);
    opl::quickSortHybrid(*this->array_);
    ASSERT_TRUE(this->isSorted(*this->array_));
}

TYPED_TEST(TypedQuickSortTest, sortHybridRandom) {
    this->fillRandom(*this->array_);
    opl::quickSortHybrid(*this->array_);
    ASSERT_TRUE(this->isSorted(*this->array_));
}



