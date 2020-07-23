#include "Function.h"
#include <stdio.h>

int main() {
    Function *f = new Function("(x+3)");
    printf("f(5) = %d\n", f->evaluate(6));

     return 0;
}