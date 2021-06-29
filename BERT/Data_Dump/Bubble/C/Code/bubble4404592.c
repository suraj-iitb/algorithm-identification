#include<stdio.h>
int main()
{
    int n,a[100],i,j,swap=0,t;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0; i<n; i++)
    {
        for(j=n-1; j>=i+1; j--)
        {
            if(a[j]<a[j-1])
            {
                t=a[j];
                a[j]=a[j-1];
                a[j-1]=t;
                swap++;
            }
        }
    }
    for(i=0; i<n; i++)
    {
        if(i!=n-1) printf("%d ",a[i]);
        else printf("%d\n",a[i]);
    }
    printf("%d\n",swap);
}

