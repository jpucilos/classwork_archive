/*
Read in n from keyboard.
Compute n!  (n factorial)
example n=3   3! = 3 * 2 * 1 = 6
try for n=10 3628800
n=20 ???
n=30
*/

#include<iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int n2 = n;

	for (int i = 1; i < n; i++){
		n2 = n2 * i;
	}

	n = n2;
	cout << n << endl;

	return 0;
}