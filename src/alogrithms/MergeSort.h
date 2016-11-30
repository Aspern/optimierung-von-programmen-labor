#ifndef OPL_MERGESPRT_H
#define OPL_MERGESPRT_H

#include <array>

template<typename T, size_t SIZE>
void merge(std::array<T, SIZE> &a, std::array<T, SIZE> &aux, int lo, int mid, int hi) {
    for (int k = lo; k <= hi; k++) {
        aux[k] = a[k];
    }

    int i = lo;
    int j = mid + 1;
    for (int k = lo; k <= hi; k++) {
        if (i > mid) {
            a[k] = aux[j++];
        } else if (j > hi) {
            a[k] = aux[j++];
        } else if (aux[j] < aux[i]) {
            a[k] = aux[j++];
        } else {
            a[k] = aux[i++];
        }
    }
}

template<typename T, size_t SIZE>
void bottomUpMergeSort(std::array<T, SIZE> &a) {
    std::array<T, SIZE> *aux = new std::array<T, SIZE>();

    for (int len = 1; len < SIZE; len *= 2) {
        for (int lo = 0; lo < SIZE - len; lo += len + len) {
            int mid = lo + len - 1;
            int hi = std::min(lo + len + len - 1, SIZE - 1);
            merge(a, *aux, lo, mid, hi);
        }
    }
}


#endif //OPL_MERGESPRT_H
