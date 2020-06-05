#include <iostream>
#include "SquareMatrix.hpp"

int main(){

    SquareMatrix *A = new SquareMatrix(3, "M");
    A->readMatrix();
    A->printMatrix();
    A->setMatrix((*A *= 2).getMatrix());
    A->printMatrix();

}