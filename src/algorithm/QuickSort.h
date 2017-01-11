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
     * @param lo Left border
     * @param hi Right border
     */
    template<typename T, size_t SIZE>
    void quickSort(std::array<T, SIZE> &a, size_t lo, size_t hi) {
        size_t i = lo - 1;
        size_t j = hi;
        // prevent overflow with unsigned integer.
        size_t p = lo;
        size_t q = hi;

        // Using the element in the middle as pivot.
        std::swap(a[(lo + hi) / 2], a[hi]);

        T v = a[hi];

        if (hi <= lo) return;

        for (;;) {
            while (a[++i] < v);

            while (v < a[--j])
                if (j == lo) break;

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
        std::swap(a[i], a[hi]);

        // prevent overflow with unsigned integer.
        i == 0 ? j = 0 : j = i - 1;
        i = i + 1;


        size_t k = lo;


        while (k < p) {
            std::swap(a[k], a[j]);
            k++;

            if (j > 0)
                j--;
        }
        k = hi - 1;
        while (k > q) {
            std::swap(a[i], a[k]);
            i++;
            if (k > 0)
                k--;
        }


        quickSort(a, lo, j);
        quickSort(a, i, hi);
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
     * @param lo Left border
     * @param hi Right border
     */
    template<typename T, size_t SIZE>
    void quickSortHybrid(std::array<T, SIZE> &a, std::array<T, SIZE> &aux, size_t lo, size_t hi) {
        size_t i = lo - 1;
        size_t j = hi;
        // prevent overflow with unsigned integer.
        size_t p = lo;
        size_t q = hi;

        // Using the element in the middle as pivot.
        std::swap(a[(lo + hi) / 2], a[hi]);

        T v = a[hi];
        if (hi <= lo) return;

        for (;;) {
            while (a[++i] < v);

            while (v < a[--j])
                if (j == lo) break;

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
        std::swap(a[i], a[hi]);

        // prevent overflow with unsigned integer.
        i == 0 ? j = 0 : j = i - 1;
        i = i + 1;

        size_t k = lo;
        while (k < p) {
            std::swap(a[k], a[j]);
            k++;
            // prevent overflow with unsigned integer.
            if (j > 0) j--;
        }
        k = hi - 1;
        while (k > q) {
            std::swap(a[i], a[k]);
            i++;
            // prevent overflow with unsigned integer.
            if (k > 0) k--;
        }

        // Proof if one half is ´opl::constant::quick_sort_cutt_off´-x larger the the other.
        if (((j - lo) < (opl::constant::quick_sort_cutt_off * (hi - i))) ||
            (((j - lo) * opl::constant::quick_sort_cutt_off < (hi - i)))) {
            int mid = (lo + hi) / 2;
            opl::insertionSort(a, lo, mid + 1);
            opl::insertionSort(a, mid + 1, hi + 1);
            bionicMerge(a, aux, lo, mid, hi);
        } else {
            quickSortHybrid(a, aux, lo, j);
            quickSortHybrid(a, aux, i, hi);
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
