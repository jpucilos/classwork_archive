/*
This program is an attempt at solving exercise 11.1 from the 10th edition of the Course Text
Author: Joseph Puciloski
Class: CS501 Assignment 6
Due: 4/14/18
*/

public class IllegalTriangleException extends Exception {
	
	public IllegalTriangleException() {}
	
	public IllegalTriangleException(String message){
		super(message);
	}
}
