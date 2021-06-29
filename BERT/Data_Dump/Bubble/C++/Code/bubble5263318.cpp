#include <stdio.h>
int main()
{
    int n,k;
    int a[101];
    int count=0;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n-i-1;j++)
        {
            if (a[j]>a[j+1])
            {
                k=a[j];
                a[j]=a[j+1];
                a[j+1]=k;
                count++;
            }
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

