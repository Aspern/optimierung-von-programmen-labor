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
     * @param left left border
     * @param middle middle of sub-arrays
     * @param right right border
     */
    template<typename T, size_t SIZE>
    void bionicMerge(std::array<T, SIZE> &a, std::array<T, SIZE> &aux, size_t left, size_t middle, size_t right) {
        size_t i = left,
                j = right,
                k = left;

        // Copy the front half ascending.
        while (i <= middle)
            aux[k++] = a[i++];

        // Copy the back half descending.
        while (j > middle)
            aux[k++] = a[j--];

        i = left;
        j = right;
        k = left;

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

        for (size_t length = 1; length < SIZE; length *= 2)
            for (size_t left = 0; left < SIZE - length; left += length + length) {
                size_t middle = left + length - 1;
                size_t right = std::min(left + length + length - 1, SIZE - 1);
                bionicMerge(a, *aux, left, middle, right);
            }

        delete aux;
    }

}


#endif //OPL_MERGESORT_H
