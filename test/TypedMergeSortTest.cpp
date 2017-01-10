#include "./util/TypedArrayTest.cpp"
#include "../src/algorithm/MergeSort.h"

template<typename T>
class TypedMergeSortTest : public ::TypedArrayTest<T> {
public:

    std::array<T, SIZE> *const array_;

    TypedMergeSortTest() : array_(new std::array<T, SIZE>()) {}

    void SetUp() {}

    void TearDown() {}

    ~TypedMergeSortTest() { delete this->array_; }
};

typedef ::testing::Types<int, long, float, double> MyTypes;
TYPED_TEST_CASE(TypedMergeSortTest, MyTypes);


TYPED_TEST(TypedMergeSortTest, sortAsc) {
    this->fillAsc(*this->array_);
    opl::bottomUpMergeSort(*this->array_);
    ASSERT_TRUE(this->isSorted(*this->array_));
}

TYPED_TEST(TypedMergeSortTest, sortDesc) {
    this->fillDesc(*this->array_);
    opl::bottomUpMergeSort(*this->array_);
    ASSERT_TRUE(this->isSorted(*this->array_));
}

TYPED_TEST(TypedMergeSortTest, sortRandom) {
    this->fillRandom(*this->array_);
    opl::bottomUpMergeSort(*this->array_);
    ASSERT_TRUE(this->isSorted(*this->array_));
}