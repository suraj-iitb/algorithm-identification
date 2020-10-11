#include<stdio.h>
int main()
{
    int i,j,n,a[105],min,t,num=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    {
        min=i;
        for(j=i;j<n;j++)
        {
            if(a[j]<a[min])
                min=j;
        }
        if(a[min]!=a[i])
        {
            t=a[i];
            a[i]=a[min];
            a[min]=t;
            num++;
        }
    }
    for(i=0;i<n-1;i++)
        printf("%d ",a[i]);
    printf("%d\n",a[i]);
    printf("%d\n",num);
    return 0;
}
