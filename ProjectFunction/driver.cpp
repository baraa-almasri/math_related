#include "Function.h"
#include <iostream>
#include <stdio.h>
#include <memory>

int main() {
    
    std::unique_ptr<Function> fn(new Function("x+35-10"));

    printf("val: %lf\n", fn->at(9));

    std::cout << Function::execParanthsFromString("2+(3+9)", 2) << std::endl;
    
    return 0;
}
