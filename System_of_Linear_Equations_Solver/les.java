import java.util.Scanner;
public class les{
    public static void main(String[] args){
        Scanner read = new Scanner(System.in);

        int eq1[] = new int[3];
        int eq2[] = new int[3];

        System.out.println("System from the form a1X + b1Y = c1 , a2X + b2Y = c2\n" +
                "Enter a1 , b1 .... ok I'm board" );

        for ( int lol = 0 ; lol < 3 ; lol++ ){
            //do it later please
            //System.out.print( (char)(97 + lol) + "  " );
            eq1[lol] = read.nextInt();
        }
        for ( int lol = 0 ; lol < 3 ; lol++ ){
            eq2[lol] = read.nextInt();
        }

        //Using Carmer's rule....
        int D , Dx , Dy;
        //some headstarts a1 = eq1[0] , b2 = eq2[1] and so on ....
        D = ( eq1[0]*eq2[1] ) - ( eq2[0]*eq1[1] );
        Dx = ( eq1[2]*eq2[1] ) - ( eq2[2]*eq1[1] );
        Dy = ( eq1[0]*eq2[2] ) - ( eq1[2]*eq2[0]);

        System.out.println("X = " + (Dx/D));
        System.out.println("Y = " + (Dy/D));


    }
}
