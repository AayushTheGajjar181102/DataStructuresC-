#include<iostream>
#include<map>
#include<string>
using namespace std;

const string n = "\n\n";

int main(){
	
	map<string, string> myDict;
	
	myDict.insert(pair<string, string>("orange", "die Orange"));
	myDict.insert(pair<string, string>("strawberry", "die Erdbeere"));
	myDict.insert(pair<string, string>("apple", "der Apfel"));
	myDict.insert(pair<string, string>("banana", "die Banane"));
	
	for(auto pair : myDict)
		cout<<pair.first<<" - "<<pair.second<<n;
	
	return 0;
} 