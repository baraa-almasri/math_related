#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include "DecimalConverter.hpp"
#include "BinaryConverter.hpp"
#include "OctalConverter.hpp"

class Converter {
public:

    ~Converter() {
        delete instance;

    }

    static Converter *getInstance() {
        instance = !instance? new Converter(): instance;


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
        
        default:
            break;
        }

    }

private: 
    static Converter *instance;

    Converter() {}

    void convertBinary(double number) const {
        printf("dec: %s\n", BinaryConverter::convertToDecimal(number).c_str());
        printf("oct: %s\n", BinaryConverter::convertToOctal(number).c_str());
        printf("hex: %s\n", BinaryConverter::convertToHexadecimal(100.010).c_str());
 
    }
    
    void convertOctal(double number) const {
        printf("dec: %s\n", OctalConverter::convertToDecimal(number).c_str());
        printf("bin: %s\n", OctalConverter::convertToBinary(number).c_str());
        printf("hex: %s\n", OctalConverter::convertToHexadecimal(number).c_str());

    }

    void convertDecimal(double number) const {
        printf("bin: %s\n", DecimalConverter::convertToBinary(number).c_str());
        printf("oct: %s\n", DecimalConverter::convertToOctal(number).c_str());
        printf("hex: %s\n", DecimalConverter::convertToHexadecimal(number).c_str());

    }
    //void convertHexadecimal(double number) {}

};

// static init
Converter *Converter::instance = nullptr;

#endif //CONVERTER_HPP