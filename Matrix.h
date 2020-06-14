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

#ifndef MATRIX_H
#define MATRIX_H
//matrix class by Baraa Al-Masri
#include <stdio.h>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Matrix{
public:
    // constructors
    Matrix(int rows, int columns, string matrixName);
    Matrix();
    // lame setters & getters
    Matrix setRows(int rows);
    int getRows();
    //
    Matrix setCols(int cols);
    int getCols();
    //
    Matrix setMatrix(vector< vector<double> > matrix);
    vector< vector<double> > getMatrix();
    //
    Matrix setMatrixName(string matrixName);
    string getMatrixName();
    //
    vector<vector<double>> getZeroMatrix();
    ////////
    // I/O functions:

    // read values into the matrix
    void readMatrix();
    // print values from matrix
    void printMatrix();

    // actual matrices operations functions

    // add equals a matrix operator
    Matrix operator += (Matrix anotherMatrix);
    // multiply equals a matrix operator
    Matrix operator *= (Matrix anotherMatrix);
    // multiply equals a scalar operator
    Matrix operator *= (double scalar);
    // find the transpose matrix
    vector< vector<double> > transpose();
    // power of matrix
    Matrix power(double exp);

    // static functions:

    // returns memory address of the matching matrix name
    static Matrix *findMatrix(char matrixName[], Matrix **array, int SIZE);

    // end of functions, well I lied :)    
    ////////////////

protected:
    // da matrix blin
    vector< vector<double> > matrix;
    // rows & columns blyat
    int rows;
    int columns;
    string matrixName;
    // zero matrix
    vector<vector<double>> zeroMatrix;
    // initialise a matrix with zeros
    void initMatrix(vector< vector<double> > &mtrx, int rows, int columns );
    // print spaces as same as matrix name
    void printSpaces(string matrixName);
    // check orders
    int checkOrders(Matrix mtrx1, Matrix mtrx2);
    // this function adds a matrix to the current matrix & returns the added matrix
    vector< vector<double> > add(Matrix anotherMatrix );
    // multiply the matrix with a given matrix and put the result in a new matrix
    vector< vector<double> > multiply( Matrix anotherMatrix );
    // multiply the matrix with a given number and put the result in a new matrix
    vector< vector<double> > scalarMultiply( double scalar );
};
// end of class

#endif // MATRIX_H