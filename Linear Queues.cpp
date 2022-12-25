#include<iostream>
using namespace std;
#define maxsize 5
class queue
{
private:    
int front;  
int rear;
int arr[40];
public:   
queue();    
void insert(int ele);    
bool isEmpty();    
bool isFull();    
void display();    
int del();
};
queue::queue(){
rear=-1;
front=-1;
}
bool queue::isEmpty()
{
return front==rear;
}
bool queue::isFull()
{
if(rear==maxsize-1)    
{        
cout<<"Queue is full"<<endl;        
return 1;    
}    
else        
return 0;
}
void queue::insert(int ele)
{
if(isFull())    
{        
cout<<"Queue is full"<<endl;        
return;    
}    
else    
{        
arr[++rear]=ele;    
}
}
int queue::del()
{
if(isEmpty())
{        
cout<<"Queue is empty"<<endl;        
return -1;
}
else
{    
return arr[++front];
}
}
void queue::display()
{
if(isEmpty())
{    
cout<<"Stack is empty"<<endl;
}
else{
for(int i=front+1;i<=rear;i++)    
{
cout<<arr[i]<<endl;    
}
}
}
int main()
{    
queue q;    
q.insert(20);    
q.insert(30);    
q.del();    
q.display();
}


