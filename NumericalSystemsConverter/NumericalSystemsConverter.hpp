#ifndef NUMERICALSYSTEMSCONVERTER_HPP
#define NUMERICALSYSTEMSCONVERTER_HPP

#include "DecimalConverter.hpp"
#include "BinaryConverter.hpp"
#include "OctalConverter.hpp"
#include "HexadecimalConverter.hpp"

class NumericalSystemsConverter {
public:

    ~NumericalSystemsConverter() {
        delete instance;

    }

    static NumericalSystemsConverter *getInstance() {
        instance = !instance? new NumericalSystemsConverter(): instance;


        return instance;
    }

    void convertToOthers(double number, int base) const {

        switch (base) {
        case 2:
            convertBinary(number);
            break;
        case 8:
            convertOctal(number);
            break;
        case 10:
            convertDecimal(number);
            break;
        case 16:
            convertHexadecimal(to_string(number));
            break;
        
        default:
            break;
        }

    }

private: 
    static NumericalSystemsConverter *instance;

    NumericalSystemsConverter() {}

    void convertBinary(double number) const {
        printf("oct: %s\n", BinaryConverter::convertToOctal(number).c_str());
        printf("dec: %s\n", BinaryConverter::convertToDecimal(number).c_str());
        printf("hex: %s\n", BinaryConverter::convertToHexadecimal(number).c_str());
 
    }
    
    void convertOctal(double number) const {
        printf("bin: %s\n", OctalConverter::convertToBinary(number).c_str());
        printf("dec: %s\n", OctalConverter::convertToDecimal(number).c_str());
        printf("hex: %s\n", OctalConverter::convertToHexadecimal(number).c_str());

    }

    void convertDecimal(double number) const {
        printf("bin: %s\n", DecimalConverter::convertToBinary(number).c_str());
        printf("oct: %s\n", DecimalConverter::convertToOctal(number).c_str());
        printf("hex: %s\n", DecimalConverter::convertToHexadecimal(number).c_str());

    }
    void convertHexadecimal(string number) const {
        printf("bin: %s\n", HexadecimalConverter::convertToBinary(number).c_str());
        printf("oct: %s\n", HexadecimalConverter::convertToOctal(number).c_str());
        printf("dec: %s\n", HexadecimalConverter::convertToDecimal(number).c_str());

    }

};

// static init
NumericalSystemsConverter *NumericalSystemsConverter::instance = nullptr;

#endif //NUMERICALSYSTEMSCONVERTER_HPP