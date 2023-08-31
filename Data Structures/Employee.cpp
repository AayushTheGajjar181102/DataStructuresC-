#include<iostream>
using namespace std;

static int current = -1;
static bool flag = false;

struct Employee{
    int id;
    string name;
    float salary;
};

void display(string input){
    cout<<input; 
}

void addEmployee(Employee rec[], int max){

    current++;

    if(current >= max){
        cout<<"\nEmployees Records are Full!\n";
        return;
    }
   
    cout<<"\nEnter Employee "<<current+1<<" Details : \n";
    display("Enter ID : ");
    cin>>rec[current].id;

    display("Enter Name : ");
    cin>>rec[current].name;

    display("Enter Salary : ");
    cin>>rec[current].salary;
}

void deleteEmployee(Employee rec[]){

    if(current < 0){
        cout<<"\n Employee Record is Empty !";
        return;
    }

    int id;
    cout<<"\nEnter ID : ";
    cin>>id;

    for(int i=0; i<=current; i++){

        Employee temp;

        if(rec[i].id == id)
            flag = true;
        
        if(flag){

            if(i < current){
                rec[i].id = rec[i+1].id;
                rec[i].name = rec[i+1].name;
                rec[i].salary = rec[i+1].salary;
            }
            else{
                rec[i].id = 0;
                rec[i].name = "";
                rec[i].salary = 0;
            }
        }
    }
}


void listOfEmployees(Employee rec[]){
    
    if(current < 0){
        cout<<"\nList is Empty ! \n";
        return;
    }
    cout<<"\nList of Employees : \n";

    for(int i=0; i<=current; i++){

        cout<<"\nEmployee "<<current+1<<" Details : \n";
        display("ID = ");
        cout<<rec[i].id;

        display("\nName = ");
        cout<<rec[i].name;

        display("\nSalary = ");
        cout<<rec[i].salary;
    }
}

int setEmpRecord(){
    int n;
    cout<<"\nEnter No. of Records : ";
    cin>>n;
    return n;
}

int main(){

    int choice;
    int no = setEmpRecord();
    struct Employee empRecord[no];

    while(1){

        cout<<"\nEnter Choice : \n";
        cout<<"\n1.Add Employee";
        cout<<"\n2.List Employee";
        cout<<"\n3.Delete Employee \n";
        cout<<"\n4.Exit \n";
        cout<<"\nEnter Choice : ";
        cin>>choice;

        switch(choice){
            case 1:
            addEmployee(empRecord, no);
            break;

            case 2:
            listOfEmployees(empRecord);
            break;

            case 3:
            deleteEmployee(empRecord);
            break;
            
            default:
            cout<<"\n Please Enter (1-3) !\n";
        }
    }
    return 0;
}