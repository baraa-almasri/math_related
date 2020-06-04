#ifndef SQUAREMATRIX_HPP
#define SQUAREMATRIX_HPP
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

    
    // read values into the matrix
    void readMatrix();

    // well it's a printing function no comments needed :)
    void printMatrix();

    // action functions :)

    // overloaded operators :) :) :)

    // add equals a matrix operator
    SquareMatrix operator += (SquareMatrix anotherMatrix);
    
    // muliply equals a matrix operator
    SquareMatrix operator *= (SquareMatrix anotherMatrix);

    // find the determinant of the matrix
    double findDeterminant();
    
    // find the trace of the matrix
    double findTrace();

    // find the transpose matrix
    vector< vector<double> > transpose();


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
    vector< vector<double> > getCofactor( vector< vector<double> > matrix, int order, int excludedRow, int excludedColumn);

    // initialse a matrix with zeros
    void initMatrix(vector< vector<double> > &mtrx, int rows, int columns);

    // print spaces as same as matrix name
    void printSpaces(string matrixName);

    // this function adds a matrix to the current matrix & returns the added matrix
    vector< vector<double> > add(SquareMatrix anotherMatrix);

    // multiply the matrix with a given matrix and put the result in a new matrix
    vector< vector<double> > multiply( SquareMatrix anotherMatrix);

};
// end of class

// some sort of linear search function

// returns memory address of the matching matrix name
// note that it need excepyiopn handelling in the main function :)
SquareMatrix *findMatrix(char matrixName[], SquareMatrix **array, int SIZE);

#endif 