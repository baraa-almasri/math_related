#include<iostream>
using namespace std;
int main(){
	cout << "System of the form a1X + b1Y + c1Z = d1 , a2X + b2Y .... and so on\n"
		<< "Enter the coefficents\n"
		<< "AND DON'T ENTER THE SAME NUMBERS for both of the equations!!\n";
	
	double eq1[3], eq2[3], eq3[3];
    double d1, d2, d3;
    for ( int lol = 0 ; lol < 4 ; lol++ ){
        cout << (char)(97 + lol) << "1 = ";
        cin >> (lol != 3 ? eq1[lol] : d1);
    }
    for ( int lol = 0 ; lol < 4 ; lol++ ){
        cout << (char)(97 + lol) << "1 = ";
        cin >> (lol != 3 ? eq2[lol] : d2);
    }
    for ( int lol = 0 ; lol < 4 ; lol++ ){
        cout << (char)(97 + lol) << "1 = ";
        cin >> (lol != 3 ? eq3[lol] : d3);
    }

/*I was checking STH
    printf("d1 = %lf, d2 = %lf, d3 = %lf \n",d1,d2,d3);

    for ( int lol = 0 ; lol < 3 ; lol++ ){
        printf("eq1[%d] = %lf, eq2[%d] = %lf ,eq2[%d] = %lf\n",lol,eq1[lol],lol,eq2[lol],lol,eq3[lol]);
    }
*/
    /*Two variables boys
    //some headstarts a1 = eq1[0] , b2 = eq2[1] and so on ....
    //D = ( eq1[0]*eq2[1] ) - ( eq2[0]*eq1[1] );
    //Dx = ( eq1[2]*eq2[1] ) - ( eq2[2]*eq1[1] );
    //Dy = ( eq1[0]*eq2[2] ) - ( eq1[2]*eq2[0]);
*/

    //Using Carmer's rule....
    double D, Dx, Dy, Dz;
    
    D = (eq1[0]*eq2[1]*eq3[2])+(eq1[1]*eq2[2]*eq3[0])+(eq1[2]*eq2[0]*eq3[1])
        -(eq1[0]*eq2[2]*eq3[1])-(eq1[1]*eq2[0]*eq3[2])-(eq1[2]*eq2[1]*eq3[0]);
    
    Dx = (d1*eq2[1]*eq3[2])+(eq1[1]*eq2[2]*d3)+(eq1[2]*d2*eq3[1])
        -(d1*eq2[2]*eq3[1])-(eq1[1]*d2*eq3[2])-(eq1[2]*eq2[1]*d3);

    Dy = (eq1[0]*d2*eq3[2])+(d1*eq2[2]*eq3[0])+(eq1[2]*eq2[0]*d3)
        -(eq1[0]*eq2[2]*d3)-(d1*eq2[0]*eq3[2])-(eq1[2]*d2*eq3[0]);
        
    Dz = (eq1[0]*eq2[1]*d3)+(eq1[1]*d2*eq3[0])+(d1*eq2[0]*eq3[1])
        -(eq1[0]*d2*eq3[1])-(eq1[1]*eq2[0]*d3)-(d1*eq2[1]*eq3[0]);

    cout << "X = " << (Dx/D) << endl;
    cout << "Y = " << (Dy/D) << endl;
    cout << "Z = " << (Dz/D) << endl;

    return 0;
}
