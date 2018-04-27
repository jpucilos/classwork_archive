/*
This program is an attempt at solving exercise 11.1 from the 10th edition of the Course Text
Author: Joseph Puciloski
Class: CS501 Assignment 6
Due: 4/14/18
*/

public abstract class GeometricObject {
	private String color = "white";
	private boolean filled;
	private java.util.Date dateCreated;


	protected GeometricObject() {
		dateCreated = new java.util.Date();
	}


	protected GeometricObject(String color, boolean filled) {
		dateCreated = new java.util.Date();
		this.color = color;
		this.filled = filled;
	}
	public String getColor() {
		return color;
	}
	/** Set a new color */
	public void setColor(String color) {
		this.color = color;
	}

	/** Return filled. Since filled is boolean,
	 * the get method is named isFilled */
	public boolean isFilled() {
		return filled;
	}
	/** Set a new filled */
	public void setFilled(boolean filled) {
		this.filled = filled;
	}
	/** Get dateCreated */
	public java.util.Date getDateCreated() {
		return dateCreated;
	}
	@Override
	public String toString() {
		return "created on " + dateCreated + "\ncolor: " + color +
				" and filled: " + filled;
	}

	/** Abstract method getArea */
	public abstract double getArea();

	/** Abstract method getPerimeter */
	public abstract double getPerimeter();
}