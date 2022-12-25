#include <iostream>

using namespace std;

class poly{
    public:
int coe;
int exp;
poly* next;
poly* read();
poly* attach(int,int,poly*);
void display(poly*);
poly* add(poly*,poly*);
};
poly* poly:: read()
{
    int n,c,e;
    cout<<"How many terms?";
    cin>>n;
    poly* front=new poly;
    poly* rear=front;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter coe and exp:";
        cin>>c>>e;
        rear=attach(c,e,rear);
    }
    poly* first= front->next;
    delete front;
    return first;
}
poly* poly::attach(int c,int e,poly* rear)
{
    poly* temp=new poly;
    temp->coe=c;
    temp->exp=e;
    temp->next=NULL;
    rear->next=temp;
    rear=temp;
    return rear;
}
void poly::display(poly* c1)
{
    for(poly* cur=c1;cur!=NULL;cur=cur->next)
    {
        cout<<cur->coe<<"x^"<<cur->exp;
        if(cur->next!=NULL)
            cout<<"+";
    }
    cout<<"\n";
}
poly* poly::add(poly*a,poly* b)
{
    poly* front=new poly;
    poly* rear=front;
    while((a!=NULL)&&(b!=NULL))
    {
        if(a->exp==b->exp)
        {
            attach(a->coe+b->coe,a->exp,rear);
            a=a->next;
            b=b->next;
        }
        else if(a->exp>b->exp)
        {
            rear=attach(a->coe,a->exp,rear);
            a=a->next;
        }
        else
        {
            rear=attach(b->coe,b->exp,rear);
            b=b->next;
        }
    }
    while((a!=NULL))
    {
        rear=attach(a->coe,a->exp,rear);
        a=a->next;
    }
        while((b!=NULL))
    {
        rear=attach(b->coe,b->exp,rear);
        b=b->next;
    }
   poly* first= front->next;
    delete front;
return first;
}

int main()
{
    poly p;
    poly  *a1,*b1,*c1;
    a1= p.read();
    b1=p.read();
    c1=p.add(a1,b1);
    p.display(c1);
}
