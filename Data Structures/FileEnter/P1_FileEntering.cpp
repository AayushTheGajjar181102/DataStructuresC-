#include<iostream>
#include<fstream>
using namespace std;

const string n = "\n\n";

void singleappend(){
	
	fstream out("../Menu/SECURE/DO NOT OPEN/Menu.cpp", ios :: app);
	string line;
	
	while(1){
		getline(cin,line);
		
		if(line == "end")
			break;
		
		if(line[line.length()-2] == '\\' && line[line.length()-1] == 'n')
			out<<endl;
		
		else
			out<<line<<endl;
	}
	out.close();
}

void another(string line){
	
	fstream out("../Menu/Menu_Driven_Funs.h", ios::out | ios :: in);
	
	out.seekp(0,ios::end);
	
	if(out.tellg() == 0)
		out<<"\t"<<line;
	
	else{
		out.seekp(-3,ios::end);
		out<<n<<"\t"<<line;
	}
	
	out.seekp(-2,ios::end);
	out<<";"<<endl<<"};";
	
	out.close();
	
}
void bothappend(){
	
	fstream out("../Menu/SECURE/DO NOT OPEN/Menu.cpp", ios :: app | ios :: in);
	string line;
	
	out<<endl;
	
	getline(cin,line);
		
	if(line[line.length()-2] == '\\' && line[line.length()-1] == 'n')
		out<<endl;
		
	else{
		string write = "";
		
		out<<line<<endl;
		out.seekg(-line.length()-1,ios :: cur);
	
		while(1){
			
			out>>line;
				
			if(!out)
				break;
			
			if(!(line == "Menu" || line == "::"))
				write += line + " ";
		}
		another(write);
	}
	out.close();
}

int main(){
	
	bothappend();
	singleappend();
	
	return 0;
}