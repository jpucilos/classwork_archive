#include<iostream>
#include<cmath>
using namespace std;

/*
class object
methods messages

class = specification of an object
object = instance of a class
encapsulation: hiding the details of an object internally (private)

*/

//goal: represent fraction like 1/2, 2/3, 5/2, what about 5/0?
//privacy in code means different than regular privacy

class Fraction{
private: // data should ALWAYS be private
	int num, den;

public:
	Fraction(int n = 0, int d = 1) : num(n), den(d){}
	
	void print() const; //this member function (method) in REDONLY{
		cout << num << "/" << den <<'\n';
	}
};
print(ostream& s, Fraction f){
	
}	

int main(){
	Fraction a(1,2); // 1/2
	Fraction b(3); // 3/1
	Fraction c; //  0/1 NOT 0/1
	Fraction d(); // NOT AN OBJECT, IT'S A FUNCTION
	a.print();
	b.print();
	c.print();
}