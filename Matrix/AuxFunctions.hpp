#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "SquareMatrix.hpp"
using namespace std; // standard namespace
// red color output
#define RED "\033[31m"
// reset color output
#define RESET "\033[0m"

// welcome screen
void welcome();
// enter matrices data
void matricesInput(SquareMatrix *matricesList[], int noOfMatrices);
// list available matrices
void listMatrices(SquareMatrix *matricesList[], int noOfMatrices);
// options menu
void operationsMenu(SquareMatrix *matricesList[], int noOfMatrices);