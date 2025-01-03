#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
};
Node *root = NULL;

Node *insertNode(Node *root,int v)
{
    if(root==NULL)
    {
        Node *n = new Node;
        n->val = v;
        n->left = NULL;
        n->right = NULL;
        root = n;
        return root;
    }
    else if(v < root->val) //left side
    {
        root->left = insertNode(root->left,v);
    }
    else //right side
    {
        root->right = insertNode(root->right,v);
    }
    return root;

}
void inOrder(Node *root)
{
    if(root==NULL)
        return;
    inOrder(root->left);
    cout<<root->val<<"->";
    inOrder(root->right);
}
/*
    1. minimun value
    2. maximum value
*/
int findMin(Node *root)
{
    if(root==NULL)
    {
        return -1;
    }
    if(root->left==NULL)
    {
        return root->val;
    }
    else
    {
        return findMin(root->left);
    }
}

int findMax(Node *root)
{
    if(root==NULL)
    {
        return -1;
    }
    if(root->right==NULL)
    {
        return root->val;
    }
    else
    {
        return findMax(root->right);
    }
}

bool searchNode(Node *root,int item)
{
    if(root==NULL)
    {
        return false;
    }
    if(root->val == item)
    {
        return true;
    }
    else if(item<root->val)
    {
        return searchNode(root->left,item);
    }
    else
    {
        return searchNode(root->right,item);
    }
}
Node *findNode(Node *root)
{
    if(root->right==NULL)
        return root;
    else
        return findNode(root->right);
}
Node *deleteNode(Node *root,int item)
{
    if(root==NULL)
        return root;
    if(item<root->val)
        root->left = deleteNode(root->left,item);
    else if(item>root->val)
        root->right = deleteNode(root->right,item);
    else ///founded
    {
        if(root->left==NULL && root->right==NULL)
        {
            /// Leave node no child
            delete root;
            root = NULL;
        }
        else if(root->left==NULL)
        {
            /// right child
            Node *ptr = root;
            root = root->right;
            delete ptr;
        }
        else if(root->right==NULL)
        {
            /// left child
            Node *ptr = root;
            root = root->left;
            delete ptr;
        }
        else
        {
            /// both child
            Node *ptr = findNode(root->left);
            root->val = ptr->val;
            root->left = deleteNode(root->left,ptr->val);
        }
        return root;
    }
}
int main()
{
    root = insertNode(root,12);
    root = insertNode(root,5);
    root = insertNode(root,15);
    root = insertNode(root,1);
    root = insertNode(root,3);
    root = insertNode(root,13);
    root = insertNode(root,14);
    root = insertNode(root,9);
    root = insertNode(root,18);



    inOrder(root);
    cout<<endl;
    cout<<findMin(root);
    cout<<endl;
    cout<<findMax(root);
    cout<<endl;
    cout<<searchNode(root,11)<<endl;
    root = deleteNode(root,15);
    inOrder(root);
    return 0;
}
