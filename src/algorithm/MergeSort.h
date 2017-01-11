#ifndef OPL_MERGESORT_H
#define OPL_MERGESORT_H

#include <array>

namespace opl {

    /**
     * Merges the sub-array from ´left´ - ´midlle´ with the sub-array from ´middle´ + 1 - ´right´.
     * Merges the sub-arrays with the bionic implmentation.
     *
     * @param a Array with values
     * @param aux Cache array
     * @param lo left border
     * @param mid middle of sub-arrays
     * @param hi right border
     */
    template<typename T, size_t SIZE>
    void bionicMerge(std::array<T, SIZE> &a, std::array<T, SIZE> &aux, size_t lo, size_t mid, size_t hi) {
        size_t i = lo,
                j = hi,
                k = lo;

        // Copy the front half ascending.
        while (i <= mid)
            aux[k++] = a[i++];

        // Copy the back half descending.
        while (j > mid)
            aux[k++] = a[j--];

        i = lo;
        j = hi;
        k = lo;

        while (i <= j) {
            if (aux[i] <= aux[j])
                a[k++] = aux[i++];
            else
                a[k++] = aux[j--];
        }
    }


    /**
     *  Sorts an array from the smallest to the largest element.
     *  Uses bottom up merge sort with an bionic implementation
     *
     * @param a Array with values
     */
    template<typename T, size_t SIZE>
    void bottomUpMergeSort(std::array<T, SIZE> &a) {
        std::array<T, SIZE> *aux = new std::array<T, SIZE>();

        for (size_t len = 1; len < SIZE; len *= 2)
            for (size_t lo = 0; lo < SIZE - len; lo += len + len) {
                size_t mid = lo + len - 1;
                size_t hi = std::min(lo + len + len - 1, SIZE - 1);
                bionicMerge(a, *aux, lo, mid, hi);
            }

        delete aux;
    }

}


#endif //OPL_MERGESORT_H
