#ifndef SUPERCONVERTER_HPP
#define SUPERCONVERTER_HPP

#include <string>
using std::string;
using std::to_string;
using std::stol;
using std::stod;
#include <algorithm>
using std::reverse;
#include <cmath> // fmod, modf(in the future)
#include "SeperatedNumber.hpp" // lol
#include <cctype>
typedef long long lli;

class SuperConverter {

    // BIG FAT NOTE ABOUT THIS CLASS!!
    // numbers are passed as strings, because of bases > 10

public:

    static string convert(
        string number, 
        const int numberBase, 
        const int targetBase)
    {
        // always make the number look like a real number
        number += number.find('.') == -1 ? "." : "";
        SuperConverter::capitalize(number);

        // ok this one is a bit messy
        // first check if the number is valid according to its base
        // if valid, check if the number's base is 10 if so
        // convert it to the target base provided, if not 10
        // convert it to 10, then the target base
        // if the number is invalid return the message "IDI NAHUI"
        // which is kinda of an error code :)
        return SuperConverter::isNumberValid(number, numberBase)?
            SuperConverter::convert0(numberBase == 10? number: 
            SuperConverter::convert0(number, numberBase, 10),
            10, targetBase):
            "IDI NAHUI!!";
    }

private:

    static string convert0(
        const string number, 
        const lli numberBase, 
        const lli targetBase)
    {
        SeperatedNumber num(number);
        string finalNumber{""};     

        // converting number pre floating point
        finalNumber += (numberBase == 10? 
            SuperConverter::convertPrePointFromDecimal:
            SuperConverter::convertPrePointToDecimal

        )(num.prePoint, numberBase == 10? targetBase: numberBase);

        // add floating point(if exists)
        finalNumber.push_back( 
            num.pointIndex == -1? (char)48: '.'
        );

        // converting number after floating point
        finalNumber += (numberBase == 10? 
            SuperConverter::convertPostPointFromDecimal:
            SuperConverter::convertPostPointToDecimal
        
        )(num.postPoint, numberBase == 10? targetBase: numberBase);

        // if the number was zero a weird string will be produced! so....
        return finalNumber == ".0"? "0.0": 
            num.negative? "-" + finalNumber: finalNumber; // also if the number is negative respect that!
    }


// more private level 1:

    static bool isNumberValid(const string number, const int numberBase) {
        for(char digit: number) {
            if((int)(digit - (numberBase > 9? 55: 48) ) >= numberBase) {

                return false;
            }
        }

        return true;
    }

    static void capitalize(string &number) {
        for(char &digit: number) {
            digit = islower(digit)? toupper(digit): digit;
        }
    }

// more private level 2:

    // before decimal point
    static string convertPrePointFromDecimal(string sPrePoint, const lli base) {
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

    // after decimal point
    static string convertPostPointFromDecimal(string sPostPoint, const lli base) {
        double postPoint = stod(sPostPoint);
        sPostPoint.clear();

        double initPostPoint = postPoint;
        double dummy;
        do {
            postPoint *= base;
            double prePointOfResult;
            postPoint = modf(postPoint, &prePointOfResult);

            sPostPoint.push_back( 
                (char)( 
                    ((int)prePointOfResult % base > 9? 55: 48) // ascii code for CAPS or number
                    + ((int)prePointOfResult % base) // how much ascii
                )
            );

        } while(( modf(postPoint, &dummy) != modf(initPostPoint, &dummy) )
            && postPoint >= 0.099);

        return sPostPoint;
    }

    /* convert to decimal as this formula
     * ∑ n[i]*(base)^i
     * where digits before decimal point have 0 based indexes
     * and after the point have indexes starting with -1 then -2 ....
     * 
    */

    // before decimal point
    static string convertPrePointToDecimal(string prePoint, const lli base) {
        reverse(prePoint.begin(), prePoint.end());

        lli convertedPrePoint{0};
        for(int k = 0; k < prePoint.size(); k++) {
            convertedPrePoint += (int)(prePoint[k] - (prePoint[k] > 64? 55 : 48 ) )
                *pow(base, k);

        }

        return to_string(convertedPrePoint);
    }
    
    // after decimal point
    static string convertPostPointToDecimal(const string postPoint, const lli base) {
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

#endif // SUPERCONVERTER_HPP