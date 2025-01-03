#include<bits/stdc++.h>
using namespace std;
struct Node{
    int vtx,w;
    Node *next;
};
int V,E;
Node *g[10];
char color[10];
int discover_time[10],finish_time[10];
int t;
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

void DFS_Visit(int src){
    color[src] = 'G';
    t = t+1;
    discover_time[src] = t;
    Node *cur = g[src];
    while(cur){
        if(color[cur->vtx]=='W'){
            DFS_Visit(cur->vtx);
        }
        cur = cur->next;
    }
    t = t + 1;
    finish_time[src] = t;
    color[src] = 'B';
    cout<<src<<"->";
}

void DFS(){
    for(int i=0;i<V;i++){
        color[i] = 'W';
    }
    t = 0;
    for(int i=0;i<V;i++){
        if(color[i]=='W'){
            DFS_Visit(i);
        }
    }
}
int main(){
    int a,b,c;
    cin>>V>>E;

    for(int i=1;i<=E;i++){
        cin>>a>>b;
        makegraph(a,b,1);
    }
    cout<<"----------Graph---------"<<endl;
    for(int i=0;i<V;i++){
        cout<<i<<": ";
        printList(g[i]);
    }
    cout<<"------------DFS Traversing------"<<endl;
    DFS();
    return 0;
}
/*
8 11
0 1
0 3
2 0
2 1
3 1
3 4
4 5
4 6
6 3
6 7
7 4
*/

