#ifndef OCTALCONVERTER_HPP
#define OCTALCONVERTER_HPP

#include "DecimalConverter.hpp" // 10to16, 10to2
#include "SeperatedNumber.hpp"
#include "Converter.hpp"
#include <string>
using std::string;
using std::stol;
using std::stod;
#include <cmath> // pow
typedef long long lli;

class OctalConverter : Converter {
private:
    // this class is not meant to have any instance
    OctalConverter() {}
    ~OctalConverter() {}

public:
    // convert from octal
    static string convertToDecimal(double number) {

        return gerenralConvert(to_string(number), 8, 8);
    }


    // AAAAAAAAAAAAAAAA

    static string convertToHexadecimal(double number) {
        
        return DecimalConverter::convertToHexadecimal(
            stod(OctalConverter::convertToDecimal(number))
        );
    }

    static string convertToBinary(double number) {

        return DecimalConverter::convertToBinary(
            stod(OctalConverter::convertToDecimal(number))
        );
    }


};

#endif // CONVERTER_HPP