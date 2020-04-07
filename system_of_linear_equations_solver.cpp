#include<iostream>
using namespace std;
int main(){
	cout << "System of the form a1X + b1Y = c1 , a2X + b2Y = c2\n"
		<< "Enter the coefficents\n"
		<< "AND DON'T ENTER THE SAME NUMBERS for both of the equations!!\n";
	
	double eq1[3] ,eq2[3];

    for ( int lol = 0 ; lol < 3 ; lol++ ){
        //do it later please
    cout << (char)(97 + lol) << "1 = ";
        cin >> eq1[lol];
    }
    for ( int lol = 0 ; lol < 3 ; lol++ ){
        cout << (char)(97 + lol) << "2 = ";
        cin >> eq2[lol];
    }

    //Using Carmer's rule....
    double D , Dx , Dy;
    //some headstarts a1 = eq1[0] , b2 = eq2[1] and so on ....
    D = ( eq1[0]*eq2[1] ) - ( eq2[0]*eq1[1] );
    Dx = ( eq1[2]*eq2[1] ) - ( eq2[2]*eq1[1] );
    Dy = ( eq1[0]*eq2[2] ) - ( eq1[2]*eq2[0]);

    cout << "X = " << (Dx/D) << endl;
    cout << "Y = " << (Dy/D) << endl;


    return 0;
}
