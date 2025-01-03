#include <bits/stdc++.h>
using namespace std;

void findModes(int arr[], int n)
{
    int counter[101] = {0};
    int maxCounter = 0;

    for (int i = 0; i < n; i++)
    {
        counter[arr[i]]++;
        if (counter[arr[i]] > maxCounter)
        {
            maxCounter = counter[arr[i]];
        }
    }

    bool allSame = true;
    for (int i = 0; i < 101; i++)
    {
        if (counter[i] > 0 && counter[i] != maxCounter)
        {
            allSame = false;
            break;
        }
    }

    if (allSame || maxCounter == 1)
    {
        cout << "There are no modes." << endl;
    }
    else
    {
        cout << "MODES: ";
        for (int i = 0; i < 101; i++)
        {
            if (counter[i] == maxCounter)
            {
                cout << i << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    int N;
    cout << "Enter the array size: ";
    cin >> N;

    int arr[N];
    cout << "Enter the numbers in the array: " << endl;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    findModes(arr, N);

    return 0;
}
