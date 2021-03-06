#include "Matrix.h" // headers already included there :)
using namespace std;
// red color output
#define RED "\033[31m"
// reset color output
#define RESET "\033[0m"

// constructors
Matrix::Matrix(int rows, int columns, string matrixName){
    setRows(rows);
    setCols(columns);
    initMatrix(this->matrix, rows, columns);
    initMatrix(this->zeroMatrix, rows, columns);
    setMatrixName(matrixName);
}
Matrix::Matrix(): Matrix(1, 1, "M"){
}

// lame setters & getters
Matrix Matrix::setRows(int rows){
    if(rows < 0)
        rows = 1;
    else
        this->rows = rows;

    // return object of the same class
    return *this;
}
int Matrix::getRows(){
    return this->rows;
}
//
Matrix Matrix::setCols(int cols){
    if(cols < 0)
        cols = 1;
    else
        this->columns = cols;
 
    // return object of the same class
    return *this;
}
int Matrix::getCols(){
    return this->columns;
}
//
Matrix Matrix::setMatrix(vector< vector<double> > matrix){
    this->matrix = matrix;

    return *this;
}
std::vector< std::vector<double> > Matrix::getMatrix(){
    return Matrix::matrix;
}
//
Matrix Matrix::setMatrixName(string matrixName){
    this->matrixName = matrixName;

    return *this;
}
string Matrix::getMatrixName(){
    return this->matrixName;
}
// 
vector<vector<double>> Matrix::getZeroMatrix(){
    return this->zeroMatrix;
}
//
string Matrix::getOrder(){
    return to_string(this->getRows()) + "*" + to_string(this->getCols());
}
////////


// I/O functions:

// read values into the matrix
void Matrix::readMatrix(){
    printf("Enter matrix %s elements:\n", this->matrixName.c_str());

    for(int row = 0 ; row < this->rows ; row++){
        for(int col = 0 ; col < this->columns ; col++){
            printf("%s%d%d = ", this->getMatrixName().c_str(), row+1, col+1);
            scanf("%lf", &matrix[row][col]);
        }
        printf("\n");
    }
}


// well it's a printing function no comments needed :)
void Matrix::printMatrix(){
    printf("\n%s = | ", matrixName.c_str());
    
    for(int row = 0 ; row < this->rows ; row++){
        for(int col = 0 ; col < this->columns ; col++){
            cout << this->matrix[row][col] << "";
            cout << (col == this->columns-1 ? " |" : " ");
        }
        printf("\n");
        if( row != rows - 1){
            printSpaces(matrixName); // print some spaces for formatting :)
            printf("   | ");
        }
    }
    printf("\n");
}


// print spaces as same as matrix name, used in "readMatrix()"
void Matrix::printSpaces(string matrixName){
    int length = matrixName.length();
    for (int i = 0; i < length; i++ ){
        printf(" ");
    }

}


// actual matrices operations functions:

// add equals a matrix operator
Matrix Matrix::operator += (Matrix anotherMatrix){
    // new matrix to hold the result
    Matrix newMatrix = *this; // has the info of the first operand so ther's no need for "initMatrix()"
    newMatrix.setMatrix( add(anotherMatrix) );
    // return the new matrix
    return newMatrix;
}


// multiply equals a matrix operator
Matrix Matrix::operator *= (Matrix anotherMatrix){
    // new matrix to hold the result
    Matrix newMatrix = *this; // has the info of the first operand so ther's no need for "initMatrix()"
    newMatrix.setMatrix( multiply(anotherMatrix) );
    // return the new matrix
    return newMatrix;
}


// multiply equals a scalar operator
Matrix Matrix::operator *= (double scalar){
    // new matrix to hold the result
    Matrix newMatrix = *this; // has the info of the first operand so ther's no need for "initMatrix()"
    newMatrix.setMatrix( scalarMultiply(scalar) );
    // return the new matrix
    return newMatrix;
}
//// end of overloaded operators


// find the transpose matrix
vector< vector<double> > Matrix::transpose(){
    int newRows = this->columns;
    int newColumns = this->rows;

    vector< vector<double> > transposedMatrix;
    initMatrix(transposedMatrix, newRows, newColumns);

    for(int row = 0; row < newRows; row++){
        for(int col = 0; col < newColumns; col++){
            transposedMatrix[row][col] = matrix[col][row];
        }
    }

    return transposedMatrix;
}


