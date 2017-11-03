#include<iostream>
using namespace std;

class LinkedList{
private:
	class Node{
	public:
		int val;
		Node* next;
		Node(int v, Node* n) : val(v), next(n) {}
	};
	
	Node* head;
	
public:
	LinkedList() : head(nullptr){}
	

	//Why is this not working?
/*
	~LinkedList () {
		Node* q;
		for(Node* p = head; p != nullptr; p = q){
			q = p->next;
			delete p;
		}
	}
*/
	friend ostream& operator <<(ostream& s, LinkedList list){
		for (Node* temp = list.head; temp != nullptr; temp = temp->next)
			s << temp->val << ',';
		return s;
	}
	
	void addEnd (int v){
		if (head == nullptr) {
			head = new Node(v, nullptr);
			return;
		}
		Node* p;
		for (p = head; p->next != nullptr; p = p -> next);
		p->next = new Node(v, nullptr);
	} 
	
	void addStart(int v){
		if(head == nullptr){
			head = new Node(v, nullptr);
			return;
		}
		head = new Node(v,head);
	}
	
	void insert(int v, int i){
		Node* p = head;
		Node* temp = nullptr;
		if(i == 0){
			addStart(v);
			return;
		}
		while(i>1){
			if(p == nullptr)
				break;
			p= p->next;
			i--;
		}	
		temp = p->next;
		p->next = new Node(v, temp);		
	}
	
	
	void removeEnd(){
		if(head == nullptr)
			return;
		if(head->next == nullptr){
			head = nullptr;
			return;
		}
		Node *p;
		for (p = head; p->next != nullptr; p = p -> next);
		delete p ->next;
		p->next = nullptr;
	}

};


int main(){
	
	LinkedList a;

	a.addStart(4);
	a.addStart(3);
	a.addStart(1);
	a.insert(2, 1);
	a.addEnd(5);
	a.addEnd(6);

	cout << a << '\n';
	
	return 0;
}
