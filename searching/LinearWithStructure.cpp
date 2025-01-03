#include<bits/stdc++.h>
using namespace std;
struct Employee{
    int ID;
    string name;
    int salary;
};

void linearSearch(Employee e[],int n){
    for(int i=0;i<n;i++){
        string name = e[i].name;
        int last = name.size()-1;
        if(e[i].salary>500 && name[last]=='m'){
            cout<<e[i].ID<<endl;
        }
    }
}

int main(){

    Employee emp[5];
    for(int i=0;i<5;i++){
        cin>>emp[i].ID>>emp[i].name>>emp[i].salary;
    }
    linearSearch(emp,5);
    return 0;
}
