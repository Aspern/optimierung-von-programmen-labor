#ifndef OPL_RUNTIMECONSTANTS_H
#define OPL_RUNTIMECONSTANTS_H

#include <array>

/**
 *  Größe der Cache-Line der aktuellen Laufzeitumgebung
 * (siehe http://www.cpu-world.com/CPUs/Core_i7/Intel-Core%20i7%20Mobile%20i7-2670QM.html)
 */
const size_t CACHE_LINE_SIZE = 64;

/**
 * Deckt die größe des Cache der aktuellen Laufzeitumgebung ab.
 */
const int CACHE_SIZE = 2621440; //~20MB

#endif //OPL_RUNTIMECONSTANTS_H
