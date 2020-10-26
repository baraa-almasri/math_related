#include <cstdio>
#include "DecimalConverter.hpp"

int main() {
    lli x = 16;

    printf("bin: %s\n", DecimalConverter::convertToBinary(x).c_str());
    printf("oct: %s\n", DecimalConverter::convertToOctal(x).c_str());
    printf("hex: %s\n", DecimalConverter::convertToHexadecimal(x).c_str());

    return 0;
}