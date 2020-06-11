//what up from Chernobyl
#include <stdio.h>
#include <math.h>
double find_length(double vector[] , int array_size);

int main(){
    
    printf("Enter desiered space:\t");
    int space;
    scanf("%d", &space);

    double vector_coordinates[space];
    puts("Enter vector's coordinates:");
    
    for ( int lol = 0 ; lol < space ; lol++ ){
        scanf("%lf", &vector_coordinates[lol]);
    }
    
    double length = find_length(vector_coordinates , space);

    if ( length == 1 ){
        printf(" ->\n||V|| = %f", length);
    }
    else {
        printf(" ->\n||V|| = %f\n", length);
        puts("Length != 1 , Rectifing....");
        printf( "^\nV = (");
        
        for ( int lol = 0 ; lol < space ; lol++ ){
            vector_coordinates[lol] /= length;
            printf("%f%s", (vector_coordinates[lol]) , ( lol < (space-1) ? " , " : "" ) );
        }
        printf( ")\n  ->\n||V || = %f\n", find_length(vector_coordinates , space) );

    }
}

double find_length(double vector[] , int array_size){
    double length = 0;
    for ( int lol = 0 ; lol < array_size ; lol++ ){
        length += pow(vector[lol],2);
    }
    return sqrt(length);
}
