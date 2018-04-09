/*
 * 		trie.cpp
 *      Author: Joseph Puciloski
 *     	Sources: http://www.geeksforgeeks.org/boggle-find-possible-words-board-characters/
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
	
	bool contains(string word){
		Node* p = root;
		for (int i = 0; i < word.length(); i++){
			int index = (int)(word[i]) - 97;
			if(p->next[index]==nullptr){
				return false;
			}
			p = p->next[index];
		}
		if(p->isWord)
			return true;
		else
			return false;
	}
	
	bool containsPrefix(string word){
		Node* p = root;
		for (int i = 0; i < word.length(); i++){
			int index = (int)(word[i]) - 97;
			if(p->next[index]==nullptr){
				return false;
			}
			p = p->next[index];
		}
		return true;
	}
};


void findNext(int size, char *boggle, bool *visited, int i, int j, string &str, Trie& dict){
    cout << "help" << '\n';
	visited[i*size + j] = true;
    str = str + boggle[i*size +j];
    if (dict.contains(str) && str.length() >= 3)
        cout << str << endl;

	for (int row=i-1; row<=i+1 && row<size; row++)
	  for (int col=j-1; col<=j+1 && col<size; col++)
		if (row >= 0 && col >= 0 && !visited[row*size + col])
		  findNext(size, boggle, visited, row, col, str, dict);
    str.erase(str.length()-1);
    visited[i*size+j] = false;
}

void findWords(int size, char *boggle, Trie& dict){
	cout << "help" << '\n';
	bool visited[size*size] = {false};
    string str = "";
    for (int i=0; i<size; i++){
       for (int j=0; j<size; j++)
             findNext(size, boggle, visited, i, j, str, dict);
	}
}

int main() {
	Trie dict;
	ifstream f ("dict.txt");
	string word;
	while(f >> word){
		dict.insert(word);
	}
	ifstream g ("boggle.dat");
	int size;
	f >> size;
	char board[size*size];
	char tile;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			f >> board[i*size+j];
	findWords(size, board, dict);	
}
