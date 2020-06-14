#ifndef AUXFUNCTIONS_H
#define AUXFUNCTIONS_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "SquareMatrix.h"
using namespace std; // standard namespace
// red color output
#define RED "\033[31m"
// reset color output
#define RESET "\033[0m"

// necessary for some reason :)
void hold(){
    puts("\n\tpress enter to continue....");
    // getchar is used to input a character
    while(getchar() != '\n');
}

// cross platform clear screen
void clear(){
    int counter = 0;
    while(counter < 100){
        puts("\n");
        counter++;
    }
}

// welcome screen
void printWelcomeScreen(){
    // clear screen equivalent
    cout << string(100, '\n');
    puts("#     ###  #  #  ###   ### #     ##  #     #");
    puts("#    #   # ## # #     #    #    #  # #  #  #");
    puts("#    #   # # ## #  ## #    #    #### # # # #");
    puts("####  ###  #  #  ###   ### #### #  #  #   #");

    puts("\n\tLongcalw Terminal Matrix Program");
    puts("\n\tBy Baraa Al-Masri . version 0.8 ");

    hold();
    clear();
}

// enter matrices data
void matricesInput(Matrix *matricesList[], int noOfMatrices){

    int rows, columns;
    // enter matrices details
    for (int index = 0; index < noOfMatrices; index++){
        printf("enter order of matrix %d:\n", index + 1);
        printf("rows = ");
        scanf("%d", &rows);
        printf("columns = ");
        scanf("%d", &columns);

        printf("enter name of matrix %d: ", index + 1);
        char matrixName[99];
        scanf("%s", &matrixName);
        printf("\n");
        // instatiate the object with the given data
        if( rows == columns){
            matricesList[index] = new Matrix(rows, columns, matrixName);
            matricesList[index] = (SquareMatrix*)matricesList[index];
        }
        else{
            matricesList[index] = new Matrix(rows, columns, matrixName);
        }
        // enter matrix's elements
        matricesList[index]->readMatrix();
    }

}

// list available matrices
void listMatrices(Matrix *matricesList[], int noOfMatrices){
    printf("available matrices:\n");
    for(int index = 0; index < noOfMatrices; index++){
        matricesList[index]->printMatrix();
    }
}

// menu
int choiceMenu(){
    puts("Available operations(two operand matrices max):\n");
    puts("1. Addition");
    puts("2. Multiplication");
    puts("3. Scalar Multiplication");
    puts("4. Matrix Transpose");
    puts("5. Matrix Determinant");
    puts("6. Matrix Trace");
    puts("7. Adjoint Matrix");
    puts("8. Matrix Inverse");
    puts("9. Power of matrix");
    puts("10. exit");
    int choice;
    printf("Enter your choice:  ");
    scanf("%d", &choice);
    if(choice == 10){
        printf("Have a nice day!\n");
        exit(0);
    }
    return choice;
}

