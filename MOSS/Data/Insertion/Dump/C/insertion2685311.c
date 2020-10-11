#include<stdio.h>
#include<string.h>
void show(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(i>0) putchar(' ');
        printf("%d",a[i]);
    }
    putchar('\n');
}
void insertionsort(int a[],int n)
{
    int t,i,j;
    for(i=1;i<n;i++)
    {
        t=a[i];
        j=i-1;
        while(j>=0&&a[j]>t)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=t;
        show(a,n);
    }
}

int main()
{
    int a[101],n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    show(a,n);
    insertionsort(a,n);
}

