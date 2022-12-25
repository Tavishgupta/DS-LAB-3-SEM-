#include <iostream>
#include<string.h>
using namespace std;
#define n 100

class stack{
private:
        int arr[n];
        int top;
    public :
        void push(char ch);
        int pop();
        int peek();
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



int stack::pop(){
    if(isEmpty()){
        cout<<"stack is Empty"<<endl;
        return  -1;
    }
    else
    return arr[top--];



}



int stack::peek(){
    if(isEmpty()){
        cout<<"stack is empty"<<endl;
        return -1;
    }
    return arr[top];
}



void stack::display()
{
    for(int i=top;i>=0;i--){
            if(arr[i]<10)
        cout<<arr[i]<<" ";
    else
        cout<<(char)(arr[i]+55);
    }
}
int main()
{
    int num;
    int base;
    int rem;
    cout<<"Enter number:";
    cin>>num;
    cout<<"Enter base:";
    cin>>base;
    stack s;
    while(num!=0)
    {
        rem=num%base;
        num=num/base;
        s.push(rem);
    }
    s.display();

}



