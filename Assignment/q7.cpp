#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int vtx, w;
    Node *next;
};

int V, E;
Node *g[10];

void makegraph(int src, int dst, int w)
{
    Node *newNode = new Node;
    newNode->vtx = dst;
    newNode->w = w;
    newNode->next = NULL;
    if (g[src] == NULL)
    {
        g[src] = newNode;
        return;
    }
    newNode->next = g[src];
    g[src] = newNode;
}

void printList(Node *ptr)
{
    while (ptr)
    {
        cout << "(" << ptr->vtx << "," << ptr->w << ")->";
        ptr = ptr->next;
    }
    cout << endl;
}

void topologicalSortUtil(int v, bool visited[], stack<int> &Stack)
{
    visited[v] = true;
    Node *ptr = g[v];

    while (ptr != NULL)
    {
        if (!visited[ptr->vtx])
        {
            topologicalSortUtil(ptr->vtx, visited, Stack);
        }
        ptr = ptr->next;
    }
    Stack.push(v);
}

void longestPath(int src)
{
    stack<int> Stack;
    int dist[V];


    bool visited[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            topologicalSortUtil(i, visited, Stack);
        }
    }

    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MIN;
    }
    dist[src] = 0;


    while (!Stack.empty())
    {
        int u = Stack.top();
        Stack.pop();

        if (dist[u] != INT_MIN)
        {
            Node *ptr = g[u];
            while (ptr != NULL)
            {
                if (dist[ptr->vtx] < dist[u] + ptr->w)
                {
                    dist[ptr->vtx] = dist[u] + ptr->w;
                }
                ptr = ptr->next;
            }
        }
    }


    cout << "The longest distances from vertex " << src << " are:\n";
    for (int i = 0; i < V; i++)
    {
        if (dist[i] == INT_MIN)
        {
            cout << "dist(" << src << ", " << i << ") = -INF\n";
        }
        else
        {
            cout << "dist(" << src << ", " << i << ") = " << dist[i] << endl;
        }
    }
}

int main()
{
    int a, b, c;
    cin >> V >> E;

    for (int i = 0; i < E; i++)
    {
        cin >> a >> b >> c;
        makegraph(a, b, c);
    }

    cout << "----------Graph---------\n";
    for (int i = 0; i < V; i++)
    {
        cout << i << ": ";
        printList(g[i]);
    }

    int src;
    cout << "Enter the source vertex: ";
    cin >> src;

    longestPath(src);

    return 0;
}

