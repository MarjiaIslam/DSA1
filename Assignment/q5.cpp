#include<bits/stdc++.h>
using namespace std;

struct Node {
    int item;
    Node* next;
};

Node *F = NULL;

bool isEmpty() {
    return F == NULL;
}

void put(int val) {
    Node *newNode = new Node;
    newNode->item = val;
    newNode->next = NULL;

    if (F == NULL) {
        F = newNode;
        return;
    }

    if (F->item > newNode->item) {
        newNode->next = F;
        F = newNode;
        return;
    }

    Node *ptr = F;
    while (ptr->next != NULL && ptr->next->item < newNode->item) {
        ptr = ptr->next;
    }

    newNode->next = ptr->next;
    ptr->next = newNode;
}

int pop() {
    if (isEmpty()) {
        cout << "UNDERFLOW" << endl;
        return -1;
    }

    int item = F->item;
    Node *tmp = F;
    F = F->next;
    delete tmp;
    return item;
}

void display() {
    if (isEmpty()) {
        cout << "Queue is Empty.." << endl;
        return;
    }

    cout << "Queue: ";
    Node *ptr = F;
    while (ptr) {
        cout << ptr->item << " -> ";
        ptr = ptr->next;
    }
    cout << "NULL" << endl;
}

int main() {
    put(5);
    put(2);
    put(8);
    put(1);

    display();

    cout << pop() << " is deleted.." << endl;
    display();

    put(7);
    put(3);
    display();

    return 0;
}

