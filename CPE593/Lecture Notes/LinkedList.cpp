#include<iostream>
using namespace std;



class LinkedList2 {
private:
	class Node{
	
	int v;
	Node* next;
	Node(int v, Node* next) : v(v), next(next){}
	};
	Node* head;
	Node* tail;
	
public:
	LinkedList2() : head(nullptr) {} //O(1)
	~LinkedList2(){ //O(n)
		Node* q;
		for(Node* p = head; p != nullptr; p = q){
			q = p ->next;
			delete p;
		}
	}
	void addStart(int v){
		if (head == nullptr){
			head = tail = new Node(v,nullptr);
			return;
		}
		head = new Node(v, head);
	}
	void addEnd(int v){
		if(head == nullptr) {
			head = tail = new Node(v,nullptr);
			return;
		}
		tail->next = new Node (v, nullptr);
		tail = tail->next;
	}
	void removeEnd(){
		if(tail == nullptr)
			return;
		if(head->next == nullptr){
			delete head;
			head = tail = nullptr;
		}
		Node* p;
		for (p = head; p->next != tail; p = p->next);
		p->next = nullptr;
		delete tail;
		tail = p;
	}
	
	void removeStart(){
		if(head == nullptr)
			return;
		if(head-> next == nullptr){
			delete head;
			head = tail = nullptr;
		}
		Node temp = head;
		head = head-> next;
		delete temp;
	}
	
	int get(int i){
		Node* p = head;
		for (; p->next != tail; p = p->next);
		if(p == nullptr)
			throw "ough";
		return p -> v;
	}
}