#include<bits/stdc++.h>
using namespace std;

struct Node{
    int item,prio;
    Node *next;
};
Node *F = NULL;

bool isEmpty(){
    return F==NULL;
}

void enqueue(int it,int p){
    Node *newNode = new Node;
    newNode->item = it;
    newNode->prio = p;
    newNode->next = NULL;

    if(F==NULL){
        F = newNode;
        return;
    }
    ///
    if(F->prio < newNode->prio){
        newNode->next = F;
        F = newNode;
    }
    else{
        Node *ptr = F;
        while(ptr->next!=NULL){
            if(ptr->next->prio < newNode->prio)
                break;
            ptr = ptr->next;
        }
        newNode->next = ptr->next;
        ptr->next = newNode;
    }
}
int dequeue(){
    if(isEmpty()){
        cout<<"UNDERFLOW"<<endl;
        return '\0';
    }
    int item = F->item;
    Node *tmp = F;
    F = F->next;
    delete tmp;
    return item;
}
void display(){
    if(isEmpty()){
        cout<<"Queue is Empty.."<<endl;
        return;
    }
    cout<<"Q: ";
    Node *ptr = F;
    while(ptr){
        cout<<"("<<ptr->item<<","<<ptr->prio<<")->";
        ptr = ptr->next;
    }
    cout<<endl;
}
int main(){

    enqueue(2,1);
    enqueue(5,3);
    enqueue(1,4);
    enqueue(10,2);
    display();
    cout<<dequeue()<<" is deleted.."<<endl;
    display();
    return 0;
}
