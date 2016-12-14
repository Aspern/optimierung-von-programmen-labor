#ifndef OPL_MERGESORT_H
#define OPL_MERGESORT_H

#include <array>

template<typename T, size_t SIZE>
void print_arr(std::array<T, SIZE> &a) {
    for (size_t i = 0; i < SIZE; i++) {
        std::cout << "a[" << i << "] = " << a[i] << std::endl;
    }
    std::cout << std::endl;
}

/**
 * Bitonische Variante der Funktion merge, dabei wird die vordere Hälfte der Folge in ihrer normalen Reihenfolge,
 * die hintere Hälfte jedoch in umgekehrter Reihenfolge in das Zwischen-Array kopiert. Somit entfallen zwei
 * Sonderfälle.
 *
 * @param a Array mit Werten
 * @param aux Zwischen-Array
 * @param lo Untere Grenze
 * @param mid Mittlere Grenze
 * @param hi Obere Grenze
 */
template<typename T, size_t SIZE>
void bionicMerge(std::array<T, SIZE> &a, std::array<T, SIZE> &aux, size_t lo, size_t mid, size_t hi) {
    size_t i = lo, j = hi, k = lo;

    // Vordere Hälfte aufsteigend kopieren.
    while (i <= mid)
        aux[k++] = a[i++];

    // Hintere Hälfte absteigend kopieren.
    while (j > mid)
        aux[k++] = a[j--];

    i = lo;
    j = hi;
    k = lo;

    // Jeweils nächste Element zurückkopieren, bis i und j sich überkreuzen.
    while (i <= j) {
        if (aux[i] <= aux[j])
            a[k++] = aux[i++];
        else
            a[k++] = aux[j--];
    }
}

/**
 * Merge Sort Variante ohne Rekursion.
 *
 * @param a Array mit Werten
 */
template<typename T, size_t SIZE>
void bottomUpMergeSort(std::array<T, SIZE> &a) {
    std::array<T, SIZE> *aux = new std::array<T, SIZE>();

    for (size_t len = 1; len < SIZE; len *= 2) {
        for (size_t lo = 0; lo < SIZE - len; lo += len + len) {
            size_t mid = lo + len - 1;
            size_t hi = std::min(lo + len + len - 1, SIZE - 1);
            bionicMerge(a, *aux, lo, mid, hi);
        }
    }

    delete aux;
}


#endif //OPL_MERGESORT_H
