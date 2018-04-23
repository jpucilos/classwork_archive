/*
This program is an attempt at solving exercise 11.1 from the 10th edition of the Course Text
Author: Joseph Puciloski
Class: CS501 Assignment 6
Due: 4/14/18
*/

import java.util.Scanner;


public class TestTriangle {
	public static void main(String[] args){
		try{		
			Scanner s = new Scanner(System.in);
			String option = new String("start");
			System.out.println("This program prompts the user to enter three sides of the triangle, a color, and a Boolean value to indicate whether the triangle is filled."); 
			System.out.println("The program should create a Triangle object with these sides and set the color and filled properties using the input.");
			System.out.println("The program should display the area, perimeter, color, and true or false to indicate whether it is filled or not.");
			while(!option.equals("quit")){
				System.out.println("Enter the lengths of the 3 sides of your triangle, separated by spaces, or enter 'quit' to quit: ");
				option = s.next();
				if(!option.equals("quit")){
					Triangle tri = new Triangle(Integer.parseInt(option), s.nextDouble(), s.nextDouble());
					System.out.println("Input a color for the triangle: ");
					tri.setColor(s.next());
					System.out.println("Input a boolean value to indicate if the triangle is filled: ");
					tri.setFilled(s.nextBoolean());
					System.out.println(tri.toString());
					System.out.println("Area: " + tri.getArea());
					System.out.println("Perimeter: " + tri.getPerimeter());
					System.out.println("Color: " + tri.getColor());
					System.out.println("Filled: " + tri.isFilled());
					System.out.println();
				}
			}
		}
		catch (IllegalTriangleException ex){
			System.err.println(ex);
		}
	}
}
