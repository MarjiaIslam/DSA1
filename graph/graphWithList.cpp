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
