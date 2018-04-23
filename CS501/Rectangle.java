/*
This program is an attempt at solving 9.1 w/ exception handling from Ch12 from the 10th edition of the Course Text
Author: Joseph Puciloski
Class: CS501 Assignment 4
Due: 3/9/18
*/
import java.util.*;

public class Rectangle {
	
	private String errorMessage = "";
	double width;
	double length;
	
	public Rectangle(){
		this.width = 1;
		this.length = 1;
	}

	
	public Rectangle(double width, double length) throws Exception {	
		if( !isValidRectangle(width, length)) {
			Exception e = new Exception(errorMessage);
            throw e;
        }
		this.width = width;
		this.length = length;
	}
	public boolean isValidRectangle(double width, double length) throws Exception {
		if(width <= 0 || length <= 0){
            errorMessage =
                    "Invalid Width/Length: Values should be greater than 0";
            return false;
        }
		return true;
	}
	
	public double getArea(){
		return width * length;
	}
	public double getLength(){
		return this.length;
	}
	public double getWidth(){
		return this.width;
	}
	public double getPerimeter(){
		return 2 * width + 2 * length;
	}
	
}