#include <iostream>
#include <stdio.h>


void twoUnknowns(){
    printf("System of the form a1X + b1Y = c1 , a2X + b2Y .... and so on, sorry I'm board\n");
	printf("Enter the coefficents\n"); 
	printf("AND DON'T ENTER THE SAME NUMBERS for both of the equations!!\n");
	
    double coefficients[2][2];
    double c[2];
    
    for(int rows(0) ; rows < 2 ; rows++){
        for(int cols(0) ; cols < 2 ; cols++){
            printf("%c%i = ", (char)(97 + cols), rows+1);
            std::cin >> coefficients[rows][cols];
        }
        printf("c%i = ", rows+1);
        std::cin >> c[rows];
    }

    //Using Carmer's rule....
    double D, Dx, Dy, Dz;

    D = (coefficients[0][0]*coefficients[1][1]) - (coefficients[1][0]*coefficients[0][1]);
    Dx = (c[0]*coefficients[1][1]) - (c[1]*coefficients[0][1]);
    Dy = (coefficients[0][0]*c[1]) - (c[0]*coefficients[1][0]);
    
    printf("X = %lf\n", Dx/D);
    printf("Y = %lf\n", Dy/D);
    
}
void threeUnknowns(){

    printf("System of the form a1X + b1Y + c1Z = d1 , a2X + b2Y .... and so on\n");
	printf("Enter the coefficents\n"); 
	printf("AND DON'T ENTER THE SAME NUMBERS for both of the equations!!\n");
	
    double coefficients[3][3];
    double d[3];
    
    for(int rows(0) ; rows < 3 ; rows++){
        for(int cols(0) ; cols < 3 ; cols++){
            printf("%c%i = ", (char)(97 + cols), rows+1);
            std::cin >> coefficients[rows][cols];
        }
        printf("d%i = ", rows+1);
        std::cin >> d[rows];
    }

    //Using Carmer's rule....

    double D, Dx, Dy, Dz;
    
    D = (coefficients[0][0]*coefficients[1][1]*coefficients[2][2])
        +(coefficients[0][1]*coefficients[1][2]*coefficients[2][0])
        +(coefficients[0][2]*coefficients[1][0]*coefficients[2][1])
        -(coefficients[0][0]*coefficients[1][2]*coefficients[2][1])
        -(coefficients[0][1]*coefficients[1][0]*coefficients[2][2])
        -(coefficients[0][2]*coefficients[1][1]*coefficients[2][0]);
    
    Dx = (d[0]*coefficients[1][1]*coefficients[2][2])
        +(coefficients[0][1]*coefficients[1][2]*d[2])
        +(coefficients[0][2]*d[1]*coefficients[2][1])
        -(d[0]*coefficients[1][2]*coefficients[2][1])
        -(coefficients[0][1]*d[1]*coefficients[2][2])
        -(coefficients[0][2]*coefficients[1][1]*d[2]);
    
    Dy = (coefficients[0][0]*d[1]*coefficients[2][2])
        +(d[0]*coefficients[1][2]*coefficients[2][0])
        +(coefficients[0][2]*coefficients[1][0]*d[2])
        -(coefficients[0][0]*coefficients[1][2]*d[2])
        -(d[0]*coefficients[1][0]*coefficients[2][2])
        -(coefficients[0][2]*d[1]*coefficients[2][0]);

    Dz = (coefficients[0][0]*coefficients[1][1]*d[2])
        +(coefficients[0][1]*d[1]*coefficients[2][0])
        +(d[0]*coefficients[1][0]*coefficients[2][1])
        -(coefficients[0][0]*d[1]*coefficients[2][1])
        -(coefficients[0][1]*coefficients[1][0]*d[2])
        -(d[0]*coefficients[1][1]*coefficients[2][0]);

    printf("X = %lf\n", Dx/D);
    printf("Y = %lf\n", Dy/D);
    printf("Z = %lf\n", Dz/D);

}

