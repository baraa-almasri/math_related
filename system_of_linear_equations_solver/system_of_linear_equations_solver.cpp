#include <cstdio>
#include "functions.hpp"

int main(){

    int choice;
    printf("How many unknowns do want to find?\n");
    printf("1.Two,  2.Three\n");
    scanf("%i", &choice);

    switch(choice){
    case 1:
        twoUnknowns();
        break;
    case 2:
        threeUnknowns();
        break;
    default:
        printf("Hold up, Invalid choice !!!!\n");
        break;
    }

    return 0;
}
