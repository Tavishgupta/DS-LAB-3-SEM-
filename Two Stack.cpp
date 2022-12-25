#include <iostream>
using namespace std;
#define n 50

class twostack{
int arr[n];
int top1,top2;
public:
twostack();
void push1(int x);
void push2(int x);
int pop1();
int pop2();
void display1();
void display2();
};
twostack::twostack()
{
    top1=-1;
    top2=n;
}
void twostack::push1(int x)
{
    if(top1==top2-1)
        cout<<"Stack is full";
    else
        arr[++top1]=x;

}
void twostack::push2(int x)
{
    if(top2-1==top1)
        cout<<"Stack is full";
    else
        arr[--top2]=x;

}
int twostack::pop1()
{
    if(top1==-1)
        cout<<"Stack is empty";

    else
        {
        int x=arr[top1];
    top1--;
    }

}
int twostack::pop2()
{
    if(top2==n)
       cout<<"Stack is empty";
    else
    {
         int x=arr[top2];
    top2++;
    }

}
void twostack::display1()
{
    cout<<"First stack elements are:"<<endl;
    for(int i=top1;i>=0;i--)
    {
        cout<<arr[i]<<endl;
    }
}
void twostack::display2()
{
    cout<<"Second stack elements are:"<<endl;
    for(int i=top2;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
}

int main()
{
    twostack s;
    s.push1(10);
    s.push1(20);
    s.push2(10);
    s.push2(20);
    s.pop2();
    s.pop1();
    s.display1();
    s.display2();
}

