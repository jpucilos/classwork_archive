#include<iostream>
using namespace std;

class RBTree{

private:
	class Node{
	public:
		int val;
		bool color;
		Node* left;
		Node* right;
		Node* parent;
		Node(int val, bool color,  Node* left, Node* right, Node* parent) 
		: val(val), color(color), left(left), right(right), parent(parent){}
		void inorder(){
			if(left !=nullptr)
				left->inorder();
			cout << val << " ";
			if(right !=nullptr)
				right->inorder();						
		}
		void preorder(){
			cout << val << " ";
			if(left !=nullptr)
				left->inorder();
			if(right !=nullptr)
				right->inorder();			
		}
		void postorder(){
			if(left !=nullptr)
				left->inorder();
			if(right !=nullptr)
				right->inorder();			
			cout << val << " ";				
		}
		Node* grandParent(){
			if(parent==nullptr)
				return nullptr;
			return parent->parent;
		}
		Node* sibling(){
			if(parent==nullptr)
				return nullptr;
			if(parent->left == this)
				return parent->right;
			else
				return parent->left;
		}
		Node* uncle(){
			Node* g = grandparent();
			if(g == nullptr)
				return nullptr;
			if(g->left == parent)
				return g->right;
			else
				return g->left;
		}
	};

	Node* root;
	
public:	

	RBTree(): root(nullptr) {}
	
	void add(int v){
		if(root == nullptr){
			root = new Node(v, 1, nullptr, nullptr, p);
			return;
		}	
		Node* p = root;
		while(true){
			if(p->val > v){
				if(p->left == nullptr){
					p->left = new Node(v, !(p->color), nullptr,nullptr, p);
					repair(p->left);
					return;
				}
				p = p->left;
			} else{
				if(p->right == nullptr){
					p->right = new Node(v, !(p->color), nullptr,nullptr, p);
					repair(p->right);
					
					return;
				}
				p=p->right;
			}
		}
	}
	
	void repair(Node* n){
		if(n->parent == nullptr)
			case1(n);
		else if(n->parent->color)
			//do nothing
			;
		else if(n->parent->!(color))
			case3(n);
		else
			case4(n);
	}
	
	void case1(Node* n){
		if(n->parent == nullptr)
			n->color = true;
	}
	void case3(Node* n){
		n->parent->color = true;
		n->uncle()->color = true;
		Node* g = n->grandparent();
		g->color = false;
		repair(g);
	}
	void case4(Node* m){
		Node* p = n->parent;
		Node* g = n->grandParent();
		
		if(n == g->left->right) {
			rotateLeft(p);
			n = n->right;
		} else if (n = g->right->left){
			rotateRight(p);
			n = n->right;
		}
		case4b(n);	
	}
	void case4(Node* m){
		Node* p = n->parent;
		Node* g = n->grandParent();
		
		if(n == p->left) {
			rotateRight(p);
		else
			rotateLeft(p);
		p->color = true;
		g->color = false;
	}
	
	
	void rotateLeft(Node* n){
		Node* p = n->right;
		assert(p != null);
		n->right = p->left;
		n->right->parent = n;
		p->left = n;
		p->parent = n->parent;
		n->parent = p;
	}
	void rotateLeft(Node* n){
		Node* p = n->left;
		assert(p != null);
		n->left = p->right;
		n->left->parent = n;
		p->right = n;
		p->parent = n->parent;
		n->parent = p;
	}
	
	void inorder(){
		root->inorder();
		cout << '\n';
	}
	void preorder(){
		root->preorder();
		cout << '\n';
	}
	void postorder(){
		root->postorder();
		cout << '\n';
	}	
};


int main(){
	RBTree a;
	a.add(5);
	a.add(25);
	a.add(75);
	a.add(2);
	a.add(1);
	a.add(9);
	a.add(123);
	
	a.postorder();
	a.preorder();
	a.inorder();
	
	
}