#include <stdio.h>
#define N 100
int main()
{
    int a[N];
    int i,j,h,n,f,tmp,count=0;

    scanf("%d",&n);

    for(h=0;h<n;h++)
    {
        scanf("%d",&a[h]);
    }
    for(i=0;i<=n-1;i++)
    {
        for(j=n-1;j>=i+1;j--)
        {
            if(a[j]<a[j-1])
            {
                tmp=a[j];
                a[j]=a[j-1];
                a[j-1]=tmp;
                count++;
            }
        }
    }
    for(f=0;f<n;f++)
    {
        printf("%d",a[f]);
        if(f==n-1) break;
        printf(" ");
    }
    printf("\n");
    printf("%d\n",count);
    

    return 0;
}

