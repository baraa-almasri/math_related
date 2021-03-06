#include "SquareMatrix.h" // headers already included there :)
using namespace std;
// red color output
#define RED "\033[31m"
// reset color output
#define RESET "\033[0m"

// constructors
SquareMatrix::SquareMatrix(int order, string matrixName): Matrix(order, order, matrixName){
    genIdentity();
}
SquareMatrix::SquareMatrix(): SquareMatrix(1, "M"){
}

// square matrix specials
// 
vector<vector<double>> SquareMatrix::getIdentityMatrix(){
    return this->identityMatrix;
}
// find the determinant of the matrix
double SquareMatrix::determinant(){
    return det( matrix, rows );
}

// find the trace of the matrix
double SquareMatrix::trace(){
    double trace = 0;
    for(int diagonal = 0; diagonal < rows; diagonal++){
        trace += matrix[diagonal][diagonal];
    }
    return trace;
}

// find the adjoint matrix
vector< vector<double> > SquareMatrix::adjoint() {
    vector <vector<double>> result;
    initMatrix(result, this->rows, this->columns);

    for(int row = 0; row < this->rows; row++){
        for (int col = 0; col < this->columns ; col++) {
            vector< vector<double> > cofactor;
            cofactor = getCofactor(this->matrix, this->rows, row, col);
            /* instead of taking the transpose of the result
             * matrix, store the values as they are transposed :)
             */
            result[col][row] = pow(-1, (row+1)+(col+1)) * det(cofactor, this->rows - 1);
        }
    }
    /* finally get the result */
    return result;
}

// find the inverse matrix
vector< vector<double> > SquareMatrix::inverse(){
    vector< vector<double> > result;
    initMatrix(result, this->rows, this->columns);

    /* fisrt find adjoint of the main matrix*/
    vector< vector<double> > adjointMatrix;
    adjointMatrix = adjoint();
    /* second find the determinant of the main matrix*/
    const double DET = determinant();
    /* then find the inverse by dividing each element of the
     * adjoint matrix over the determinant
     */
    for(int row = 0; row < this->rows; row++){
        for (int col = 0; col < this->columns ; col++) {
            result[row][col] = adjointMatrix[row][col]/DET;
        }
    }
    /* finally get the result */
    return result;
}



// generate an identity matrix
void SquareMatrix::genIdentity() {
    initMatrix(this->identityMatrix, this->getRows(), this->getCols());
    for(int diag = 0; diag < this->getRows(); diag++) {
        this->identityMatrix[diag][diag] = 1;
    }
}

// the actual determinant finder :)
double SquareMatrix::det( vector<vector<double>> matrix, int order ){
    double answer = 0;
    // if order is 1x1 return the only element in the matrix
    if( order == 1){
        return matrix[0][0];
    }
    // if order is 2x2 calcuate the order in the basic way
    if( order == 2 ){
        return ( matrix[0][0] * matrix[1][1] ) - ( matrix[1][0] * matrix[0][1] );
    }
    // targeted first row 
    for(int mainCol = 0; mainCol < order; mainCol++){
        vector< vector<double> > newMatrix;
        /* equaling the new matrix with the cofactor of each element of the first row
         * of the main matrix
         */
        newMatrix = getCofactor( matrix , order, 0, mainCol);
        answer += pow(-1, mainCol) * matrix[0][mainCol] * (det( newMatrix, order - 1 ));
    }
    // return the answer when the recursion base is reached
    return answer;
}
