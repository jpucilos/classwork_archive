/*
This program is an attempt at solving exercise 11.1 from the 10th edition of the Course Text
Author: Joseph Puciloski
Class: CS501 Assignment 6
Due: 4/14/18
*/

public class Triangle extends GeometricObject {
	private double side1 = 1.0;
	private double side2 = 1.0;
	private double side3 = 1.0;
	
	public Triangle(){
		side1 = 1.0;
		side2 = 1.0;
		side3 = 1.0;
	}
	
	public Triangle(double a, double b, double c) throws IllegalTriangleException{
		if (a+b<=c || a+c<=b || b+c<=a)
			throw new IllegalTriangleException("sum of two sides must be greater than the third side, please try again");
		side1 = a;
		side2 = b;
		side3 = c;
	}
	
	public double getside1(){
		return side1;
	}
	
	public double getside2(){
		return side2;
	}
	public double getside3(){
		return side3;
	}
	
	public void setside1(double n) throws IllegalTriangleException{
		if (n+side2<=side3 || n+side3<=side2 || side2+side3<=n)
			throw new IllegalTriangleException("sum of two sides must be greater than the third side");
		side1 = n;
	}
	
	public void setside2(double n) throws IllegalTriangleException{
		if (side1+n<=side3 || side1+side3<=n || n+side3<=side1)
			throw new IllegalTriangleException("sum of two sides must be greater than the third side");
		side2 = n;
	}
	public void setside3(double n) throws IllegalTriangleException{
		if (side1+side2<=n || side1+n<=side2 || side2+n<=side1)
			throw new IllegalTriangleException("sum of two sides must be greater than the third side");
		side3 = n;
	}
	
	@Override
	public double getArea() {
		double s = (side1+side2+side3)/2;
		return Math.sqrt(s*(s-side1)*(s-side2)*(s-side3));
	}

	@Override
	public double getPerimeter() {
		return side1 + side2 + side3;
	}
	
	public String toString(){
		return "Triangle: side1 = " + side1 + " side2 = " + side2 + " side3 = " + side3;
	}

}
