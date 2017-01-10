#ifndef OPL_SELECTIONSORT_H
#define OPL_SELECTIONSORT_H

#include <array>
#include "./MinimumSearch.h"

namespace opl {

    /**
     * Sorts an array from the smallest to the largest element.
     *
     * @param a Array with values
     */
    template<typename T, size_t SIZE>
    void selectionSort(std::array<T, SIZE> &a) {
        for (size_t i = 0; i < SIZE - 1; i++) {
            std::swap(a[i], a[opl::minimum(a, i)]);
        }
    }

    /**
     * Sorts an array from the smallest to the largest element. Uses an optimized minimum search.
     *
     * @param  a Array with values
     */
    template<typename T, size_t SIZE>
    void selectionSortOptimized(std::array<T, SIZE> &a) {
        for (size_t i = 0; i < SIZE - 1; i++) {
            std::swap(a[i], a[opl::minimumOptimized(a, i)]);
        }
    }

    /**
     * Sorts an array from the smallest to the largest element. Uses minimum search with prefetch.
     *
     * @param  a Array with values
     */
    template<typename T, size_t SIZE>
    void selectionSortWithPrefetch(std::array<T, SIZE> &a) {
        for (size_t i = 0; i < SIZE - 1; i++) {
            std::swap(a[i], a[opl::minimumWithPrefetch(a, i)]);
        }
    }
}


#endif //OPL_SELECTIONSORT_H
