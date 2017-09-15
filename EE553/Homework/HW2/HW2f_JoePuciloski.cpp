#include<iostream>
#include<fstream>
using namespace std;

double average(int x[], int n){
	double sum = 0;
	for (int i=0; i < n; i++)
		sum += x[i];
	sum = sum / n;
	return sum;
}

int main(){
	ifstream f("2f.dat");
	int n;
	f >> n;
	int x[n];
	for (int i = 0; i < n; i++)
		f >> x[i];
	cout << average(x, n);
	return 0;
}