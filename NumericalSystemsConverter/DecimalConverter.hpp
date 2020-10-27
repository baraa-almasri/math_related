#ifndef DECIMALCONVERTER_HPP
#define DECIMALCONVERTER_HPP

#include <string>
using std::string;
using std::to_string;
#include "Converter.hpp" // parent

// accuracy 95%
class DecimalConverter : Converter {
private:
    // this class is not meant to have any instances
    DecimalConverter() {}
    ~DecimalConverter() {}

public:
    static string convertToBinary(const double number) {
        
        return gerenralConvert(to_string(number), 2, 10);
    }

    static string convertToOctal(const double number) {
        
        return gerenralConvert(to_string(number), 8, 10);
    }

    static string convertToHexadecimal(double number) {
        
        return gerenralConvert(to_string(number), 16, 10);
    }

    
};

#endif // CONVERTER_HPP