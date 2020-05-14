#include <cstdio>
#include <vector>
#include "matrix.hpp"
#include "functions.hpp"

int main(int argCount, char *argValue[]){
    
    printf("Enter order of the matrix(square matrix): ");
    int order;
    scanf("%i", &order);
    Matrix matrix = Matrix(order);

    matrix.readMatrix();
    matrix.printMatrix();
    //m.det();
    printf("det = %lf\n", matrix.findDeterminant() );

    //std::vector< std::vector<double> > B;
    Matrix B = Matrix(order);
    B.readMatrix();

    B.printMatrix();
    B.add(matrix.getMatrix());
    B.printMatrix();


    return 0;
}