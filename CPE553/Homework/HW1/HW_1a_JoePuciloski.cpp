/*
read in a number from keyboard (suppose n = 5)

	if it's odd, multiply by 3 and add 1.
	if it's even divide by 2.

	Repeat until the number converges to 1
	5	16	8	4	2	1	
*/

#include<iostream>
using namespace std;

int main(){
	int number;
	cin >> number;
	while (number != 1){
		if (number % 2 == 1){
			number = number * 3 + 1;
			cout << number << '\n';
		}
		else{
			number = number / 2;
			cout << number << '\n';
		}
	}
	return number;
}