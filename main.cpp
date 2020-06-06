#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "SquareMatrix.h"
#include "AuxFunctions.h"
int main(void){
    // welcome screen
    welcome();

    printf("enter number of square matrices you want to have:  ");
    int noOfMatrices;
    scanf("%d", &noOfMatrices);
    // matrices list
    SquareMatrix *matricesList[noOfMatrices];
    // enter matrices' data
    matricesInput(matricesList, noOfMatrices);
    // list available matrices
    listMatrices(matricesList, noOfMatrices);
    // print operations menu
    operationsMenu(matricesList, noOfMatrices);


    return 0;
}