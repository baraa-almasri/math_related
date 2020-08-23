#ifndef MATRIX_H
#define MATRIX_H
//matrix class by Baraa Al-Masri
#include <stdio.h>
#include <vector>
using std::vector;
#include <math.h>
#include <stdlib.h>
#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::endl;

class Matrix{
public:
    // constructors
    Matrix(int, int, string);
    Matrix();

    // lame setters & getters
    Matrix setRows(int);
    int getRows();
    //
    Matrix setCols(int);
    int getCols();
    //
    Matrix setMatrix(vector< vector<double> >);
    vector< vector<double> > getMatrix();
    //
    Matrix setMatrixName(string);
    string getMatrixName();
    //
    vector<vector<double>> getZeroMatrix();
    //
    string getOrder();
    // I/O functions:
    
    // read values into the matrix
    void readMatrix();

    // print values from matrix
    void printMatrix();

    // actual matrices operations functions

    // add equals a matrix operator
    Matrix operator += (Matrix);

    // multiply equals a matrix operator
    Matrix operator *= (Matrix);

    // multiply equals a scalar operator
    Matrix operator *= (double);

    // find the transpose matrix
    vector< vector<double> > transpose();

    // power of matrix
    Matrix power(double);
    
    // cofactor function
    vector< vector<double> > getCofactor( vector< vector<double> >, int, int, int );

    // static functions:

    // returns memory address of the matching matrix name
    static Matrix *findMatrix(char[], Matrix **, int);
    
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
    void initMatrix(vector< vector<double> > &, int, int );

    // print spaces as same as matrix name
    void printSpaces(string);

    // check orders
    int checkOrders(Matrix, Matrix);

    // this function adds a matrix to the current matrix & returns the added matrix
    vector< vector<double> > add(Matrix);

    // multiply the matrix with a given matrix and put the result in a new matrix
    vector< vector<double> > multiply( Matrix );

    // multiply the matrix with a given number and put the result in a new matrix
    vector< vector<double> > scalarMultiply( double );
};
// end of class

#endif // MATRIX_H
