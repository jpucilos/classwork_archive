#include<iostream>
using namespace std;

class DLinkedList2 {
private:
	class Node{
	
	int v;
	Node* next;
	Node* prev;
	Node(int v, Node* prev, Node* next) : v(v), prev(prev), next(next){}
	};
	
	Node* head;
	Node* tail;
	
public:
	LinkedList2() : head(nullptr), tail(nullptr) {} //O(1)
	~LinkedList2(){ //O(n)
		Node* q;
		for(Node* p = head; p != nullptr; p = q){
			temp = p ->next;
			delete p;
		}
	}
	void addStart(int v){
		if (head == nullptr){
			head = tail = new Node(v,nullptr);
			return;
		}
		head = new Node(v, nullptr, head);
	}
	void addEnd(int v){
		if(head == nullptr) {
			head = tail = new Node(v,nullptr);
			return;
		}
		tail->next = new Node (v, tail, nullptr);
		tail = tail->next;
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
		Node temp = head;
		head = head-> next;
		head-> prev = nullptr;
		delete temp;
	}
	
	int get(int i){
		Node* p = head;
		for (; p->next != tail; p = p->next);
		if(p == nullptr)
			throw "ough";
		return p -> v;
	}

	insertAfter(Node* p, int v){
		if(p->next == null){
			tail = new Node (v, p, nullptr);
			p->next = tail;
		}
		p->next = new Node(v, p->next, p);
	}
	
	insertBefore(Node* p, int v){
		if(p -> prev == null){
			head = new Node (v, nullptr, p);
			p->prev  = head;
		}
		insertAfter(p->next, v);
	}
	
}