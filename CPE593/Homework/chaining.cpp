/*
 *     hashMapLinearChaining.cpp
 *     Author: Joseph Puciloski
 *     Sources: Previous semester's lectures for hash function
 *				http://www.cplusplus.com/reference/vector/vector/
 */

#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;


class HashMapLinearChaining {
private:
	vector <string>* table;
	int size;

public:
	HashMapLinearChaining(){
		size = 26;
		table = new vector<string>[size];
	}
	int hash(const string& s) const {
		int sum = 0;
		for (unsigned int i = 0; i < s.size(); i++)
			sum = (sum * 26 + s[i]) % size;
		return sum % size;
	}

	void add(string s) {
		(table[hash(s)]).push_back(s);
	}

	void checkDictionary(const string& s){
		if(find(table[hash(s)].begin(), table[hash(s)].end(), s) != table[hash(s)].end())
			cout << "true" << '\n';
		else
			cout << "false" << '\n';
	}
	void displayHistogram(){
		for (int i = 0; i < 26; i++)
			cout << i << " " << table[i].size()<< '\n';
	}
};

int main() {
	HashMapLinearChaining m;
	ifstream f ("dict.txt");
	string word;
	while(f >> word){
		m.add(word);
	}
	
	ifstream g ("hw8.dat");
	string check;
	while(g >> check){
		m.checkDictionary(check);
	}
	
	
	m.displayHistogram();

	return 0;
}


