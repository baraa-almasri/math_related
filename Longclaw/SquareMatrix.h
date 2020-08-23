#ifndef SQUAREMATRIX_H
#define SQUAREMATRIX_H
//matrix class by Baraa Al-Masri
#include <stdio.h>
#include <vector>
using std::vector;
#include <math.h>
#include <stdlib.h>
#include "Matrix.h"
#include <string>
using std::string;

//this whole thing deals with square matrices so rows = columns
class SquareMatrix: public Matrix{
public:
    // constructors
    SquareMatrix(int, string);
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
    double det( vector<vector<double>>, int );

    // generate an identity matrix coressponding to the order of the original matrix
    void genIdentity();

};
// end of class
#endif // SQUAREMATRIX_H
