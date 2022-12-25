#include <iostream>
#include<string.h>
using namespace std;
#define n 100

class stack{
private:
        char arr[n];
        int top;
    public :
        void push(char ch);
        char pop();
        char peek();
        void display();
        bool isEmpty();
        bool isFull();
        stack();
};

stack::stack(){
    top= -1;
}



bool stack::isEmpty(){
    return (top==-1);
}



bool stack::isFull(){
    return (top==n-1);
}



void stack::push(char ch){
    if(isFull()){
        cout<<"stack overflow"<<endl;
    }
    else
    arr[++top]=ch;
}



char stack::pop(){
    if(isEmpty()){
        cout<<"stack is Empty"<<endl;
        return  -1;
    }
    else
    return arr[top--];



}



char stack::peek(){
    if(isEmpty()){
        cout<<"stack is empty"<<endl;
        return -1;
    }
    return arr[top];
}



void stack::display()
{
    for(int i=top;i>=0;i--){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int j,len=0;
    char c[30],a;
    int flag=0;
    stack s;
    cout<<"Enter expression:";
    cin>>c;
    for(j=0;c[j]!='\0';j++)
        len++;
    for(j=0;j<len;j++)
    {
        if((c[j]=='(')||(c[j]=='[')||(c[j]=='{'))
           s.push(c[j]);
           else
           {
           a= s.pop();
           if((c[j]==')'&& a=='(')||(c[j]==']'&& a=='[')||(c[j]=='}'&& a=='{'))
            flag=1;
            else{
                flag=0;
    cout<<"Invalid expression";
                break;
           }
    }
        }
    if (flag==1 && s.isEmpty())
        cout<<"Valid expression";
}
