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
    printf("Enter the degree: ");
    int m,n,k=1,item;
    int i,j;
    scanf("%d",&m);
    n=m;
    m++;
    n++;
    a[0].row=m;
    a[0].column=n;
    printf("\nEnter the elements as a 2-D matrix of size %d: \n",m);
    printf("The matrix row number is equal to power of x and column number is the power of y. Enter the value for each term as the matrix element.\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&item);
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
    printf("Polynomial is : \nx power\ty power\tCoeff\t\n");
    int i;
    for(i=1;i<=a[0].value;i++)
    {
        printf("%d\t%d\t%d\n",a[i].row,a[i].column,a[i].value);;
    }
}
void multiply(SM *m,SM *a,SM *b){
    int i,j,k=1,l;
    for(i=0;i<200;i++) m[i].column = m[i].row = m[i].value = 0;
    m[0].row = a[0].row+b[0].row;
    m[0].column = a[0].column+b[0].column;
    for(i=1;i<=a[0].value;i++){
        for(j=1;j<=b[0].value;j++){
        for(l=1;l<k;l++){
            if(m[l].row == a[i].row+b[j].row && m[l].column==a[i].column+b[j].column){
                m[l].value+=a[i].value*b[j].value;
                break;
            }
        }
        if(l==k){
            m[k].value = a[i].value*b[j].value;
            m[k].row = a[i].row+b[j].row;
            m[k].column=a[i].column+b[j].column;
            k++;
        }
    }
    }
    m[0].value = k-1;
}
int main()
{
    SM a[100],b[100];
    input(a);
    input(b);
    printf("\nThe input polynomials are - \n");
    display(a);
    display(b);
    SM m[200];
    printf("\nMultiplying the polynomials... \n");
    printf("\nThe final polynomial is - \n");
    multiply(m,a,b);
    display(m);
    return 0;
}
