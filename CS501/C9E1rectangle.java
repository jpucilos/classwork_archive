/*
This program is an attempt at solving 9.1 w/ exception handling from Ch12 from the 10th edition of the Course Text
Author: Joseph Puciloski
Class: CS501 Assignment 4
Due: 3/9/18
*/
import java.util.*;

public class C9E1rectangle {
	public static void main(String[] args){
		System.out.println("This program is the test program for Rectangle.java, it creates two from user input and calculates area and perimeter.");
		System.out.println("Exception handling is used to handle widths and lengths of 0 or less in the Rectangle.java file.");		
		Rectangle a = new Rectangle();
		Scanner sc = new Scanner(System.in);
		while (true){
			System.out.println("Please Enter the Width and Length of a rectangle separated by a space, enter 0 to quit:");
			try {
				double width = sc.nextDouble();
				if(width == 0)
					return;
				double length = sc.nextDouble();
				a = new Rectangle(width, length);
				System.out.println("The width of rectangle  is: " + a.getWidth());
				System.out.println("The length of rectangle is: " + a.getLength());
				System.out.println("The area of rectangle is: " + a.getArea());
				System.out.println("The perimeter of rectangle is: " + a.getPerimeter());
			} catch (Exception e){
				System.out.println(e.getMessage());
			}
		}
	}
}