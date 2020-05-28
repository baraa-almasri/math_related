#ifndef MATRIX_HPP
#define MATRIX_HPP
//matrix class by Baraa Al-Masri
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctype.h>
#include <iostream>
using namespace std;
//this whole thing deals with square matrices so rows = columns
class SquareMatrix{
public:
    // overloaded constructors
    SquareMatrix(int order, string matrixName){
        setRows(order);
        setCols(order);
        initMatrix(SquareMatrix::matrix, order, order);
        setMatrixName(matrixName);
    }
    SquareMatrix(){
        setRows(1);
        setCols(1);
        initMatrix(SquareMatrix::matrix, 1, 1);
        
    }
    /*squareMatrix(vector< vector<double> > otherMatrix, int order){
        squareMatrix(order);
        squareMatrix::matrix = otherMatrix;
    }*/
    // lame setters & getters
    SquareMatrix setRows(int rows){
        if(rows < 0)
            rows = 1;
        else
            this->rows = rows;
        // return object of the same class
        return *this;
    }    
    int getRows(){
        return this->rows;
    }
    
    SquareMatrix setCols(int cols){
        if(cols < 0)
            cols = 1;
        else
            this->columns = cols;
        // return object of the same class
        return *this;
    }    
    int getCols(){
        return this->columns;
    }
    //
    SquareMatrix setMatrix(vector< vector<double> > matrix){
        this->matrix = matrix;
        return *this;
    }
    std::vector< std::vector<double> > getMatrix(){
        return SquareMatrix::matrix;
    }
    //
    SquareMatrix setMatrixName(string matrixName){
        this->matrixName = matrixName;
        return *this;
    }
    string getMatrixName(){
        return this->matrixName;
    }
    ////////

    
    // read values into the matrix
    void readMatrix(){
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
    void printMatrix(){
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

    // this function adds a matrix to the current matrix & returns the added matrix
    vector< vector<double> > add(SquareMatrix *anotherMatrix){
        // orders check
        int order = this->matrix.size();
        int order2 = anotherMatrix->getMatrix().size();
        if(order != order2 ){
            printf("Hold up different orders no sum for you!\n");
            exit(0);
        }
        // another matrix's 2D array
        vector< vector<double> > otherMatrix;
        otherMatrix = anotherMatrix->getMatrix();
        // new matrix
        string newMatrixName =  matrixName + " + " + anotherMatrix->getMatrixName();
        SquareMatrix *newMatrix = new SquareMatrix(order, newMatrixName);
        vector< vector<double> > newMatrixsArray;
        initMatrix(newMatrixsArray, order, order);

        printf("size1 = %d, size2 = %d\n", order, order2);
        for(int row = 0; row < order; row++){
            for(int col = 0; col < order; col++){
                newMatrixsArray[row][col] = otherMatrix[row][col] + this->matrix[row][col];
            }
        }
        newMatrix->setMatrix(newMatrixsArray);
        return newMatrix->getMatrix();
    }
    
    // find the determinant of the matrix
    double findDeterminant(){
        return det(rows, matrix);
    }
    
    // find the trace of the matrix
    double find_trace(){
        double trace = 0;
        for(int diagonal = 0; diagonal < rows; diagonal++){
            trace += matrix[diagonal][diagonal];
        }
        return trace;
    }

    // find the transpose matrix
    vector< vector<double> > transpose(){
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
    // multiply the matrix with a given matrix and put the result in a new matrix
    vector< vector<double> > multiply( vector< vector< double> > otherMatrix){
        // rows & columns of the other matrix
        int otherRows = otherMatrix.size();
        int otherColumns = otherMatrix.front().size();
        // rows & columns of the resulting matrix
        int newRows = SquareMatrix::rows;
        int newColumns = otherColumns;
        // new matrix
        vector< vector<double> > newMatrix;
        initMatrix(newMatrix, newRows, newColumns);
        // Multiplying matrix a and b and storing in array mult.
        for(int i = 0; i < SquareMatrix::rows; ++i)
            for(int j = 0; j < otherColumns; ++j)
                for(int k = 0; k < SquareMatrix::columns; ++k){
                    newMatrix[i][j] += SquareMatrix::matrix[i][k] * otherMatrix[k][j];
                }
        // finally get the resulting matrix
        return newMatrix;
    }
 

    // end of functions, well I lied :)    
    ////////////////

private:
    // da matrix blin
    std::vector< std::vector<double> > matrix;
    // rows & columns blyat
    int rows;
    int columns;
    string matrixName;

    // determinant finder, it's private so the object function call is not parameterized :)
    // otherwise it'll get messy like a bee kingdom
    double det(int rows, std::vector<std::vector<double>> mainMatrix){ //wondering why called mainMatrix
        int cols = rows; // for readablity                 //scroll down to see some messed up blin 
        double answer = 0;
        if(rows == 2){
            //answer += ( mainMatrix[0][0] * mainMatrix[1][1] ) - ( mainMatrix[1][0] * mainMatrix[0][1] );
            //return answer;
            return ( mainMatrix[0][0] * mainMatrix[1][1] ) - ( mainMatrix[1][0] * mainMatrix[0][1] );
        }
            
        else if (rows > 2){

            int newRows, newCols;
            int cols = rows; // for readablity
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
        }
        // finally return the answer when the recieved matrix is 1*1
        return answer;
    
    }

    // initialse a matrix with zeros
    void initMatrix(vector< vector<double> > &mtrx, int rows, int columns){

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
    void printSpaces(string matrixName){
        int length = matrixName.length();
        for (int i = 0; i < length; i++ ){
            printf(" ");
        }

    }

};
// end of class
#endif 