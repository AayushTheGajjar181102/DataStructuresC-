#include<iostream>
#include "../Menu/Menu_Driven_Funs.h"
using namespace std;

class Node{
	
	public:
	int data, priority;
	Node* next;
	
	Node(int val, int prio){
		
		data = val;
		priority = prio;
		next = NULL;
	}
};

class Queue : public Menu{
	
	public:
		int* get_values();
	
	void enqueue(Node* &PQueue){
		
		int *v = get_values();
		Node* object = new Node(v[0], v[1]);
		
		if(!PQueue)
			PQueue = object;
		
		else{
			Node* temp = PQueue;
			Node* obj = NULL;
				
			while(temp){
				
				if((temp->priority == object->priority && temp->data > object->data) || (temp->priority > object->priority)){
					
					object->next = temp;
						
					if(!obj)
						PQueue = object;
					else
						obj->next = object;
						
					break;
				}
				
				else if(!temp->next){
					temp->next = object;
					break;
				}
					
				else if(temp->priority <= object->priority){
					obj = temp;
					temp = temp->next;
				}
			}
		}
	}
	
	bool dequeue(Node* &PQueue){
		
		if(!PQueue){
			cout<<n<<"Priority Queue is Underflow !!!"<<endl;
			return false;
		}
		
		else{
			int pos, i = 1;
			
			cout<<n<<"Enter Position : ";
			cin>>pos;
			
			if(pos < 1)
				cout<<n<<"Entered Wrong Position !!!"<<endl;
			
			else if(pos >= 1){
				
				Node* object = PQueue;
				
				if(pos == 1){
					
					if(object->next)
						PQueue = PQueue->next;
					else
						PQueue = NULL;
					
					cout<<n<<" | "<<object->data<<" |  | "<<object->priority<<" | "<<" is deleted ..."<<endl;
					delete object;
				}
				
				else{
					bool match = false;
					
					while(object->next){
						
						if(i+1 < pos){
							object = object->next;
							i++;
						}
						else{
							match = true;
							break;
						}
					}
					
					if(match){
						Node* temp = object->next;
						
						object->next = object->next->next;
						
						cout<<n<<" | "<<temp->data<<" |  | "<<temp->priority<<" | "<<" is deleted ..."<<endl;
						
						delete temp;
					}
					else
						cout<<n<<"Entered Wrong Position !!!"<<endl;
				}
			}
			return true;
		}
	}
	
	void peek(Node* PQueue){
		
		if(!PQueue)
			cout<<n<<"Priority Queue is Overflow !!!"<<endl;
		else
			cout<<n<<" | "<<PQueue->data<<" |  | "<<PQueue->priority<<" | "<<" is at peek position ..."<<endl;
	}
	
	void display(Node* PQueue){
		
		if(!PQueue)
			cout<<n<<"Priority Queue is Overflow !!!"<<endl;
		
		else{
			
			Node *temp = PQueue;
			
			cout<<n;
			
			while(temp){
				
				cout<<"  | "<<temp->data<<" | "<<" | "<<temp->priority<<" |  ";
				temp = temp->next;
			}
			cout<<endl;
		}
	}
};

int* Queue :: get_values(){
	
	int *values = new int(2);
	
	cout<<n<<"Enter Value : ";
	cin>>values[0];
	
	cout<<endl<<"Enter Priority : ";
	cin>>values[1];
	
	return values;
}

int main(){
	
	Node* PrioQueue = NULL;
	Queue create;
	
	while(1){
		
		bool bug = false;
		create.infoqueue();
		
		char ch = create.choice();
			
		switch(ch){
				
			case '1':
				create.enqueue(PrioQueue);
				bug = true;
			break;
			
			case '2':
				bug = create.dequeue(PrioQueue);
			break;
			
			case '3':
				create.peek(PrioQueue);
			break;
			
			case '4':
				create.display(PrioQueue);
			break;
				
			case '5':
				cout<<n<<"You Exit ..."<<n;
				exit(0);
			
			default:
				cout<<n<<"You Entered Wrong Choice !!!"<<endl;
		}
		create.clear(bug);
	}
	
	return 0;
}