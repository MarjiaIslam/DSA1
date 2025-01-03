#include<bits/stdc++.h>
using namespace std;
struct Node{
    int vtx,w;
    Node *next;
};
int V,E;
Node *g[10];

void makegraph(int src,int dst,int w){
    Node *newNode = new Node;
    newNode->vtx = dst;
    newNode->w = w;
    newNode->next = NULL;
    if(g[src]==NULL){
        g[src] = newNode;
        return;
    }
    newNode->next = g[src];
    g[src] = newNode;
}

void printList(Node *ptr){
    while(ptr){
        cout<<"("<<ptr->vtx<<","<<ptr->w<<")->";
        ptr = ptr->next;
    }
    cout<<endl;
}

void BFS(int src){
    int par[V],dist[V];
    char color[V];
    for(int i=0;i<V;i++){
        color[i] = 'W';
        par[i] = -1;
        dist[i] = 0;
    }
    queue<int> Q;
    color[src] = 'G';
    Q.push(src);

    while(!Q.empty()){
        int cur_node = Q.front();
        Q.pop();
        if(color[cur_node]=='B')
            continue;
        /// Neighbor
        Node *ptr = g[cur_node];

        while(ptr){
            int neighbor = ptr->vtx;
            if(color[neighbor]=='W'){
                dist[neighbor] = dist[cur_node] + ptr->w;
                par[neighbor] = cur_node;
                color[neighbor] = 'G';
                Q.push(neighbor);
            }
            ptr = ptr->next;
        }
        color[cur_node] = 'B';
        cout<<cur_node<<"->";
    }

}

int main(){
    int a,b,c;
    cin>>V>>E;

    for(int i=1;i<=E;i++){
        cin>>a>>b>>c;
        makegraph(a,b,c);
        makegraph(b,a,c);/// only for undirected graph
    }
    cout<<"----------Graph---------"<<endl;
    for(int i=0;i<V;i++){
        cout<<i<<": ";
        printList(g[i]);
    }
    BFS(0);
    return 0;
}
/*
6 8
0 1 4
0 2 3
1 3 5
2 3 1
2 4 7
2 5 13
3 4 9
4 5 2
*/
