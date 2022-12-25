#include <iostream>

using namespace std;

class node
{
    public:
    int row;
    int col;
    int val;
    node* next;
    node* insert(node*,int,int,int);
    void print(node*,int,int);
    node* transpose(node*);
    node* sorting(node*);
    void display(node*);
};
node* node::insert(node* head,int r,int c,int v)
{
    node* temp=new node;
    temp->row=r;
    temp->col=c;
    temp->val=v;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
        temp->next=head;
    }
    else
    {
     node* curr=head;
     while(curr->next!=head)
            curr=curr->next;
     curr->next=temp;
     temp->next=head;
    }
    return head;
}
void node::print(node* head,int m,int n)
{
    if(head==NULL)
        cout<<"Empty matrix";
   else
   {
       node* curr=head;
       for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
           if(curr->row==i&&curr->col==j)
           {
                cout<<curr->val<<" ";
                curr=curr->next;
           }
           else
            cout<<"0"<<" ";
        }
        cout<<endl;
    }
}
}
node* node::sorting(node* head)
{
    if(head==NULL)
    {
        cout<<"No nodes present"<<endl;
    }
    else
    {
        node* curr=head;
                do{
            node* nextptr = curr->next;
            while(nextptr!=head){
                if(nextptr->row < curr->row){
                    swap(nextptr->row,curr->row);
                    swap(nextptr->col,curr->col);
                    swap(nextptr->val,curr->val);
                }
                nextptr = nextptr->next;
            }
            curr = curr->next;
        }while(curr->next!=head);
    }
    return head;
}
node* node::transpose(node* head)
{
    node* curr=head;
    int x;
    x = curr->row;
    curr->row = curr->col;
    curr->col = x;
    curr=curr->next;
    while(curr!=head)
    { x = curr->row;
    curr->row = curr->col;
    curr->col = x;
    curr=curr->next;
    }
    return head;
}
void node::display(node* head)
{
  node* curr=head;
  cout<<"->"<<curr->row<<"->"<<curr->col<<"->"<<curr->val<<endl;
  curr=curr->next;
  while(curr!=head)
  {
    cout<<"->"<<curr->row<<"->"<<curr->col<<"->"<<curr->val<<endl;
    curr=curr->next;
  }
}
int main()
{
    node a;
    node* head=NULL;
    int i,j,m,n,v;
    cout<<"Enter rows:";
    cin>>m;
    cout<<"Enter columns:";
    cin>>n;
    cout<<"Enter values:";
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>v;
            if(v!=0)
                head=a.insert(head,i,j,v);
        }
    }
    cout<<"Matrix:"<<endl;
    a.display(head);
    head=a.transpose(head);
    head=a.sorting(head);
    cout<<"Transpose:"<<endl;
    a.display(head);
}
