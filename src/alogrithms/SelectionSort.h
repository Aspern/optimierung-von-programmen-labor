#ifndef OPL_SELECTIONSORT_H
#define OPL_SELECTIONSORT_H

#include <array>
#include "MinimumSearch.h"

/**
 * Für den Algorithmus 'Sortieren mit Direkter Auswahl' mit der
 * normalen Minimumsuche aus.
 *
 * @param a Array mit Werten
 */
template<typename T, size_t SIZE>
void selectionSort_v1(std::array<T, SIZE> &a) {
    for(size_t i = 0; i < SIZE - 1; i++) {
        std::swap(a[i], a[minimumSearch_v1(a, i)]);
    }
}

/**
 * Für den Algorithmus 'Sortieren mit Direkter Auswahl' mit der ersten
 * Variante der Minimumsuche aus (Laden der nächsten Cacheline).
 *
 * @param a Array mit Werten
 */
template<typename T, size_t SIZE>
void selectionSort_v2(std::array<T, SIZE> &a) {
    for(size_t i = 0; i < SIZE - 1; i++) {
        std::swap(a[i], a[minimumSearch_v2(a, i)]);
    }
}

/**
 * Für den Algorithmus 'Sortieren mit Direkter Auswahl' mit der zweiten
 * Variante der Minimumsuche aus (__buildin_prefetch).
 *
 * @param a Array mit Werten
 */
template<typename T, size_t SIZE>
void selectionSort_v3(std::array<T, SIZE> &a) {
    for(size_t i = 0; i < SIZE - 1; i++) {
        std::swap(a[i], a[minimumSearch_v3(a, i)]);
    }
}

#endif //OPL_SELECTIONSORT_H
