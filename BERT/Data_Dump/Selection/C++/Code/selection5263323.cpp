#include <stdio.h>
int main()
{
    int n;
    int a[110],count=0,k;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for (int i=0;i<n;i++)
    {
        int c=i;
        for (int j=i+1;j<n;j++)
        {
            if (a[j]<a[c])
            {
                c=j;
            }
        }
        if (c!=i)
        {
            k=a[c];
            a[c]=a[i];
            a[i]=k;
            count++;
        }
    }
    for (int i=0;i<n;i++)
    {
        if (i==n-1)
            printf("%d\n",a[i]);
        else
            printf("%d ",a[i]);
    }
    printf("%d\n",count);
    return 0;
}

