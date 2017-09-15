#include<iostream>
using namespace std;


class Vec3d {
private:
	double x, y, z;
public:
	Vec3d (double x = 0.0, double y = 0.0, double z = 0.0) : x(x), y(y), z(z){}
	
	friend Vec3d operator +(Vec3d a, Vec3d c){
		Vec3d ans(a.x + c.x, a.y + c.y, + a.z + c.z);
		return ans;
	}
	friend ostream&  operator << (ostream& s, const Vec3d& v) {
		return s << "("<<v.x<<","<<v.y<<","<<v.z<<")";
	}
	friend Vec3d operator *(Vec3d a, int b){
		Vec3d ans(a.x * b, a.y *b, a.z* b);
		return ans;
	}
	friend Vec3d operator *(int b, Vec3d a){
		Vec3d ans(a.x * b, a.y *b, a.z* b);
		return ans;
	}
	Vec3d add(Vec3d v) const{
		Vec3d ans(x + v.x, y + v.y, z+v.z);
		return ans;
	}
	double dot(Vec3d v)const{
		return x*v.x + y*v.y + z*v.z;
	}
};

int main() {
	const Vec3d a(1.0, 2, 2.5); //(1.0, 2.0, 2.5) (x,y,z)
	cout << a << '\n';
	Vec3d b(5.0);         //(5.0, 0.0, 0.0)
	Vec3d c = a + b;
	cout << c << '\n';
	Vec3d c2 = a.add(b);   // call a method
	cout << c2 << '\n';
	double d = a.dot(b); //  dot product = a.x*b.x + a.y*b.y + a.z*b.z
	cout << d << '\n';

	Vec3d e = a * 2;   //scalar multiplication
	cout << e << '\n';
	Vec3d f = 2 * a;   //scalar multiplication
	cout << f << '\n';
}
