#ifndef OPL_SIMPLEARRAYS_H
#define OPL_SIMPLEARRAYS_H

#include <array>

namespace opl {

    namespace min {
        const bool bool_ = false;
        const int int_ = -42;
        const long long_ = -565;
        const float float_ = -42.5;
        const double double_ = -565.7;
        const std::string string_ = "\t\t\t";
    }

    namespace array {

        std::array<bool, 16> bool_ = {
                true,
                false,
                true,
                false,
                false,
                false,
                true,
                true,
                true,
                false,
                true,
                false,
                min::bool_,
                true,
                true,
                false
        };

        std::array<int, 16> int_ = {
                42,
                -8,
                0,
                9,
                23,
                min::int_,
                7,
                7,
                81,
                65,
                108,
                5,
                -7,
                12,
                11,
                55
        };

        std::array<long, 16> long_ = {
                420,
                -80,
                0,
                9,
                23,
                min::long_,
                7,
                7,
                81,
                65,
                108,
                5,
                -7,
                120,
                11,
                55
        };

        std::array<float, 16> float_{
                -4.5,
                17.6,
                0.1,
                0,
                47.11,
                min::float_,
                -42.3,
                147.6,
                8.4,
                6.78,
                55.6,
                0.7,
                8.8,
                8.8,
                66.0,
                77
        };

        std::array<double, 16> double_{
                -4.5,
                17.6,
                0.1,
                0,
                47.11,
                min::double_,
                -42.3,
                147.6,
                8.4,
                6.78,
                55.6,
                0.7,
                8.8,
                8.8,
                -565.6666666,
                66.0
        };

        std::array<std::string, 16> string_{
                "BBBBBB",
                "KJKJKJ",
                "585858",
                min::string_,
                "&%&%&%",
                "//////",
                "AAAAAAA",
                "LLLLLL",
                "ßßßßßß",
                "ZOPZOP",
                "AAAAAA",
                "777777",
                "LLLLLL",
                "JAKDAÖ",
                "ÖÄÖÄÖÄ",
                "!?+*~-"
        };

    }
}

#endif //OPL_SIMPLEARRAYS_H
