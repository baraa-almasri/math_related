//what up from Chernobyl
import java.util.Scanner;
import java.lang.Math;
class vector_length_finder{
    static double find_length(double vect[] , int array_size){
        double length = 0;
        for ( int lol = 0 ; lol < array_size ; lol++ ){
            length += Math.pow(vect[lol],2);
        }
        return Math.sqrt(length);
    }
    public static void main(String[] args){
        Scanner read = new Scanner(System.in);
        System.out.print("Enter desiered space:\t");
        int s = read.nextInt();

        double vec_cords[] = new double[s];
        System.out.println("Enter vector's coordinates:");
        for ( int lol = 0 ; lol < s ; lol++ ){
            vec_cords[lol] = read.nextDouble();
        }
        double length = find_length(vec_cords , s);

        if ( length == 1 ){
            System.out.println(" =>\n" + "||V|| = " + (length) );
        }
        else {
            System.out.println( " =>\n" + "||V|| = " + (length) + "\n");
            System.out.println( "Length != 1 , Rectifing....");
            System.out.print( "^\n" + "V = " + "(" );
            for ( int lol = 0 ; lol < s ; lol++ ){
                vec_cords[lol] /= length;
                System.out.print( (vec_cords[lol]) + ( lol < (s-1) ? " , " : "" ) );
            }
            System.out.println( ")\n" + "  =>\n" + "||V || = " + (find_length(vec_cords , s)) );

        }

    }
}
