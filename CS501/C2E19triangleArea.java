import java.util.Scanner;

public class C2E19triangleArea {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	System.out.println("For this program the user inputs numbers (double) representing coordinates of three points, the area of the resultant triangle is then calculated.");
	System.out.println("Please enter the coordinates of the three points in the following format : 'x1 y1 x2 y2 x3 y3'");	
	double x1 = sc.nextDouble();
	double y1 = sc.nextDouble();
	double x2 = sc.nextDouble();
	double y2 = sc.nextDouble();
	double x3 = sc.nextDouble();
	double y3 = sc.nextDouble();
	
	double side1 = Math.abs(Math.pow(Math.pow(x2-x1,2) + Math.pow(y2-y1,2),0.5));
	System.out.println(side1);
	double side2 = Math.abs(Math.pow(Math.pow(x3-x2,2) + Math.pow(y3-y2,2),0.5));
	System.out.println(side2);
	double side3 = Math.abs(Math.pow(Math.pow(x3-x1,2) + Math.pow(y3-y1,2),0.5));
	System.out.println(side3);
	double s = (side1+side2+side3)/2;
	System.out.println("Area is: " + Math.pow(Math.abs(s*(s - side1)*(s - side2)*(s - side3)), 0.5));
	
    }
}