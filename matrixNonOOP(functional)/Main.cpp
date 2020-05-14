#include <cstdio>
#include <vector>
#include "functions.hpp"

int main(int argCount, char *argValue[]){
    
    printf("Enter number of rows/columns: ");
    int unknowns;
    scanf("%i", &unknowns);

    std::vector< std::vector<double> > matrix;
    readMatrix(unknowns, matrix);
    printMatrix(unknowns, matrix);


    printf("det = %lf\n", det(unknowns,matrix));
    
    return 0;
}
