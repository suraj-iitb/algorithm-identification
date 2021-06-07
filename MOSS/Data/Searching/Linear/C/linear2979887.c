#include<stdio.h>

int linearSearch(int,int);

int S[10000];

int main()
{
    int n,q,i,count=0,flag;
    int T[10000];

    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&S[i]);
    }

    scanf("%d",&q);
    for(i=0;i<q;i++)
    {
        scanf("%d",&T[i]);
        flag=linearSearch(n,T[i]);
        if(flag==0)count++;
    }
    printf("%d\n",count);
    return 0;
}

int linearSearch(int n,int key)
{
    int i=0;
    S[n]=key;
    while(S[i]!=key)i++;
    if(i!=n)return 0;
    return 1;
}
