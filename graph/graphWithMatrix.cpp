#include<bits/stdc++.h>
using namespace std;

int G[10][10];
int V,E;

int main(){
    int a,b,w;
    cin>>V>>E;
    for(int i=1;i<=E;i++){
        cin>>a>>b>>w;
        G[a][b] = w;
        G[b][a] = w; ///only for undirected graph
    }

    cout<<"-------Graph--------"<<endl;
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cout<<G[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
/*
5 4
0 3 5
0 4 2
1 2 1
1 4 3
*/
