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

    }

    ~Function() {

    }
    

    double at(double point) {
        this->replaceX(point);
        std::cout << "in fn: " <<this->polynomial << std::endl;
        return this->evaluateInfix(this->polynomial);
    }


//private:

    string polynomial;

//private: // functions
    
    double evaluateInfix(string polynomial) {

    	for ( int k = 0; k < polynomial.size(); k++ ) {
            string sFirstOperand{""};
            string sSecondOperand{""};

      		if ( isOperator(polynomial[k]) ) {
                char op = polynomial[k];
                // to replace operators with hash to replace it with the value
                polynomial[k] = '#'; 

                for( int l = k-1; !isOperator(polynomial[l]) && l >= 0; l-- ) {
                    sFirstOperand.push_back(polynomial[l]);
                }

                std::reverse(sFirstOperand.begin(), sFirstOperand.end());   

                for( int l = k+1; !isOperator(polynomial[l]) && l < polynomial.size(); l++ ) {
                    sSecondOperand.push_back(polynomial[l]);
                    // new index
                    k = l;
                }
            
                sFirstOperand.push_back('#');
                sFirstOperand += sSecondOperand;
                sFirstOperand.push_back('*');
    
                polynomial = std::regex_replace(polynomial, 
                    (std::regex)sFirstOperand, std::to_string( 
                    execOperator( stod(sFirstOperand)
                        , stod(sSecondOperand)
                        , op) )
                );
    		}
    	}		

        return std::stod(polynomial);
    }

    void replaceX(double x) {
        std::string preX;
        std::string afterX;

        for(int k = 1; k < this->polynomial.size(); k++) {
           if(this->polynomial[k] == 'x' && isdigit(this->polynomial[k - 1])) {
               preX = this->polynomial.substr(0, k);
               preX.push_back('*');
               afterX = this->polynomial.substr(k, this->polynomial.size());

               this->polynomial = preX + afterX;

           }

        }
        this->polynomial.resize(this->polynomial.size() + 20*std::to_string(x).size());
        this->polynomial = std::regex_replace(this->polynomial, 
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

    // execute a binary operator using a character variable
    static double execOperator(double rightOperand, double leftOperand, char op){

        return (op == '+')? rightOperand + leftOperand:
            (op == '-')? rightOperand - leftOperand:
            (op == '*')? rightOperand * leftOperand:
            (op == '/')? rightOperand / leftOperand: 
            (op == '^')? pow(rightOperand, leftOperand): 0;
    }

    // check for operator
    static bool isOperator(char character){
        char c = character;

        return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
    }
    
};
