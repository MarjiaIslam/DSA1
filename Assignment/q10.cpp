#include <bits/stdc++.h>
using namespace std;

struct Employee
{
    string name;
    int id;
    int workHours;
};

struct Node
{
    Employee data;
    Node *next;
};

class MinStack
{
public:
    MinStack()
    {
        TOP = NULL;
    }

    void push(Employee employee)
    {
        Node *newNode = new Node;
        newNode->data = employee;
        newNode->next = NULL;
        if(TOP==NULL)
        {
            TOP = newNode;
            return;
        }
        newNode->next = TOP;
        TOP = newNode;
    }

    Employee pop()
    {
        if (isEmpty())
        {
            cout << "UNDERFLOW" << endl;
            Employee e1;
            return e1;
        }
        Node *tmp = TOP;
        TOP = TOP->next;
        Employee item = tmp->data;
        delete tmp;
        return item;
    }

    Employee top()
    {
        if (isEmpty())
        {
            cout << "UNDERFLOW" << endl;
            Employee e1;
            return e1;
        }
        return TOP->data;
    }

    Employee getMin()
    {
        if (isEmpty())
        {
            cout << "UNDERFLOW" << endl;
            Employee e1;
            return e1;
        }

        Node *temp = TOP;
        Employee minEmployee = temp->data;

        while (temp != NULL)
        {
            if (temp->data.workHours < minEmployee.workHours)
            {
                minEmployee = temp->data;
            }
            temp = temp->next;
        }

        return minEmployee;
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
            cout << temp->data.name << " (" << temp->data.id << ") - Work Hours: " << temp->data.workHours << endl;
            temp = temp->next;
        }
    }

private:
    Node *TOP;

    bool isEmpty()
    {
        return TOP == NULL;
    }
};

int main()
{
    MinStack stack;

    int N;
    cout << "Enter the number of employees (N): ";
    cin >> N;

    Employee employees[N];
    for (int i = 0; i < N; i++)
    {
        cout << "Enter details for employee " << i + 1 << ":" << endl;
        cout << "Name: ";
        cin >> employees[i].name;
        cout << "ID: ";
        cin >> employees[i].id;
        cout << "Work Hours: ";
        cin >> employees[i].workHours;

        stack.push(employees[i]);
    }

    cout << "\nEmployees in the stack:" << endl;
    stack.display();

    cout << "\nTop employee: " << stack.top().name << endl;

    Employee minEmployee = stack.getMin();
    cout << "Employee with minimum work hours: " << minEmployee.name
         << " (ID: " << minEmployee.id << ", Work Hours: " << minEmployee.workHours << ")" << endl;

    return 0;
}

