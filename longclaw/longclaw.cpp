#include <stdio.h>
#include "SquareMatrix.h"
#include "AuxFunctions.h"
int main(){
    printWelcomeScreen();
    printf("enter number of matrices you want to have:  ");
    int noOfMatrices;
    scanf("%d", &noOfMatrices);
    Matrix *matricesList[noOfMatrices];
    matricesInput(matricesList, noOfMatrices);
    operationsMenu(matricesList, noOfMatrices);

    return 0;
}