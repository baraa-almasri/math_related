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
void welcome(){
    // clear screen equivalent
    cout << string(100, '\n');
    puts("#     ###  #  #  ###   ### #     ##  #     #");
    puts("#    #   # ## # #     #    #    #  # #  #  #");
    puts("#    #   # # ## #  ## #    #    #### # # # #");
    puts("####  ###  #  #  ###   ### #### #  #  #   #");
    
    puts("\n\tLongcalw Terminal Matrix Program");
    puts("\n\tBy Baraa Al-Masri . version 0.7 ");
    
    hold();
    clear();
}

// enter matrices data
void matricesInput(SquareMatrix *matricesList[], int noOfMatrices){

    int order;
    // enter matrices details
    for (int index = 0; index < noOfMatrices; index++){
        printf("enter order of matrix %d: ", index + 1);
        scanf("%d", &order);
        printf("enter name of matrix %d: ", index + 1);
        char matrixName[99];
        scanf("%s", &matrixName);
        printf("\n");
        // instatiate the object with the given data
        matricesList[index] = new SquareMatrix(order, matrixName);
        // enter matrix's elements
        matricesList[index]->readMatrix();
    }

}

// list available matrices
void listMatrices(SquareMatrix *matricesList[], int noOfMatrices){
    printf("available matrices:\n");
    for(int index = 0; index < noOfMatrices; index++){
        matricesList[index]->printMatrix();
    }
}

// menu
int choiceMenu(){
    printf("Available operations(two operand matrices max):\n");
    printf("1. Addition\n");
    printf("2. Multiplication\n");
    printf("3. Scalar Multiplication\n");
    printf("4. Matrix Transpose\n");
    printf("5. Matrix Determinant\n");
    printf("6. Matrix Trace\n");
    printf("7. Adjoint Matrix\n");
    printf("8. Matrix Inverse\n");
    printf("9. exit\n");
    int choice;
    printf("Enter your choice:  ");
    scanf("%d", &choice);
    if(choice == 9){
        printf("Have a nice day!\n");
        exit(0);
    }
    return choice;
}

// operations menu
void operationsMenu(SquareMatrix *matricesList[], int noOfMatrices){
    // choose an operation to be done on matrix(s)
    while(1){
        int choice = choiceMenu();
        // set pointers to the operand matrices
        SquareMatrix *mtrxPtr1, *mtrxPtr2;

        printf("enter matrix(s) name(s) to operate on(from the list you provided earlier):\n");
        printf(RED);
        printf("please don't enter a name that doesn't belong to the list, or the program will crash :(\n");
        printf(RESET);
        // name of the first operand matrix
        char name1[99];
        printf("name1:  ");
        scanf("%s", &name1);
        // set matrix pointer as matrix name
        mtrxPtr1 = findMatrix(name1, matricesList, noOfMatrices);

        if (choice < 3){
            // name of the second operand matrix(well if exists)
            char name2[99];
            printf("name2:  ");
            scanf("%s", &name2);
            // set matrix pointer as matrix name
            mtrxPtr2 = findMatrix(name2, matricesList, noOfMatrices);
        }
        // a matrix to hold the reulting answers & its name
        SquareMatrix *tempMatrix;
        string newMatrixName;
        // choice maker, hmm....
        switch( choice ){
            case 1:
                // setting result matrix values
                newMatrixName = mtrxPtr1->getMatrixName() + " + " + mtrxPtr2->getMatrixName();
                tempMatrix = new SquareMatrix(mtrxPtr1->getRows(), newMatrixName);
                tempMatrix->setMatrix( (*mtrxPtr1 += *mtrxPtr2).getMatrix() )  ;
                // printing result matrix value
                tempMatrix->printMatrix();
                break;
            case 2:
                // setting result matrix values
                newMatrixName = mtrxPtr1->getMatrixName() + " * " + mtrxPtr2->getMatrixName();
                tempMatrix = new SquareMatrix(mtrxPtr1->getRows(), newMatrixName);
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
                tempMatrix = new SquareMatrix(mtrxPtr1->getRows(), newMatrixName);
                tempMatrix->setMatrix( (*mtrxPtr1 *= scalar).getMatrix() );
                // printing result matrix value
                tempMatrix->printMatrix();
                break;
            case 4:
                // setting result matrix values
                newMatrixName = mtrxPtr1->getMatrixName() + " Transpose " ;
                tempMatrix = new SquareMatrix(mtrxPtr1->getRows(), newMatrixName);
                tempMatrix->setMatrix( mtrxPtr1->transpose() );
                // printing result matrix value
                tempMatrix->printMatrix();
                break;
            case 5:
                printf("\ndet(%s) = %lf\n\n", mtrxPtr1->getMatrixName().c_str(), mtrxPtr1->determinant());
                break;
            case 6:
                printf("\ntrace(%s) = %lf\n\n", mtrxPtr1->getMatrixName().c_str(), mtrxPtr1->trace());
                break;
            case 7:
                // setting result matrix values
                newMatrixName = "adj(" + mtrxPtr1->getMatrixName() + ") ";
                tempMatrix = new SquareMatrix(mtrxPtr1->getRows(), newMatrixName);
                tempMatrix->setMatrix( mtrxPtr1->adjoint() );
                // printing result matrix value
                tempMatrix->printMatrix();
                break;

            case 8:
                // setting result matrix values
                newMatrixName = "inverse(" + mtrxPtr1->getMatrixName() + ") ";
                tempMatrix = new SquareMatrix(mtrxPtr1->getRows(), newMatrixName);
                tempMatrix->setMatrix( mtrxPtr1->inverse() );
                // printing result matrix value
                tempMatrix->printMatrix();
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