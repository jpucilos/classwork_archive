/*
sum the numbers from 1 to 100.
Display the answer using the Gauss formula n(n+1)/2
Display the answer using a loop.  Verify that both answers are the same.
*/

#include<iostream>
using namespace std;

int main(){
	int sum1 = 0;
	int sum2 = 0;

	sum1 = 100*(100 + 1) / 2;

	for (int i = 1; i <= 100; i++){
		sum2 += i;
	}
	cout << "Gauss Formula: " << sum1 << '\n';
	cout << "With a loop: " << sum2 << '\n';

	return 0;
}