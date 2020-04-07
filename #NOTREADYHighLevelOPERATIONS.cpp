#include<iostream>
#include<iomanip>
using namespace std;
double SQRT( double number );
double CUBRT( double number );
double POW( double base , int power );
int main(){
    double X;
    cout << "Headlines: Calculator with style!!\n";
    while(true){
        cout << "Enter number to operate on! :\t";
        cin >> X;
        cout << "Choose an operation:\n" << "1. Square Root , 2. Qubic Root , 3.Natural Logarithm \n4.Normal Logarithm\n" ;
	int choice;
	cin >> choice;
	switch (choice){
		case 1:
			cout << "√" << X << " = " << setprecision(50) << fixed << SQRT(X) << endl;
			break;
		case 2:
			cout << "3√" << X << " = " << setprecision(50) << fixed << CUBRT(X) << endl;
			break;
		case 5:
			cout << "Enter power:    ";
			int pow; cin >> pow;
			cout << X << "^" << pow << " = " << POW(X,pow) << endl;
			break;
		default:
			cout << "Invalid value!\n";
	}

        cout << "1.Continue , 2.Exit ? ";
        int proceed;
        cin >> proceed;
        if ( proceed == 2 ) break;

    }

    return 0;
}
double SQRT( double number ){
    double counter;
    for ( counter = 0.00001 ; counter < number ; counter += 0.00001 ){
        double c_squareed = counter*counter;
        if ( c_squareed >= (number - 0.0001) && c_squareed <= (number + 0.0001) ) 
            return counter;
    }
}
double CUBRT( double number ){
    double counter;
    for ( counter = 0.00001 ; counter < number ; counter += 0.00001 ){
        double c_cubed = counter*counter*counter;
        if ( c_cubed >= (number - 0.0001) && c_cubed <= (number + 0.0001) ) 
            return counter;
    }
}
double POW( double base , int power ){
	double temp = base;
	for ( int lol = 1 ; lol < power ; lol++ ){
		base *= temp;
	}
	return base;	
}
/* double LOG10( double number ){
    double counter;
    for ( counter = 0.00001 ; counter < number ; counter += 0.00001 ){
        double c_exp = counter*counter*counter;
        if ( c_cubed >= (number - 0.0001) && c_cubed <= (number + 0.0001) ) 
            return counter;
    }
}*/
