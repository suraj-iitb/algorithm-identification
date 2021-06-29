#include<stdio.h>
void insertionSort(int a[],int n)
{
    int i,v,j,k;
    for(i=1; i<=n-1; i++)
    {
        v=a[i];
        j=i-1;
        while(j>=0&&a[j]>v)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=v;
        for(k=0; k<=n-1; k++)
        {
            if(k!=n-1)
                printf("%d ",a[k]);
            else
                printf("%d\n",a[k]);
        }
    }
}
int main()
{
    int n,a[105],i;
    scanf("%d",&n);
    for(i=0; i<=n-1; i++)
        scanf("%d",&a[i]);
    for(i=0; i<=n-1; i++)
    {
        if(i!=n-1)
            printf("%d ",a[i]);
        else
            printf("%d\n",a[i]);


    }
    insertionSort(a,n);
    return 0;
}

