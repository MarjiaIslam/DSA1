#include <bits/stdc++.h>
using namespace std;

struct Employee {
    string name;
    int id;
    string position;
};

struct Node {
    Employee data;
    Node *next;
};

Node *head = NULL;

void insert(Employee employee) {
    Node *newNode = new Node;
    newNode->data = employee;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int countConnectedEmployees() {
    if (head == NULL) {
        return 0;
    }

    int count = 0;
    Node *current = head;
    string connectedNames = "";

    while (current != NULL) {
        if (current->next != NULL) {
            connectedNames += current->data.name + " and " + current->next->data.name + "\n";
            count++;
            current = current->next;
        }
        current = current->next;
    }

    if (count > 0) {
        cout << "Connected Employees:\n" << connectedNames;
    } else {
        cout << "No connected employees." << endl;
    }

    return count;
}

void display() {
    if (head == NULL) {
        cout << "Linked list is empty." << endl;
        return;
    }

    cout << "------------- EMPLOYEE LIST --------------" << endl;
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data.name << " (" << temp->data.id << "), " << temp->data.position << endl;
        temp = temp->next;
    }
}

int main() {
    int N;

    cout << "Enter the number of employees: ";
    cin >> N;

    for (int i = 0; i < N; i++) {
        Employee employee;
        cout << "Enter details for employee " << i + 1 << ":" << endl;
        cout << "Name: ";
        cin >> employee.name;
        cout << "ID: ";
        cin >> employee.id;
        cout << "Position: ";
        cin >> employee.position;

        insert(employee);
    }

    display();

    int connectedEmployees = countConnectedEmployees();
    cout << "Number of connected pairs of employees: " << connectedEmployees << endl;

    return 0;
}
