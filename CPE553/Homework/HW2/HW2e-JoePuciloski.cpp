#include<iostream>
#include<cmath>
using namespace std;

unsigned long long fact(unsigned long long n){
	unsigned long long facts = 1ULL;
	for (unsigned long long i = n; i > 0; i--)
		facts *= i;
	return facts;
}

unsigned long long fact2(unsigned long long n){
	if (n == 1)
		return 1;
	return n * fact2(n - 1);
}
int fibo(int n){
	int n2 = 1;
	int n3 = 1;
	int fibosum = 0;
	if (n == 1)
		return 1;
	if (n == 2)
		return 1;
	for (int i = n - 2; i > 0; i--){
		fibosum = n2 + n3;
		n3 = n2;
		n2 = fibosum;
	}
	return fibosum;
}
int fibo2(int n){
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return (fibo2(n - 1) + fibo2(n - 2));

}
unsigned long long choose(int n, int r){
	unsigned long long combo = 1;
	for (int i = n; i > n - r; i--)
		combo *= i;
	combo = combo / fact(r);
	return combo;
}

int main() {
	cout << fact(5) << ' ' << fact2(5) << '\n';
	cout << fact(15) << ' ' << fact2(15) << '\n';
	cout << fibo(5) << ' ' << fibo2(5) << '\n';
	cout << fibo(13) << ' ' << fibo2(13) << '\n';
	cout << choose(52, 6) << '\n';
}