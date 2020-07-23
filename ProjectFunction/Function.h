#include <stdio.h> 
#include <string.h> // for appendChrToStr function
#include <math.h> // for execOperator function
#include <stdlib.h> // used malloc only
#include <stack> // for convertInToPost function
#include <ctype.h> // for convertInToPost function
#include <regex.h>

class Function {
public:
    Function(char *equation) {
        this->equation = equation;
    }

    /*int evaluate(int value) {
        std::regex x ("[(x)]");
        std::string eq = this->equation;
        char *tmp = regex;
        return solvePostfix();
    }*/


private:
    char *equation;

    // functions

    // append character to string
    char *appentChrToStr(char *SrcString, char character) {
        // temp string
        char *temp = (char *)malloc(strlen(SrcString) + 1);
        // add the sourve string to temporary string
        strcpy(temp, SrcString);
        // add the character to the new string
        temp[strlen(SrcString)] = character;

        // return the new string
        return temp;
    }

    // execute a binary operator using a character variable
    int execOperator(int rightOperand, int leftOperand, char operation){
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
        }
    }

    // check for operator
    bool isOperator(char character){
        char c = character;
        return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') ? 1 : 0;
    }

    // convert infix to postfix
    char *convertInToPost(char *infix) {
        std::stack<char> *tmp = new std::stack<char>;
        
        char *postfix = (char *)malloc(sizeof(char)*strlen(infix));
        char t;
        
        for(int i = 0; i < strlen(infix) ;i++) {   
            
            switch(infix[i]) {
                case '^':
                case '-': 
                case '+':
                case '/':
                case '*':
                tmp->push(infix[i]);
                break;
                case ')':   
                    postfix = appentChrToStr(postfix, tmp->top());
                    tmp->pop();
                    break;
            }
            
            if(isalnum(infix[i])) {
                postfix = appentChrToStr(postfix, infix[i]);
            }
        }
        
        return postfix;
    }

    // solve postfix (duh)
    int solvePostfix(char *postfix){
        for(int lol = 0; lol < strlen(postfix); lol++){
            // temporary string to store the original string after evaluating two numbers with thier operator
            char *temp = "";
            if( isOperator(postfix[lol]) ){
                // step one: append elements before the operands & operator to the temporary string

                // i starts @ 0 because the main string will have final results of operands & operators
                // & ends @ main index - 2 because the index has the operator & the two indexes before it has the operands
                for(int i = 0; i < lol - 2; i++){
                    if(i >= 0)
                        temp = appentChrToStr(temp, postfix[i]);
                        
                }
                // step two: append the evaluated number to the temporary string

                int rightOperand = (int)(postfix[lol-2] - 48);
                int leftOperand = (int)(postfix[lol-1] - 48);

                int result = execOperator( rightOperand, leftOperand, postfix[lol] );
                
                temp = appentChrToStr(temp, (char)(result + 48) );

                // step three: 
                // append the rest of the postfix into the temp string

                for(int i = lol + 1; i < strlen(postfix); i++){
                    temp = appentChrToStr(temp, postfix[i]);
                }

                // step four
                // update the postfix string with the evaluated answers

                postfix = temp;

                // step five
                // reset the counter to match with the new postfix string

                lol = 0;

                // step six if there's no more operators return the final number
                
                if( strlen(postfix) == 1){
                    return atoi(postfix);
                }

            }

        }
    }

};