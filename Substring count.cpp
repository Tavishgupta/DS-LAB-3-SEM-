#include <iostream>

using namespace std;

int main()
{
   string s;
   string s1;
   int i,j,count=0;
   cout<<"Enter the string:";
   getline(cin,s);
   cout<<"Enter the substring:";
   getline(cin,s1);
   for(i=0;i<s.length();i++){
    if(s[i]==s1[0])
   {
       for(j=0;j<s1.length();j++)
       {
           int k=i;
        if(s[k]!=s1[j])
        break;
        else{
            count++;
        k++;
        }
   }
}}
cout<<"Occurences of substring:";
cout<<count;
}
