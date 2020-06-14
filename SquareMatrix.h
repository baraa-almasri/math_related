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
#include "Matrix.h"
using namespace std;
//this whole thing deals with square matrices so rows = columns
class SquareMatrix: public Matrix{
public:
    // constructors
    SquareMatrix(int order, string matrixName);
    SquareMatrix();
    
    // setters, getters
    vector<vector<double>> getIdentityMatrix();
    
    // actual matrices operations functions

    // find the determinant of the matrix
    double determinant();

    // find the trace of the matrix
    double trace();

    // find the adjugate matrix
    vector< vector<double> > adjoint();

    // find the inverse matrix
    vector< vector<double> > inverse();

    // end of functions, well I lied :)    
    ////////////////

private:
    // identity matrix
    vector<vector<double>> identityMatrix;

    // determinant finder, it's private so the object function call is not parameterized :)
    // otherwise it'll get messy like a bee hive
    double det( vector<vector<double>> matrix, int rows );

    // generate an identity matrix coressponding to the order of the original matrix
    void genIdentity();

    // cofactor function
    vector< vector<double> > getCofactor( vector< vector<double> > matrix, int order, int excludedRow, int excludedColumn );

};
// end of class
#endif // SQUAREMATRIX_H