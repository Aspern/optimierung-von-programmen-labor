#ifndef OPL_RUNTIMECONSTANTS_H
#define OPL_RUNTIMECONSTANTS_H

#include <array>

namespace opl {

    namespace constant {

        /**
         * Cache-line size of the current runtime (intel i7)
         *
         * @see http://www.cpu-world.com/CPUs/Core_i7/Intel-Core%20i7%20Mobile%20i7-2670QM.html
         */
        const size_t cache_line_size = 64;

        /**
         * Maximum possible cache size in bytes for the current runtime (~20MB)
         */
        const int max_cache_size = 2621440;

        /**
         * If this number of elements is reached in a sub-array of a quick sort execution,
         * the algorithm becomes inefficient.
         */
        const int quick_sort_cutt_off = 9;

        /**
         * The minimum size of elements that has effect on the runtime environment.
         */
        const size_t min_array_size = 65536;

        /**
         * The size of elements that are no more executable on the runtime environment.
         */
        const size_t max_array_size = 524288;

    }
}
#endif //OPL_RUNTIMECONSTANTS_H
