//matrix class by Baraa Al-Masri
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <iostream>

//this whole thing deals with square matrices so rows = columns
class Matrix{
public:
    // overloaded constructors
    Matrix(int order){
        setRows(order);
        setCols(order);
    }
    Matrix(){
        setRows(1);
        setCols(1);
    }
    // lame setters & getters
    void setRows(int rows){
        if(rows < 0)
            rows = 1;
        else
            this->rows = rows;
    }    
    int getRows(){
        return this->rows;
    }
    
    void setCols(int cols){
        if(cols < 0)
            cols = 1;
        else
            this->columns = cols;
    }    
    int getCols(){
        return this->columns;
    }
    //
    std::vector< std::vector<double> > getMatrix(){
        return matrix;
    }
    ////////

    // action functions :)
    // read values into the matrix
    void readMatrix(){
        printf("Enter matrix's elements:\n");

        int cols = Matrix::rows; // for readablity
        for(int row = 0 ; row < rows ; row++){
            // temporary vector to store columns
            std::vector<double> tempVector;
            for(int col = 0 ; col < cols ; col++){
                // temporary variable to store element
                double temp;
                printf("m%i%i = ", row+1,col+1);
                scanf("%lf", &temp);
                // add the temporary variable to the temporary vector
                tempVector.push_back(temp);

            }
            // add the temporary vector to the current row of the main 2D vector
            Matrix::matrix.push_back(tempVector);   
            // and roll over if condition is true :) 
        }
    }
    // well it's a printing function no comments needed :)
    void printMatrix(){
        printf("\nM = | ");
        int cols = Matrix::rows; // for readablity
        for(int row = 0 ; row < rows ; row++){
            for(int col = 0 ; col < cols ; col++){
                std::cout << Matrix::matrix[row][col] << "";
                std::cout << (col == cols-1 ? " |" : " ");
            }
            printf("\n");
            std::cout << (row != rows - 1 ? "    | " : "");
            
        }
        printf("\n");
    }
    void add(std::vector< std::vector<double> > anotherMatrix){
        int order = Matrix::matrix.size();
        int order2 = anotherMatrix.size();
        
        if(order != order2 ){
            printf("Hold up different orders no sum for you!\n");
            exit(0);
        }

        for(int row = 0; row < order; row++){
            for(int col = 0; col < order; col++){
                Matrix::matrix[row][col] += anotherMatrix[row][col];
            }
        }

    }
    
    // find determinant of a matrix
    double findDeterminant(){
        return det(rows, matrix);
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


};
