#include "SquareMatrix.h" // headers already included there :)
using namespace std;

// constructors
SquareMatrix::SquareMatrix(int order, string matrixName){
    setRows(order);
    setCols(order);
    initMatrix(SquareMatrix::matrix, order, order);
    setMatrixName(matrixName);
}
SquareMatrix::SquareMatrix(){
    setRows(1);
    setCols(1);
    initMatrix(SquareMatrix::matrix, 1, 1);
    setMatrixName("M");
}

// lame setters & getters
SquareMatrix SquareMatrix::setRows(int rows){
    if(rows < 0)
        rows = 1;
    else
        this->rows = rows;
    // return object of the same class
    return *this;
}
int SquareMatrix::getRows(){
    return this->rows;
}

SquareMatrix SquareMatrix::setCols(int cols){
    if(cols < 0)
        cols = 1;
    else
        this->columns = cols;
    // return object of the same class
    return *this;
}
int SquareMatrix::getCols(){
    return this->columns;
}
//
SquareMatrix SquareMatrix::setMatrix(vector< vector<double> > matrix){
    this->matrix = matrix;
    return *this;
}
std::vector< std::vector<double> > SquareMatrix::getMatrix(){
    return SquareMatrix::matrix;
}
//
SquareMatrix SquareMatrix::setMatrixName(string matrixName){
    this->matrixName = matrixName;
    return *this;
}
string SquareMatrix::getMatrixName(){
    return this->matrixName;
}
////////

// I/O functions:

// read values into the matrix
void SquareMatrix::readMatrix(){
    printf("Enter matrix %s elements:\n", matrixName.c_str());

    int cols = SquareMatrix::rows; // for readablity
    for(int row = 0 ; row < rows ; row++){
        for(int col = 0 ; col < cols ; col++){
            printf("element%d%d = ", row+1, col+1);
            scanf("%lf", &matrix[row][col]);
        }
        printf("\n");
    }
}

// well it's a printing function no comments needed :)
void SquareMatrix::printMatrix(){
    //printf("\nMatrix's elements:");
    printf("\n%s = | ", matrixName.c_str());
    int cols = SquareMatrix::rows; // for readablity
    for(int row = 0 ; row < rows ; row++){
        for(int col = 0 ; col < cols ; col++){
            std::cout << SquareMatrix::matrix[row][col] << "";
            std::cout << (col == cols-1 ? " |" : " ");
        }
        printf("\n");
        if( row != rows - 1){
            printSpaces(matrixName); // print some spaces for formatting :)
            printf("   | ");
        }
    }
    printf("\n");
}

// print spaces as same as matrix name, used in "readMatrix()"
void SquareMatrix::printSpaces(string matrixName){
    int length = matrixName.length();
    for (int i = 0; i < length; i++ ){
        printf(" ");
    }

}

// actual matrices operations functions:

// add equals a matrix operator
SquareMatrix SquareMatrix::operator += (SquareMatrix anotherMatrix){
    // new matrix to hold the result
    SquareMatrix newMatrix = *this; // has the info of the first operand so ther's no need for "initMatrix()"
    newMatrix.setMatrix( add(anotherMatrix) );
    // return the new matrix
    return newMatrix;
}

// multiply equals a matrix operator
SquareMatrix SquareMatrix::operator *= (SquareMatrix anotherMatrix){
    // new matrix to hold the result
    SquareMatrix newMatrix = *this; // has the info of the first operand so ther's no need for "initMatrix()"
    newMatrix.setMatrix( multiply(anotherMatrix) );
    // return the new matrix
    return newMatrix;
}

// multiply equals a scalar operator
SquareMatrix SquareMatrix::operator *= (double scalar){
    // new matrix to hold the result
    SquareMatrix newMatrix = *this; // has the info of the first operand so ther's no need for "initMatrix()"
    newMatrix.setMatrix( scalarMultiply(scalar) );
    // return the new matrix
    return newMatrix;
}
//// end of overloaded operators


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

