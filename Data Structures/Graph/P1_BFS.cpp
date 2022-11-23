#include<iostream>
#include "../Menu/Menu_Driven_Funs.h"
using namespace std;

class Graph : public Menu{
	
	protected:
		int **graph;
		char *regraph;
		int vertices = 1;
	
	void get_edges();
	int get_vertices();
	void get_graph_size();
	void get_choice(int, int);
	
	void get_edge(int edge, char &a, char &b){
		
		cout<<n<<"Edge "<<edge+1<<" Vertex 1 -> Vertex 2 :-- ";
			
		cout<<n<<"Enter Vertex 1 : ";
		cin>>a;
			
		cout<<endl<<"Enter Vertex 2 : ";
		cin>>b;
	}
	
	
	public:
	
	void get_graph(){
		
		get_graph_size();
		get_edges();
	}
	
	void display(bool bug){
		
		clear(bug);
		
		cout<<endl<<"Graph Representation with Array : "<<n<<"   ";
		
		for(int i = 0; i <= vertices; i++){
			
			for(int j = 0; j < vertices; j++){
				
				if(i == 0)
					cout<<" "<<regraph[j]<<" ";
				
				else{
					if(j == 0)
						cout<<" "<<regraph[i-1]<<" ";
					
					cout<<" "<<graph[i-1][j]<<" ";
				}
			}
			
			cout<<n;
		}
	}
};

class BFS : public Graph{
	
	int *queue = new int[vertices];
	bool *check = new bool[vertices]{false};
	int front, rear;
	
	bool isfull();
	bool isempty();
	int get_value();
	
	public:
		void Delete();
		
	BFS(){front = rear = -1;}
	
	void enqueue(){
		
		if(isempty()){
			
			front++;
			
			queue[++rear] = get_value();
			
			check[queue[rear]] = true;
			
			cout<<endl<<"Breath First Search = ";
		}
		
		while(!isempty()){
				
			int v = dequeue();
		
			cout<<char(v+65);
				
			if(v > -1){
				
				for(int i = 0; i < vertices; i++){
						
					if(graph[v][i] == 1){
						
						if(!check[i]){
							
							queue[++rear] = i;
							check[i] = true;
						}
					}
				}
			}
			
			if(!isempty())
				cout<<" -> ";
		}
	}
	
	int dequeue(){
		
		if(isempty()){
			
			cout<<n<<"Queue is UnderFlow !!!"<<endl;
			return -1;
		}
		else
			return queue[front++];
	}
};


int Graph :: get_vertices(){
		
	cout<<endl<<"Enter Number of Vertices : ";
	cin>>vertices;
	
	return vertices;
}

void Graph :: get_graph_size(){
		
	int ch = 64;
	
	graph = new int*[get_vertices()];
	regraph = new char[vertices];
		
	for(int i = 0; i < vertices; i++){
		
		graph[i] = new int[vertices]{0};
		regraph[i] = ++ch;
	}
}

void Graph :: get_edges(){
		
	int t;
		
	cout<<endl<<"Enter Number of Edges : ";
	cin>>t;
	
	for(int i = 0; i < t; i++){
		
		clear(0);
		char a, b;
		
		get_edge(i,a,b);
		
		while(1){
			
			if((int(a-65) < 0 || int(a-65) >= vertices) || (int(b-65) < 0 || int(b-65) >= vertices)){
			
				cout<<endl<<"Enter Vertices between (A - "<<char(vertices+64)<<") Only !!!"<<endl;
				
				clear(1);
				get_edge(i,a,b);
			}
			else{
				graph[int(a-65)][int(b-65)] = 1;
				break;
			}
		}
	}
}
	
void Graph :: get_choice(int i, int j){
		
	clear(0);
	isAdjacent(i,j);
		
	switch(choice()){
				
		case '0':
			graph[i][j] = 0;
		break;
			
		case '1':
			graph[i][j] = 1;
		break;
					
		default:
			cout<<endl<<"You Entered Wrong Choice !!!";
			get_choice(i,j);
	}
}

int BFS :: get_value(){
	
	char value;
		
	cout<<"Enter Any Vertex Between (A - "<<char(vertices+64)<<") : ";
	cin>>value;
		
	if(int(value-65) < 0 || int(value-65) >= vertices){
		
		cout<<endl<<"Vertex is not Exist !!!"<<endl;
		
		display(1);
		return get_value();
	}
		
	return int(value-65);
}

void BFS :: Delete(){
		
	for(int i = 0; i < vertices; i++)
		delete graph[i];
		
	delete graph;
	delete queue;
	delete check;
	
	cout<<n;
}

bool BFS :: isfull(){
	
	if(rear == vertices-1)
		return true;
	else
		return false;
}

bool BFS :: isempty(){
	
	if(rear == -1)
		return true;
	
	else if(front > rear){
		front = rear = -1;
		return true;
	}
	else
		return false;
}


int main(){
	
	BFS GT;
	GT.get_graph();
	GT.display(0);
	GT.enqueue();
	GT.Delete();
	
	return 0;
}