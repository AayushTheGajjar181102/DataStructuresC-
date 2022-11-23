#include<iostream>
#include "../Menu/Menu_Driven_Funs.h"
using namespace std;

class Queue : public Menu{
	
	int rear, front, size;
	float *queue;
	
	public:
	bool isfull();
	bool isempty();
	void get_size();
	float get_value();
	
	Queue(){rear = front = -1;}
	
	void enqueue(){
		
		if(isfull())
			cout<<n<<"Queue is Overflow !"<<endl;
		
		else{
			
			if(front == -1)
				front++;
			
			queue[++rear] = get_value();
			cout<<endl<<queue[rear]<<" is added ..."<<endl;
		}
	}
	
	void dequeue(){
		
		if(isempty())
			cout<<n<<"Queue is Underflow !"<<endl;
		
		else
			cout<<n<<queue[front++]<<" is deleted ..."<<endl;
	}
	
	void peek(){
		
		if(isempty())
			cout<<n<<"Queue is Underflow !"<<endl;
		else
			cout<<n<<queue[front]<<" is at peek position ..."<<endl;
	}
	
	void display(){
		
		if(isempty())
			cout<<n<<"Queue is Underflow !"<<endl;
		
		else{
			cout<<n<<"Display : "<<n;
			
			for(int i = front; i <= rear; i++)
				cout<<"  | "<<queue[i]<<" |  ";
			
			cout<<endl;
		}
	}
};

float Queue :: get_value(){
	
	float value;
	
	cout<<n<<"Enter Value : ";
	cin>>value;
	
	return value;
}

void Queue :: get_size(){
	
	cout<<endl<<"Enter Size of a Queue : ";
	cin>>size;
	
	queue = new float[size];
}

bool Queue :: isfull(){
	
	if(rear == size - 1)
		return true;
	else
		return false;
}

bool Queue :: isempty(){
	
	if(rear == -1)
		return true;
	
	else if(front > rear){
		rear = front = -1;
		return true;
	}
	else
		return false;
}

int main(){
	
	Queue create;
	create.get_size();
	
	while(1){
		
		create.clear(false);
		create.infoqueue();
		
		char ch = create.choice();
		
		switch(ch){
			
			case '1':
				create.enqueue();
			break;
			
			case '2':
				create.dequeue();
			break;
			
			case '3':
				create.peek();
			break;
			
			case '4':
				create.display();
			break;
			
			case '5':
				cout<<n<<"You Exit ..."<<n;
				exit(0);
			
			default:
				cout<<n<<"You Entered Wrong Choice !!!"<<endl;
		}
	}
	return 0;
}
