#include <iostream>
using namespace std;
class Mstack{
    int top[30],bottom[20];
    int ns,maxsize;
    int a[60];
public:
    Mstack(int n,int m)
    {
        ns=m;
        maxsize=n;
        for(int i=0;i<ns;i++)
            top[i]=bottom[i]=((maxsize/ns)*i)-1;
    }
        void push(int,int);
        int pop(int);
        void display(int);
    };

    void Mstack::push(int i,int ele)
    {
        if((top[i]==bottom[i+1])||(top[i]==maxsize-1))
            cout<<"Stack is full";
        else
        {
        top[i]++;
        a[top[i]]=ele;
        }
    }

   int Mstack::pop(int i)
   {
       int ele;
       if(top[i]==bottom[i]){
        cout<<"Stack is empty";
        return 0;
       }
       else
       {
           ele=a[top[i]];
           top[i]--;
           return ele;
       }

   }

   void Mstack::display(int i)
   {

       if(top[i]==bottom[i])
        cout<<"Stack is empty";
       else
       {
           for(int j=top[i];j>bottom[i];j--)
            cout<<a[j]<<endl;
       }

   }
   int main()
   {
       int n,m;
       cout<<"Enter stack size:";
       cin>>n;
       cout<<"Enter number of stacks:";
       cin>>m;
       Mstack s(n,m);
       s.push(0,10);
        s.push(0,20);
         s.push(0,30);
         s.pop(0);
         s.push(1,1);
         s.push(1,2);
         s.pop(1);
          cout<<"First stack elements are:"<<endl;
       s.display(0);
       cout<<"Second stack elements are:"<<endl;
       s.display(1);
   }
