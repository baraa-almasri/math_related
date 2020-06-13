#include <stdio.h>
#include <math.h>
typedef long int li;
li digCheck(double);

double chop(double, li ,li);
double round(double, li ,li);
void norm0(double , li);
void norm1(double , li);

int main() {
    while(1) {
        printf("Enter a number:\t");
        int num;
        scanf("%d", &num);

        printf("1.Chop or 2.Round ?\t");
        int choice;
        scanf("%d", &choice);

        int chopped, rounded;
        li digits = digCheck(num);

        switch (choice) {
            case 1:
                printf("Enter number of digts chopping:\t");
                scanf("%d", &chopped);
                norm0(chop(num, chopped , digits), digits);
                norm1(chop(num, chopped , digits), digits);
                //System.out.println( chop(num , chopped ));
                break;
            case 2:
                printf("Enter number of digts after rounding:\t");
                scanf("%d", &rounded);

                norm0(round(num, rounded , digits), digits);
                norm1(round(num, rounded , digits), digits);
                //System.out.println( round(num , rounded ));
                break;
            default:
                puts("Invalid selection!!");
        }

        printf("1.Continue, 2.Exit ? \t\t");
        int proceed;
        scanf("%d", &proceed);
        if ( proceed == 2 ) break;
    }
}

li digCheck(double x){
    long digi = 0;
    while(x > 1){
        x /= 10;
        digi++;
    }
    return digi ;
}

double chop(double number , li chopped , li digits){
    for ( int i = 1 ; i <= digits - chopped ; i++ ){
        number -= fmod( number, pow(10,i ) );
    }
    return number;
}

double round(double number , li rounded , li digits){
    double temp = number;
    for ( int i = 1 ; i <= digits - rounded ; i++ ){
        number -= fmod( number, pow(10,i ) );
    }
    if ( fmod(temp, pow(10, digits - rounded) ) >= 5 ){
        number += pow(10,digits - rounded);
    }
    return number;
}

//normalizers:
void norm0(double number , li dig){
    printf("NORM0 = %lf * 10^%ld\n", number/pow(10,dig), dig );
}

void norm1(double number , li dig){
    printf("NORM1 = %lf * 10^%ld\n", number/pow(10,dig - 1), (dig-1) );
}