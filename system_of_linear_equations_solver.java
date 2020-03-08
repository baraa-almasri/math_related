import java.util.Scanner;
public class system_of_linear_equations_solver{
    public static void main(String[] args){
        Scanner read = new Scanner(System.in);

        double[] eq1 = new double[3], eq2 = new double[3];

        System.out.println("System from the form a1X + b1Y = c1 , a2X + b2Y = c2\n" +
                "Enter a1 , b1 .... ok I'm board" +
                "AND DON'T ENTER THE SAME NUMBERS for both of the equations" );

        for ( int lol = 0 ; lol < 3 ; lol++ ){
            //do it later please
            System.out.print( (char)(97 + lol) + "1 = " );
            eq1[lol] = read.nextDouble();
        }
        for ( int lol = 0 ; lol < 3 ; lol++ ){
            System.out.print( (char)(97 + lol) + "2 = " );
            eq2[lol] = read.nextDouble();
        }

        //Using Carmer's rule....
        double D , Dx , Dy;
        //some headstarts a1 = eq1[0] , b2 = eq2[1] and so on ....
        D = ( eq1[0]*eq2[1] ) - ( eq2[0]*eq1[1] );
        Dx = ( eq1[2]*eq2[1] ) - ( eq2[2]*eq1[1] );
        Dy = ( eq1[0]*eq2[2] ) - ( eq1[2]*eq2[0]);

        System.out.println("X = " + (Dx/D));
        System.out.println("Y = " + (Dy/D));


    }
}
