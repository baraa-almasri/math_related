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
#ifndef SQUAREMATRIX_H
#define SQUAREMATRIX_H
//matrix class by Baraa Al-Masri
#include <stdio.h>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
//this whole thing deals with square matrices so rows = columns
class SquareMatrix{
public:
    // constructors
    SquareMatrix(int order, string matrixName);
    SquareMatrix();

    // lame setters & getters
    SquareMatrix setRows(int rows);
    int getRows();

    SquareMatrix setCols(int cols);
    int getCols();
    //
    SquareMatrix setMatrix(vector< vector<double> > matrix);
    std::vector< std::vector<double> > getMatrix();
    //
    SquareMatrix setMatrixName(string matrixName);
    string getMatrixName();
    ////////

    // I/O functions:

    // read values into the matrix
    void readMatrix();

    // print values from matrix
    void printMatrix();

    // actual matrices operations functions

    // add equals a matrix operator
    SquareMatrix operator += (SquareMatrix anotherMatrix);

    // multiply equals a matrix operator
    SquareMatrix operator *= (SquareMatrix anotherMatrix);

    // multiply equals a scalar operator
    SquareMatrix operator *= (double scalar);

    // find the determinant of the matrix
    double determinant();

    // find the trace of the matrix
    double trace();

    // find the transpose matrix
    vector< vector<double> > transpose();

    // find the adjugate matrix
    vector< vector<double> > adjoint();

    // find the inverse matrix
    vector< vector<double> > inverse();

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
    // otherwise it'll get messy like a bee hive
    double det( std::vector<std::vector<double>> matrix, int rows );

    // cofactor function
    vector< vector<double> > getCofactor( vector< vector<double> > matrix, int order, int excludedRow, int excludedColumn );

    // initialse a matrix with zeros
    void initMatrix(vector< vector<double> > &mtrx, int rows, int columns );

    // print spaces as same as matrix name
    void printSpaces(string matrixName);

    // this function adds a matrix to the current matrix & returns the added matrix
    vector< vector<double> > add(SquareMatrix anotherMatrix );

    // multiply the matrix with a given matrix and put the result in a new matrix
    vector< vector<double> > multiply( SquareMatrix anotherMatrix );

    // multiply the matrix with a given number and put the result in a new matrix
    vector< vector<double> > scalarMultiply( double scalar );

};
// end of class

// returns memory address of the matching matrix name
SquareMatrix *findMatrix(char matrixName[], SquareMatrix **array, int SIZE);

#endif 