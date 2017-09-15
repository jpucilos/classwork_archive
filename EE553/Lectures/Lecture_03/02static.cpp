#include<iostream>
#include<string>
using namespace std;

class Person{
private:
	string name;
	int age;
	static int count; //in this context, static means class shared
public:
	Person(string n, int a): name(n), age(a){
		count++;
	}
	
	static int getCount() {
		return count;
	}
	~Person()
		count--;
	friend ostream& operator <<(ostream& s, const Person& p) {//const Person& p == Person p but faster
		return s << p.name << " " << p.age;
	}
};

int Person::count = 0;

int main(){
	Person p1("Dov", 50);
	Person p2("Yu-Dong", 45);
	cout << p1 <<'\n';
	cout << Person::getCount();
}