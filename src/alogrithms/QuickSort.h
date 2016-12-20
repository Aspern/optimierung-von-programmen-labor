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

    //richtiges 3-way partiioning
    //schlimmster fall ohne division multiplikation erkennen
    // --> dann abbrich und mittig teilen: 1 merge schritt

    /* recursion */
    if (startIndex < j)
        quickSort(arr, startIndex, j);
    if (i < endIndex)
        quickSort(arr, i, endIndex);
}


template<typename T, size_t SIZE>
void quicksortThreeWay(std::array<T, SIZE> &a, int l, int r) {
    int i = l - 1;
    int j = r;
    int p = l - 1;
    int q = r;

    // Verwende mittleres Element als Pivot-Element.
    std::swap(a[(l + r) / 2], a[r]);

    T v = a[r];
    if (r <= l) return;

    for (;;) {
        while (a[++i] < v);

        while (v < a[--j])
            if (j == l) break;

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
    std::swap(a[i], a[r]);
    j = i - 1;
    i = i + 1;

    for (int k = l; k < p; k++, j--)
        std::swap(a[k], a[j]);
    for (int k = r - 1; k > q; k--, i++)
        std::swap(a[i], a[k]);

    quicksortThreeWay(a, l, j);
    quicksortThreeWay(a, i, r);
}

template<typename T, size_t SIZE>
void quickSort(std::array<T, SIZE> &arr) {
    quicksortThreeWay(arr, 0, SIZE - 1);
}

#endif //OPL_QUICKSORT_H
