#include <bits/stdc++.h>
using namespace std;


struct Node
{
    string name;
    float cgpa;
    Node *left;
    Node *right;
};
Node *root = NULL;

Node *insertNode(Node *root, string nm, float cg)
{
    if(root==NULL)
    {
        Node *n = new Node;
        n->name = nm;
        n->cgpa = cg;
        n->left = NULL;
        n->right = NULL;
        root = n;
        return root;
    }
    else if(cg < root->cgpa) //left side
    {
        root->left = insertNode(root->left,nm,cg);
    }
    else //right side
    {
        root->right = insertNode(root->right,nm,cg);
    }
    return root;

}
void inOrder(Node *root)
{
    if(root==NULL)
        return;
    inOrder(root->left);
    cout<< root->name <<"->";
    inOrder(root->right);
}
int main()
{
    root = insertNode(root,"sakib", 3.9);
    root = insertNode(root, "mollah", 3.95);
    root = insertNode(root,"rashed", 3.8);
    root = insertNode(root,"jarin", 3.85);
    root = insertNode(root,"nayeem", 3.92);

    inOrder(root);
    cout<<endl;
    return 0;
}

