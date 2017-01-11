#ifndef OPL_MINIMUMSEARCH_H
#define OPL_MINIMUMSEARCH_H

#include "../runtime/Constants.h"

namespace opl {

    /**
     * Returns the position of the minimum in an array starting on a ´left´ border.
     *
     * @param a Array with values
     * @param lo Left Border
     * @return Position of the minimum
     */
    template<typename T, size_t SIZE>
    size_t minimum(const std::array<T, SIZE> &a, size_t lo) {
        size_t min = lo;

        for (size_t i = lo; i < SIZE; i++) {
            if (a[min] > a[i])
                min = i;
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
     * Returns the position of the minimum in an array starting on a ´left´ border. The algorithm uses
     * loop unrolling to optimize the performance.
     *
     * @param a Array with values
     * @param lo Left Border
     * @return Position of the minimum
     */
    template<typename T, size_t SIZE>
    size_t minimumOptimized(const std::array<T, SIZE> &a, size_t lo) {
        const size_t nElementsInCacheLine = (opl::constant::cache_line_size / sizeof(T));
        size_t min = lo;

        for (size_t i = lo; i < SIZE; i += nElementsInCacheLine)
            for (size_t j = i; j < i + nElementsInCacheLine && j < SIZE; j++)
                if (a[min] > a[j])
                    min = j;

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
     * Returns the position of the minimum in an array starting on a ´left´ border. The algorithm uses
     * ´__builtin_prefetch´ to optimze the performance.
     *
     * @param a Array mit Werten
     * @param lo Left Border
     * @return Index, an welchem sich das Minimum befindet.
     */
    template<typename T, size_t SIZE>
    size_t minimumWithPrefetch(const std::array<T, SIZE> &a, size_t lo) {
        const size_t nElementsInCacheLine = (opl::constant::cache_line_size / sizeof(T));
        size_t min = lo;

        for (size_t i = lo; i < SIZE; i += nElementsInCacheLine) {
            __builtin_prefetch(&a[i + nElementsInCacheLine]);
            for (size_t j = i; j < i + nElementsInCacheLine && j < SIZE; j++)
                if (a[min] > a[j])
                    min = j;
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
