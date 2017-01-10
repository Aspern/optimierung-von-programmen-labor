#ifndef OPL_MINIMUMSEARCH_H
#define OPL_MINIMUMSEARCH_H

#include "../measurement/RuntimeConstants.h"

namespace opl {

    /**
     * Returns the position of the minimum in an array starting on a defined start position.
     *
     * @param a Array with values
     * @param start Position to start the minimum search
     * @return Position of the minimum
     */
    template<typename T, size_t SIZE>
    size_t minimum(const std::array<T, SIZE> &a, size_t start) {
        size_t min = start;

        for (size_t i = start; i < SIZE; i++) {
            if (a[min] > a[i]) {
                min = i;
            }
        }

        return min;
    }

    /**
     * Returns the minimum of an array.
     *
     * @param a Array with values
     * @return Minimum of the Array
     */
    template<typename T, size_t SIZE>
    T minimum(const std::array<T, SIZE> &a) {
        return a[minimum(a, 0)];
    }


    /**
     * Returns the position of the minimum in an array starting on a defined start position. The algorithm uses
     * loop unrolling to optimze the performance.
     *
     * @param a Array with values
     * @param start Position to start the minimum search
     * @return Position of the minimum
     */
    template<typename T, size_t SIZE>
    size_t minimumOptimized(const std::array<T, SIZE> &a, size_t start) {
        const size_t range = (CACHE_LINE_SIZE / sizeof(T));
        size_t min = start;

        for (size_t i = start; i < SIZE; i += range) {
            for (size_t j = i; j < i + range && j < SIZE; j++) {
                if (a[min] > a[j]) {
                    min = j;
                }
            }
        }
        return min;
    }

    /**
     * Returns the minimum of an array. The algorithm uses loop unrolling to optimze the performance.
     *
     * @param a Array with values
     * @return Minimum of the Array
     */
    template<typename T, size_t SIZE>
    T minimumOptimized(const std::array<T, SIZE> &a) {
        return a[minimumOptimized(a, 0)];
    }

    /**
     * Returns the position of the minimum in an array starting on a defined start position. The algorithm uses
     * ´__builtin_prefetch´ to optimze the performance.
     *
     * @param a Array mit Werten
     * @param from Startindex bei der Iteration
     * @return Index, an welchem sich das Minimum befindet.
     */
    template<typename T, size_t SIZE>
    size_t minimumWithPrefetch(const std::array<T, SIZE> &a, size_t from) {
        const size_t range = (CACHE_LINE_SIZE / sizeof(T));
        size_t min = from;

        for (size_t i = from; i < SIZE; i += range) {
            __builtin_prefetch(&a[i + range]);
            for (size_t j = i; j < i + range && j < SIZE; j++) {
                if (a[min] > a[j]) {
                    min = j;
                }
            }
        }
        return min;
    }

    /**
     * Returns the minimum of an array starting on a defined start position. The algorithm uses ´__builtin_prefetch´
     * to optimze the performance.
     *
     * @param a Array with values
     * @return Minimum of the Array
     */
    template<typename T, size_t SIZE>
    T minimumWithPrefetch(const std::array<T, SIZE> &a) {
        return a[minimumWithPrefetch(a, 0)];
    }
}

#endif //OPL_MINIMUMSEARCH_H
