//#include "Function.h"
#include <stdio.h>
#include <string>
#include <regex>
#include <ctype.h>
#include <iostream>
#include <algorithm>
#include <math.h>

using std::string;
using std::regex;

bool isOperator(char character){
    char c = character;

    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

double execOperator(double rightOperand, double leftOperand, char operation){
    switch(operation){
        case '+':
            return rightOperand + leftOperand;
        case '-':
            return rightOperand - leftOperand;
        case '*':
            return rightOperand * leftOperand;
        case '/':
            return rightOperand / leftOperand;
        case '^':
            return pow(rightOperand,  leftOperand);
        default: 
            printf("Wrong operation!!\n");
            return 0;
    }
}

double evalFromString(string polynomial) {
    double rFinalNumber{0.0};

    double rFirstOperand;
    double rSecondOperand;

    bool firstEnterd{false};

	for ( int k = 0; k < polynomial.size(); k++ ) {
        string sFirstOperand{""};
        string sSecondOperand{""};

        rFirstOperand = 0.0;
        rSecondOperand = 0.0;

		if ( isOperator(polynomial[k]) ) {
            char op = polynomial[k];
            // to replace operators with hash to replace it with the value
            polynomial[k] = '#'; 

            for( int l = k-1; !isOperator(polynomial[l]) && l >= 0; l-- ) {
                sFirstOperand.push_back(polynomial[l]);
            }

            std::reverse(sFirstOperand.begin(), sFirstOperand.end());   
            rFirstOperand = std::stod(sFirstOperand);

            for( int l = k+1; !isOperator(polynomial[l]) && l < polynomial.size(); l++ ) {
                sSecondOperand.push_back(polynomial[l]);
                // new index
                k = l;
            }
            
            rSecondOperand = std::stod(sSecondOperand);

            sFirstOperand.push_back('#');
            sFirstOperand += sSecondOperand;
            sFirstOperand.push_back('*');

            rFinalNumber += execOperator(rFirstOperand, rSecondOperand, op);

            polynomial = std::regex_replace(polynomial, 
                (std::regex)sFirstOperand, std::to_string( 
                execOperator(rFirstOperand, rSecondOperand, op)
                )
            );
                    
            // remove duplicate numbers            
            rFinalNumber -= rFirstOperand == rSecondOperand ? rFirstOperand: 0;
		}
	
	}		

    return std::stod(polynomial);
    //return rFinalNumber;
}


int main() {

    string fun = "10+16-2";

    std::cout << evalFromString(fun) << std::endl;

    std::regex x("16#2*");
    string lol = "18";

    fun = std::regex_replace(fun, x, lol);

    std::cout << fun << std::endl;

    //Function *f = new Function("(x+3)");
//    printf("f(5) = %d\n", f->evaluate(6));

     return 0;
}
