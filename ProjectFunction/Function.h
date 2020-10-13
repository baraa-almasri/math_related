#include <string> // lol
#include <math.h> // pow
#include <stdlib.h> // malloc 
#include <regex> // regex_replace
#include <algorithm> // replace_if
#include <iostream>

using std::string;

class Function {
public:
    Function(string polynomial) {
        this->polynomial = polynomial;
        this->lowerenPolynomial();
        this->removeSpaces();
        if(this->checkConstFunction()) {
            puts("Constant Function!");
        }

    }

    ~Function() {
        // no destructor
    }
    

    double at(double point) {

        return this->evaluateInfix(
            this->replaceX(this->polynomial ,point)
        );
    }


private:

    string polynomial;

private: // functions
    
    double evaluateInfix(string polynomial) const {

    	for ( int k = 0; k < polynomial.size(); k++ ) {

            polynomial = isOperator(polynomial[k])? evaluateTwoOperandsInString(polynomial, k): polynomial;
    		
    	}		

        return std::stod(polynomial);
    }

    string evaluateTwoOperandsInString(string polynomial, uint operatorsIndex) const {
        
        string sFirstOperand{""};
        string sSecondOperand{""};
        
        char op = polynomial[operatorsIndex];
        // to replace operators with hash to replace it with the value
        polynomial[operatorsIndex] = '#'; 

        for( int l = operatorsIndex-1; l >= 0 && !isOperator(polynomial[l]); l-- ) {
            sFirstOperand.push_back(polynomial[l]);

        }
        
        // since the number is pushed_back in a revered way!
        std::reverse(sFirstOperand.begin(), sFirstOperand.end());   

        for( int l = operatorsIndex+1; !isOperator(polynomial[l]) && l < polynomial.size(); l++ ) {
            sSecondOperand.push_back(polynomial[l]);

        }
        
        sFirstOperand.push_back('#');
        sFirstOperand += sSecondOperand;
        sFirstOperand.push_back('*');
    
        return  std::regex_replace(polynomial, 
            (std::regex)sFirstOperand, std::to_string( 
            execOperator( stod(sFirstOperand)
                , stod(sSecondOperand)
                , op) )
        );

    }

    // TODO:
    // fix this shit!
    string replaceX(string polynomial, double x) const {
        std::string preX;
        std::string afterX;

        for(int k = 1; k < polynomial.size(); k++) {
           if(polynomial[k] == 'x' && isdigit(polynomial[k - 1])) {
               preX = polynomial.substr(0, k);
               preX.push_back('*');
               afterX = polynomial.substr(k, polynomial.size());

               polynomial = preX + afterX;

           }

        }

        return std::regex_replace(polynomial, 
            (std::regex("[x]")), std::to_string(x));
    }

    void lowerenPolynomial() {
        for(char &c: this->polynomial) {
            c = isupper(c)? (char)tolower(c): c;

        }
    }

    void removeSpaces() {
        this->polynomial = 
            std::regex_replace(this->polynomial,
            (std::regex)"\\s", "");

    }

    bool checkConstFunction() const {
        for(char c: this->polynomial) {
            if(c == 'x') {

                return false;
            }
        }

        return true;
    }

    // execute a binary operator using a character variable
    static double execOperator(double rightOperand, double leftOperand, char op) {

        return (op == '+')? rightOperand + leftOperand:
            (op == '-')? rightOperand - leftOperand:
            (op == '*')? rightOperand * leftOperand:
            (op == '/')? rightOperand / leftOperand: 
            (op == '^')? pow(rightOperand, leftOperand): 0;
    }

    // check for operator
    static bool isOperator(char character) {
        char c = character;

        return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
    }
    
};
