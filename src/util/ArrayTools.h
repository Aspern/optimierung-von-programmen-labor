#ifndef OPL_ARRAYUTILITIES_H
#define OPL_ARRAYUTILITIES_H

#include <random>
#include <iostream>
#include "../runtime/Constants.h"


namespace opl {

    /**
     * Fills an array with ascending values.
     *
     * @param a Empty array
     */
    template<typename T, size_t SIZE>
    void fillArrayAsc(std::array<T, SIZE> &a) {
        for (size_t i = 0; i < SIZE; i++)
            a[i] = (T) i;
    }

    /**
     * Fills an array with descending values.
     *
     * @param a Empty array
     */
    template<typename T, size_t SIZE>
    void fillArrayDesc(std::array<T, SIZE> &a) {
        for (size_t i = SIZE, j = 0; i > 0; --i, ++j)
            a[j] = (T) i - 1;
    }

    /**
     * Fills an array with random values.
     *
     * @param a Empty array
     */
    template<typename T, size_t SIZE>
    void fillArrayRandom(std::array<T, SIZE> &a) {
        std::mt19937_64 generator;
        generator.seed(std::random_device{}());

        for (size_t i = 0; i < SIZE; i++)
            a[i] = (T) generator();
    }

    /**
     * Clears the cache of the runtime environment
     */
    void clearCache() {
        std::array<long, opl::constant::max_cache_size> *a = new std::array<long, opl::constant::max_cache_size>();

        for (int i = 0; i < opl::constant::max_cache_size; i++)
            a->at(i) = 1L;

        delete a;
    }
}


#endif //OPL_ARRAYUTILITIES_H
