#include <stdio.h>
int a[100];
int main()
{
    int n,k,i,j,key,sum=0;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
    }
    for(k=1; k<=n; k++)
    {
        if(k>1)
            printf(" ");
        printf("%d",a[k]);
    }
    printf("\n");

    for(j=2; j<=n; j++)
    {
        key=a[j];
        i=j-1;
        while(i>=1&&a[i]>key)
        {
            a[i+1]=a[i];
            i--;
        }
        a[i+1]=key;
        for(k=1; k<=n; k++)
        {
            if(k>1)
                printf(" ");
            printf("%d",a[k]);
        }
        printf("\n");
    }
    return 0;
}
