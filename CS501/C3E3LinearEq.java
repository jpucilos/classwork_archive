/*
This program is an attempt at solving Chapter 3 Exercise 3 from the 10th edition of the Course Text
Author: Joseph Puciloski
Class: CS501 Assignment 2
Due: 2/3/18
*/

import java.util.Scanner;

public class C3E3LinearEq {
    public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("For this program the user inputs numbers (double) representing two linear equations in the form ax + by = e and cx + dy = f");
		System.out.println("Then the program solves for x and y using Cramer's rule");
		System.out.println("Please enter the values of a,b,c,d,e,f in the following format : 'a b c d e f':");	
		double a = sc.nextDouble();
		double b = sc.nextDouble();
		double c = sc.nextDouble();
		double d = sc.nextDouble();
		double e = sc.nextDouble();
		double f = sc.nextDouble();
		if(a*d - b*c == 0)
			System.out.println("There is no solution");
		else
			System.out.println("X is: " + (e*d - b*f)/(a*d-b*c) + " and Y is: " + (a*f - e*c)/(a*d-b*c));
    }
}