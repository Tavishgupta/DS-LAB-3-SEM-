#include <iostream>

using namespace std;

class node{
public:
    int data;
    node* next;
    void inserta();
    void insertb();
    void deletee();
    void print();
    void reverse();
    void sort();
    void deletealt();
    void inssort();
}*head;
void node::inserta()
{
 node* temp=new node();
 cout<<"Enter value:";
 cin>>temp->data;
 temp->next=NULL;
 cout<<"Enter element after which node is to be inserted:";
 int x;
 cin>>x;
 if(head==NULL)
 {
     head=temp;
    cout<<"List is empty and node appended";
 }
 else{
        node* curr=head;
     while((curr->data!=x)&&(curr->next!=NULL))
    curr=curr->next;
    node* c=curr->next;
 curr->next=temp;
 temp->next=c;
}}
void node::insertb()
{
  node* temp=new node();
 cout<<"Enter value:";
 cin>>temp->data;
 temp->next=NULL;
 cout<<"Enter element before which node is to be inserted:";
 int x;
 cin>>x;
 if(head==NULL)
     {
     head=temp;
    cout<<"List is empty and node appended";
 }
 else if(head->next==NULL)
 {
     node* curr=head;
     temp->next=curr;
     head=temp;
 }
 else{
 node* curr=head;
 while((curr->next->data!=x)&&(curr->next!=NULL))
    curr=curr->next;
 node* c=curr->next;
 curr->next=temp;
 temp->next=c;
}}
void node::deletee()
{
    cout<<"Enter element to be deleted:";
    int x;
    cin>>x;
    if(head==NULL)
        cout<<"Nothing to delete";
    else{
             node* curr=head;
    node* prev;
    while((curr->data!=x)&&(curr!=NULL))
    {
        prev=curr;
        curr=curr->next;
    }
    if(curr==head)
        head=head->next;
    else
    {
        prev->next=curr->next;
    }
    delete curr;
    }
}
void node::print()
{
    if(head==NULL)
        cout<<"Nothing to print";
    else
    {
         node* curr=head;
    while(curr!=NULL)
    {
        cout<<"->"<<curr->data;
      curr=curr->next;
    }

}
}
void node::reverse()
{
    node *prev = NULL, *curr=head, *temp;
        while(curr!=NULL){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        head=prev;
    }
    void node:: sort()
    {
        node* temp = NULL;
   node* h = head;
   node* next = head->next;

   while(next!=NULL) {

       if(h->data >next->data) {
           temp = h;
           h = next;
           temp->next = temp->next->next;
           h->next = temp;
           next = h->next;
           }
        else {
            h = h->next;
            next = next->next;

        }
    }}
    void node::deletealt()
    {
     if(head==NULL)
            cout<<"Nothing to delete";
     else{
     node* prev=head;
        while(prev!=NULL)
        {
             node* curr=prev;
            for(int i=0;i<1;i++)
                curr=curr->next;
                prev->next=curr->next;
                delete curr;
                prev=prev->next;
        }}}
        void node::inssort()
        {
            sort();
            node* temp;
            cout<<"Enter value:";
            cin>>temp->data;
            node* curr=head;
       while(curr->data<curr->next->data)
       curr=curr->next;
       node* n;
       n=curr->next;
       curr->next=temp;
       temp->next=n;
        }
int main()
{
node a;
while(1)
{
cout<<"\n 1.Insert an element before another element in the existing list \n 2.Insert an element after another element in the existing list\n 3.Delete a given element from the list \n 4.Traverse the list \n 5.Reverse the list \n 6.Sort the list\n 7.Delete alternate nodes \n 8.Insert in sorted list \n 9.Exit"<<endl;
int x;
cin>>x;
switch(x)
{
    case 1:
        a.insertb();
    break;
    case 2:
        a.inserta();
        break;
    case 3:
        a.deletee();
        break;
    case 4:
        a.print();
        break;
    case 5:
        a.reverse();
        break;
    case 6:
        a.sort();
        break;
    case 7:
        a.deletealt();
        break;
    case 8:
        a.inssort();
        break;
    case 9:
        exit(0);
    default:
        cout<<"Invalid input";
}}
}
