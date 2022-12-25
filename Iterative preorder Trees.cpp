#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node* lc;
    node* rc;
    node* create();
    void preorder(node*);
};
node* node::create()
{
    int x;
    cout<<"Enter data(-1 for no data):";
    cin>>x;
    if(x==-1)
        return NULL;
    node*p=new node;
    p->data=x;
    cout<<"Enter left child of"<<x<<endl;
    p->lc=create();
    cout<<"Enter right child of"<<x<<endl;
    p->rc=create();
    return p;
}
void node::preorder(node* root)
{
        cout<<"Iterative Preorder Traversal >>";
        if(root==NULL)
            return;
        stack <node*> S;
        node* curr= root;
        S.push(curr);
        while(!S.empty()){
            curr=S.top();
            S.pop();
            cout<<curr->data<<' ';
            if(curr->rc)
                S.push(curr->rc);
            if(curr->lc)
                S.push(curr->lc);
        }
        cout<<endl;
}
int main()
{
    node a;
    node* root=NULL;
    root=a.create();
    a.preorder(root);
}
