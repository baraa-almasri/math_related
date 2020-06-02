#include "SquareMatrix.hpp" // headers already included there :)
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



// action functions :)

// overloaded operators :) :) :)

// add equals a matrix operator
SquareMatrix SquareMatrix::operator += (SquareMatrix anotherMatrix){
    // new matrix to hold the result
    SquareMatrix newMatrix = *this; // has the info of the first operand so ther's no need for "initMatrix()"
    newMatrix.setMatrix( add(anotherMatrix) );
    // return the new matrix
    return newMatrix;
}


// muliply equals a matrix operator
SquareMatrix SquareMatrix::operator *= (SquareMatrix anotherMatrix){
    // new matrix to hold the result
    SquareMatrix newMatrix = *this; // has the info of the first operand so ther's no need for "initMatrix()"
    newMatrix.setMatrix( multiply(anotherMatrix) );
    // return the new matrix
    return newMatrix;
}
//// end of overloaded operators


// find the determinant of the matrix
double SquareMatrix::findDeterminant(){
    return det(rows, matrix);
}


// find the trace of the matrix
double SquareMatrix::findTrace(){
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


// the actual determinant finder :)
double SquareMatrix::det(int rows, std::vector<std::vector<double>> mainMatrix){ //wondering why called mainMatrix
    int cols = rows; // for readablity                 //scroll down to see some messed up blin 
    double answer = 0;
    if(rows == 2){
        return ( mainMatrix[0][0] * mainMatrix[1][1] ) - ( mainMatrix[1][0] * mainMatrix[0][1] );
    }

    int newRows, newCols;
    newRows = rows - 0; // those two where "rows - 1" then I realised that
    newCols = cols - 0; // this moo ain't working so....


    // first row, alternating columns
    for(int mainCol = 0; mainCol < cols; mainCol++){
        std::vector< std::vector<double> > newMatrix;
        // for future reads :)
        // I had to stop @ newRows - 1 so the index won't be out of range in the main matrix
        for(int newRow = 0; newRow < newRows - 1; newRow++){
            // temporary vector to store columns
            std::vector<double> tempVector;
                
            for(int newCol = 0; newCol < newCols; newCol++){
                    
                if( newCol != mainCol ){
                    double temp;
                    temp = mainMatrix[newRow+1][newCol];
                    tempVector.push_back(temp);

                }
            }
            // add the temporary vector to the current row of the main 2D vector
            newMatrix.push_back(tempVector);

        }
        answer += pow(-1, mainCol) * mainMatrix[0][mainCol] * (det(newRows-1, newMatrix));
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
    vector< vector<double> > newMatrixsArray;
    initMatrix(newMatrixsArray, rows1, cols1);

    for(int row = 0; row < rows1; row++)
        for(int col = 0; col < cols1; col++)
            newMatrixsArray[row][col] = otherMatrix[row][col] + this->matrix[row][col];
        
    
    return newMatrixsArray;
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
    vector< vector<double> > newMatrix;
    initMatrix(newMatrix, rows3, columns3);
    
    // Multiplying matrix 1 and 2 and storing in matrix 3.
    for( int row3 = 0; row3 < rows3; row3++ )
        for( int col3 = 0; col3 < columns3; col3++ )
            for( int common = 0; common < commons; common++ )
                newMatrix[row3][col3] += this->matrix[row3][common] * otherMatrix[common][col3];

    // finally get the resulting matrix
    return newMatrix;
}