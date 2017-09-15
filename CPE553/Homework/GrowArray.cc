#include<iostream>
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
	//Constructor (no parameters)
	GrowArray() : data(NULL), used(0), capacity(0) {}
	
	//destructor
	~GrowArray() { 
		delete [] data;
	}
	
	
	//Copy Constructor
	GrowArray(const GrowArray& orig): data(new int[orig.used]), used(orig.used), capacity(orig.capacity) {
		for (int i = 0; i < orig.used; i++)
			data[i] = orig.data[i];
	}
	
	//= operator
	GrowArray& operator =(GrowArray copy) {
		int* temp = data; data = copy.data; copy.data = temp;
	}
	
	
	// << operator
	friend ostream& operator <<(ostream& s, const GrowArray& a){
		for (int i = 0; i < a.used; i++)
			s << a.data[i] << ";";
		return s;
	}
	
	//add method (int only)
	void add(int orig) {
		if (used >= capacity)
			grow();
		data[used++] = orig;
	}
	
	void add(const GrowArray& orig){
		for(int i = 0; i < orig.used; i++){
			if (used >= capacity)
				grow();
			data[used++] = orig.data[i];
		}
	}
	
};

GrowArray f(GrowArray x) {
  x.add(1);
  return x;
}

//Assignment: make main work
int main() {
  GrowArray a;
  for (int i = 0; i < 10; i++)
    a.add(i);
  
  GrowArray b = a;
  cout << b << '\n';
  GrowArray c;
  c = a;
  cout << b << '\n';
  c = f(b);
  cout << b << '\n';
  
}