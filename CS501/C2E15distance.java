import java.util.Scanner;

public class C2E15distance {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	System.out.println("For this program the user inputs numbers (double) representing coordinates of two points, the distance between these points is then calculated.");
	System.out.println("Please enter the coordinates of the two points in the following format : 'x1 y1 x2 y2'");
	double x1 = sc.nextDouble();
	double y1 = sc.nextDouble();
	double x2 = sc.nextDouble();
	double y2 = sc.nextDouble();
	
	System.out.println("Distance is: " + Math.abs(Math.pow(Math.pow(x2-x1,2) + Math.pow(y2-y1,2),0.5)));
	
    }
}