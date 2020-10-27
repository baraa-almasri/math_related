#ifndef OCTALCONVERTER_HPP
#define OCTALCONVERTER_HPP

#include "DecimalConverter.hpp" // 10to16, 10to2
#include "SeperatedNumber.hpp"
#include <string>
using std::string;
using std::stol;
using std::stod;
#include <cmath> // pow
typedef long long lli;

class OctalConverter {
private:
    // this class is not meant to have any instance
    OctalConverter() {}
    ~OctalConverter() {}

public:
    // convert from octal
    static string convertToDecimal(double number) {
        SeperatedNumber octNum(number);
        // the compiler will convert it to decimal value, if declared as a normal number
        string sDecNum{""};         
        // converting number pre floating point
        sDecNum += convertPrePoint(stol(octNum.prePoint), 8);
        // add floating point(if exists)
        sDecNum.push_back( 
            octNum.pointIndex == -1? (char)48: '.'
        );
        // converting number after floating point
        sDecNum += convertPostPoint(stod(octNum.postPoint), 8);

        return sDecNum;
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


private: // shady functions

    static string convertPrePoint(lli prePoint, lli base = 10) {
        string sPrePoint{to_string(prePoint)};
        reverse(sPrePoint.begin(), sPrePoint.end());

        lli convertedPrePoint{0};
        for(int k = 0; k < sPrePoint.size(); k++) {
            convertedPrePoint += (int)(sPrePoint[k] - 48)*pow(base, k);

        }

        return to_string(convertedPrePoint);
    }

    static string convertPostPoint(double postPoint, lli base = 10) {
        string sPostPoint{to_string(postPoint)};

        double convertedPostPoint{0};
        for(int k = 2; k < sPostPoint.size(); k++) {
            // k-1 beacuase index started at 2 where point was at index 1 LOL
            convertedPostPoint += (int)(sPostPoint[k] - 48)*pow(base, -1*(k-1));
            
        }

        // only the fractional part :)
        return to_string(convertedPostPoint).substr(2, std::string::npos);
    }

};

#endif // CONVERTER_HPP