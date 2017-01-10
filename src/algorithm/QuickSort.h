#ifndef OPL_QUICKSORT_H
#define OPL_QUICKSORT_H

#include <array>
#include "./InsertionSort.h"
#include "./MergeSort.h"
#include "../runtime/Constants.h"

namespace opl {

    /**
     * Sorts an array from ´left´ - ´right´ from the smallest to the largest element.
     * Uses three-way-partitioning.
     *
     * @param a Array with values
     * @param left Left border
     * @param right Right border
     */
    template<typename T, size_t SIZE>
    void quickSort(std::array<T, SIZE> &a, int left, int right) {
        int i = left - 1;
        int j = right;
        int p = left - 1;
        int q = right;

        // Using the element in the middle as pivot.
        std::swap(a[(left + right) / 2], a[right]);

        T v = a[right];
        if (right <= left) return;

        for (;;) {
            while (a[++i] < v);

            while (v < a[--j])
                if (j == left) break;

            if (i >= j)
                break;

            std::swap(a[i], a[j]);

            if (a[i] == v) {
                p++;
                std::swap(a[p], a[i]);
            }
            if (v == a[j]) {
                q--;
                std::swap(a[j], a[q]);
            }
        }
        std::swap(a[i], a[right]);
        j = i - 1;
        i = i + 1;

        for (int k = left; k < p; k++, j--)
            std::swap(a[k], a[j]);
        for (int k = right - 1; k > q; k--, i++)
            std::swap(a[i], a[k]);

        quickSort(a, left, j);
        quickSort(a, i, right);
    }

    /**
     * Sorts an array from the smallest to the largest element..
     *
     * @param a Array with values
     */
    template<typename T, size_t SIZE>
    void quickSort(std::array<T, SIZE> &a) {
        quickSort(a, 0, SIZE - 1);
    }

    /**
     * Sorts an array from the smallest to the largest element. Uses a hybrid implementation that switches to
     * insertion sort if quick-sort becomes inefficient.
     *
     * @param a Array with values
     * @param aux Cache for sub-arrays
     * @param left Left border
     * @param right Right border
     */
    template<typename T, size_t SIZE>
    void quickSortHybrid(std::array<T, SIZE> &a, std::array<T, SIZE> &aux, int left, int right) {

        if (right - left < opl::constant::quick_sort_cutt_off) {
            opl::insertionSort(a, left, right + 1);
        } else {

            int i = left - 1;
            int j = right;
            int p = left - 1;
            int q = right;

            // Using the element in the middle as pivot.
            std::swap(a[(left + right) / 2], a[right]);

            T v = a[right];
            if (right <= left) return;

            for (;;) {
                while (a[++i] < v);

                while (v < a[--j])
                    if (j == left) break;

                if (i >= j)
                    break;

                std::swap(a[i], a[j]);

                if (a[i] == v) {
                    p++;
                    std::swap(a[p], a[i]);
                }
                if (v == a[j]) {
                    q--;
                    std::swap(a[j], a[q]);
                }
            }
            std::swap(a[i], a[right]);
            j = i - 1;
            i = i + 1;

            for (int k = left; k < p; k++, j--)
                std::swap(a[k], a[j]);
            for (int k = right - 1; k > q; k--, i++)
                std::swap(a[i], a[k]);

            // Proof if one half is ´opl::constant::quick_sort_cutt_off´-x larger the the other.
            if (j - left < opl::constant::quick_sort_cutt_off * (right - i)
                || right - i < (j - left) * opl::constant::quick_sort_cutt_off) {
                int mid = (left + right) / 2;
                quickSortHybrid(a, aux, left, mid);
                quickSortHybrid(a, aux, mid + 1, right);
                bionicMerge(a, aux, left, mid, right);
            } else {
                quickSortHybrid(a, aux, left, j);
                quickSortHybrid(a, aux, i, right);
            }
        }
    }

    /**
     * Sorts an array from the smallest to the largest element. Uses a hybrid implementation that switches to
     * insertion sort if quick-sort becomes inefficient.
     *
     * @param a Array with values
     */
    template<typename T, size_t SIZE>
    void quickSortHybrid(std::array<T, SIZE> &a) {
        std::array<T, SIZE> *aux = new std::array<T, SIZE>();
        quickSortHybrid(a, *aux, 0, SIZE - 1);
        delete aux;
    }

}

#endif //OPL_QUICKSORT_H
