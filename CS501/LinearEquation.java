/*
This program is an attempt at solving 9.11-12 from the 10th edition of the Course Text
Author: Joseph Puciloski
Class: CS501 Assignment 4
Due: 3/9/18
*/

public class LinearEquation {
	private double a,b,c,d,e,f;	
	public LinearEquation(double a, double b, double c, double d, double e, double f){
		this.a = a;
		this.b = b;
		this.c = c;
		this.d = d;
		this.e = e;
		this.f = f;
	}
	
	public LinearEquation(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4){
		this.a = (y1-y2);
		this.b = -(x1-x2);
		this.c = (y3-y4);
		this.d = -(x3-x4);
		this.e = (y1-y2)*x1 - (x1-x2) * y1;
		this.f = (y3-y4)*x3 - (x3-x4) * y3;
	}
	
	
	public boolean isSolvable(){
		if(a*d - b*c == 0)
			return false;
		return true;
	}
	
	public double getA(){
		return this.a;
	}
	public double getB(){
		return this.b;
	}
	public double getC(){
		return this.c;
	}
	public double getD(){
		return this.d;
	}
	public double getE(){
		return this.e;
	}
	public double getF(){
		return this.f;
	}
	
	public double getX(){
		return (this.e*this.d - this.b*this.f)/(this.a*this.d-this.b*this.c);
	}
	public double getY(){
		return (this.a*this.f - this.e*this.c)/(this.a*this.d-this.b*this.c);
	}
}