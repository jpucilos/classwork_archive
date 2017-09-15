#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){
	const double pi = 3.14159265358979323846;
	double x, y, theta, d = 0.0;
	cin >> theta >> d;
	while(theta && d >= 0.0){
		cout << setprecision(5);
		double x = x + d * (sin(theta * pi / 180));
		double y = y + d * (cos(theta * pi / 180));
		cout << "Location: x = "<<x<<", y = "<<y<<'\n';
		cin >> theta >> d;	
	}
	return 0;
}
