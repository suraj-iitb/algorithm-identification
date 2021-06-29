#include <stdio.h>
int main()
{
    int n,a[100];
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for (int i=0;i<n;i++)
    {
        int v=a[i];
        for (int j=0;j<i;j++)
        {
            if (v<a[j])
            {
                for (int c=i-1;c>=j;c--)
                {
                    a[c+1]=a[c];
                }
                a[j]=v;
                break;
            }
        }
        for (int i=0;i<n;i++)
        {
            if (i==n-1)
                printf("%d\n",a[i]);
            else
                printf("%d ",a[i]);
        }
    }
    return 0;
}

