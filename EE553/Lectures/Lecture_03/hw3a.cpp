#include<iostream>
using namespace std;

int main() {
	Vec3d a(1.0, 2, 2.5); //(1.0. 2.0, 2.5) (x,y,z)
	Vec3d b(5.0);		  //(5.0, 0.0, 0.0)
	Vec3d c = a + b;
	cout << c << '\n';
	Vec3d c = a.add(b); //call a method
	double d = a.dot(b); // dot product = a.x*b.x + a.y*b.y + a.z*b.z*b
	cout << d << '\n';
	Vec3d e = a * 2; //scalar mulitplication
	Vec3d f = 2 * a; //might have to make another one here
}