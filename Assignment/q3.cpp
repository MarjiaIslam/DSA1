#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;
Node *middle = NULL;
int length = 0;


Node *createNode(int value)
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void updateMiddle()
{
    if (length == 0)
    {
        middle = NULL;
    }
    else
    {
        int mid = length / 2;
        Node *cur = head;
        for (int i=0; i<mid; i++)
        {
            cur = cur->next;
        }
        middle = cur;
    }
}

void printEvenList()
{
    Node *temp = head;
    bool foundEven = false;
    while (temp!=NULL)
    {
        if (temp->data % 2 == 0)
        {
            cout << temp->data << " -> ";
            foundEven = true;
        }
        temp = temp->next;
    }
    cout<< "NULL" ;
    if (!foundEven)
    {
        cout << "No even numbers in the list";
    }
    cout << endl;
}

void printList()
{
    Node *temp = head;
    while (temp!=NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int listLength()
{
    return length;
}

void insertAtMiddle(int value)
{
    Node *newNode = createNode(value);
    if (head == NULL)
    {
        head = newNode;
        middle = newNode;
    }
    else if (length == 1)
    {
        newNode->next = head->next;
        head->next = newNode;
        middle = newNode;
    }
    else
    {

    int mid = length / 2;

    Node *cur = head;
    for (int i=0; i < mid-1; i++)
    {
        cur = cur->next;
    }

    newNode->next = cur->next;
    cur->next = newNode;
    }

    length++;
    updateMiddle();
}


int deleteMax()
{
    if (head == NULL) return -1;

    Node *temp = head;
    Node *maxNode = head;

    while (temp!=NULL)
    {
        if (temp->data > maxNode->data)
        {
            maxNode = temp;
        }
        temp = temp->next;
    }

    int maxValue = maxNode->data;

    Node *cur = head;
    Node *prev = NULL;
    while(cur->data != maxValue)
    {
        prev = cur;
        cur = cur->next;
    }

    if(prev!=NULL)
    {
        prev->next = cur->next;
    }
    delete cur;
    length--;
    updateMiddle();
    return maxValue;
}


int main()
{
    insertAtMiddle(5);
    insertAtMiddle(2);
    insertAtMiddle(4);
    insertAtMiddle(3);
    insertAtMiddle(7);


    cout << "List after insertions: ";
    printList();

    cout << "Even numbers in the list: ";
    printEvenList();

    cout << "List length: " << listLength() << endl;

    cout << "Max is: " << deleteMax() << endl;

    cout << "List after deleting max: ";
    printList();

    return 0;
}

