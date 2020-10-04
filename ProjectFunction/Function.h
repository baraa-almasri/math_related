#include <string> // lol
#include <math.h> // pow
#include <stdlib.h> // malloc 
#include <regex> // regex_replace

using std::string;

class Function {
public:
    Function(string polynomial) {
        this->polynomial = polynomial;

    }

    ~Function() {

    }
    

    double at(double point) {

        return this->evaluateInfix(this->polynomial);
    }


private:

    string polynomial;

private: // functions
    
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

    string replaceX(double x) {

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
