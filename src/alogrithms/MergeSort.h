#ifndef OPL_MERGESPRT_H
#define OPL_MERGESPRT_H

#include <array>

template<typename T, size_t SIZE>
void merge(std::array<T, SIZE> &a, std::array<T, SIZE> &aux, size_t lo, size_t mid, size_t hi) {
    for (size_t k = lo; k <= hi; k++) {
        aux[k] = a[k];
    }

    size_t i = lo;
    size_t j = mid + 1;
    for (size_t k = lo; k <= hi; k++) {
        if (i > mid) {
            a[k] = aux[j++];
        } else if (j > hi) {
            a[k] = aux[i++];
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

    for (size_t len = 1; len < SIZE; len *= 2) {
        for (size_t lo = 0; lo < SIZE - len; lo += len + len) {
            size_t mid = lo + len - 1;
            size_t hi = std::min(lo + len + len - 1, SIZE - 1);
            merge(a, *aux, lo, mid, hi);
        }
    }

    delete aux;
}


#endif //OPL_MERGESPRT_H
