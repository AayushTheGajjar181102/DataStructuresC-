#include<iostream>
#include "../Menu/Menu_Driven_Funs.h"
using namespace std;

class Queue : public Menu{
	
	int front, rear, size;
	float *dequeue;
	
	public:
	void del();
	bool isfull();
	bool isempty();
	void get_size();
	float get_value();
	
	Queue(){front = rear = -1;}
	
	void enqueue_back(){
		
		if(isfull())
			cout<<n<<"Dequeue is Overflow !"<<endl;
		
		else{
			if(front == -1)
				front++;
			
			rear = (rear + 1)%size;
			dequeue[rear] = get_value();
		}
	}
	
	void dequeue_back(){
		
		if(isempty())
			cout<<n<<"Dequeue is Underflow !"<<endl;
		
		else{
			cout<<n<<dequeue[rear]<<" is deleted ..."<<endl;
			
			if(rear == front)
				front = rear = -1;
			
			else if(rear == 0)
				rear = size - 1;
			else
				rear--;
		}
	}
	
	void enqueue_front(){
		
		if(front == -1)
			enqueue_back();
		
		else{
			
			if(isfull())
				cout<<n<<"Dequeue is Overflow !"<<endl;
			
			else{
				
				if(front == 0)
					front = size;
				
				dequeue[--front] = get_value();
			}
		}
	}
	
	void dequeue_front(){
		
		if(isempty())
			cout<<n<<"Dequeue is Underflow !"<<endl;
		
		else{
			cout<<n<<dequeue[front]<<" is deleted ..."<<endl;
			
			if(front == rear)
				front = rear = -1;
			else
				front = (front + 1)%size;
		}
	}
	
	void peek(){
		
		if(isempty())
			cout<<n<<"Dequeue is Underflow !"<<endl;
		else
			cout<<n<<dequeue[front]<<" is at peek position ..."<<endl;
		
	}
	
	void display(){
		
		if(isempty())
			cout<<n<<"Dequeue is Underflow !"<<endl;
		
		else{
			cout<<n<<"Display : "<<n;
			
			int i = front;
			for(; i != rear; i = (i+1)%size)
				cout<<"  "<<i<<"| "<<dequeue[i]<<" |  ";
			
			cout<<"  "<<i<<"| "<<dequeue[i]<<" |  "<<endl;
		}
		
	}
};

bool Queue :: isfull(){
	
	if((rear + 1)%size == front || (front - 1)%size == rear)
		return true;
	else
		return false;
}

bool Queue :: isempty(){
	
	if(rear == -1 && front == -1)
		return true;
	else
		return false;
}

void Queue :: get_size(){
	
	cout<<endl<<"Enter Size for a Dequeue : ";
	cin>>size;
	
	dequeue = new float[size];
}

float Queue :: get_value(){
	
	float value;
	
	cout<<n<<"Enter Value : ";
	cin>>value;
	
	return value;
}

void Queue :: del(){delete dequeue;}

int main(){
	
	Queue create;
	create.get_size();
	
	while(1){
		
		create.clear(false);
		create.infodequeue();
		
		char ch = create.choice();
		
		switch(ch){
			
			case '1':
				create.enqueue_front();
			break;
			
			case '2':
				create.enqueue_back();
			break;
			
			case '3':
				create.dequeue_front();
			break;
			
			case '4':
				create.dequeue_back();
			break;
			
			case '5':
				create.peek();
			break;
			
			case '6':
				create.display();
			break;
			
			case '7':
				create.del();
				cout<<n<<"You Exit ..."<<n;
				exit(0);
			
			default:
				cout<<n<<"You Entered Wrong Choice !!!"<<endl;
		}
	}
	return 0;
}