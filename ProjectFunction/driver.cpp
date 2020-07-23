#include "Function.h"
#include <stdio.h>
#include <iostream>

int main() {
    Function *f = new Function("(x+3)");
    printf("f(5) = %d\n", f->evaluate(5));

     return 0;
}