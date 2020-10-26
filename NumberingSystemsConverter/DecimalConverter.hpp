#ifndef DECIMALCONVERTER_HPP
#define DECIMALCONVERTER_HPP

#include <string>
#include <algorithm>
using std::reverse;
using std::string;
typedef long long lli;

class DecimalConverter {
private:
    // this class is not meant to have any instance
    DecimalConverter() {}
    ~DecimalConverter() {}

public:
    static string convertToBinary(lli decNum) {

        string binNum{""}; // the compiler will convert it to decimal value, if declared as a normal number
        while(decNum != 0) {
            binNum.push_back( (char)( (decNum % 2) + 48) );
            decNum /= 2;
        }
        reverse(binNum.begin(), binNum.end());

        return binNum;
    }

    static string convertToOctal(lli decNum) {

        string octNum{""}; // the compiler will convert it to decimal value, if declared as a normal number
        while(decNum != 0) {
            octNum.push_back( (char)( (decNum % 8) + 48) );
            decNum /= 8;
        }
        reverse(octNum.begin(), octNum.end());

        return octNum;
    }

    static string convertToHexadecimal(lli decNum) {

        string hexNum{""}; // the compiler will convert it to decimal value, if declared as a normal number
        while(decNum != 0) {
            hexNum.push_back( 
                (char) ( 
                    decNum % 16 > 10? 65: 48
                    + decNum % 16
                )
            );
            decNum /= 16;
        }
        reverse(hexNum.begin(), hexNum.end());

        return hexNum;
    }
    
};

#endif // CONVERTER_HPP