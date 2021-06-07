#include<stdio.h>
#include<string.h>
int search(int a[],int n,int target)
{
    a[n]=target;
    int i=0;
    while(a[i]!=target)
        i++;
    return i!=n;
}

int main()
{
    int n,q,count=0;
    int a[10005],b[505];

    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        scanf("%d",&b[i]);
        if(search(a,n,b[i])) count++;
    }
    printf("%d\n",count);
}

