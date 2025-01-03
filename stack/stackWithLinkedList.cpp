#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node *next;
};
Node *TOP = NULL;

bool isEmpty(){
    return TOP == NULL;
}
void push(int item){
    Node *newNode = new Node;
    newNode->val = item;
    newNode->next = NULL;
    if(TOP==NULL){
        TOP = newNode;
        return;
    }
    newNode->next = TOP;
    TOP = newNode;
}

int pop(){
    if(isEmpty()){
        cout<<"UNDERFLOW"<<endl;
        return -1;
    }
    Node *tmp = TOP;
    TOP = TOP->next;
    int item = tmp->val;
    delete tmp;
    return item;

}
int peek(){
    return TOP->val;
}
void display()
{
    if (isEmpty())
    {
        cout << "Stack is empty!" << endl;
        return;
    }
    Node *temp = TOP;
    while (temp != NULL)
    {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main(){
    push(10);
    push(5);
    push(7);
    push(13);
    display();
    cout<<peek()<<endl;
    cout<<pop()<<" is deleted"<<endl;
    cout<<peek()<<endl;
    display();
    return 0;
}