// find the transpose matrix
vector< vector<double> > SquareMatrix::transpose(){
    int new_rows = SquareMatrix::columns;
    int new_columns = SquareMatrix::rows;

    vector< vector<double> > transposedMatrix;
    initMatrix(transposedMatrix, new_rows, new_columns);

    for(int row = 0; row < new_rows; row++){
        for(int col = 0; col < new_columns; col++){
            transposedMatrix[row][col] = matrix[col][row];
        }
    }
    return transposedMatrix;
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

/* return cofactor matrix of an element of a matrix */
vector< vector<double> > SquareMatrix::getCofactor( vector< vector<double> > matrix, int order, int excludedRow, int excludedColumn){
    /* cofactored matrix  */
    vector< vector<double> > newMatrix;

    for( int row = 0; row < order; row++ ){
        vector< double > temp;
        for( int col = 0; col < order; col++ ){
            /* if element in the main matrix doesn't intersect with the
             *  excluded row or column then it's added to the cofactor matrix */
            if( row != excludedRow && col != excludedColumn){
                //double tempElement = matrix[row][col];
                temp.push_back(matrix[row][col]);
            }
        }
        /* add the temporary array to the matrix */
        if( !temp.empty() )
            newMatrix.push_back(temp);
    }
    /* return the cofactor matrix */
    return newMatrix;
}

// the actual determinant finder :)
double SquareMatrix::det( vector<vector<double>> matrix, int order ){
    double answer = 0;
    if( order == 2 ){
        return ( matrix[0][0] * matrix[1][1] ) - ( matrix[1][0] * matrix[0][1] );
    }

    // first row alternating columns
    for(int mainCol = 0; mainCol < order; mainCol++){
        vector< vector<double> > newMatrix;
        /* equaling the new matrix with the cofactor of each element of the first row
         * of the main matrix
         */
        newMatrix = getCofactor( matrix , order, 0, mainCol);
        answer += pow(-1, mainCol) * matrix[0][mainCol] * (det( newMatrix, order - 1 ));
    }

    // finally return the answer when the recieved matrix is 1*1
    return answer;

}

// this function adds a matrix to the current matrix & returns the added matrix
vector< vector<double> > SquareMatrix::add( SquareMatrix anotherMatrix ){
    // orders check
    int rows1 = this->getRows();
    int cols1 = this->getCols();
    int rows2 = anotherMatrix.getRows();
    int cols2 = anotherMatrix.getCols();

    if( rows1 != rows2 && cols1 != cols2 ){
        printf("Hold up different orders no sum for you!\n");
        exit(0);
    }

    // anotherMatrix's 2D array
    vector< vector<double> > otherMatrix;
    otherMatrix = anotherMatrix.getMatrix();

    // new matrix
    vector< vector<double> > result;
    initMatrix(result, rows1, cols1);

    for(int row = 0; row < rows1; row++)
        for(int col = 0; col < cols1; col++)
            result[row][col] = otherMatrix[row][col] + this->matrix[row][col];


    return result;
}

// multiply the matrix with a given matrix and put the result in a new matrix
vector< vector<double> > SquareMatrix::multiply( SquareMatrix anotherMatrix ){
    // the another matrix's vector
    vector< vector<double> > otherMatrix;
    otherMatrix = anotherMatrix.getMatrix();

    // rows & columns of the other matrix
    int rows2 = anotherMatrix.getRows();
    int columns2 = anotherMatrix.getCols();

    // rows & columns of the resulting matrix
    // suppose newRows : rows1, rows3
    //         newCols : columns2, columns3
    //         Common  : rows2, columns1
    int rows3 = this->rows;
    int columns3 = columns2;

    // orders check
    if( this->columns != rows2 ){
        printf("Hold up different orders no multiplication for you!\n");
        exit(0);
    }

    // shared rows & columns
    int commons = this->columns;
    // new matrix
    vector< vector<double> > result;
    initMatrix(result, rows3, columns3);

    // Multiplying matrix 1 and 2 and storing in matrix 3.
    for( int row3 = 0; row3 < rows3; row3++ )
        for( int col3 = 0; col3 < columns3; col3++ )
            for( int common = 0; common < commons; common++ )
                result[row3][col3] += this->matrix[row3][common] * otherMatrix[common][col3];

    // finally get the resulting matrix
    return result;
}

// multiply the matrix with a given number and put the result in a new matrix
vector< vector<double> > SquareMatrix::scalarMultiply( double scalar ){
    /* a matrix to store the result */
    vector< vector<double> > result;
    result = this->matrix;

    for( int row = 0; row < this->rows; row++ ){
        for( int col = 0; col < this->columns; col++ ){
            result[row][col] *= scalar;
        }
    }
    /* finally get the result */
    return result;
}

// initialse a matrix with zeros
void SquareMatrix::initMatrix(vector< vector<double> > &mtrx, int rows, int columns){

    for(int row = 0 ; row < rows ; row++){
        // temporary vector to store columns
        std::vector<double> tempVector;
        for(int col = 0 ; col < columns ; col++){
            // add the temporary variable to the temporary vector
            tempVector.push_back(0);
        }
        // add the temporary vector to the current row of the main 2D vector
        mtrx.push_back(tempVector);
    }
    //return mtrx; //blyat what was I thinking :)
}


// returns memory address of the matching matrix name note that it needs exceptiopn 
// handelling in the main function or wherever the place it's been called from :)
SquareMatrix *findMatrix(char matrixName[], SquareMatrix **array, int SIZE){ // pointer to pointer i.e pointer to the
    // array of pointers(objects)
    for(int i = 0; i < SIZE; i++)
        //try{
        if(array[i]->getMatrixName() == matrixName)
            return array[i];
        /*}
        catch (std::logic_error){
            printf(RED);
            printf("no such matrix found!\t re-choose!\n");
            printf(RESET);
            continue;
        }*/

}