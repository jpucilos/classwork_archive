#include<iostream>
using namespace std;

class BinaryTree{

private:
	class Node{
	public:
		int val;
		Node* left;
		Node* right;
		Node* parent;
		Node(int val, Node* left, Node* right) : val(val), left(left), right(right){}
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
	};

	Node* root;
public:	

	BinaryTree(): root(nullptr) {}

	void add(int v){
		if(root == nullptr){
			root = new Node(v, nullptr, nullptr);
			return;
		}	
		Node* p = root;
		while(true){
			if(p->val > v){
				if(p->left == nullptr){
					p->left = new Node(v, nullptr,nullptr);
					return;
				}
				p = p->left;
			} else{
				if(p->right == nullptr){
					p->right = new Node(v, nullptr,nullptr);
					return;
				}
				p=p->right;
			}
		}
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
	BinaryTree a;
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