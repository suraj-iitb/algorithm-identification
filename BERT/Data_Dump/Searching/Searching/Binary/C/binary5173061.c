#include <stdio.h>

int s[100000];


int main()
{
    int i,n,key,q;
    int count=0;

    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&s[i]);
    }
    scanf("%d",&q);
    for(i=0;i<q;i++)
    {
        scanf("%d",&key);
        if(search(key,n)) count++;
    }
    printf("%d\n",count);

    return 0;
}

int search(int key, int n)
{
    int left=0;
    int right=n;
    int mid;
    while(left<right)
    {
        mid=(left+right)/2;
        if(key>s[mid]) left=mid+1;
        else if(key==s[mid]) return 1;
        else right=mid;
    }
    return 0;
}

