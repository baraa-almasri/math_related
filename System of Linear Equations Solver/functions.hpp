#include <cstdio>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

void readMatrix( vector<vector<double> >& matrix, int order ){
    for(int row = 0 ; row < order ; row++){
        // temporary vector to store columns
        vector<double> tempVector;
        for(int col = 0 ; col < order ; col++){
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
    	printf("\n");
    }
}

/* return cofactor matrix of an element of a matrix */
vector< vector<double> > getCofactor( vector< vector<double> > matrix, int order, int excludedRow, int excludedColumn){
	/* coofactored matrix  */
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
double det( vector<vector<double>> matrix, int order ){ 
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
void enterAugmentedMatrixData(int order, vector< vector<double> > &coefficents, vector<double> &constants){
	puts("System of the form a1X1 + a2X2 + .... + anXn = b\n");
	puts("Enter the coefficents\n"); 
	// the augmented matrix, well part of it	
	readMatrix( coefficents, order );
  	
	puts("enter constants:\n");
  	// constants vector(math vector not that STL)
    for(int moo = 0; moo < order; moo++){
       	printf("b%i = ", moo+1);
		double temp;
		scanf("%lf", &temp);
		constants.push_back(temp);
    }

}
/* find solution of system of n linear equations */
void solveSystem(int order){
	//Using Carmer's rule....
	vector< vector<double> > coefficents; 
	vector<double> constants;
	enterAugmentedMatrixData(order, coefficents, constants);	
	double D;
	D = det( coefficents, order ); 

	// since it's a system for n variables we're gonna need a vector to store those variables
	vector<double> rawVariables; // you'll find why it's called raw :) in line 111
	// but first we need matrices with the constant column so....
	vector<vector<double>> tempMatrix;
	tempMatrix = coefficents;
	for(int column = 0; column < order; column++){
		// now swinging between rows
		for(int row = 0; row < order; row++){
        		tempMatrix[row][column] = constants[row];   
   		}
		rawVariables.push_back( det( tempMatrix, order ) );

		tempMatrix = coefficents;
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
