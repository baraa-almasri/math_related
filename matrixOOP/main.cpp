#include <cstdio>
#include "Matrix.hpp"

int main(void){
    printf("Enter order of the matrix(square matrix):  ");
    int order;
    scanf("%d", &order);

    squareMatrix *A = new squareMatrix(order);
    A->readMatrix();
    A->printMatrix(); 
    // determinant & trace
    printf("determinant of A = %lf\n", A->findDeterminant());
    printf("trace of A = %lf\n", A->find_trace());
    // transpose
    printf("\nA transpose:\n");
    squareMatrix *A_Transpose = new squareMatrix(order);
    A_Transpose->setMatrix(A->transpose());
    A_Transpose->printMatrix();
    // add & multiply
    squareMatrix *B = new squareMatrix(order);
    B->readMatrix();
    B->printMatrix();
    
    
    // a matrix to store AxB
    squareMatrix *AmultB = new squareMatrix(order); 
    AmultB->setMatrix(A->multiply(B->getMatrix()));
    printf("A x B \n");
    AmultB->printMatrix();

    // add matrix B to matrix A
    A->add(B->getMatrix());
    printf("A + B \n");
    A->printMatrix(); // print matrix A after the addition

    return 0;
}