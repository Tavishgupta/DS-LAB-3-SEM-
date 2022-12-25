#include <iostream>
using namespace std;

class dnode{
public:
int data;
dnode* next;
dnode* prev;
void insrear();
void print();
void inspos();
void deleteend();
}*head;

void dnode::insrear()
{
    dnode* temp=new dnode;
 cout<<"Enter value:";
 cin>>temp->data;
 temp->next=NULL;
 temp->prev=NULL;
 if(head==NULL)
 {
    head=temp;
 }
 else{
    dnode* curr=head;
    while(curr->next!=NULL)
    curr=curr->next;
    temp->prev=curr;
    curr->next=temp;

 }
}
void dnode::print()
{
    if(head==NULL)
        cout<<"Nothing to print";
    else
    {
         dnode* curr=head;
    while(curr!=NULL)
    {
        cout<<"->"<<curr->data;
      curr=curr->next;
    }
}
}
void dnode::inspos()
{
    dnode* temp=new dnode;
 cout<<"Enter value:";
 cin>>temp->data;
 temp->next=NULL;
 temp->prev=NULL;
 cout<<"Enter position:";
 int x;
 cin>>x;
 if(head==NULL)
    {
        head=temp;
    }
    else
    {
        dnode* curr=head;
        for(int i=1;i<x-1;i++)
        {
            curr=curr->next;
        }
          temp->prev=curr;
          temp->next=curr->next;
          curr->next=temp;
           temp->next->prev=temp;
    }}
  void dnode::deleteend()
  {
      if(head==NULL)
        cout<<"Nothing to delete";
        else if(head->next==NULL)
        {
            head=NULL;
        }
      else
      {
          dnode* curr=head;
          dnode* del;
          while(curr->next!=NULL)
            curr=curr->next;
            del=curr;
          curr=curr->prev;
          curr->next=NULL;
          delete del;
      }
  }
int main()
{
    dnode a;
    a.insrear();
    a.insrear();
    a.inspos();
    a.deleteend();
    a.print();

}
