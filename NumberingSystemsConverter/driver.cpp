#include <cstdio>
#include "DecimalConverter.hpp"
#include <cmath>

int main() {
    double x = 69.420;

    printf("bin: %s\n", DecimalConverter::convertToBinary(x).c_str());
    printf("oct: %s\n", DecimalConverter::convertToOctal(x).c_str());
    printf("hex: %s\n", DecimalConverter::convertToHexadecimal(x).c_str());


    return 0;
}