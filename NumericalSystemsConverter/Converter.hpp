#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <string>
using std::string;
using std::to_string;
using std::stol;
using std::stod;
#include <algorithm>
using std::reverse;
#include <cmath> // fmod, modf(in the future)
#include "SeperatedNumber.hpp" // lol
typedef long long lli;

class Converter {
protected:

    static string gerenralConvert(
        const string number, 
        const int targetBase, 
        const int originalBase) 
    {
        SeperatedNumber num(number);
        // the compiler will convert it to decimal value, if declared as a normal number
        string finalNumber{""};         
        // converting number pre floating point
        finalNumber += 
            (originalBase == 10? convertPrePoint10: 
                convertPrePoint)(num.prePoint, targetBase
            );

        // add floating point(if exists)
        finalNumber.push_back( 
            num.pointIndex == -1? (char)48: '.'
        );

        // converting number after floating point
        finalNumber += 
            (originalBase == 10? convertPostPoint10: 
                convertPostPoint)(num.postPoint, targetBase
            );

        return finalNumber;
    }

private:
    // convert from decimal
    static string convertPrePoint10(string sPrePoint, const lli base) {
        lli prePoint = stol(sPrePoint);
        sPrePoint.clear();

        while(prePoint != 0) {
            sPrePoint.push_back( 
                (char)( 
                    (prePoint % base > 9? 55: 48)
                    + (prePoint % base)
                )
            );
            prePoint /= base;
        }
        reverse(sPrePoint.begin(), sPrePoint.end());


        return sPrePoint;
    }

    // convert from decimal
    static string convertPostPoint10(string sPostPoint, const lli base) {
        double postPoint = stod(sPostPoint);
        sPostPoint.clear();

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

        } while(( (int)fmod(postPoint*10, 10) 
            != (int)fmod(nInitPostPoint*10, 10) )
            && postPoint != 0);


        return sPostPoint;
    }

    // convert to decimal
    static string convertPrePoint(string prePoint, const lli base) {
        reverse(prePoint.begin(), prePoint.end());

        lli convertedPrePoint{0};
        for(int k = 0; k < prePoint.size(); k++) {
            convertedPrePoint += (int)(prePoint[k] - (prePoint[k] > 64? 55 : 48 ) )
                *pow(base, k);

        }

        return to_string(convertedPrePoint);
    }

    // convert to decimal
    static string convertPostPoint(string postPoint, const lli base) {
        double convertedPostPoint{0};
        for(int k = 2; k < postPoint.size(); k++) {
            // k-1 beacuase index started at 2 where point was at index 1 LOL
            convertedPostPoint += (int)(postPoint[k] - (postPoint[k] > 64? 55 : 48 ))
            *pow(base, -1*(k-1));
            
        }

        // only the fractional part :)
        return to_string(convertedPostPoint).substr(2, std::string::npos);
    }


};

#endif // CONVERTER_HPP