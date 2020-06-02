#include <cstdio>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

void readMatrix(int rows, vector<vector<double> >& matrix){
    int cols = rows; // for readablity
    for(int row = 0 ; row < rows ; row++){
        // temporary vector to store columns
        vector<double> tempVector;
        for(int col = 0 ; col < cols ; col++){
            // temporary variable to store element
            double temp;
            printf("a%i%i = ", row+1, col+1);
            scanf("%lf", &temp);
            // add the temporary variable to the temporary vector
            tempVector.push_back(temp);

        }
        // add the temporary vector to the current row of the main 2D vector
        matrix.push_back(tempVector);   
        // and roll over if condition is true :) 
    }
}
// the actual determinant finder :)
double det(int rows, std::vector<std::vector<double>> mainMatrix){ //wondering why called mainMatrix
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

void solveSystem(int order){
    printf("System of the form a1X1 + a2X2 + .... + anXn = b\n");
	printf("Enter the coefficents\n"); 
	// the augmented matrix, well part of it	
    vector<vector<double>> matrix;
	readMatrix(order, matrix);
  	
  	// constants vector(math vector not that STL)
    double constants[order];
    for(int moo = 0; moo < order; moo++){
        printf("b%i = ", moo+1);
        scanf("%lf", &constants[moo]);
    }

    //Using Carmer's rule....
    double D;
    D = det(order, matrix); 

    // since it's a system for n variables we're gonna need a vector to store those variables
    vector<double> rawVariables; // you'll find why it's called raw :) in line 
    // but first we need matrices with the constant column so....
    vector<vector<double>> tempMatrix;
    tempMatrix = matrix;
    for(int column = 0; column < order; column++){
        // now swinging between rows
        for(int row = 0; row < order; row++){
            tempMatrix[row][column] = constants[row];   
        }
        rawVariables.push_back( det(order, tempMatrix) );

        tempMatrix = matrix;
    }
    // k because I couldn't find a better name, you got a better name suggest it I'm all ears
    for(int k = 0; k < order; k++){
        printf("var%i = %lf \n",k+1 , rawVariables[k]/D);
    }
  
  /*for(int k : rawVariables){
        printf("var = %lf \n" , k/D);
    }
  */
 
}
