#include<iostream>
#include "../Menu/Menu_Driven_Funs.h"
using namespace std;

class Node{
	
	public:
	int data;
	Node *left, *right;
	
	Node(int val){
		
		data = val;
		left = NULL;
		right = NULL;
	}
};

class BinaryTree : public Menu{
	
	public:
	int get_value();
	
	Node* insertion(Node* treenode, int value){
		
		if(!treenode){
			Node* temp = new Node(value);
			return temp;
		}
	
		else if(treenode->data > value)
			treenode->left = insertion(treenode->left, value);
		
		else if(treenode->data < value)
			treenode->right = insertion(treenode->right, value);
		
		else if(treenode->data == value)
			cout<<n<<"Value is not valid !!!"<<endl;
		
		return treenode;
	}
	
	void inorder(Node* treenode){
		
		if(treenode){
			
			inorder(treenode->left);
			cout<<treenode->data<<"  ";
			inorder(treenode->right);
		}
	}
	
	void preorder(Node* treenode){
		
		if(treenode){
			
			cout<<treenode->data<<"  ";
			preorder(treenode->left);
			preorder(treenode->right);
		}
	}
	
	void postorder(Node* treenode){
		
		if(treenode){
			
			postorder(treenode->left);
			postorder(treenode->right);
			cout<<treenode->data<<"  ";
		}

	}
};

int BinaryTree :: get_value(){
	
	int value;
	
	cout<<endl<<"Enter Value : ";
	cin>>value;
	
	return value;
}

int main(){
	
	BinaryTree create;
	Node* start = NULL;
	
	while(1){
		
		create.infotree();
		
		char ch = create.choice();
		
		bool bug = false;
		
		switch(ch){
			
			case '1':
				start = create.insertion(start, create.get_value());
				bug = true;
			break;
			
			case '2':
				cout<<endl;
				create.inorder(start);
				cout<<endl;
			break;
			
			case '3':
				cout<<endl;
				create.preorder(start);
				cout<<endl;
			break;
			
			case '4':
				cout<<endl;
				create.postorder(start);
				cout<<endl;
			break;
			
			case '5':
				cout<<n<<"You Exit ..."<<n;
				exit(0);
			
			default:
				cout<<n<<"You Entered Wrong Choice !!! ";
		}
		create.clear(bug);
	}
	
	return 0;
}