#include <gtest/gtest.h>
#include <random>

template<typename T>
class TypedArrayTest : public ::testing::Test {
protected:

    std::mt19937_64 generator;

    TypedArrayTest() { this->generator.seed(std::random_device{}()); }

    virtual ~TypedArrayTest() {}

    template<size_t SIZE>
    void fillAsc(std::array<T, SIZE> &a) {
        for (size_t i = 0; i < SIZE; ++i)
            a[i] = (T) i;
    }

    template<size_t SIZE>
    void fillDesc(std::array<T, SIZE> &a) {
        for (size_t i = SIZE, j = 0; i > 0; --i, ++j)
            a[j] = (T) i - 1;
    }

    template<size_t SIZE>
    void fillRandom(std::array<T, SIZE> &a) {
        for (size_t i = 0; i < SIZE; ++i)
            a[i] = (T) this->generator();
    }

    template<size_t SIZE>
    bool isSorted(std::array<T, SIZE> &a) {
        for (size_t i = 0; i < SIZE - 1; ++i)
            if (a[i] > a[i + 1])
                return false;
        return true;
    }
};




