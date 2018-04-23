/*
This program is an attempt at solving 9.11-12 from the 10th edition of the Course Text
Author: Joseph Puciloski
Class: CS501 Assignment 4
Due: 3/9/18
*/

import java.util.Scanner;

public class C9E11_12LinearEq {
    public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Part 1 of the program the user inputs numbers (double) representing two linear equations in the form ax + by = e and cx + dy = f");
		System.out.println("Then the program solves for x and y using Cramer's rule");
		System.out.println("Part 2 of the program the user inputs numbers (double) representing two linear lines with the endpoints: (x1,y1) (x2,y2) ... etc.");
		while(true){
			System.out.println("Please enter the values of a,b,c,d,e,f in the following format : 'a b c d e f', enter 0 to quit:");	
			double a = sc.nextDouble();
			if(a  == 0)
				return;
			double b = sc.nextDouble();
			double c = sc.nextDouble();
			double d = sc.nextDouble();
			double e = sc.nextDouble();
			double f = sc.nextDouble();
			LinearEquation eq = new LinearEquation(a, b, c, d, e, f);
			
			if(eq.isSolvable())
				System.out.println("The solution to this equation is: X = " + eq.getX() + " and Y = " + eq.getY());
			else
				System.out.println("This equation has no solution");
		
			
			System.out.println("Please enter the values of the two lines in the following format : 'x1 y1 x2 y2 x3 y3 x4 y4', enter 0 to quit:");
			double x1 = sc.nextDouble();
			if(x1==0)
				return;			
			double y1 = sc.nextDouble();
			double x2 = sc.nextDouble();
			double y2 = sc.nextDouble();
			double x3 = sc.nextDouble();
			double y3 = sc.nextDouble();
			double x4 = sc.nextDouble();
			double y4 = sc.nextDouble();
			LinearEquation eq2 = new LinearEquation(x1, y1, x2, y2, x3, y3, x4, y4);
			if(eq.isSolvable())
				System.out.println("The intersection to these lines is at: X = " + eq2.getX() + " and Y = " + eq2.getY());
			else
				System.out.println("These lines have no intersection");
		}
    
	}
}