// if valid for addition return 1, for multiplication return 2, else return 0
int Matrix::checkOrders(Matrix mtrx1, Matrix mtrx2){
    // rows & columns of the first matrix
    int rows1 = mtrx1.getRows();
    int cols1 = mtrx1.getCols();
    // rows & columns of the second matrix
    int rows2 = mtrx2.getRows();
    int cols2 = mtrx2.getCols();  

    // rows & columns of the mtrx1*mtrx2
    // suppose newRows : rows1, rows3
    //         newCols : columns2, columns3
    //         Common  : rows2, columns1
    int rows3 = rows1;
    int cols3 = cols2;

    // return 1 for sum ability
    if( rows1 == rows2 && cols1 == cols2 ){ // bug to be fixed
                                           // for now just accept 1 or 2 for multiply
                                          // for future add a function to check matrix type
        return 1;
    }
    // return 2 for multiply ability
    else if( cols1 == rows2 ){

        return 2;
    }
    // return 0 for nothing available
    return 0;

}


// this function adds a matrix to the current matrix & returns the added matrix
vector< vector<double> > Matrix::add( Matrix anotherMatrix ){
    // orders check
    if(checkOrders(*this, anotherMatrix) != 1){
        puts(RED);
        puts("different orders so I ruined the answer :)");
        puts(RESET);
        return anotherMatrix.getZeroMatrix();
    }

    // anotherMatrix's 2D array
    vector< vector<double> > otherMatrix;
    otherMatrix = anotherMatrix.getMatrix();

    // new matrix
    vector< vector<double> > result;
    initMatrix(result, this->getRows(), this->getCols());

    for(int row = 0; row < this->getRows(); row++)
        for(int col = 0; col < this->getCols(); col++)
            result[row][col] = otherMatrix[row][col] + this->matrix[row][col];


    return result;
}


// multiply the matrix with a given matrix and put the result in a new matrix
vector< vector<double> > Matrix::multiply( Matrix anotherMatrix ){
    // the another matrix's vector
    vector< vector<double> > otherMatrix;
    otherMatrix = anotherMatrix.getMatrix();

    // remindeer!: rows & columns of the resulting matrix
    // suppose newRows : rows1, rows3
    //         newCols : columns2, columns3
    //         Common  : rows2, columns1

    if(checkOrders(*this, anotherMatrix) == 0){
        puts(RED);
        puts("different orders so I ruined the answer :)");
        puts(RESET);
        return anotherMatrix.getZeroMatrix();
    }
    // shared rows & columns
    int commons = this->columns;
    // new matrix
    vector< vector<double> > result;
    initMatrix(result, this->getRows(), anotherMatrix.getCols());

    // Multiplying matrix 1 and 2 and storing in matrix 3.
    for( int row3 = 0; row3 < this->getRows(); row3++ )
        for( int col3 = 0; col3 < anotherMatrix.getCols(); col3++ )
            for( int common = 0; common < commons; common++ )
                result[row3][col3] += this->matrix[row3][common] * otherMatrix[common][col3];

    // finally get the resulting matrix
    return result;
}


// multiply the matrix with a given number and put the result in a new matrix
vector< vector<double> > Matrix::scalarMultiply( double scalar ){
    // a matrix to store the result 
    vector< vector<double> > result;
    result = this->matrix;

    for( int row = 0; row < this->rows; row++ ){
        for( int col = 0; col < this->columns; col++ ){
            result[row][col] *= scalar;
        }
    }
    // finally get the result 
    return result;
}


// multiply the matrix with a given matrix and put the result in a new matrix
Matrix Matrix::power( double exponent ){
    Matrix *result = this;
    static int counter = 0;
    if (!(counter > 0)){
        // set name here so it wont be done several times :)
        string resultName = getMatrixName() + " ^ " + to_string(exponent); 
        result->setMatrixName(resultName);
    }

    if ( exponent == 1 ){       
        return *result;
    }
    counter++;        
    return *result *= power( exponent - 1);
}


// initialise a matrix with zeros
void Matrix::initMatrix(vector< vector<double> > &mtrx, int rows, int columns){

    for(int row = 0 ; row < rows ; row++){
        // temporary vector to store columns
        vector<double> temp;
        for(int col = 0 ; col < columns ; col++){
            // add the temporary variable to the temporary vector
            temp.push_back(0);
        }
        // add the temporary vector to the current row of the main 2D vector
        mtrx.push_back(temp);
    }
    //return mtrx; //blyat what was I thinking :)
}


// returns memory address of the matching matrix name
Matrix* Matrix::findMatrix(char matrixName[], Matrix **array, const int SIZE){ 
    for(int i = 0; i < SIZE; i++)
        if(array[i]->getMatrixName() == matrixName)
            return array[i];
        
    return nullptr;
}


/* return cofactor matrix of an element of a matrix */
vector< vector<double> > Matrix::getCofactor( vector< vector<double> > matrix, int order, int excludedRow, int excludedColumn){
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
