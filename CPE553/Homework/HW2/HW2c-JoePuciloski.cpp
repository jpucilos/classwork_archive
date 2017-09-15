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

int countPrimes(unsigned long long a, unsigned long long b){
	int count = 0;
	for (unsigned long long i = a;i <= b; i++){
		if (isPrime(i))
			count++;
	}
	return count;
}

int main(){
	int a;
	int b;
	while (1){
		cout << "Enter your boundaries to test (lower number first):" << endl;
		cin >> a;
		cin >> b;
		cout << "There are " << countPrimes(a, b) << " prime numbers between " << a << " and " << b << '\n';
	}
}