/*
This program is an attempt at solving exercise 10.13 from the 10th edition of the Course Text
Author: Joseph Puciloski
Class: CS501 Assignment 6
Due: 4/14/18
*/


import java.util.Scanner;

public class TestMyRectangle2D {
	
	public static void main(String[] args){
		Scanner s = new Scanner(System.in);
		String option = new String("not_quit");
		while(!option.equals("quit")){
			try{
				
				System.out.println("This program asks the user to define a rectangle as a base, and then repeatedly asks for test rectangles");			
				System.out.println("Then program tests for contain, overlap, abut, and distinct rectangles");			
				System.out.println("Create a BASE rectangle (x y width height), or enter 'quit' to quit: ");
				
				option = s.next();
				
				if(!option.equals("quit")){
					MyRectangle2D r1 = new MyRectangle2D(Integer.parseInt(option), s.nextDouble(), s.nextDouble(), s.nextDouble());	
					while(!option.equals("back")){
						System.out.println("Create a TEST rectangle (x, y, width, height), or enter 'back' to enter another BASE rectangle: ");
						option = s.next();
						if(!option.equals("back")){
							MyRectangle2D r2 = new MyRectangle2D(Integer.parseInt(option), s.nextDouble(), s.nextDouble(), s.nextDouble());
							System.out.println("Contains: " + r1.contains(r2));
							System.out.println("Overlap: " + r1.overlaps(r2));
							System.out.println("Abut: " + r1.abut(r2));
							System.out.println("Disjunct: " + ( !(r1.contains(r2)) && !(r1.overlaps(r2)) && !(r1.abut(r2))));				
						}
					}
				}
			}
			catch (ArithmeticException ex){
				System.err.println(ex);
			}
		}
	}
}
