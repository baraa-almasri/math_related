//matrix class by Baraa Al-Masri
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include "SquareMatrix.hpp"
using namespace std;

// overloaded constructors
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
/*squareMatrix(vector< vector<double> > otherMatrix, int order){
    squareMatrix(order);
    squareMatrix::matrix = otherMatrix;
}*/
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

// find the determinant of the matrix
double SquareMatrix::findDeterminant(){
    return det(rows, matrix);
}

// find the trace of the matrix
double SquareMatrix::find_trace(){
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
    
    vector< vector<double> > transposed_matrix;
    initMatrix(transposed_matrix, new_rows, new_columns);
    
    for(int row = 0; row < new_rows; row++){
        for(int col = 0; col < new_columns; col++){
            transposed_matrix[row][col] = matrix[col][row];
        }
            
    }

    return transposed_matrix;

}



// end of functions, well I lied :)    
////////////////

// da matrix blin
/*  std::vector< std::vector<double> > matrix;
// rows & columns blyat
int rows;
int columns;
string matrixName;
*/
// determinant finder, it's private so the object function call is not parameterized :)
// otherwise it'll get messy like a bee kingdom
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
    //printf("LOL Cyka\n");

    // finally return the answer when the recieved matrix is 1*1
    return answer;

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
        // and roll over if condition is true :) 
    }
    //return mtrx; //blyat what was I thinking :)
}
// print spaces as same as matrix name
void SquareMatrix::printSpaces(string matrixName){
    int length = matrixName.length();
    for (int i = 0; i < length; i++ ){
        printf(" ");
    }

}

// this function adds a matrix to the current matrix & returns the added matrix
vector< vector<double> > SquareMatrix::add(SquareMatrix anotherMatrix){
    // orders check
    int order = this->getRows();
    int order2 = anotherMatrix.getRows();
    if(order != order2 ){
        printf("Hold up different orders no sum for you!\n");
        exit(0);
    }
    // another matrix's 2D array
    vector< vector<double> > otherMatrix;
    otherMatrix = anotherMatrix.getMatrix();
    // new matrix
    string newMatrixName =  matrixName + " + " + anotherMatrix.getMatrixName();
    SquareMatrix *newMatrix = new SquareMatrix(order, newMatrixName);
    vector< vector<double> > newMatrixsArray;
    initMatrix(newMatrixsArray, order, order);

    for(int row = 0; row < order; row++){
        for(int col = 0; col < order; col++){
            newMatrixsArray[row][col] = otherMatrix[row][col] + this->matrix[row][col];
        }
    }
    newMatrix->setMatrix(newMatrixsArray);
    return newMatrix->getMatrix();
}

// multiply the matrix with a given matrix and put the result in a new matrix
vector< vector<double> > SquareMatrix::multiply( SquareMatrix anotherMatrix){
    // the another matrix's vector
    vector< vector<double> > otherMatrix;
    otherMatrix = anotherMatrix.getMatrix();
    // rows & columns of the other matrix
    int otherRows = anotherMatrix.getRows();
    int otherColumns = anotherMatrix.getCols();
    // rows & columns of the resulting matrix
    int newRows = this->rows;
    int newColumns = otherColumns;
    // new matrix
    vector< vector<double> > newMatrix;
    initMatrix(newMatrix, newRows, newColumns);
    // Multiplying matrix a and b and storing in array mult.
    for(int row1 = 0; row1 < this->rows; row1++)
        for(int col2 = 0; col2 < otherColumns; col2++)
            for(int col1 = 0; col1 < this->columns; col1++){
                newMatrix[row1][col2] += this->matrix[row1][col1] * otherMatrix[col1][col2];
            }
    // finally get the resulting matrix
    return newMatrix;
}


// some sort of linear search function

// returns memory address of the matching matrix name
// note that it need excepyiopn handelling in the main function :)
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
