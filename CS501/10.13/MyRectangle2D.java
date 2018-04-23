/*
This program is an attempt at solving exercise 10.13 from the 10th edition of the Course Text
Author: Joseph Puciloski
Class: CS501 Assignment 6
Due: 4/14/18
*/
public class MyRectangle2D {
	private double x;
	private double y;
	private double width;
	private double height;
	
	public MyRectangle2D(){
		x = 0;
		y = 0;
		width = 1;
		height = 1;
	}
	
	public MyRectangle2D(double X, double Y, double w, double h){
		if (w < 0 || h < 0)
			throw new ArithmeticException("Sides can not have a length of less than 0");
		x = X;
		y = Y;
		width = w;
		height = h;
	}
	
	public double getArea(){
		return width*height;
	}
	
	public double getPerimeter(){
		return width*2+height*2;
	}
	
	public boolean contains(double X, double Y){
		if ( (X < x+(width/2)) && (X > x-(width/2)) && (Y < y+(height/2)) && (Y > y-(height/2))){
			return true;
		}
		else{
			return false;
		}
	}
	
	public boolean contains(MyRectangle2D r){
		if ( (r.x+r.width/2 < x+(width/2)) && (r.x-r.width/2 > x-(width/2)) && (r.y+r.height/2 < y+(height/2)) && (r.y-r.height/2 > y-(height/2))){
			return true;
		}
		else{
			return false;
		}
	}
	
	public boolean overlaps(MyRectangle2D r){
		if ( (r.x-r.width/2 > x+(width/2)) || (r.x+r.width/2 < x-(width/2)) || (r.y+r.height/2 < y-(height/2)) && (r.y-r.height/2 > y+(height/2))){
			return false;
		}
		else{
			if (r.contains(this) || this.contains(r)){
				return false;
			}
			else{
			return true;
			}
		}
	}
	
	public boolean abut (MyRectangle2D r){
		if ((r.x-r.width/2 > x+(width/2)) || (r.x+r.width/2 < x-(width/2)) || (r.y-r.height/2 > y+(height/2)) || (r.y+r.height/2 < y-(height/2)))
			return false;
		if(r.overlaps(this) || this.contains(r))
			return false;
		return true;
		
	}
	
	public void setX(double X){
		x = X;
	}
	
	public void setY(double Y){
		y = Y;
	}
	
	public double getX(){
		return x;
	}
	
	public double getY(){
		return y;
	}
	
	public void setWidth(double w){
		if (w < 0)
			throw new ArithmeticException("Sides can not have a length of less than 0");
		width = w;
	}
	
	public void setHeight(double h){
		if (h < 0)
			throw new ArithmeticException("Sides can not have a length of less than 0");
		height = h;
	}
	
	public double getWidth(){
		return width;
	}
	
	public double getHeight(){
		return height;
	}
	
	
}
