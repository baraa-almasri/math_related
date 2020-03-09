//what up from the land of hexies
import java.util.Scanner;
class vector_parellelty{

    public static void main(String[] args){
        Scanner read = new Scanner(System.in);
        System.out.print("Enter your desired space:\t");
        int space = read.nextInt();

        double[] vector1 = new double[space],  vector2 = new double[space];
        double[] scaler = new double[space];


        for ( int lol = 0 ; lol < space ; lol++ ){
            System.out.print("Enter coordinate " + (lol+1) + " of vector1:\t");
            vector1[lol] = read.nextDouble();
         }
        System.out.println();
        for ( int lol = 0 ; lol < space ; lol++ ){
            System.out.print("Enter coordinate " + (lol+1) + " of vector2:\t");
            vector2[lol] = read.nextDouble();
            scaler[lol] = (vector1[lol] / vector2[lol]);
        }

        boolean parallel = true;
        for ( int lol = 0 ; lol < space - 1 ; lol++ ) {
            if ( scaler[lol] != scaler[lol+1] ){
                parallel = false;
                break;
            }
        }

        if ( parallel ){
            System.out.println("Vector1 & Vector2 are Parallel!" +
                    "\n & Vector1 = " + scaler[0] + " * Vector2");
        }
        else {
            System.out.println("Vector1 & Vector2 are not Parallel!");
        }


    }
}
