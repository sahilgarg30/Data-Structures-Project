#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100 //Maximum degree possible
#define max(a,b) (a>b?a:b)

typedef struct{
int row;
int column;
int value;
}SM;
void input(SM *a)
{
    cout<<"Enter number of rows and columns: ";
    int m,n,k=1,item;
    int i,j;
    cin>>m>>n;
    a[0].row=m;
    a[0].column=n;
    cout<<"Enter the elements: ";
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            cin>>item;
            if(item==0)
                continue;
            a[k].row=i;
            a[k].column=j;
            a[k].value=item;
            k++;
        }
    }
    a[0].value=k-1;
}
void display(SM *a)
{
    cout<<"Matrix is : "<<endl<<"Row\t"<<"Column\t"<<"Value\t"<<endl;
    for(int i=0;i<=a[0].value;i++)
    {
        cout<<a[i].row<<"\t"<<a[i].column<<"\t"<<a[i].value<<endl;
    }

}
int main()
{
    SM a[100],b[100];
    input(a);
    input(b);
    display(a);
    display(b);
    SM m[200];
    //multiply(m);
    return 0;
}
