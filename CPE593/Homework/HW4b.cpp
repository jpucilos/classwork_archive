/*
 * 		HW4b.cpp
 *	  	Created on: November 1st, 2017
 *      Author: Joseph Puciloski
 *     	Sources: HW4a.cpp, Lecture Notes
 */
 
#include<string>
#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

class DLinkedList2{
private:
	class Node{
	public:
		int val;
		Node* prev;
		Node* next;
		Node (int val, Node* prev, Node* next): val(val), prev(prev), next(next) {}
	};

	Node* head;
	Node* tail;	

public:
	DLinkedList2() : head(nullptr), tail(nullptr) {}
	
	//Why is this not working?
//	 ~DLinkedList2(){
//		 Node* q;
//		 for (Node* p = head; p != nullptr; p = q){
//			 q = p->next;
//			 delete p;
//		 }
//	 }
	
	friend ostream& operator <<(ostream& s, DLinkedList2 list){
		for(Node* p = list.head; p != nullptr; p = p->next)
			s << p->val<<',';
		return s;
	}
	
	void addStart(int val){
		if(head == nullptr){
			head = tail = new Node(val, nullptr, nullptr);
			return;
		}
		head = new Node(val, nullptr, head);
		(head->next)->prev = head;
	}
	
	void addEnd(int val){
		if(head == nullptr){
			head = tail = new Node(val, nullptr, nullptr);
			return;
		}
		tail = new Node(val, tail, nullptr);
		(tail->prev)->next = tail;
	}

	void removeEnd(){
		if(tail == nullptr)
			return;
		if(head->next == nullptr){
			delete head;
			head = tail = nullptr;
		}
		tail = tail -> prev;
		delete tail-> next;
		tail -> next = nullptr;
	}
	
	void removeStart(){
		if(head == nullptr)
			return;
		if(head-> next == nullptr){
			delete head;
			head = tail = nullptr;
		}
		Node* temp = head;
		head = head-> next;
		head-> prev = nullptr;
		delete temp;
	}
};

int main(){
	ifstream f ("HW4b.txt");
	DLinkedList2 temp;
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
			for (int i = a; i <= c; i += b){
				temp.addStart(i);
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
				temp.addEnd(i);	
		}
		else if (action == "REMOVE_BACK"){
			string numbers;
			f >> numbers;
			int a;
			stringstream strToint(numbers);
			strToint >> a;
			for (int i = a; i > 0; i--)
				temp.removeEnd();
		}
		else if (action == "REMOVE_FRONT"){
			string numbers;
			f >> numbers;
			int a;
			stringstream strToint(numbers);
			strToint >> a;
			for (int i = a; i > 0; i--)
				temp.removeStart();
		}
	}
	f.close();
}


//Expected test output:
//9,7,5,3,1,5,10,15,20,25,
//5,3,1,5,10,15,
