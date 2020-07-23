#include <string> // for solvePostfix function
#include <math.h> // for execOperator function
#include <stdlib.h> // used malloc only
#include <stack> // for convertInToPost function
#include <ctype.h> // for convertInToPost function
#include <regex> // regular expression

class Function {
public:
    Function(std::string equation) {
        this->equation = equation;
    }
    
    int evaluate(int value) {
        // temp string 
        std::string tmp;
        // convert function equation to postfix
        tmp = convertInToPost(this->equation);
        // regex to match x
        std::regex x("[(x)]");

        // get the evaluated value
        return solvePostfix(std::regex_replace(tmp, x, std::to_string(value)) );// << std::endl;
    }


private:

    std::string equation;

    // functions

    // execute a binary operator using a character variable
    static int execOperator(int rightOperand, int leftOperand, char operation){
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
    static bool isOperator(char character){
        char c = character;
        return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') ? 1 : 0;
    }

    // convert infix to postfix
    static std::string convertInToPost(std::string infix) {
        std::stack<char> *tmp = new std::stack<char>;
        
        std::string postfix = "";
        char t;
        
        for(int i = 0; i < infix.length() ;i++) {   
            
            switch(infix[i]) {
                case '^':
                case '-': 
                case '+':
                case '/':
                case '*':
                tmp->push(infix[i]);
                break;
                case ')':   
                    postfix.push_back(tmp->top());
                    tmp->pop();
                    break;
            }
            
            if(isalnum(infix.at(i))) {
                postfix.push_back(infix.at(i));
            }
        }
        
        return postfix;
    }

    // solve postfix (duh)
    static int solvePostfix(std::string postfix){
        for(int lol = 0; lol < postfix.length(); lol++){
            // temporary string to store the original string after evaluating two numbers with thier operator
            std::string temp = "";
            if( isOperator(postfix[lol]) ){
                // step one: append elements before the operands & operator to the temporary string

                // i starts @ 0 because the main string will have final results of operands & operators
                // & ends @ main index - 2 because the index has the operator & the two indexes before it has the operands
                for(int i = 0; i < lol - 2; i++){
                    if(i >= 0)
                        temp.push_back(postfix.at(i));
                }
                // step two: append the evaluated number to the temporary string

                int rightOperand = (int)(postfix[lol-2] - 48);
                int leftOperand = (int)(postfix[lol-1] - 48);

                int result = execOperator( rightOperand, leftOperand, postfix[lol] );
                
                temp.push_back( (char)(result + 48) );

                // step three: 
                // append the rest of the postfix into the temp string

                for(int i = lol + 1; i < postfix.length(); i++){
                    temp.push_back(postfix.at(i));
                }

                // step four
                // update the postfix string with the evaluated answers

                postfix = temp;

                // step five
                // reset the counter to match with the new postfix string

                lol = 0;

                // step six if there's no more operators return the final number
                
                if( postfix.length() == 1){
                    return std::stoi(postfix);
                }

            }

        }
    }

};