//
// Created by Adrian.Weber on 10.01.2017.
//

#ifndef OPL_RESULT_H
#define OPL_RESULT_H

#include <iostream>
#include <fstream>
#include <w32api/rpc.h>
#include <map>

class Result {
private:
    std::ofstream file;
    std::map<size_t, std::string> names = {
            {0, "SelectionSort"},
            {1, "SelectionSort[Optimized]"},
            {2, "SelectionSort[Prefetch]"},
            {3, "InsertionSort"},
            {4, "InsertionSort[Prefetch]"},
            {5, "MergeSort[Bottom-up]"},
            {6, "QuickSort[Three-Way]"},
            {7, "QuickSort[Hybrid]"}
    };
    std::map<size_t, std::string> modes = {
            {0, "ASC"},
            {1, "DESC"},
            {2, "RANDOM"}
    };


public:
    Result() {
        this->file.open("result.txt");
    }

    void addSize(size_t size) {
        this->file << "\nSIZE(" << size << "):\n";
    }

    void addAlgorithm(size_t id) {
        this->file << "\t" << this->names.find(id)->second << ":\n";
    }

    void addMode(size_t id, long duration) {
        this->file << "\t\t" << this->modes.find(id)->second << ": " << duration << "ms\n";
    }

    virtual ~Result() {
        this->file.close();
        delete &this->file;
        delete &this->names;
        delete &this->modes;
    }
};

#endif //OPL_RESULT_H
