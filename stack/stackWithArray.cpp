#include<bits/stdc++.h>
using namespace std;
#define MAXSIZE 10
int TOP = -1,stck[MAXSIZE];

bool isEmpty(){
    return TOP == -1;
}

bool isFull(){
    return TOP+1 == MAXSIZE;
}

void push(int item){
    if(isFull())
    {
        cout<<"OVERFLOW"<<endl;
        return;
    }
    TOP = TOP + 1;
    stck[TOP] = item;
}

int POP(){
    if(isEmpty()){
        cout<<"UNDERFLOW"<<endl;
        return -1;
    }
    int item = stck[TOP];
    TOP = TOP-1;
    return item;
}

int peek(){
    return stck[TOP];
}

int main(){
    push(10);
    push(5);
    push(7);
    push(13);
    cout<<"Top:"<<TOP<<endl;
    cout<<peek()<<endl;
    cout<<POP()<<" is deleted"<<endl;
    cout<<"Top:"<<TOP<<endl;
    cout<<peek()<<endl;
    return 0;
}
