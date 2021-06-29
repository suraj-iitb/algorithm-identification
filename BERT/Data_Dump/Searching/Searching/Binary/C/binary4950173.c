#include<stdio.h>

int a[100000],n;

int binarySearch(int x);

int main(void)
{
    int i,q,k,sum=0;
    
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    
    scanf("%d",&q);
    for(i=0;i<q;i++)
    {
        scanf("%d",&k);
        if(binarySearch(k))
        {
            sum++;
        }
    }
    printf("%d\n",sum);
    
    return 0;
}

int binarySearch(int x)
{
    int l=0,r=n,m;
    
    while(l<r)
    {
        m=(l+r)/2;
        if(x==a[m])
        {
            return 1;
        }
        if(x>a[m])
        {
            l=m+1;
        }
        else if(x<a[m])
        {
            r=m;
        }
    }
    return 0;
}
