/*-----------------------------------------------------------------------------
 *Created by Baraa Al-Masri | E-Mail : baraa.masri@asu.edu.jo | Twitter : @baraa_c137
 *Grab me a cup of coffee : https://www.paypal.me/baraamasri
 *Contributer: Baraa Al-Masri
 *------------------------------------------------------------------------------
 *This program is free software: you can redistribute it and/or modify
 *it under the terms of the GNU General Public License as published by
 *the Free Software Foundation, either version 2 of the License, or
 *(at your option) any later version.
 *This program is distributed in the hope that it will be useful,
 *but WITHOUT ANY WARRANTY; without even the implied warranty of
 *MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *GNU General Public License for more details.
 *You should have received a copy of the GNU General Public License
 *along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *-------------------------------------------------------------------------------
 */
#include "SquareMatrix.h" // headers already included there :)
using namespace std;
// red color output
#define RED "\033[31m"
// reset color output
#define RESET "\033[0m"

// constructors
SquareMatrix::SquareMatrix(int order, string matrixName): Matrix(order, order, matrixName){
    /*setRows(order);
    setCols(order);
    initMatrix(SquareMatrix::matrix, order, order);
    setMatrixName(matrixName);
*/}
SquareMatrix::SquareMatrix(): Matrix(){
  /*  setRows(1);
    setCols(1);
    initMatrix(SquareMatrix::matrix, 1, 1);
    setMatrixName("M");
*/}

// actual matrices operations functions:
// square matrix specials

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
    // cofactored matrix  
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
    // if order is 1x1 return the oly element in the matrix
    if( order == 1){
        return matrix[0][0];
    }
    // if order is 2x2 calcuate the order in the basic way
    if( order == 2 ){
        return ( matrix[0][0] * matrix[1][1] ) - ( matrix[1][0] * matrix[0][1] );
    }
    // targeted first row 
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
