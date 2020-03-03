import java.util.Scanner;
import java.lang.Math;
public class calculator {
    static double fact(double x){
        double f = 1;
        for(int i = 1;i<=x;i++){
            f *= i;
        }
        return f;
    }
    public static void main(String[] args){
        //System.out.println("lol");
        Scanner mooscan = new Scanner(System.in);

        while(true) {
            System.out.println("Enter two numbers: {X , Y}");
            double num = mooscan.nextDouble();
            double num2 = mooscan.nextDouble();
            System.out.println("Choose an operation:");
            System.out.println("1. +\t\t2. -\t\t3. *\t\t4. /\t\t5.Power X^Y\n6.sqrt(x)\t\t7. log10(X)\t\t8. X!\t9.exit");
            int operation = mooscan.nextInt();
            if ( operation == 9 ) break;
            switch (operation) {
                case 1:
                    System.out.println(num + num2);
                    break;
                case 2:
                    System.out.println(num - num2);
                    break;
                case 3:
                    System.out.println(num * num2);
                    break;
                case 4:
                    System.out.println(num / num2);
                    break;
                case 5:
                    System.out.println(Math.pow(num, num2));
                    break;
                case 6:
                    System.out.println(Math.sqrt(num));
                    break;
                case 7:
                    System.out.println(Math.log(num));
                    break;
                case 8:
                    System.out.println(fact(num));
                    break;
                default:
                    System.out.println("invalid selection!");
                    continue;

            }
            System.out.println("One more time LOL");
        }
        System.out.println("Have a nice day!");
    }
}
