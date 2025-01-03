#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *next;
};

Node *TOP = NULL;

int isEmpty()
{
    return TOP == NULL;
}

void push(int item)
{
    int studentID = 112230958;
    int sum = (1 + 1 + 2 + 2 + 3 + 0 + 9 + 5 + 8);
    int pos = (sum % 4) + 1;

    Node *newNode = new Node;
    newNode->val = item;
    newNode->next = NULL;

    if (isEmpty() || pos == 1)
    {
        newNode->next = TOP;
        TOP = newNode;
        return;
    }

    int currentSize = 0;
    Node* temp = TOP;
    while (temp != NULL)
    {
        currentSize++;
        temp = temp->next;
    }

    if (pos > currentSize)
    {
        newNode->next = TOP;
        TOP = newNode;
        return;
    }

    temp = TOP;
    int counter = 1;

    while (temp->next != NULL && counter < pos - 1)
    {
        temp = temp->next;
        counter++;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

int pop()
{
    if (isEmpty())
    {
        cout << "UNDERFLOW" << endl;
        return -1;
    }

    Node *temp = TOP;
    TOP = TOP->next;
    int item = temp->val;
    delete temp;
    return item;
}

int peek()
{
    return TOP->val;
}

void display()
{
    if (isEmpty())
    {
        cout << "Stack is empty!" << endl;
        return;
    }
    Node* temp = TOP;
    while (temp != NULL)
    {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void Sort()
{
    Node *sortedHead = NULL;

    while (!isEmpty())
    {
        int temp = pop();

        Node *newNode = new Node;
        newNode->val = temp;
        newNode->next = NULL;

        if (sortedHead == NULL || temp >= sortedHead->val)
        {
            newNode->next = sortedHead;
            sortedHead = newNode;
        }
        else
        {
            Node *current = sortedHead;
            while (current->next != NULL && current->next->val > temp)
            {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    while (sortedHead != NULL)
    {
        push(sortedHead->val);
        Node *temp = sortedHead;
        sortedHead = sortedHead->next;
        delete temp;
    }
}

int main()
{
    push(10);
    push(5);
    push(7);
    push(13);
    push(15);
    push(20);

    cout << "Stack elements after pushing: ";
    display();

    cout << "Top element (peek): " << peek() << endl;
    cout << "Popped element: " << pop() << endl;

    cout << "Stack elements after popping: ";
    display();

    Sort();
    cout << "Stack elements after sorting: ";
    display();

    return 0;
}
