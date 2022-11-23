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

class DFS : public Graph{
	
	int *stack = new int[vertices], top;
	bool *check = new bool[vertices]{false};
	
	bool isfull();
	bool isempty();
	int get_value();
	
	void push(int value){stack[++top] = value;}
		
	int pop(){return stack[top--];}
	
	void printcheck(int v){
		
		cout<<" "<<char(v+65)<<" ";
		check[v] = true;
	}
	
	public:
		
	DFS(){top = -1;}
	
	void search(){
		
		while(!isfull()){
			
			if(isempty()){
				
				push(get_value());
				printcheck(stack[top]);
			}
			
			else{
				
				bool state = true;
				
				for(int i = 0; i < vertices; i++){
						
					if(graph[stack[top]][i] == 1 && (!check[i])){
				
						push(i);
						printcheck(stack[top]);
						state = false;
						break;
					}
				}
				
				if(state && top == 0)
					break;
				
				else if(state){
					
					top--;
					search();
				}
			}
		}
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

int DFS :: get_value(){
	
	char ch;
	cout<<endl<<"Enter Any Vertex between (A - "<<char(vertices+64)<<") : ";
	cin>>ch;
	
	if(int(ch-65) < 0 || int(ch-65) >= vertices){
		
		cout<<endl<<"Vertex is not Exist !!!"<<endl;
		display(1);
		return get_value();
	}
		
	return int(ch-65);
}

bool DFS :: isfull(){
	
	if(top >= vertices)
		return true;
	else
		return false;
}

bool DFS :: isempty(){
	
	if(top < 0)
		return true;
	else
		return false;
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

int main(){
	
	DFS GT;
	GT.get_graph();
	GT.display(0);
	GT.search();
	cout<<n;
	return 0;
}