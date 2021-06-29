#include<stdio.h>
#include<string.h>
void show(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(i) putchar(' ');
        printf("%d",a[i]);
    }
}
 
void SelectionSort(int a[],int n)
{
    int i,j,min,t,count=0;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i;j<n;j++)
            if(a[min]>a[j])
            {
                min=j;
            }
        t=a[min];a[min]=a[i];a[i]=t;
        if(min!=i) count++;
    }
    show(a,n);
    putchar('\n');
    printf("%d\n",count);
}
int main()
{
    int a[101];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
 
    SelectionSort(a,n);
 
}
