#include<bits/stdc++.h>
using namespace std;
#define SIZE 5

int Q[SIZE],F = -1, R = -1;
bool isEmpty(){
    return F == -1;
}
bool isFull(){
    return R+1 == SIZE;
}
void enqueue(int v){
    if(isFull()){
        cout<<"OVERFLOW"<<endl;
        return;
    }
    if(F==-1){///For the fast
        F=R=0;
    }
    else{/// For other cases
        R = R + 1;
    }
    Q[R] = v;
}
int dequeue(){
    if(isEmpty()){
        cout<<"UNDERFLOW"<<endl;
        return -1;
    }
    int item = Q[F];
    if(F==R){
        F=R=-1;
    }
    else{
       F = F + 1;
    }
    return item;
}
void display(){
    if(isEmpty()){
        cout<<"Queue is Empty.."<<endl;
        return;
    }
    cout<<"Q: ";
    for(int i=F; i<=R; i++){
        cout<<Q[i]<<" ";
    }
    cout<<endl;
}
int main(){

    enqueue(10);
    enqueue(17);
    enqueue(5);
    display();
    cout<<dequeue()<<" is deleted."<<endl;
    display();
    return 0;
}
