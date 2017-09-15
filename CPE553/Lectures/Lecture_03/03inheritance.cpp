#include<iostream>
using namespace std;

//We need inheritance!!!
class A {
	
};

class B: public A {
	
};

class Vehicle {
	int speed;
public:
	int payToll();
};

class Car : public Vehicle{
	string color;

};

class bus{
	int numPassengers;
	int speed;
	int payToll(); //how do we relate this function with the one in car?

	
	
	
	