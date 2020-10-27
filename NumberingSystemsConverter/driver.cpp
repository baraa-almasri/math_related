#include <cstdio>
#include "DecimalConverter.hpp"
#include "BinaryConverter.hpp"
#include "OctalConverter.hpp"
#include <cmath>

int main() {
    double x = 69.3;

    puts("decmial to");
    printf("bin: %s\n", DecimalConverter::convertToBinary(x).c_str());
    printf("oct: %s\n", DecimalConverter::convertToOctal(x).c_str());
    printf("hex: %s\n\n", DecimalConverter::convertToHexadecimal(62.75).c_str());

    puts("binary to");
    printf("dec: %s\n", BinaryConverter::convertToDecimal(100.010).c_str());
    printf("oct: %s\n", BinaryConverter::convertToOctal(100.010).c_str());
    printf("hex: %s\n\n", BinaryConverter::convertToHexadecimal(100.010).c_str());

    puts("octal to");
    printf("dec: %s\n", OctalConverter::convertToDecimal(76.6).c_str());
    printf("bin: %s\n", OctalConverter::convertToBinary(76.6).c_str());
    printf("hex: %s\n\n", OctalConverter::convertToHexadecimal(76.6).c_str());

    return 0;
}