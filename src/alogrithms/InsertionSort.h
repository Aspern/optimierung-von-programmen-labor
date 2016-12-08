#ifndef OPL_INSERTIONSORT_H
#define OPL_INSERTIONSORT_H

#include <array>

template<typename T, size_t SIZE>
void insertionSort_v1(std::array<T, SIZE> &a) {
    for (size_t i = 1; i < SIZE; i++) {
        T value = a[i];
//        size_t j = i;
        for(size_t j = i; j > 0 && a[j - 1] > value; j--) {
            std::swap(a[j], a[j - 1]);
        }
/*        while (j > 0 && a[j - 1] > value) {
            a[j] = a[j - 1];
            j--;
            a[j] = value;
        }*/

    }
}

template<typename T, size_t SIZE>
void insertionSort_v2(std::array<T, SIZE> &a) {

}

#endif //OPL_INSERTIONSORT_H
