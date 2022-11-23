#include<iostream>
using namespace std;

const string n = "\n\n";

class Node{
	
	public:
	int data;
	Node *left, *right;
	
	Node(int data){
		
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

class BinaryTree{
	
	public:
	int get_value();
	
	void add(Node* &start, Node* &temp, Node* object){
		
		if(!start){
			start = object;
			temp = start;
		}
		
		else{
			if(object->data > temp->data){
				
				if(temp->right)
					add(start, temp->right, object);
				else
					temp->right = object;
			}
			
			else if(object->data < temp->data){
				
				if(temp->left)
					add(start, temp->left, object);
				else
					temp->left = object;
			}
		
			else
				cout<<n<<"Value is not Valid !!!"<<endl;
		}
	}
	
	void inorder(Node* head){
		
		Node* temp = head;
		
		if(temp->left)
			inorder(temp->left);
		
		cout<<temp->data<<"  ";
		
		if(temp->right)
			inorder(temp->right);
		
	}
	
	void preorder(Node* head){
		
		Node* temp = head;
		
		cout<<temp->data<<"  ";
	
		if(temp->left)
			preorder(temp->left);
		
		if(temp->right)
			preorder(temp->right);
	}
	
	void postorder(Node* head){
		
		Node* temp = head;
		
		if(temp->left)
			postorder(temp->left);
		
		if(temp->right)
			postorder(temp->right);
		
		cout<<temp->data<<"  ";
	}
};

int BinaryTree :: get_value(){
	
	int value;
	
	cout<<endl<<"Enter Value : ";
	cin>>value;
	
	return value;
}

int main(){
	
	Node* start = NULL;
	Node* temp = NULL;
	
	BinaryTree B;
	
	Node* ob = new Node(B.get_value());
	B.add(start,temp,ob);
	
	ob = new Node(B.get_value());
	B.add(start,temp,ob);
	
	ob = new Node(B.get_value());
	B.add(start,temp,ob);
	
	ob = new Node(B.get_value());
	B.add(start,temp,ob);
	
	ob = new Node(B.get_value());
	B.add(start,temp,ob);
	
	cout<<n;
	B.inorder(start);
	
	cout<<n;
	B.preorder(start);
	
	cout<<n;
	B.postorder(start);
	
	cout<<n;
	
	return 0;
}