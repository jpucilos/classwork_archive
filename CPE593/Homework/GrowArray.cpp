/*
 * HW14a.cpp
 *
 *  Created on: October 15th, 2015
 *      Author: Joseph Puciloski
 *     Sources: EE553  Fall 2017 GrowArray Homework Assignment
 */
#include<string>
#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

class GrowArray {
private:
	int* data;
	int used;
	int capacity;
	void grow() {
		capacity = capacity * 2 + 2;
		int* temp = data;
		data = new int[capacity];
		for (int i = 0; i < used; i++)
			data[i] = temp[i];
		delete [] temp;
	}
	
public:
	GrowArray() : data(NULL), used(0), capacity(0) {}
	~GrowArray() { 
		delete [] data;
	}
	GrowArray(const GrowArray& orig): data(new int[orig.used]), used(orig.used), capacity(orig.capacity) {
		for (int i = 0; i < orig.used; i++)
			data[i] = orig.data[i];
	}
	GrowArray& operator =(GrowArray copy) {
		int* temp = data; data = copy.data; copy.data = temp;
	}
	friend ostream& operator <<(ostream& s, const GrowArray& a){
		for (int i = 0; i < a.used - 1; i++)
			s << a.data[i] << ",";
		s << a.data[a.used - 1];
		return s;
	}
	void add(const GrowArray& orig){
		for(int i = 0; i < orig.used; i++){
			if (used >= capacity)
				grow();
			data[used++] = orig.data[i];
		}
	}

	void add_front(int orig) {
		if (used >= capacity)
			grow();
		used++;
		for (int i = used; i > 0; i--)
			data[i] = data[i-1];
		data[0] = orig;
	}
	void add_back(int orig) {
		if (used >= capacity)
			grow();
		data[used++] = orig;
	}
	void remove_back(){
		used--;
	}
	void remove_front(){
		used--;
		for (int i = 0; i < used; i++)
			data[i] = data[i+1];
	}
};

int main(){
	ifstream f ("HW4a.txt");
	GrowArray temp;
	string action;
	while(f >> action){
		if(action == "OUTPUT")
			cout << temp << '\n';	
		else if (action == "ADD_FRONT"){
			string numbers;
			f >> numbers;
			int pos, a, b, c;
			
			pos = numbers.find(":");
			stringstream strTointa(numbers.substr(0, pos));
			strTointa >> a;
			numbers.erase(0, pos + 1);
			
			pos = numbers.find(":");
			stringstream strTointb(numbers.substr(0, pos));
			strTointb >> b;
			numbers.erase(0, pos + 1);
			
			stringstream strTointc(numbers);
			strTointc >> c;
			
			//cout << a << " " << b  << " "<< c <<'\n';
			
			for (int i = a; i <= c; i += b){
				temp.add_front(i);
			}
		}
		else if (action == "ADD_BACK"){
			string numbers;
			f >> numbers;
			int pos, a, b, c;
			
			pos = numbers.find(":");
			stringstream strTointa(numbers.substr(0, pos));
			strTointa >> a;
			numbers.erase(0, pos + 1);
			
			pos = numbers.find(":");
			stringstream strTointb(numbers.substr(0, pos));
			strTointb >> b;
			numbers.erase(0, pos + 1);
			
			stringstream strTointc(numbers);
			strTointc >> c;
			
			for (int i = a; i <= c; i += b)
				temp.add_back(i);	
		}
		else if (action == "REMOVE_BACK"){
			string numbers;
			f >> numbers;
			int a;
			stringstream strToint(numbers);
			strToint >> a;
			for (int i = a; i > 0; i--)
				temp.remove_back();
		}
		else if (action == "REMOVE_FRONT"){
			string numbers;
			f >> numbers;
			int a;
			stringstream strToint(numbers);
			strToint >> a;
			for (int i = a; i > 0; i--)
				temp.remove_front();
		}
	}


	f.close();
}