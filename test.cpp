#include "Matrix.h"
#include <stdio.h>

int main(){
    Matrix *A = new Matrix(2, 3, "A");
    A->readMatrix();
    A->printMatrix();

    return 0;
}