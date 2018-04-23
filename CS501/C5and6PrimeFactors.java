/*
This program is an attempt at solving Chapter 5 Exercise 16, 20, and Chapter 6 Exercise 10 from the 10th edition of the Course Text
Author: Joseph Puciloski
Class: CS501 Assignment 3
Due: 2/24/18
*/
import java.util.Scanner;

public class C5and6PrimeFactors {
	public static void main(String[] args){
		System.out.println("This program prints the first 50 primes, populates an array with any prime under 1000, and then takes user input and prints the prime factors in increasing order.");
		System.out.println("First 50 primes:");
		int [] primes = new int [200];
		primes[0] = 2;
		System.out.print("2 ");
		int count = 1;
		for(int i = 3; i < 1000; i+= 2){
			if(isPrime(i)){
				if(count <= 49)
					System.out.print(i + " ");
				if(count <= 199){
					primes[count] = i;
					count++;
				}
			}
		}
		System.out.println('\n');
		Scanner sc = new Scanner(System.in);
		int n = 1;
		while(n != 0){
			System.out.println("Please enter a single integer, and this program will tell you if it's prime and then if it isn't it will show you it's prime factorization. Press '0' to quit");
			n = sc.nextInt();
			if(isPrime(n))
				System.out.println(n + " is Prime");
			else if(n <= 0){}
			else if(n == 1){
				System.out.println("1 is not prime but does not have a prime factorization");
			}
			else{
				System.out.println("The Prime Factorization of " + n + " is:");
				try{	
					while(!isPrime(n)){
						int i;
						for (i = 0; n % primes[i] != 0; i++){}
						n = n / primes[i];
						System.out.print(primes[i] + " ");					
					}
					System.out.println(n);
				} catch(Exception e){
					System.err.println("The number you entered has two or more prime factors larger than 1000, and cannot be handled by this program");
				}
			}	
		}
	}
	
    private static boolean isPrime(int num) {
        if (num < 2) 
			return false;
        if (num == 2) 
			return true;
        if (num % 2 == 0) 
			return false;
        for (int i = 3; i * i <= num; i += 2)
            if (num % i == 0) return false;
        return true;
	}
}