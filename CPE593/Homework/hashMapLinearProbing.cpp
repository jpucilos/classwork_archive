/*
 *     hashMapLinearProbing.cpp
 *     Author: Joseph Puciloski
 *     Sources: http://burtleburtle.net/bob/hash/integer.html  (for hash function)
 */

#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class HashMapLinearProbing {
private:
	int* table;
	int size;
	int used;
	int limit;
	int* hist;

	void grow() {
		int tempSize = size;
		size = size * 2 + 2;
		int* temp = table;
		table = new int[size];
		for (int i = 0; i < tempSize; i++)
			table[i] = temp[i];
		for (int i = tempSize; i < size; i++)
			table[i] = -1;

		delete[] temp;
		limit*=2;
	}

public:
	HashMapLinearProbing(){
		size = 50;
		limit = size/2;
		used = 0;
		table = new int[size];
		hist = new int[50];
		for(int i = 0; i < size; i++){
			table[i] = -1;
			hist[i] = 0;
		}
	}
	uint32_t hash( uint32_t a)
	{
	    a = (a+0x7ed55d16) + (a<<12);
	    a = (a^0xc761c23c) ^ (a>>19);
	    a = (a+0x165667b1) + (a<<5);
	    a = (a+0xd3a2646c) ^ (a<<9);
	    a = (a+0xfd7046c5) + (a<<3);
	    a = (a^0xb55a4f09) ^ (a>>16);
	    return a % size;
	}


	void add(int s) {
		if (used >= limit)
			grow();
		int bin = hash(s);
		int count = 0;
		while (table[bin] >= 0 ) {
			bin = (bin+1) % size;
			count ++;
		}
		hist[count] = hist[count] + 1;
		table[bin] = s;
		used++;
	}

	void displayHistogram(){
		for (int i = 0; i < 50; i++){
			cout << i << " " << hist[i]<< '\n';
		}
	}
};
//
//int main() {
//  int n;
//  cin >> n;
//  HashMapLinearProbing m;
//  for (int i = 0; i < n; i++)
//    m.add(i);
//  m.displayHistogram();
//}
