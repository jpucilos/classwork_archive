/*
 * 		trie.cpp
 *      Author: Joseph Puciloski
 *     	Sources: Lecture Notes
 */
 
#include<string>
#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

class Trie{
private:
	class Node{
	public:
		Node* next[26];
		bool isWord;
		Node(){
			for(int i = 0; i< 26; i++)
				next[i] = nullptr;
		}
		
	};
	Node* root;
public:
	Trie() : root(new Node) {}
	
	void insert(string word){
		Node* p = root;
		for (int i = 0; i < word.length(); i++){
			int index = (int)(word[i]) - 97;
			if(p->next[index] == nullptr)
				p->next[index] = new Node();
			p = p->next[index];
		}
		p->isWord = true;
	}
	
	void contains(string word){
		Node* p = root;
		for (int i = 0; i < word.length(); i++){
			int index = (int)(word[i]) - 97;
			if(p->next[index]==nullptr){
				cout << "false" << '\n';
				return;
			}
			p = p->next[index];
		}
		if(p->isWord)
			cout << "true" << '\n';
		else
			cout << "false" << '\n';
	}
	
	void containsPrefix(string word){
		Node* p = root;
		for (int i = 0; i < word.length(); i++){
			int index = (int)(word[i]) - 97;
			if(p->next[index]==nullptr){
				cout << "false" << '\n';
				return;
			}
			p = p->next[index];
		}
		cout << "true" << '\n';
	}
};





int main() {
	Trie m;
	ifstream f ("dict.txt");
	string word;
	while(f >> word){
		m.insert(word);
	}
	ifstream g ("hw5.txt");
	string check;
	while(g >> check){
		m.contains(check);
	}
}
