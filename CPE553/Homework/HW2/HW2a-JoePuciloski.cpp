#include<iostream>
#include<cmath>
using namespace std;

int main(){
	double v = 5.0;
	while (v <= 60.0){
		double t = 40.0;
		while (t >= -45.0){
			int windchill = round(35.74 + 0.6215 * t - 35.75 * pow(v, 0.16) + 0.4275 * t * pow(v, 0.16));
			cout << windchill << ' ';
			t -= 5.0;
		}
		cout << '\n';
		v += 5.0;
	}
}