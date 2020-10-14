#include "Function.h"
#include <iostream>
#include <stdio.h>
#include <memory>

int main() {
    
    std::unique_ptr<Function> fn(new Function("2x+420-10+1"));
    printf("val: %lf\n", fn->at(9));

  
    return 0;
}
