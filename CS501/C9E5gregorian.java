/*
This program is an attempt at solving 9.5 from the 10th edition of the Course Text
Author: Joseph Puciloski
Class: CS501 Assignment 4
Due: 3/9/18
*/
import java.util.*;

public class C9E5gregorian {
	public static void main(String[] args){
		System.out.println("This program uses GregorianCalender from Java API and prints the current month/day/year, as well as converts a pre-determined");
		System.out.println("time in milliseconds to month/day/year.");
		GregorianCalendar greg = new GregorianCalendar();
		System.out.println("Today's Date: " + (greg.get(GregorianCalendar.MONTH)+1) + "/" + greg.get(GregorianCalendar.DAY_OF_MONTH) + "/" + greg.get(GregorianCalendar.YEAR));
		greg.setTimeInMillis(1234567898765L);
		System.out.println("At 1234567898765 milliseconds the date was: " + (greg.get(GregorianCalendar.MONTH)+1) + "/" + greg.get(GregorianCalendar.DAY_OF_MONTH) + "/" + greg.get(GregorianCalendar.YEAR));
	}
}