#ifndef SEPERATEDNUMBER_HPP
#define SEPERATEDNUMBER_HPP

#include <string>
using std::string;
using std::to_string;

struct SeperatedNumber {
    string prePoint;
    string postPoint;
    int pointIndex;

    SeperatedNumber(double x) {
        this->pointIndex = to_string(x).find('.');

        this->prePoint = to_string(x).substr(0, 
            this->pointIndex == -1? to_string(x).size():
            this->pointIndex
        );

        this->postPoint = "0" +
            (this->pointIndex == -1? "0" :
            to_string(x).substr(this->pointIndex, std::string::npos)
        );
    }
};

#endif // SEPERATEDNUMBER_HPP