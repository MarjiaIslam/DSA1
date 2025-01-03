#include<bits/stdc++.h>
using namespace std;

struct Node{
    char item;
    Node *next;
};
Node *F = NULL, *R = NULL;

bool isEmpty(){
    return F==NULL;
}

void enqueue(char ch){
    Node *newNode = new Node;
    newNode->item = ch;
    newNode->next = NULL;

    if(F==NULL){
        F = newNode;
        R = newNode;
        return;
    }

    R->next = newNode;
    R = newNode;
}
char dequeue(){
    if(isEmpty()){
        cout<<"UNDERFLOW"<<endl;
        return '\0';
    }
    char item = F->item;
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
        cout<<ptr->item<<"->";
        ptr = ptr->next;
    }
    cout<<endl;
}
int main(){

    enqueue('a');
    enqueue('c');
    display();
    cout<<dequeue()<<" is deleted.."<<endl;
    display();
    return 0;
}
