#ifndef HEXADECIMALCONVERTER_HPP
#define HEXADECIMALCONVERTER_HPP

#include "DecimalConverter.hpp" // 10to2, 10to8
#include <string>
using std::string;
#include "Converter.hpp" // parent
typedef long long lli;

class HexadecimalConverter : Converter {
private:
    // this class is not meant to have any instance
    HexadecimalConverter() {}
    ~HexadecimalConverter() {}

public:
    
    static string convertToDecimal(string number) {

        return gerenralConvert(number, 16, 16);
    }

    // AAAAAAAAAAAAAAAA

    static string convertToOctal(string number) {

        return DecimalConverter::convertToOctal(
            stod(HexadecimalConverter::convertToDecimal(number))
        );
    }

    static string convertToBinary(string number) {

        return DecimalConverter::convertToBinary(
            stod(HexadecimalConverter::convertToDecimal(number))
        );
    }

};

#endif // CONVERTER_HPP