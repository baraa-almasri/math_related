#include "Function.h"
#include <string>
#include <stdio.h>


int main() {
    Function fn("2.1-3.14*10");

    printf("val: %lf\n", fn.at(9));

    return 0;
}
