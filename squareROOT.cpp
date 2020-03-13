#include<iostream>
using namespace std;
double SQRT( double number );
int main(){
    double X;
    while(true){
        cout << "Enter number to find its square root! :\t";
        cin >> X;
        cout << "√" << X << " = " << SQRT(X) << endl;

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
