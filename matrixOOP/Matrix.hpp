#ifndef MATRIX_HPP
#define MATRIX_HPP
//matrix class by Baraa Al-Masri
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;
//this whole thing deals with square matrices so rows = columns
class squareMatrix{
public:
    // overloaded constructors
    squareMatrix(int order){
        setRows(order);
        setCols(order);
        initMatrix(squareMatrix::matrix, order, order);
    }
    squareMatrix(){
        setRows(1);
        setCols(1);
        initMatrix(squareMatrix::matrix, 1, 1);
    }
    /*squareMatrix(vector< vector<double> > otherMatrix, int order){
        squareMatrix(order);
        squareMatrix::matrix = otherMatrix;
    }*/
    // lame setters & getters
    squareMatrix setRows(int rows){
        if(rows < 0)
            rows = 1;
        else
            this->rows = rows;

        return *this;
    }    
    int getRows(){
        return this->rows;
    }
    
    squareMatrix setCols(int cols){
        if(cols < 0)
            cols = 1;
        else
            this->columns = cols;
        
        return *this;
    }    
    int getCols(){
        return this->columns;
    }
    //
    squareMatrix setMatrix(vector< vector<double> > mtrx){
        squareMatrix::matrix = mtrx;
        return *this;
    }
    std::vector< std::vector<double> > getMatrix(){
        return squareMatrix::matrix;
    }
    ////////

    
    // read values into the matrix
    void readMatrix(){
        printf("Enter matrix's elements:\n");

        int cols = squareMatrix::rows; // for readablity
        for(int row = 0 ; row < rows ; row++){
            for(int col = 0 ; col < cols ; col++){
                printf("m%d%d = ", row+1, col+1);
                scanf("%lf", &matrix[row][col]);               
            }
            printf("\n");
        }
    }
    // well it's a printing function no comments needed :)
    void printMatrix(){
        printf("\nMatrix's elements:");
        printf("\n| ");
        int cols = squareMatrix::rows; // for readablity
        for(int row = 0 ; row < rows ; row++){
            for(int col = 0 ; col < cols ; col++){
                std::cout << squareMatrix::matrix[row][col] << "";
                std::cout << (col == cols-1 ? " |" : " ");
            }
            printf("\n");
            std::cout << (row != rows - 1 ? "| " : "");
            
        }
        printf("\n");
    }
    // action functions :)
    // this function adds a matrix to the current matrix
    void add(std::vector< std::vector<double> > anotherMatrix){
        int order = squareMatrix::matrix.size();
        int order2 = anotherMatrix.size();
        
        if(order != order2 ){
            printf("Hold up different orders no sum for you!\n");
            exit(0);
        }

        for(int row = 0; row < order; row++){
            for(int col = 0; col < order; col++){
                squareMatrix::matrix[row][col] += anotherMatrix[row][col];
            }
        }

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
        int new_rows = squareMatrix::columns;
        int new_columns = squareMatrix::rows;
        
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
        int newRows = squareMatrix::rows;
        int newColumns = otherColumns;
        // new matrix
        vector< vector<double> > newMatrix;
        initMatrix(newMatrix, newRows, newColumns);
        // Multiplying matrix a and b and storing in array mult.
        for(int i = 0; i < squareMatrix::rows; ++i)
            for(int j = 0; j < otherColumns; ++j)
                for(int k = 0; k < squareMatrix::columns; ++k){
                    newMatrix[i][j] += squareMatrix::matrix[i][k] * otherMatrix[k][j];
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

};
// end of class
#endif 