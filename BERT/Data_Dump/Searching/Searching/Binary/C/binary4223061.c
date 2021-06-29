#include <stdio.h>
#define NOT_FOUND 0
int binarySearch(int *p,int key,int n)
{
    int left = 0,right = n;
    int mid;
    while(left<=right)
    {
        mid = (left+right)/2;
        if(p[mid]==key)
            return 1;
        else if(p[mid]>key)
            right = mid - 1;
        else if(p[mid]<key)
            left = mid + 1;
    }
    return NOT_FOUND;
}
int main()
{
    int S[100000],T[50000];
    int n,m,i,count = 0;
    scanf("%d",&n);
    for(i = 0;i < n;i++)
    {
        scanf("%d",&S[i]);
    }
    scanf("%d",&m);
    for(i = 0;i < m;i++)
    {
        scanf("%d",&T[i]);
    }
    for(i = 0;i < m;i++)
    {
        if(binarySearch(S,T[i],n))
            count++;
    }
    printf("%d\n",count);
}


