#include <bits/stdc++.h>
using namespace std;

#define SIZE 1000
int Q[SIZE], F = -1, R = -1;
int freq[101];

bool isEmpty() {
    return F == -1;
}

bool isFull() {
    return R + 1 == SIZE;
}

void enqueue(int v) {
    if (isFull()) {
        cout << "OVERFLOW" << endl;
        return;
    }
    if (F == -1) {
        F = R = 0;
    } else {
        R = (R + 1) % SIZE;
    }
    Q[R] = v;
}


void display() {
    if (isEmpty()) {
        cout << "Queue is Empty" << endl;
        return;
    }
    cout << "Q: ";
    for (int i = F; i <= R; i++) {
        cout << Q[i] << " ";
    }
    cout << endl;
}

void findMostFrequent() {
    int maxCount = 0;
    int mostFrequentValue = -1;

    for (int i=1; i <= 100; i++) {
        freq[i] = 0;
    }

    for (int i=F; i <= R; i++) {
        freq[Q[i]]++;
    }

    for (int i=1; i <= 100; i++) {
        if (freq[i] > maxCount) {
            maxCount = freq[i];
            mostFrequentValue = i;
        }
    }

    if (maxCount>1) {
        cout << "The most occurred value: " << mostFrequentValue << " occurred " << maxCount << " times" << endl;
    } else {
        cout << "No value occurred more than once." << endl;
    }
}

int main() {
    int N;

    cout << "Enter the number of random values: ";
    cin >> N;

    if (N <= 0 || N >= 1000) {
        cout << "Invalid input!! N should be between 0 and 1000." << endl;
        return 0;
    }

    srand(time(0));

    cout << "Random values: ";
    for (int i = 0; i < N; i++) {
        int randomValue = rand() % 100 + 1;
        cout << randomValue << " ";
        enqueue(randomValue);
    }
    cout << endl;

    findMostFrequent();

    return 0;
}
