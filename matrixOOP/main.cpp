#include <stdio.h>
#include <stdlib.h>
#include "Matrix.hpp"
#include <iostream>
// red color output
#define RED "\033[31m"
// reset color output
#define RESET "\033[0m"
    
int main(void){
    printf("enter number of square matrices you want to have:  ");
    int noOfMatrices;
    scanf("%d", &noOfMatrices);
    SquareMatrix *matricesList[noOfMatrices];// = new SquareMatrix[2];

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

    printf("available matrices:\n");
    for(SquareMatrix *matrix: matricesList){
        matrix->printMatrix();
    }
    // choose an opertation to be done on matrix(s)
    while(1){
        printf("Available operations(two matrices only):\n");
        printf("1. Addition\n");
        printf("2. Multiplication\n");
        printf("3. Transpose (of one matrix)\n");
        printf("4. Determinant (of one matrix)\n");
        printf("5. Trace (of one matrix)\n");
        printf("6. exit\n");
        int choice;
        printf("Enter your choice:  ");
        scanf("%d", &choice);
        if(choice == 6){
            printf("Have a nice day!\n");
            exit(0);
        }
        // set pointers to the matrices
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
        std::string newMatrixName;
        // choice maker, hmm....
        switch( choice ){
            case 1:
                // setting result matrix value
                newMatrixName = mtrxPtr1->getMatrixName() + " + " + mtrxPtr2->getMatrixName();
                tempMatrix = new SquareMatrix(order, newMatrixName);        
                tempMatrix->setMatrix( mtrxPtr1->add(mtrxPtr2) );
                // printing result matrix value
                tempMatrix->printMatrix();
                break;
            case 2:
                // setting result matrix value
                newMatrixName = mtrxPtr1->getMatrixName() + " x " + mtrxPtr2->getMatrixName();
                tempMatrix = new SquareMatrix(order, newMatrixName);        
                tempMatrix->setMatrix( mtrxPtr1->multiply(mtrxPtr2->getMatrix()) );
                // printing result matrix value
                tempMatrix->printMatrix();
                break;
            
            case 3:
                // setting result matrix value
                newMatrixName = mtrxPtr1->getMatrixName() + " Transpose " ;
                tempMatrix = new SquareMatrix(order, newMatrixName);        
                tempMatrix->setMatrix( mtrxPtr1->transpose() );
                // printing result matrix value
                tempMatrix->printMatrix();
                break;
            case 4:
                printf("\ndeterminant of matrix %s = %lf\n", mtrxPtr1->getMatrixName().c_str(), mtrxPtr1->findDeterminant());
                break;
            case 5:
                printf("\ntrace of matrix %s = %lf\n", mtrxPtr1->getMatrixName().c_str(), mtrxPtr1->find_trace());
                break;
            default:
                printf(RED);
                printf("Invalid choice!\n");
                printf(RESET);
                printf("Test");
        }

    }

 
    return 0;
}

