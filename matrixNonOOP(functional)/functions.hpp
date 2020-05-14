#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

//this whole thing deals with square matrices so rows = columns
void readMatrix(int rows, vector<vector<double> >& matrix){
    int cols = rows; // for readablity
    for(int row = 0 ; row < rows ; row++){
        // temporary vector to store columns
        vector<double> tempVector;
        for(int col = 0 ; col < cols ; col++){
            // temporary variable to store element
            double temp;
            scanf("%lf", &temp);
            // add the temporary variable to the temporary vector
            tempVector.push_back(temp);

        }
        // add the temporary vector to the current row of the main 2D vector
        matrix.push_back(tempVector);   
        // and roll over if condition is true :) 
    }
}
// well it's a printing function no comments needed :)
void printMatrix(int rows, vector<vector<double>> matrix){
    int cols = rows; // for readablity
    for(int row = 0 ; row < rows ; row++){
        for(int col = 0 ; col < cols ; col++){
            printf("%lf ", matrix.at(row).at(col));
        }
        printf("\n");     
    }
}

// this dude generates an n*n matrix from an (n+1)*(n+1) matrix
vector<vector<double>> genMatrix(int rows, vector< vector<double> > mainMatrix){
    int newRows, newCols;
    int cols = rows; // for readablity
    newRows = rows - 0; // those two where rows - 1 then I realised that
    newCols = cols - 0; // this shit ain't working so....
    
    vector< vector<double> > newMatrix;

    // first row, alternating columns
    for(int mainCol = 0; mainCol < cols; mainCol++){
        // for future reads :)
        // I had to stop @ newRows - 1 so the index won't be out of range in the main matrix
        for(int newRow = 0; newRow < newRows - 1; newRow++){
            // temporary vector to store columns
            vector<double> tempVector;
            
            for(int newCol = 0; newCol < newCols; newCol++){
                
                if( newCol != mainCol  ){
                    //newMatrix[newRow][newCol] = mainMatrix[newRow+1][newCol+1];
                    double temp;
                    temp = mainMatrix[newRow+1][newCol];
                    tempVector.push_back(temp);

                }
            }
            // add the temporary vector to the current row of the main 2D vector
            newMatrix.push_back(tempVector);
            
        }
        return newMatrix;
    }

}


double det(int rows, vector<vector<double>> mainMatrix){ //wondering why called mainMatrix
    int cols = rows; // for readablity                 //scroll down to see some messed up shit 
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
        newCols = cols - 0; // this shit ain't working so....


        // first row, alternating columns
        for(int mainCol = 0; mainCol < cols; mainCol++){
            vector< vector<double> > newMatrix;
            // for future reads :)
            // I had to stop @ newRows - 1 so the index won't be out of range in the main matrix
            for(int newRow = 0; newRow < newRows - 1; newRow++){
                // temporary vector to store columns
                vector<double> tempVector;
                
                for(int newCol = 0; newCol < newCols; newCol++){
                    
                    if( newCol != mainCol ){
                        //newMatrix[newRow][newCol] = mainMatrix[newRow+1][newCol+1];
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