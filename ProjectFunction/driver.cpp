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
using std::stod;
double evalFromString(string polynomial) {

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
                    , op)
                )
            );
                    

		}
	
	}		

    return std::stod(polynomial);
}


int main() {

    string fun = "2*6+33";

    std::cout << evalFromString(fun) << std::endl;

    std::regex x("16#2*");
    string lol = "18";

    fun = std::regex_replace(fun, x, lol);

    std::cout << fun << std::endl;

    //Function *f = new Function("(x+3)");
//    printf("f(5) = %d\n", f->evaluate(6));

     return 0;
}
