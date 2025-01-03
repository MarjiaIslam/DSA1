#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;

Node *createNode(int value)
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(int value)
{
    Node *newNode = createNode(value);
    if (head==NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}


void insertInMid(int value)
{
    if (head==NULL)
    {
        head = createNode(value);
        return;
    }

    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    int mid = count / 2;


    Node *cur = head;
    for (int i = 0; i < mid - 1; i++)
    {
        cur = cur->next;
    }

    Node *newNode = createNode(value);
    newNode->next = cur->next;
    cur->next = newNode;
}


void addArrayAtEnd(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        insertAtEnd(arr[i]);
    }
}


void deleteKthElement(int k)
{
    if (head==NULL) return;

    if (k == 1)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node *cur = head;
    Node *prev = NULL;
    for (int i=0; i < k-1; i++)
    {
        prev = cur;
        cur = cur->next;
    }
    if(prev!=NULL)
    {
        prev->next = cur->next;
    }
    delete cur;

}


void replaceLastWithSum()
{
    if (head==NULL) return;

    int sum = 0;
    Node *temp = head;
    while (temp->next != NULL)
    {
        sum += temp->data;
        temp = temp->next;
    }
    sum += temp->data;

    temp->data = sum;
}


void searchEvenNumbers()
{
    Node *temp = head;
    bool foundEven = false;
    while (temp != NULL)
    {
        if (temp->data % 2 == 0)
        {
            cout << temp->data << " ";
            foundEven = true;
        }
        temp = temp->next;
    }
    if (!foundEven)
    {
        cout << "No even numbers found in the list.";
    }
    cout << endl;
}



void reverseList()
{
    Node *prev = NULL;
    Node *current = head;
    Node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}


void printList()
{
    Node *temp = head;
    while (temp !=NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{

    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtEnd(40);

    cout << "Original List: ";
    printList();


    insertInMid(25);
    cout << "After inserting 25 in middle: ";
    printList();


    int arr[] = {50, 60, 70};
    addArrayAtEnd(arr, 3);
    cout << "After adding array at end: ";
    printList();


    deleteKthElement(3);
    cout << "After deleting 3rd element: ";
    printList();


    replaceLastWithSum();
    cout << "After replacing last element with sum: ";
    printList();


    cout << "Even numbers in the list: ";
    searchEvenNumbers();



    reverseList();
    cout << "After reversing the list: ";
    printList();

    return 0;
}
