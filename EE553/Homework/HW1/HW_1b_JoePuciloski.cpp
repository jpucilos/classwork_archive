/*
Convergence of n-gons
	1. Start with a circle r= 1
	2. Circumscribe a triangle, (n=3) around the circle
	3. Circumscribe a circle around the triangle
	4. Circumscribe a square (n=4) around the circle
	5. Circumscribe a circle around the square...
	6. Circumscribe a pentagon (n=5) around the circle.
	...
	print out the radius for n=10, 100, 1000, 10000, 100000,
	10^6
*/

#include<iostream>
#include<cmath>
using namespace std;

int main(){
	double pi = 3.1415926535897;
	int n = 10;
	while (n <= 1000000){
		double r = 1.0;
		for (double i = 3.0; i < n; i++){
			r = r * (1 / cos(pi / i));	//formula I found on Wolfram
		}
		cout <<"When n = "<<n<< ", the radius is: "<< r << endl;
		n *= 10;
	}
	return 0;
}
