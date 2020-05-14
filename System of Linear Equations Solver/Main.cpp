#include <stdio.h>
#include "functions.hpp"
int main(){
    printf("Enter order of unknowns: ");
    int unknowns;
    scanf("%i", &unknowns);
    solveSystem(unknowns);

    return 0;
}