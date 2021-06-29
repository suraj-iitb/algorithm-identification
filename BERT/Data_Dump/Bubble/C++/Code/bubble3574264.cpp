#include <stdio.h>
int main()
{
    int a[100],i,j,t,n,count=0;
    scanf("%d",&n);  
    for(i=1;i<=n;i++)  
    {
        scanf("%d",&a[i]);
    }
    for(i=1;i<=n-1;i++) 
    {
        for(j=1;j<=n-i;j++) 
        {
            if(a[j]>a[j+1])
            { 
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
                count++;
            }
        }
    }
    int q=0;
    for(i=1;i<=n;i++)  
    {
        if(q)
        {
            printf(" ");
        }
        printf("%d",a[i]);
        q++;
    }
    printf("\n");
    printf("%d\n",count);
    return 0;
}
