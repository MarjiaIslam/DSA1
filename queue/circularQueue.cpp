#include<bits/stdc++.h>
using namespace std;
#define SIZE 5

int Q[SIZE],F = -1, R = -1;
bool isEmpty(){
    return F == -1;
}
bool isFull(){
    return R+1 == F;
}
void enqueue(int v){
    if(isFull()){
        cout<<"OVERFLOW"<<endl;
        return;
    }
    if(F==-1){///For the fast
        F=R=0;
    }
    /// R = (R+1)%SIZE;
    else if(R+1==SIZE){
        R = 0;
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
    /// F = (F+1)%SIZE;
    else if(F+1==SIZE){
        F = 0;
    }
    else{
       F = F + 1;
    }
    return item;
}
void display(){
    int i;
    if(isEmpty()){
        cout<<"Queue is Empty.."<<endl;
        return;
    }
    cout<<"Q: ";
    for(i=F; i!=R; i=(i+1)%SIZE){
        cout<<Q[i]<<" ";
    }
    cout<<Q[i];
    cout<<endl;
}
int main(){

    enqueue(10);
    enqueue(17);
    enqueue(5);
    display();
    cout<<dequeue()<<" is deleted."<<endl;
    display();
    enqueue(13);
    enqueue(11);
    display();
    enqueue(9);
    display();
    return 0;
}
