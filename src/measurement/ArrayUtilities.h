#ifndef OPL_ARRAYUTILITIES_H
#define OPL_ARRAYUTILITIES_H

#include <random>
#include <iostream>
#include "RuntimeConstants.h"

const int ARRAY_ASC = 0;
const int ARRAY_DESC = 1;
const int ARRAY_RAND = 2;

/**
 * Befüllt ein Array fester Größe mit aufsteigenden Werten.
 *
 * @param a Array mit fester Größe
 */
template<typename T, size_t SIZE>
void fillArrayAsc(std::array<T, SIZE> &a) {
    for (size_t i = 0; i < SIZE; i++) {
        a[i] = (T) i;
    }
}

/**
 * Befüllt ein Array fester Größe mit absteigenden Werten.
 *
 * @param a Array mit fester Größe
 */
template<typename T, size_t SIZE>
void fillArrayDesc(std::array<T, SIZE> &a) {
    for (size_t i = SIZE; i > 0; i--) {
        a[i - 1] = (T) i;
    }
}

/**
 * Befüllt ein Array fester Größe mit zufälligen Werten.
 *
 * @param a Array mit fester Größe
 */
template<typename T, size_t SIZE>
void fillArrayRandom(std::array<T, SIZE> &a) {
    std::mt19937 generator;
    generator.seed(std::random_device{}());

    for (size_t i = 0; i < SIZE; i++) {
        a[i] = (T) generator();
    }
}


/**
 * Leert den Cache des Computers.
 */
/*void clear_cache_20mb(){
    std::array<long, CACHE_SIZE> *a = new std::array<long, CACHE_SIZE>();

    for (int i = 0; i < CACHE_SIZE; i++) {
        a->at(i) = 1L;
    }
    delete a;
}*/

/**
 * Füllt ein Array anhand eines Modus:
 *   ARRAY_ASC -> Aufsteigend sortiert befüllt
 *   ARRAY_DESC -> Absteigend sortiert befüllt
 *   ARRAY_RAND -> Mit zufallszahlen befüllt
 *
 * @param mode Definierter Füllmpdus
 * @param a Array mit fester Größe
 */
template<typename T, size_t SIZE>
void fillArrayAndClearCache(int mode, std::array<T, SIZE> &a) {

    if (mode == ARRAY_ASC) {
        fillArrayAsc(a);
    } else if (mode == ARRAY_DESC) {
        fillArrayDesc(a);
    } else if (mode == ARRAY_RAND) {
        fillArrayRandom(a);
    }

    //clear_cache_20mb();
}


#endif //OPL_ARRAYUTILITIES_H
