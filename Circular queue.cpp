#include <iostream>
using namespace std;
#define n 7
class Queue{

    int front,rear;
    int arr[n];
public:
    Queue();
    bool isFull();
    bool isEmpty();
    void insert(int x);
    int del();
    void display();
};

Queue::Queue(){
    front=-1;
    rear=-1;
}

bool Queue::isFull(){
    if((front == 0 && rear == n-1) ||
            (rear == (front-1)%(n-1))){
        return 1;
    }
    else{
        return 0;
    }
}

bool Queue::isEmpty(){
    return (front==rear);
}

void Queue::insert(int x)
{
    if(isFull()){
        cout<<"queue overflow"<<endl;
        return;
    }
    rear=(rear+1)%n;
    arr[rear]=x;
}
int Queue::del(){
if(isEmpty()){
        cout<<"Queue is empty"<<endl;
return -1;
}
front=(front+1)%n;
return arr[front];
}

void Queue::display()
{
    for(int i=(front+1)%n;i<=rear;i++)
    {
        cout<<arr[i]<<"\t";
    }
}

int main(){

    Queue a;
    a.insert(1);
    a.insert(2);
    a.insert(3);
    a.insert(4);
    a.insert(5);
    a.insert(6);
    a.insert(7);
    a.del();
    a.insert(1);
    a.display();


    return 0;
}

