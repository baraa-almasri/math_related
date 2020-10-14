#include <string> // to_string, stod
#include <math.h> // pow
#include <stdlib.h> // malloc 
#include <regex> // regex_replace
#include <algorithm> // replace_if, reverse, find_if

using std::to_string;
using std::stod;
using std::string;
using std::regex;

class Function {
private:
    string equation;

public:
    Function(string equation) {
        this->equation = equation;
        this->lowerenEquation();
        this->removeSpaces();
        if(this->checkConstFunction()) {
            puts("Constant Function!");
        }

    }

    ~Function() {
        // no destructor
    }
    
    double at(double point) const {

        return this->evaluateInfix(
            this->replaceX(this->equation ,point)
        );
    }


private: // functions
    
    static double evaluateInfix(string polynomial) {

    	for ( int k = 0; k < polynomial.size(); k++ ) {
            
            polynomial = polynomial[k] == '('? execParanthsInString(polynomial): polynomial;
            polynomial = isOperator(polynomial[k])? evaluateTwoOperandsInString(polynomial, k): polynomial;
            k = isOperator(polynomial[k])? k-1: k;
    		
    	}		

        return stod(polynomial);
    }

    static string evaluateTwoOperandsInString(string polynomial, uint operatorIndex) {

        char op = polynomial[operatorIndex];
        // to replace operators with hash to replace it with the value
        polynomial[operatorIndex] = '#'; 

        string sFirstOperand = polynomial.substr(0, operatorIndex);
        
        string sSecondOperand = polynomial.substr(operatorIndex + 1,
            polynomial.find( *std::find_if(polynomial.begin(), polynomial.end(), isOperator) )
            - 1 -
            operatorIndex  
        );     
    
        // regex pattern to replace first and second
        // operands in the given polynomial string
        string sReplacePattern = sFirstOperand + '#' + sSecondOperand;
        // pattern requirements!
        sReplacePattern.push_back('*');

        return regex_replace(polynomial, 
            (regex)sReplacePattern, to_string( 
            execOperator( stod(sFirstOperand)
                , stod(sSecondOperand)
                , op) )
        );

    }

    // return a string with parenthesis evaluated at some index
    static string execParanthsInString(string polynomial) {

        string sInfixExpression;
        sInfixExpression = polynomial.substr( 
            polynomial.find('(') + 1, polynomial.find(')') - 1
            
        );

        return evaluateTwoOperandsInString(sInfixExpression, 
            sInfixExpression.find(*std::find_if(
                polynomial.begin(), polynomial.end(), isOperator)) ) + 
                    polynomial.substr(polynomial.find(')') + 1, string::npos);
    }

    // TODO:
    // use actual number instead of strings!
    static string replaceX(string polynomial, double x) {
        string preX;
        string afterX;
        string preXadjacent{to_string(x)};
        
        for(int k = 1; k < polynomial.size(); k++) {
            if(polynomial[k] == 'x' && isdigit(polynomial[k - 1])) {
                // count digits before x
                uint noDigitsBeforeX{0};
                string digitsBeforeX{""};
                for(int l = k - 1; l >= 0 && !isOperator(polynomial[l]); l--) {
                    noDigitsBeforeX++;
                    digitsBeforeX.push_back(polynomial[l]);
                }
                // number slapped in in a reverse order
                std::reverse(digitsBeforeX.begin(), digitsBeforeX.end());

                // everything before x and its coefficient 
                preX = polynomial.substr(0, k - noDigitsBeforeX);

                // final format
                // \\(\d\\*[x]\\)
                preX.push_back('(');
                preX += digitsBeforeX;
                preX.push_back('*');
                preX.push_back('x');
                preX.push_back(')');

                // everything after x and its coefficient
                afterX = polynomial.substr(k+1, polynomial.size());

                polynomial = preX + afterX;

            }

        }

        return regex_replace(polynomial, 
            (regex("[x]")), to_string(x));
    }

    // convert each letter to lower case
    void lowerenEquation() {
        for(char &c: this->equation) {
            c = isupper(c)? (char)tolower(c): c;

        }
    }

    // remove spaces from the function's equation
    void removeSpaces() {
        this->equation = 
            regex_replace(this->equation,
            (regex)"\\s", "");

    }

    // check if the equation reresents a line
    bool checkConstFunction() const {
        for(char c: this->equation) {
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
