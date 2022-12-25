#include<iostream>
#define n 100
using namespace std;

class node
{
    public:
    int data;
    node* lc;
    node* rc;
    node* create();
    void preorder(node*);
    void postorder(node*);
    void inorder(node*);
    node* createi(node*);
    void preorderi(node*);
    int depth(node*);
    int leaf(node*);
    int ancestors(node*,int);
    node* parent(node*,int);
    node* copy(node*);
};
class stack
{
    public:
    int top;
    node* a[n];
    stack()
    {
        top=-1;
    }
    bool isFull()
    {
        return (top==n-1);
    }
    bool isEmpty()
    {
        return (top==-1);
    }
    void push(node* x)
    {
        if(isFull())
            cout<<"Stack is full";
        else
            a[++top]=x;
    }
    node* pop()
    {
        if(isEmpty())
            cout<<"Stack is empty";
        else
            return a[top--];
    }
    node* peek()
    {
         if(isEmpty())
            cout<<"Stack is empty";
        else
            return a[top];
    }
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
    cout<<"Enter left child of:"<<x<<endl;
    p->lc=create();
    cout<<"Enter right child of:"<<x<<endl;
    p->rc=create();
    return p;
}
void node::preorderi(node* root)
{
    if(root==NULL)
        return;
    stack s;
    node* curr=root;
    s.push(curr);
    while(!s.isEmpty())
    {
        curr=s.pop();
        cout<<curr->data;
        if(curr->rc)
            s.push(curr->rc);
        if(curr->lc)
            s.push(curr->lc);
    }
}

void node::preorder(node* root)
{
if(root==NULL)
    return;
cout<<root->data;
preorder(root->lc);
preorder(root->rc);
}
void node::postorder(node* root)
{
    if(root==NULL)
        return;
    postorder(root->lc);
    postorder(root->rc);
    cout<<root->data;
}
void node::inorder(node* root)
{
    if(root==NULL)
        return;
    inorder(root->lc);
    cout<<root->data;
    inorder(root->rc);
}
int node::depth(node* root)
{
    if(root==NULL)
        return NULL;
    int ldepth=depth(root->lc);
    int rdepth=depth(root->rc);
    if(ldepth>rdepth)
        return ldepth+1;
    else
        return rdepth+1;
}
int node::leaf(node* root)
{
    if(root==NULL)
        return 0;
    else if(root->lc==NULL&&root->rc==NULL)
        return 1;
    else
        return leaf(root->lc)+leaf(root->rc);
}
int node::ancestors(node* root,int x)
{
    if(root==NULL)
        return 0;
    if(root->data==x)
        return 1;
    if(ancestors(root->lc,x)||ancestors(root->rc,x))
    {
        cout<<root->data<<"";
        return 1;
    }
    return 0;
}
node* node::parent(node* root,int x)
{
    if(root==NULL)
        return NULL;
    if((root->lc!=NULL&&root->lc->data==x)||(root->rc!=NULL&&root->rc->data==x))
        return root;
    node* res=parent(root->lc,x);
    if(res!=NULL)
        return res;
    res=parent(root->rc,x);
    return res;
}
node* node::copy(node* root){
        if(!root)
            return NULL;
        node* dest= new node;
        dest->data=root->data;
        dest->lc=copy(root->lc);
        dest->rc=copy(root->rc);
        return dest;
}
int main()
{
    node a;
    node* root=NULL;
    node* root1=NULL;
    root=a.create();
    a.preorder(root);
    node* roo1=NULL;
    root1=a.copy(root);
    a.preorder(root1);
}
