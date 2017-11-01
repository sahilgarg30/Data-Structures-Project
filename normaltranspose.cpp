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
    cin>>m>>n;
    a[0].row=m;
    a[0].column=n;
    cout<<"Enter the elements: ";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
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
void SM::display(SM *a)
{
    cout<<"Fast transpose is : "<<endl<<"Row\t"<<"Column\t"<<"Value\t"<<endl;
    for(int i=0;i<=a[0].value;i++)
    {
        cout<<a[i].row<<"\t"<<a[i].column<<"\t"<<a[i].value<<endl;
    }

}
void SM::transpose(SM *a, SM *b)
{
    int i,j,n,currentb;
    n=a[0].value;
    b[0].row=a[0].column;
    b[0].column=a[0].row;
    b[0].value=n;
    if(n>0)
    {
        currentb=1;
        for(i=0;i<a[0].column;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(a[j].column==i)
                {
                    b[currentb].row=a[j].column;
                    b[currentb].column=a[j].row;
                    b[currentb].value=a[j].value;
                    currentb++;
                }
            }
        }
    }
}
int main()
{
    SM a[20],b[20],c;
    c.input(a);
    c.transpose(a,b);
    c.display(b);
}
