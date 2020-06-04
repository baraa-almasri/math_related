#include "SquareMatrix.hpp" // headers already included there :)
using namespace std;

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

// print spaces as same as matrix name, used in "readMatrix()"
void SquareMatrix::printSpaces(string matrixName){
    int length = matrixName.length();
    for (int i = 0; i < length; i++ ){
        printf(" ");
    }

}
