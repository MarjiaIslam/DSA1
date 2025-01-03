#include<bits/stdc++.h>
using namespace std;

int G[10][10];
int V, E;

int main()
{
    int a, b;

    cin >> V >> E;

    for(int i = 1; i <= E; i++)
    {
        cin >> a >> b;
        G[a][b] = 1;
        G[b][a] = 1;
    }


    cout << "-------Graph (Adjacency Matrix)--------" << endl;
    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            cout << G[i][j] << " ";
        }
        cout << endl;
    }

    int max_adjacent = -1;
    int vertex_with_max_adjacent = -1;

    for(int i = 0; i < V; i++)
    {
        int count_adjacent = 0;
        for(int j = 0; j < V; j++)
        {
            if(G[i][j] == 1)
            {
                count_adjacent++;
            }
        }

        if(count_adjacent > max_adjacent)
        {
            max_adjacent = count_adjacent;
            vertex_with_max_adjacent = i;
        }
    }

    cout << "Vertex with the highest number of adjacent nodes: " << vertex_with_max_adjacent << endl;

    return 0;
}

