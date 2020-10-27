#ifndef BINARYCONVERTER_HPP
#define BINARYCONVERTER_HPP

#include "DecimalConverter.hpp" // 10to16, 10to8
#include "SeperatedNumber.hpp"
#include <string>
using std::string;
using std::stol;
using std::stod;
#include <cmath> // pow
typedef long long lli;

class BinaryConverter {
private:
    // this class is not meant to have any instance
    BinaryConverter() {}
    ~BinaryConverter() {}

public:
    static string convertToDecimal(double number) {
        SeperatedNumber binNum(number);
        // the compiler will convert it to decimal value, if declared as a normal number
        string sDecNum{""};         
        // converting number pre floating point
        sDecNum += convertPrePoint(stol(binNum.prePoint), 2);
        // add floating point(if exists)
        sDecNum.push_back( 
            binNum.pointIndex == -1? (char)48: '.'
        );
        // converting number after floating point
        sDecNum += convertPostPoint(stod(binNum.postPoint), 2);

        return sDecNum;
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