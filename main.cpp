
#include "src/measurement/ArrayUtilities.h"
#include "src/alogrithms/MinimumSearch.h"
#include "src/alogrithms/SelectionSort.h"
#include "src/alogrithms/MergeSort.h"
#include "src/alogrithms/QuickSort.h"
#include "src/measurement/Chronometry.h"
#include <chrono>
#include <sstream>

using namespace std;
using namespace chrono;

void add_duration_to_stream(stringstream &stream, double duration, int iteration) {
    stream << duration;
    iteration < 2 ? stream << " & " : stream << "\\\\\n\\hline";
}

template<typename T, size_t SIZE>
void measureMinimumSearchAlgorithm(array<T, SIZE> &a, T(*f)(const array<T, SIZE> &a), stringstream &stream) {
    T min;
    stream << SIZE << " & ";
    for (int i = 0; i < 3; i++) {
        fillArrayAndClearCache(i, a);
        high_resolution_clock::time_point t1 = high_resolution_clock::now();
        min = f(a);
        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        long d = duration_cast<microseconds>(t2 - t1).count();
        add_duration_to_stream(stream, d, i);
    }

    stream << endl << endl;
    stream << min << endl << endl;
}

template<typename T, size_t SIZE>
void measureSortAlgorithm(array<T, SIZE> &a, void(*f)(array<T, SIZE> &a), stringstream &stream) {
    stream << SIZE << " & ";
    for (int i = 0; i < 3; i++) {
        fillArrayAndClearCache(i, a);
        high_resolution_clock::time_point t1 = high_resolution_clock::now();
        f(a);
        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        long d = duration_cast<milliseconds>(t2 - t1).count();
        add_duration_to_stream(stream, d, i);
    }
    stream << endl << endl;
}

template<typename T, size_t N>
void measureRuntime(stringstream &stream) {
    array<T, N> *a = new array<double, N>();
    measureMinimumSearchAlgorithm(*a, minimumSearch_v1, stream);
    measureMinimumSearchAlgorithm(*a, minimumSearch_v2, stream);
    measureMinimumSearchAlgorithm(*a, minimumSearch_v3, stream);
    measureSortAlgorithm(*a, selectionSort_v1, stream);
    measureSortAlgorithm(*a, selectionSort_v2, stream);
    measureSortAlgorithm(*a, selectionSort_v3, stream);
    delete a;
}



int main() {
 /*   stringstream stream;

*//*    measureRuntime<double, 16384>(stream);
    measureRuntime<double, 32768>(stream);*//*
//    measureRuntime<double, 65536>(stream);
//    measureRuntime<double, 131072>(stream);
//    measureRuntime<double, 262144>(stream);
//    measureRuntime<double, 524288>(stream);
//    measureRuntime<double, 1048576>(stream);

//    measureRuntime<double, 2097152>(stream);
//    measureRuntime<double, 4194304>(stream);
//    measureRuntime<double, 8388608>(stream);
//    measureRuntime<double, 16777216>(stream);
//    measureRuntime<double, 33554432>(stream);
//    measureRuntime<double, 67108864>(stream);
//    measureRuntime<double, 134217728>(stream);
//    measureRuntime<double, 268435456>(stream);
//    measureRuntime<double, 536870912>(stream);
//
//    cout << stream.str();


    array<int, 9> a = {6,2, 4, 1, 5, 3, 8, 7,0};



    bottomUpMergeSort(a);

    for(size_t i = 0; i < 8; i++) {
        std::cout << a[i] << std::endl;
    }

    return 0;*/

    //std::cout << std::endl << is_prime<6>::value << std::endl;

    std::array<int, 32> a = {1, 99, 5, -4, 8, 7, 6, 1, 0, 47, 635, 21, -6, 4, 98, 76, 1, 99, 5, -4, 8, 7, 6, 1, 0, 47, 635, 21, -6, 4, 98, 76};

    quickSort(a);

    for(size_t i = 0; i < 32; i++) {
        std::cout << std::endl << a[i] << std::endl;
    }

    return 0;
}


