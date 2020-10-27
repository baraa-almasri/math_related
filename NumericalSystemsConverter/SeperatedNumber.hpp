#ifndef SEPERATEDNUMBER_HPP
#define SEPERATEDNUMBER_HPP

#include <string>
using std::string;
using std::to_string;

struct SeperatedNumber {
    string prePoint;
    string postPoint;
    int pointIndex;

    SeperatedNumber(string x) {
        this->pointIndex = x.find('.');

        this->prePoint = x.substr(0, 
            this->pointIndex == -1? x.size():
            this->pointIndex
        );

        this->postPoint = "0" +
            (this->pointIndex == -1? "0" :
            x.substr(this->pointIndex, std::string::npos)
        );
    }
};

#endif // SEPERATEDNUMBER_HPP