// operations menu
void operationsMenu(Matrix *matricesList[], int noOfMatrices){
    // choose an operation to be done on matrix(s)
    while(1){
        int choice = choiceMenu();
        // set pointers to the operand matrices
        SquareMatrix *mtrxPtr1, *mtrxPtr2;
        Matrix *nonSquarePtr1 = mtrxPtr1, *nonSquarePtr2 = mtrxPtr2;

        printf("enter matrix(s) name(s) to operate on(from the list you provided earlier):\n");
        printf(RED);
        printf("please don't enter a name that doesn't belong to the list, or the program will crash :(\n");
        printf(RESET);
        // name of the first operand matrix
        char name1[99];
        printf("name1:  ");
        scanf("%s", &name1);
        // set matrix pointer as matrix name
        mtrxPtr1 = (SquareMatrix*)SquareMatrix::findMatrix(name1, matricesList, noOfMatrices);

        if (choice < 3){
            // name of the second operand matrix(well if exists)
            char name2[99];
            printf("name2:  ");
            scanf("%s", &name2);
            // set matrix pointer as matrix name
            mtrxPtr2 = (SquareMatrix*)SquareMatrix::findMatrix(name2, matricesList, noOfMatrices);
        }
        // a matrix to hold the reulting answers & its name
        Matrix *tempMatrix;
        string newMatrixName;
        // choice maker, hmm....
        switch( choice ){
            case 1:
                // setting result matrix values
                newMatrixName = mtrxPtr1->getMatrixName() + " + " + mtrxPtr2->getMatrixName();
                tempMatrix = new Matrix(mtrxPtr1->getRows(), mtrxPtr1->getCols(), newMatrixName);
                tempMatrix->setMatrix( (*mtrxPtr1 += *mtrxPtr2).getMatrix() )  ;
                // printing result matrix value
                tempMatrix->printMatrix();
                break;
            case 2:
                // setting result matrix values
                newMatrixName = mtrxPtr1->getMatrixName() + " * " + mtrxPtr2->getMatrixName();
                tempMatrix = new Matrix(mtrxPtr1->getRows(), mtrxPtr2->getCols(), newMatrixName);
                tempMatrix->setMatrix( (*mtrxPtr1 *= *mtrxPtr2).getMatrix() );
                // printing result matrix value
                tempMatrix->printMatrix();
                break;
            case 3:
                printf("enter a scalar:  ");
                double scalar;
                scanf("%lf", &scalar);
                // setting result matrix values
                newMatrixName = mtrxPtr1->getMatrixName() + " * " + to_string(scalar);
                tempMatrix = new Matrix(mtrxPtr1->getRows(), mtrxPtr1->getCols(), newMatrixName);
                tempMatrix->setMatrix( (*mtrxPtr1 *= scalar).getMatrix() );
                // printing result matrix value
                tempMatrix->printMatrix();
                break;
            case 4:
                // setting result matrix values
                newMatrixName = mtrxPtr1->getMatrixName() + " Transpose " ;
                tempMatrix = new Matrix(mtrxPtr1->getRows(), mtrxPtr1->getCols(), newMatrixName);
                tempMatrix->setMatrix( mtrxPtr1->transpose() );
                // printing result matrix value
                tempMatrix->printMatrix();
                break;
            case 5:
                mtrxPtr1 = (SquareMatrix*)mtrxPtr1;
                printf("\ndet(%s) = %lf\n\n", mtrxPtr1->getMatrixName().c_str(), mtrxPtr1->determinant());
                break;
            case 6:

                mtrxPtr1 = (SquareMatrix*)mtrxPtr1;
                printf("\ntrace(%s) = %lf\n\n", mtrxPtr1->getMatrixName().c_str(), mtrxPtr1->trace());
                break;
            case 7:
                mtrxPtr1 = (SquareMatrix*)mtrxPtr1;
                // setting result matrix values
                newMatrixName = "adj(" + mtrxPtr1->getMatrixName() + ") ";
                tempMatrix = new SquareMatrix(mtrxPtr1->getRows(), newMatrixName);
                tempMatrix->setMatrix( mtrxPtr1->adjoint() );
                // printing result matrix value
                tempMatrix->printMatrix();
                break;

            case 8:
                mtrxPtr1 = (SquareMatrix*)mtrxPtr1;
                // setting result matrix values
                newMatrixName = "inverse(" + mtrxPtr1->getMatrixName() + ") ";
                tempMatrix = new SquareMatrix(mtrxPtr1->getRows(), newMatrixName);
                tempMatrix->setMatrix( mtrxPtr1->inverse() );
                // printing result matrix value
                tempMatrix->printMatrix();
                break;
            
            case 9:
                printf("enter power:  ");
                double power;
                scanf("%lf", &power);
                mtrxPtr1->power(power).printMatrix();
                break;

            default:
                printf(RED);
                printf("Invalid choice!\n");
                printf(RESET);
                printf("Test");
        }
    }
}

#endif
