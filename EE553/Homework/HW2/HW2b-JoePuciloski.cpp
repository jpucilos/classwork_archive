#include<iostream>
using namespace std;

bool isPrime(unsigned long long p){
	if (p == 1)
		return false;
	if (p == 2)
		return true;
	for (int i = p / 2; i > 1; i--){
		if (p % i == 0)
			return false;
	}
	return true;
}

int main(){
	int n;
	while (1){
		cout << "Enter a positive number and I'll tell you if it's prime or not!" << endl;
		cin >> n;
		if (isPrime(n))
			cout << "Prime" << '\n';
		else
			cout << "Not Prime" << '\n';
	}
	cin >> n;
}