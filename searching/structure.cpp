#include<bits/stdc++.h>
using namespace std;

struct Student{
    int ID;
    string name;
    float cgpa;
};

int main(){
    Student s[10];
    for(int i=0;i<3;i++){
        cin>>s[i].ID>>s[i].name>>s[i].cgpa;
    }
    for(int i=0;i<3;i++){
        cout<<"--------Student #"<<i+1<<"-------"<<endl;
        cout<<"ID: "<<s[i].ID<<endl;
        cout<<"Name: "<<s[i].name<<endl;
        cout<<"CGPA: "<<s[i].cgpa<<endl;
        cout<<"------------------------------"<<endl;
    }
    return 0;
}
