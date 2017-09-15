/*
Compute the sum 1/1^2 + 1/2^2 + 1/3^2 + .... 1/n^2  
Use float to compute your answer.  Note that this will result in a maximum accuracy of 7 digits.
Figure out how many iterations you will need before the contribution of 1/n2 is too small and no longer matters.
Then, instead of printing this sum (which will be unrecognizable, some strange number around 1.64) print out the following expression:
sqrt(6*s)
where s is the sum.
In order to use the sqrt function you will have to #include <cmath>
You may recognize the number you get from this.  But it will not be very accurate.
Now, try to make n bigger.  And compute the answer backwards as well.  The output of your program should be:
cout << sqrt(6 * s1) << '\n';
cout << sqrt(6 * s2) << '\n';
where s1 and s2 are the sums computed forward and backward.
*/

#include<iostream>
#include<cmath>
using namespace std;

int main(){
	float sum = 0.0f;
	float sum2 = 0.0f;

	for (float i = 1.0f; i <= 10000; i = i + 1.0){
		sum = 1/pow(i, 2.0) + sum;
		//cout << i <<"   "<< sum << '\n';
	}
	for (float i = 10000.0f; i > 0; i = i - 1.0){
		sum2 = 1 / pow(i, 2.0) + sum2;
		//cout << i << "   " << sum2 << '\n';
	}

	cout << sqrt(6.0 * sum) << '\n';
	cout << sqrt(6.0 * sum2) << '\n';

	//as N increases, sum2 appears to be more accurate.
	
	return 0;
}
