/*
This program is an attempt at solving Chapter 4 Exercise 2 from the 10th edition of the Course Text
Author: Joseph Puciloski
Class: CS501 Assignment 2
Due: 2/3/18
*/

import java.util.Scanner;

public class C4E2GreatCircleDistance {
    public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("For this program the user inputs two points on the Earth's surface, and the Great Circle Distance is returned.");
		System.out.println("Positive values represent North and West values, negative represent South and East values, as according to the exercise.");
		System.out.println("Please enter the values of the two points in the following format : 'x1 y1 x2 y2'");	
		double x1 = Math.toRadians(sc.nextDouble());
		double y1 = Math.toRadians(sc.nextDouble());
		double x2 = Math.toRadians(sc.nextDouble());
		double y2 = Math.toRadians(sc.nextDouble());
		double d = 6371.01 * Math.acos(Math.sin(x1) * Math.sin(x2) + Math.cos(x1) * Math.cos(x2) * Math.cos(y1 - y2));
		System.out.println("The distance between the two points is: " + d + " km");
    }
}