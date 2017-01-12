#ifndef OPL_INSERTIONSORT_H
#define OPL_INSERTIONSORT_H

#include "../runtime/Constants.h"

namespace opl {

    /**
     * Sorts an array from between ´left´ and ´right´ from the smallest to the largest element.
     *
     * @param a Array with values
     * @param lo Left border
     * @param hi Right border
     */
    template<typename T, size_t SIZE>
    void insertionSort(std::array<T, SIZE> &a, size_t lo, size_t hi) {
        for (size_t i = lo + 1; i < hi; i++)
            for (size_t j = i; j > lo && a[j - 1] > a[j]; j--)
                std::swap(a[j], a[j - 1]);

    }


    /**
     * Sorts an array from the smallest to the largest element.
     *
     * @param a Array with values
     */
    template<typename T, size_t SIZE>
    void insertionSort(std::array<T, SIZE> &a) {
        insertionSort(a, 0, SIZE);
    }

    /**
     * Sorts an array from the smallest to the largest element.
     * Uses ´__builtin_prefetch´ to optimize performance.
     *
     * @param a Array with values
     */
    template<typename T, size_t SIZE>
    void insertionSortWithPrefetch(std::array<T, SIZE> &a) {
        const size_t nElementsInCacheLine = (opl::constant::cache_line_size / sizeof(T));

        for (size_t i = 1; i < SIZE; i++)
            for (size_t j = i + nElementsInCacheLine; j > nElementsInCacheLine;) {
                j -= nElementsInCacheLine;
                __builtin_prefetch(&a[j - nElementsInCacheLine]);
                for(size_t k = j; k > 0  && a[k - 1] > a[k]; k--)
                    std::swap(a[k], a[k-1]);
            }
    }

}

#endif //OPL_INSERTIONSORT_H
