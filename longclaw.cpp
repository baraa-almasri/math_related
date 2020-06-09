#include <stdio.h>
#include "SquareMatrix.h"
#include "AuxFunctions.h"
int main(){
    welcome();
    printf("enter number of square matrices you want to have:  ");
    int noOfMatrices;
    scanf("%d", &noOfMatrices);
    SquareMatrix *matricesList[noOfMatrices];
    matricesInput(matricesList, noOfMatrices);
    listMatrices(matricesList, noOfMatrices);
    operationsMenu(matricesList, noOfMatrices);

    return 0;
}