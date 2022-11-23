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
			
			rear = (rear + 1)%size;
			queue[rear] = get_value();
			
			cout<<n<<"front = "<<front<<"   rear = "<<rear<<n;
		}
	}
	
	void dequeue(){
		
		if(isempty())
			cout<<n<<"Queue is Underflow ! "<<endl;
		
		else{
			cout<<n<<queue[front]<<" is deleted ..."<<endl;
			
			if(front == rear)
				front = rear = -1;
			else
				front = (front + 1)%size;
		}
	}
	
	void peek(){
		
		if(isempty())
			cout<<n<<"Queue is Underflow ! "<<endl;
		else
			cout<<n<<queue[front]<<" is at peek position ..."<<endl;
	}
	
	void display(){
	
		if(isempty())
			cout<<n<<"Queue is Underflow !"<<endl;
		
		else{
			cout<<n<<"Display : "<<n;
			
			int i = front;
			for(; i != rear; i = (i+1)%size)
				cout<<" "<<i<<"| "<<queue[i]<<" |  ";
			
			cout<<" "<<i<<"| "<<queue[i]<<" |  "<<endl;
		}
		
	}
};

bool Queue :: isfull(){
	
	if((rear+1)%size == front)
		return true;
	else
		return false;
}

bool Queue :: isempty(){
	
	if(front == -1 && rear == -1)
		return true;
	else
		return false;
}

void Queue :: get_size(){
	
	cout<<endl<<"Enter Size of a Queue : ";
	cin>>size;
	
	queue = new float[size];
}

float Queue :: get_value(){
	
	float value;
	
	cout<<n<<"Enter Value : ";
	cin>>value;
	
	return value;
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