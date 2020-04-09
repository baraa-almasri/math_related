#include<iostream>
using namespace std;
int main(){
	cout << "System of the form a1X + b1Y + c1Z = d1 , a2X + b2Y .... and so on\n"
		<< "Enter the coefficents\n"
		<< "AND DON'T ENTER THE SAME NUMBERS for both of the equations!!\n";
	
    double coefficients[3][3];
    double d[3];
    
    for(int rows(0) ; rows < 3 ; rows++){
        for(int cols(0) ; cols < 3 ; cols++){
            cout << (char)(97 + cols) << rows+1 <<" = ";
            cin >> coefficients[rows][cols];
        }
        cout << "d" << rows+1 << " = ";
        cin >> d[rows];
    }

/*  Two variables boiz :)
    //some headstarts a1 = eq1[0] , b2 = eq2[1] and so on ....
    //D = ( eq1[0]*eq2[1] ) - ( eq2[0]*eq1[1] );
    //Dx = ( eq1[2]*eq2[1] ) - ( eq2[2]*eq1[1] );
    //Dy = ( eq1[0]*eq2[2] ) - ( eq1[2]*eq2[0]);
*/

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
            
    cout << "X = " << (Dx/D) << endl;
    cout << "Y = " << (Dy/D) << endl;
    cout << "Z = " << (Dz/D) << endl;

    return 0;
}
