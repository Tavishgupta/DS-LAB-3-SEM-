#include<iostream>
#define n 100
using namespace std;
class SM{
private:
    int row;
    int col;
    int val;
public:
    void createSparse(int r,int c,int v)
    {
        row=r;
        col=c;
        val=v;

    }
    void display(SM a[])
    {
            int i,j,k=1;
            for( i=0;i<a[0].row;i++){
                for(j=0;j<a[0].col;j++)
                {
                    if((a[k].row==i)&&(a[k].col==j))
                    {
                        cout<<a[k++].val<<"\t";
                    }
                    else
                    {
                        cout<<"0"<<"\t";
                    }
                }cout<<endl;
            }
    }
    void fastTranspose(SM a[],SM b[]){
            int i,j,Total[a[0].col],Index[a[0].col+1];
    b[0].row=a[0].col;
    b[0].col=a[0].row;
    b[0].val=a[0].val;
    if(a[0].val>0){
        for(i=0;i<=a[0].col;i++)
            Total[i]=0;
        for(i=1;i<=a[0].val;i++)
         Total[a[i].col]++;
        Index[0]=1;
        for(i=1;i<=a[0].col;i++){
            Index[i]=Index[i-1]+Total[i-1];
        }
        for(i=1;i<=a[0].val;i++){
            j=Index[a[i].col]++;
        b[j].row=a[i].col;
        b[j].col=a[i].row;
        b[j].val=a[i].val;
        }
   }
        }
};
int main(){
SM a[n],b[n];
int i,j,matrix[n][n],count=0,k=1,row,col;
cout<<"Enter rows and columns"<<endl;
cin>>row>>col;
for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            cin>>matrix[i][j];
            if(matrix[i][j]!=0){
                count++;
                a[k].createSparse(i,j,matrix[i][j]);
                k++;
            }
        }
}a[0].createSparse(i,j,count);
a[0].display(a);
cout<<"Matrix by fast transpose"<<endl;
a[0].fastTranspose(a,b);
b[0].display(b);


}





