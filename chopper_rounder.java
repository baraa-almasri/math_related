import java.util.Scanner;
import java.lang.Math;
public class chopper_rounder {
    static long digCheck(double x){
        long digi = 0;
        while(x > 1){
            x /= 10;
            digi++;
        }
        return digi ;
    }

    static double chop(double number , long chopped ){
        for ( int i = 1 ; i <= chopped ; i++ ){
            number -= ( number % Math.pow(10,i ) );
        }
        return number;
    }
    static double round(double number , long rounded ){
        double temp = number;
        for ( int i = 1 ; i <= rounded ; i++ ){
            number -= ( number % Math.pow(10,i ) );
        }
        if ( temp % Math.pow(10, rounded) >= 5 ){
            number += Math.pow(10,rounded);
        }
        return number;
    }
    //normalizers:
    static void norm0(double number , long dig){
        System.out.println("NORM0 = " + number/Math.pow(10,dig) + " * 10^" + dig );
    }
    static void norm1(double number , long dig){
        System.out.println("NORM1 = " + number/Math.pow(10,dig - 1) + " * 10^" + (dig-1) );
    }
//yo if you got lost here's the main method (function recently xD)
    public static void main(String[] args) {
        Scanner read = new Scanner(System.in);

        while(true) {
            System.out.print("Enter a number:\t");
            int num = read.nextInt();

            System.out.print("1.Chop or 2.Round ?\t");
            int choice = read.nextInt();
            int chopped, rounded;
            long digits = digCheck(num);

            switch (choice) {
                case 1:
                    System.out.print("Enter number of digts you want to chop:\t");
                    chopped = read.nextInt();
                    norm0(chop(num, chopped), digits);
                    norm1(chop(num, chopped), digits);
                    //System.out.println( chop(num , chopped ));
                    break;
                case 2:
                    System.out.print("Enter number of digts you want to remove:\t");
                    rounded = read.nextInt();

                    norm0(round(num, rounded), digits);
                    norm1(round(num, rounded), digits);
                    //System.out.println( round(num , rounded ));
                    break;
                default:
                    System.out.println("Invalid selection!!");
            }

            System.out.println("1.Continue, 2.Exit ? \t\t");
            int proceed = read.nextInt();
            if ( proceed == 1 ) continue;
            else break;
        }

    }
}
