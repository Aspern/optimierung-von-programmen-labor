#ifndef OPL_CHRONOMETRY_H
#define OPL_CHRONOMETRY_H

#include <chrono>

#include "./ArrayTools.h"
#include "../runtime/Constants.h"
#include "../algorithm/SelectionSort.h"
#include "../algorithm/InsertionSort.h"
#include "../algorithm/MergeSort.h"
#include "../algorithm/QuickSort.h"


namespace opl {

    template<size_t SIZE, size_t N>
    struct TestCases {
        static constexpr std::array<void (*)(std::array<double, SIZE> &), 3> data = {
                opl::fillArrayAsc,
                opl::fillArrayDesc,
                opl::fillArrayRandom
        };

        static void execute(void(*algorithm)(std::array<double, SIZE> &), std::array<double, SIZE> &a) {
            data[N](a);
            opl::clearCache();
            auto start = std::chrono::high_resolution_clock::now();
            algorithm(a);
            auto end = std::chrono::high_resolution_clock::now();
            std::cout << " & " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
            TestCases<SIZE, N + 1>::execute(algorithm, a);
        }
    };

    template<size_t SIZE>
    struct TestCases<SIZE, 3> {
        static void
        execute(void(*algorithm)(std::array<double, SIZE> &), std::array<double, SIZE> &a) {}
    };

    template<size_t SIZE, size_t N>
    struct Algorithms {
        static constexpr std::array<void (*)(std::array<double, SIZE> &), 2> data = {
//                opl::minimumTest,
//                opl::minimumOptimizedTest,
//                opl::minimumWithPrefetchTest,
//                opl::selectionSort,
//                opl::selectionSortOptimized,
//                opl::selectionSortWithPrefetch,
                opl::insertionSort,
                opl::insertionSortWithPrefetch,
//                opl::bottomUpMergeSort,
//                opl::quickSort,
//                opl::quickSortHybrid
        };

        static void execute(std::array<double, SIZE> &a) {
            std::cout << std::endl;
            std::cout << SIZE;
            TestCases<SIZE, 0>::execute(data[N], a);
            std::cout << "\\\\" <<  std::endl << "\\hline" << std::endl;
            Algorithms<SIZE, N + 1>::execute(a);
        }
    };

    template<size_t SIZE>
    struct Algorithms<SIZE, 2> {
        static void execute(std::array<double, SIZE> &a) {}
    };


    template<size_t SIZE>
    struct Chronometry {
        static void execute() {
            std::array<double, SIZE> *a = new std::array<double, SIZE>();
            std::cout << "============================={" << SIZE << "}=============================" <<  std::endl;
            Algorithms<SIZE, 0>::execute(*a);
            std::cout << "============================={END}=============================" <<  std::endl << std::endl;
            Chronometry<SIZE * 2>::execute();
            delete a;
        }
    };

    template<>
    struct Chronometry<opl::constant::max_array_size> {
        static void execute() {}
    };

}


#endif //OPL_CHRONOMETRY_H
