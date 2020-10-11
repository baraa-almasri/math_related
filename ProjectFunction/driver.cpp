#include "Function.h"
#include <iostream>
#include <stdio.h>
#include <memory>

int main() {
    
    std::unique_ptr<Function> fn(new Function("2.1-3. 14 *10x"));

    printf("val: %lf\n", fn->at(9));
    std::cout << fn->polynomial << std::endl;
    
    return 0;
}
