#ifndef OPL_QUICKSORT_H
#define OPL_QUICKSORT_H

#include <array>

template<typename T, size_t SIZE>
void quickSort(std::array<T, SIZE> &arr, int startIndex, int endIndex) {
    int i = startIndex, j = endIndex;
    int pivot = arr[(startIndex + endIndex) / 2];

    /* partition */
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;                               
        }
    };

    /* recursion */
    if (startIndex < j)
        quickSort(arr, startIndex, j);
    if (i < endIndex)
        quickSort(arr, i, endIndex);
}

template<typename T, size_t SIZE>
void quickSort(std::array<T, SIZE> &arr) {
    quickSort(arr, 0, SIZE - 1);
}


#endif //OPL_QUICKSORT_H
