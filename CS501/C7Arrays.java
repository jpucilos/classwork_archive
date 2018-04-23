/*
This program is an attempt at solving Chapter 7 Exercise 9, 10, and 20 from the 10th edition of the Course Text
Author: Joseph Puciloski
Class: CS501 Assignment 3
Due: 2/24/18
*/
import java.util.Scanner;

public class C7Arrays {
	public static void main(String[] args){
		System.out.println("This program 10 doubles, prints the smallest element and it's index, and then sorts the array by a modified selection sort.");
		System.out.println("Please enter 10 numbers separated by spaces:");
		double [] a = new double [10];
		Scanner sc = new Scanner(System.in);
		for (int i = 0; i < 10; i++)
			a[i] = sc.nextDouble();
		System.out.println("The smallest number is: " + min(a) + " and it's index is: " + indexOfSmallestElement(a));
		
		selectionSortMod(a);
		System.out.println("Here is the sorted array:");
		for (int i = 0; i < 10; i++)
			System.out.print(a[i] + "  ");	
		
	}
	
	public static int indexOfSmallestElement(double[] a){
		double min = a[0];
		int mindex = 0;
		for (int i = 1; i < 10; i++){
			if(a[i] < min){
				min = a[i];
				mindex = i;
			}
		}
		return mindex;
	}
	
	public static double min(double[] a){
		double min = a[0];
		for (int i = 1; i < 10; i++){
			if(a[i] < min)
				min = a[i];
		}
		return min;
	}
	
	
	public static void selectionSortMod(double[] list) {
		for (int i = list.length - 1; i >= 0; i--) {
			double currentMax = list[i];
			int currentMaxIndex = i;
			for (int j = i - 1; j >= 0; j--) {
				if (currentMax < list[j]) {
					currentMax = list[j];
					currentMaxIndex = j;
				}
			}
			if (currentMaxIndex != i) {
				list[currentMaxIndex] = list[i];
				list[i] = currentMax;
			}
		}
	}
	
	
	
	
}