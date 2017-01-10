#include "./src/util/Chronometry.h"


int main() {

    std::cout << std::endl;

    Result *result = new Result();
    opl::Chronometry<opl::constant::min_array_size>::execute(*result);
    delete result;

    return 0;
}



