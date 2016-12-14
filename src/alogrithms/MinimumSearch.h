#ifndef OPL_MINIMUMSEARCH_H
#define OPL_MINIMUMSEARCH_H

#include "../measurement/RuntimeConstants.h"

/**
 * Normale Minimumsuche.
 *
 * @param a Array mit Werten
 * @param from Startindex bei der Iteration
 * @return Index, an welchem sich das Minimum befindet.
 */
template<typename T, size_t SIZE>
size_t minimumSearch_v1(const std::array<T, SIZE> &a, size_t from)  {
    size_t min = from;

    for(size_t i = from; i < SIZE; i++) {
        if(a[min] > a[i]) {
            min = i;
        }
    }

    return min;
}

/**
 * Normale Minimumsuche.
 *
 * @param a Array mit Werden
 * @return Minimum
 */
template<typename T, size_t SIZE>
T minimumSearch_v1(const std::array<T, SIZE> &a) {
    return a[minimumSearch_v1(a, 0)];
}


/**
 * Minimumsuche mit Zugriff auf Element in der nächsten Cache-Line.
 *
 * @param a Array mit Werten
 * @param from Startindex bei der Iteration
 * @return Index, an welchem sich das Minimum befindet.
 */
template<typename T, size_t SIZE>
size_t minimumSearch_v2(const std::array<T, SIZE> &a, size_t from) {
    const size_t range = (CACHE_LINE_SIZE / sizeof(T));
    size_t min = from;

    for (size_t i = from; i < SIZE; i += range) {
        for (size_t j = i; j < i + range && j < SIZE; j++) {
            if (a[min] > a[j]) {
                min = j;
            }
        }
    }
    return min;
}

/**
 * Minimumsuche mit Zugriff auf Element in der nächsten Cache-Line.
 *
 * @param a Array mit Werten
 * @return Minimum
 */
template<typename T, size_t SIZE>
T minimumSearch_v2(const std::array<T, SIZE> &a) {
    return a[minimumSearch_v1(a, 0)];
}

/**
 * Minimumsuche mit Compiler Prefetch Funktion.
 *
 * @param a Array mit Werten
 * @param from Startindex bei der Iteration
 * @return Index, an welchem sich das Minimum befindet.
 */
template<typename T, size_t SIZE>
size_t minimumSearch_v3(const std::array<T, SIZE> &a, size_t from) {

    // Anzahl Elemente des Datentyps T, die in eine Cache-Line passen.
    const size_t range = (CACHE_LINE_SIZE / sizeof(T));
    size_t min = from;

    for (size_t i = from; i < SIZE; i += range) {
        __builtin_prefetch(&a[i + range]);
        for (size_t j = i; j < i + range && j < SIZE; j++) {
            if (a[min] > a[j]) {
                min = j;
            }
        }
    }
    return min;
}

/**
 * Minimumsuche mit Compiler Prefetch Funktion.
 *
 * @param a Array mit Werten
 * @return Minimum
 */
template<typename T, size_t SIZE>
T minimumSearch_v3(const std::array<T, SIZE> &a) {
    return a[minimumSearch_v3(a, 0)];
}


#endif //OPL_MINIMUMSEARCH_H
