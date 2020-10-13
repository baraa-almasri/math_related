#include "Function.h"
#include <iostream>
#include <stdio.h>
#include <memory>

int main() {
    
    std::unique_ptr<Function> fn(new Function("x^2+55+2x"));

    printf("val: %lf\n", fn->at(9));
    
    return 0;
}
