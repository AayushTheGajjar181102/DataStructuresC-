#include<iostream>
#include "../../Menu_Driven_Funs.h"
using namespace std;

void Menu :: infodequeue(){
	
	cout<<endl<<"MENU : ";
	cout<<n<<"1. Enqueue At Front";
	cout<<n<<"2. Enqueue At Back";
	cout<<n<<"3. Dequeue At Front";
	cout<<n<<"4. Dequeue At Back";
	cout<<n<<"5. Peek";
	cout<<n<<"6. Display";
	cout<<n<<"7. Exit";
}

void Menu :: infoqueue(){
	
	cout<<endl<<"MENU : ";
	cout<<n<<"1. Enqueue";
	cout<<n<<"2. Dequeue";
	cout<<n<<"3. Peek";
	cout<<n<<"4. Display";
	cout<<n<<"5. Exit";
}

void Menu :: infotree(){

	cout<<endl<<"MENU :";
	cout<<n<<"1. Insertion";
	cout<<n<<"2. Inorder Traversal";
	cout<<n<<"3. Preorder Traversal";
	cout<<n<<"4. Postorder Traversal";
	cout<<n<<"5. Exit";
}

void Menu :: isAdjacent(int i, int j){
	
	cout<<endl<<"Are "<<i<<" and "<<j<<" adjacent vertices ? ";
	cout<<n<<"0. No";
	cout<<n<<"1. Yes ";
}

char Menu :: choice(){
	
	string ch;
	
	cout<<n<<"Enter Choice : ";
	getline(cin,ch);
	
	if(ch[1] == '\0')
		return ch[0];
	else
		return '/';
}

void Menu :: clear(bool b){
	
	cout<<n<<"Press ENTER Key : ";
	
	if(b)
		cin.get() == '\n';
		
	if(cin.get() == '\n')
		system("clear");
	else
		clear(b);
	
}

void Menu :: infoSimpleList(){
	
	cout<<endl<<"MENU :-";
	cout<<n<<"1. First Insertion";
	cout<<n<<"2. Last Insertion";
	cout<<n<<"3. Between Insertion";
	cout<<n<<"4. First Deletion";
	cout<<n<<"5. Between Deletion";
	cout<<n<<"6. Last Deletion";
	cout<<n<<"7. Display";
	cout<<n<<"8. Size";
	cout<<n<<"9. Exit";
}

void Menu :: infostack(){
	
	cout<<endl<<"MENU :-";
	cout<<n<<"1. Push";
	cout<<n<<"2. Pop";
	cout<<n<<"3. Peep";
	cout<<n<<"4. Display";
	cout<<n<<"5. Exit";
}

