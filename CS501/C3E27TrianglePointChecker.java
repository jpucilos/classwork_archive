/*
This program is an attempt at solving Chapter 3 Exercise 27 from the 10th edition of the Course Text
Author: Joseph Puciloski
Class: CS501 Assignment 2
Due: 2/3/18
*/

import java.util.Scanner;

public class C3E27TrianglePointChecker {
    public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("For this program the user inputs an x and y coordinate (double) and the program will inform the user if the point is in the pre-specified triangle or not");
		System.out.println("Please enter the values of x and y in the following format : 'x y'");	
		double x = sc.nextDouble();
		double y = sc.nextDouble();
		if(x >= 0 && y >= 0 && y <=100 && x <= (100-y)*2)
			System.out.println("The point is in the triangle");
		else
			System.out.println("The point is not in the triangle");
    }
}