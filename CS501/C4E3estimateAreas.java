/*
This program is an attempt at solving Chapter 4 Exercise 3 from the 10th edition of the Course Text
Author: Joseph Puciloski
Class: CS501 Assignment 2
Due: 2/3/18
*/
public class C4E3estimateAreas {
    public static void main(String[] args) {
		System.out.println("For this program the area enclosed by four pre-determined cities is determined using formulas from exercises 4.2 and 2.19" + '\n');

		System.out.println("The coordinates for Atlanta Georgia are: " + 33.7435063 + " " + -84.5535959);
		System.out.println("The coordinates for Orlando Florida are: " + 28.5383355 + " " + -81.3792365);
		System.out.println("The coordinates for Sanvanna Georgia are: " + 32.0835407 + " " + -81.0998342);
		System.out.println("The coordinates for Charlotte North Carolina are: " + 35.2270869 + " " + -80.8431267 + '\n');
		
		double at1 = Math.toRadians(33.7435063);
		double at2 = Math.toRadians(-84.5535959);
		double or1 = Math.toRadians(28.5383355);
		double or2 = Math.toRadians(-81.3792365);
		double sa1 = Math.toRadians(32.0835407);
		double sa2 = Math.toRadians(-81.0998342);
		double ch1 = Math.toRadians(35.2270869);
		double ch2 = Math.toRadians(-80.8431267 + '\n');
		
		double dat2or = 6371.01 * Math.acos(Math.sin(at1) * Math.sin(or1) + Math.cos(at1) * Math.cos(or1) * Math.cos(at2 - or2));
		double dor2sa = 6371.01 * Math.acos(Math.sin(or1) * Math.sin(sa1) + Math.cos(or1) * Math.cos(sa1) * Math.cos(or2 - sa2));
		double dsa2ch = 6371.01 * Math.acos(Math.sin(sa1) * Math.sin(ch1) + Math.cos(sa1) * Math.cos(ch1) * Math.cos(sa2 - ch2));
		double dch2at = 6371.01 * Math.acos(Math.sin(ch1) * Math.sin(at1) + Math.cos(ch1) * Math.cos(at1) * Math.cos(ch2 - at2));
		double dat2sa = 6371.01 * Math.acos(Math.sin(at1) * Math.sin(sa1) + Math.cos(at1) * Math.cos(sa1) * Math.cos(at2 - sa2));
		
		
		System.out.println("The distance between Atlanta and Orlando is: " + dat2or + " km");
		System.out.println("The distance between Orlando and Savanna is: " + dor2sa + " km");
		System.out.println("The distance between Savanna and Charlotte is: " + dsa2ch + " km");
		System.out.println("The distance between Charlotta and Atlanta is: " + dch2at + " km");
		System.out.println("The distance between Atlanta and Savanna is: " + dat2sa + " km" + '\n');
		
		double s1 = (dat2or+dor2sa+dat2sa)/2;
		double s2 = (dch2at+dsa2ch+dat2sa)/2;
		double area1 = Math.pow(Math.abs(s1*(s1 - dat2or)*(s1 - dor2sa)*(s1 - dat2sa)), 0.5);
		double area2 = Math.pow(Math.abs(s2*(s2 - dch2at)*(s2 - dch2at)*(s2 - dat2sa)), 0.5);
		
		System.out.println("Area between Atlanta, Orlando, and Savanna: " + area1 + " km^2");
		System.out.println("Area between Atlanta, Charlotte, and Savanna: " + area2 + " km^2");
		System.out.println("Total Enclosed Area: " + (area1 + area2) + " km^2");
		
    }
}