#ifndef DECIMALCONVERTER_HPP
#define DECIMALCONVERTER_HPP

#include <string>
using std::string;
using std::to_string;
using std::stol;
using std::stod;
#include <algorithm>
using std::reverse;
#include <cmath> // fmod
#include "SeperatedNumber.hpp"
typedef long long lli;

// accuracy 95%
class DecimalConverter {
private:
    // this class is not meant to have any instance
    DecimalConverter() {}
    ~DecimalConverter() {}

public:
    static string convertToBinary(const double number) {
        SeperatedNumber decNum(number);
        // the compiler will convert it to decimal value, if declared as a normal number
        string sBinNum{""};         
        // converting number pre floating point
        sBinNum += convertPrePoint(stol(decNum.prePoint), 2);
        // add floating point(if exists)
        sBinNum.push_back( 
            decNum.pointIndex == -1? (char)48: '.'
        );
        // converting number after floating point
        sBinNum += convertPostPoint(stod(decNum.postPoint), 2);
        

        return sBinNum;
    }

    static string convertToOctal(const double number) {
        SeperatedNumber decNum(number);
        // the compiler will convert it to decimal value, if declared as a normal number
        string sOctNum{""};         
        // converting number pre floating point
        sOctNum += convertPrePoint(stol(decNum.prePoint), 8);
        // add floating point(if exists)
        sOctNum.push_back( 
            decNum.pointIndex == -1? (char)48: '.'
        );
        // converting number after floating point
        sOctNum += convertPostPoint(stod(decNum.postPoint), 8);

        return sOctNum;
    }

    static string convertToHexadecimal(double number) {
        SeperatedNumber decNum(number);
        // the compiler will convert it to decimal value, if declared as a normal number
        string sHexNum{""};         
        // converting number pre floating point
        sHexNum += convertPrePoint(stol(decNum.prePoint), 16);
        // add floating point(if exists)
        sHexNum.push_back( 
            decNum.pointIndex == -1? (char)48: '.'
        );
        // converting number after floating point
        sHexNum += convertPostPoint(stod(decNum.postPoint), 16);

        return sHexNum;
    }

private: // shady functions

    static string convertPrePoint(lli prePoint, lli base = 10) {
        string sPrePoint{""};

        while(prePoint != 0) {
            sPrePoint.push_back( 
                (char)( 
                    prePoint % base > 9? 55: 48
                    + prePoint % base
                )
            );
            prePoint /= base;
        }
        reverse(sPrePoint.begin(), sPrePoint.end());


        return sPrePoint;
    }

    static string convertPostPoint(double postPoint, lli base = 10) {
        string sPostPoint{""};

        double nInitPostPoint = postPoint;
        
        do {
            postPoint *= base;
            int prePoint = fmod( postPoint
                , base == 16? 100: 10 );
            sPostPoint.push_back( 
                (char)( 
                    (prePoint % base > 9? 55: 48)
                    + (prePoint % base)
                )
            );
            postPoint -= prePoint;

        } while((int)fmod(postPoint*10, 10) != (int)fmod(nInitPostPoint*10, 10) 
            && postPoint != 0);


        return sPostPoint;
    }

};

#endif // CONVERTER_HPP