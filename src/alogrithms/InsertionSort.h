#ifndef OPL_INSERTIONSORT_H
#define OPL_INSERTIONSORT_H

#include "../measurement/RuntimeConstants.h"

/**
 *
 * @tparam T
 * @tparam SIZE
 * @param a
 */
template<typename T, size_t SIZE>
void insertionSort_v1(std::array<T, SIZE> &a, size_t l, size_t r) {
    for (size_t i = l + 1; i < r; i++) {
        for(size_t j = i; j > 0 && a[j - 1] > a[j]; j--) {
            std::swap(a[j], a[j - 1]);
        }
    }
}

/**
 *
 * @tparam T
 * @tparam SIZE
 * @param a
 */
template<typename T, size_t SIZE>
void insertionSort_v1(std::array<T, SIZE> &a) {
    /*for (size_t i = 1; i < SIZE; i++) {
        for(size_t j = i; j > 0 && a[j - 1] > a[j]; j--) {
            std::swap(a[j], a[j - 1]);
        }
    }*/
    insertionSort_v1(a, 0, SIZE);
}



/**
 *
 * @tparam T
 * @tparam SIZE
 * @param a
 */
template<typename T, size_t SIZE>
void insertionSort_v2(std::array<T, SIZE> &a) {

    // Anzahl Elemente des Datentyps T, die in eine Cache-Line passen.
    const size_t range = (CACHE_LINE_SIZE / sizeof(T));

/*    for (size_t i = 1; i < SIZE; i++) {
        __builtin_prefetch(&a[i - range]);
        for(size_t j = i; j > 0 && a[j - 1] > a[j]; j--) {
            std::swap(a[j], a[j - 1]);
        }
    }*/


   /* for(size_t i = 0; i < SIZE; i++) {
        for(size_t j = i + range; j > 0 && a[j - range - 1] > a[j - range]; j -= range) {
            __builtin_prefetch(&a[i - range]);
            for(size_t k = j; k > i - range; k--) {
                std::swap(a[k], a[k - 1]);
            }
        }
    }*/

    size_t cacheCnt;

    for (size_t i = 1; i < SIZE; i++) {
        cacheCnt = 0;
        for (size_t j = i; j > 0 && a[j - 1] > a[j]; j--) {
            if (cacheCnt <= 0) {
                __builtin_prefetch(&a[j - range]);
                cacheCnt = range;
            }
            cacheCnt--;
            std::swap(a[j], a[j - 1]);
        }
    }


}

#endif //OPL_INSERTIONSORT_H
