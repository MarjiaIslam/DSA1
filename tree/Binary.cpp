#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node *left;
    Node *right;
};

Node *addNode(int v){
    Node *n = new Node;
    n->val = v;
    n->left = NULL;
    n->right = NULL;

    return n;
}
void preOrder(Node *root){
    if(root==NULL)
        return;
    cout<<root->val<<endl;
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node *root){
    if(root==NULL)
        return;

    inOrder(root->left);
    cout<<root->val<<endl;
    inOrder(root->right);
}

void postOrder(Node *root){
    if(root==NULL)
        return;

    postOrder(root->left);

    postOrder(root->right);
    cout<<root->val<<endl;
}

int main(){
    Node *root = NULL;

    root = addNode(7);
    root->left = addNode(11);
    root->right = addNode(13);
    root->right->left = addNode(6);
    root->left->left = addNode(10);
    root->right->right = addNode(9);
    root->right->left->right = addNode(5);
    postOrder(root);

    return 0;
}
