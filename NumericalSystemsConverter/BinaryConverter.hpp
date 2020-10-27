#ifndef BINARYCONVERTER_HPP
#define BINARYCONVERTER_HPP

#include "DecimalConverter.hpp" // 10to16, 10to8
#include "Converter.hpp" // parent
#include <string>
using std::string;

class BinaryConverter : Converter {
private:
    // this class is not meant to have any instance
    BinaryConverter() {}
    ~BinaryConverter() {}

public:
    static string convertToDecimal(double number) {

        return gerenralConvert(to_string(number), 2, 2);
    }

    // these ones are hacks but working :)

    static string convertToOctal(double number) {

        return DecimalConverter::convertToOctal(
            stod(BinaryConverter::convertToDecimal(number))
        );
    }

    static string convertToHexadecimal(double number) {

        return DecimalConverter::convertToHexadecimal(
            stod(BinaryConverter::convertToDecimal(number))
        );
    }

};

#endif // CONVERTER_HPP