//what up from the land of hexies
#include <stdio.h>
int main(){
   printf("Enter your desired space:\t");
   int space;
   scanf("%d", &space);

   double vector1[space], vector2[space];
   double scalars[space];


   for ( int lol = 0 ; lol < space ; lol++ ){
       printf("Enter coordinate %d of vector1:\t", (lol+1) );
       scanf("%lf", &vector1[lol]);
    }
   puts("");
   for ( int lol = 0 ; lol < space ; lol++ ){
       printf("Enter coordinate %d of vector1:\t", (lol+1) );
       scanf("%lf", &vector2[lol]);
    
       scalars[lol] = (vector1[lol] / vector2[lol]);
   }

   int parallel = 1;
   for ( int lol = 0 ; lol < space - 1 ; lol++ ) {
       if ( scalars[lol] != scalars[lol+1] ){
           parallel = 0;
           break;
       }
   }

   if ( parallel ){
       printf("Vector1 & Vector2 are Parallel!\n & Vector1 = %f * Vector2", scalars[0] );
   }
   else {
       puts("Vector1 & Vector2 are not Parallel!");
   }
   puts("");

}
