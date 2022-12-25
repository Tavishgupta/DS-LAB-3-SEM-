#include <iostream>

using namespace std;

class node
{
    public:
    int data;
    node* lc;
    node* rc;
    node* insertion(node*);
    void search(node*);
    void display(node*);
    node* deleten(node*,int);

};
node* node::insertion(node* root)
{
    node* temp=new node();
    cout<<"Enter the element:"<<endl;
    int ele;
    cin>>ele;
    temp->data=ele;
    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        node* curr=root;
        node* prev=NULL;
        while(curr!=NULL)
        {
            prev=curr;
            if(temp->data<curr->data)
                curr=curr->lc;
            else if(temp->data>curr->data)
                curr=curr->rc;
            else
            {
                cout<<"Insertion not possible"<<endl;
            }
        }
        if(temp->data>prev->data)
            prev->rc=temp;
        else
            prev->lc=temp;
    }
    return root;
}
void node::search(node* root)
{
    int x;
    cout<<"Enter element to be searched:";
    cin>>x;
    if(root==NULL)
    {
        cout<<"Tree is empty";
        return;
    }
    node* curr=root;
    while(curr!=NULL)
    {
        if(curr->data==x)
        {
            cout<<"Element found";
            return;
        }
        else if(x<curr->data)
            curr=curr->lc;
        else
            curr=curr->rc;
    }
    cout<<"Element not found";
}
void node::display(node* root)
{
    if(root==NULL)
        return;
    display(root->lc);
    cout<<"->"<<root->data;
    display(root->rc);
}
node* node::deleten(node* root,int elem)
{
if(root==NULL)
        return root;
    if(elem>root->data)
        root->rc=deleten(root->rc,elem);
    else if(elem<root->data)
        root->lc=deleten(root->lc,elem);
    else{
        node* temp=NULL;
        if(root->lc==NULL){
            temp=root->rc;
            delete root;
            return temp;
        }
        else if(root->rc==NULL){
            temp= root->lc;
            delete root;
            return temp;
        }
        else{
            // Both children exist
            temp=root;
            while(temp && temp->lc){
                temp=temp->lc;
            }
            root->data=temp->data;
            root->rc=deleten(root->rc,temp->data);
        }
    }
    return root;
}
int main()
{
    node a;
    node* root=NULL;
    root=a.insertion(root);
    root=a.insertion(root);
    root=a.insertion(root);
    root=a.insertion(root);
   root=a.deleten(root,2);
    a.display(root);
}
