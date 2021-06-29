#include<stdio.h>

int A[1000000],c;

int sum(int key)
{
    int a=0,b=c,num;
    while(a<b)
    {
        num=(a+b)/2;
        if(key==A[num]) return 1;
        if(key>A[num])a=num+1;
        else if(key<A[num])b=num;
    }
    return 0;
}
int main()
{
    int i,j,k,tum=0;
    scanf("%d",&c);
    for(i=0;i<c;i++)
    {
        scanf("%d",&A[i]);
        
    }
    scanf("%d",&j);
    for(i=0;i<j;i++)
    {
        scanf("%d",&k);
        if(sum(k))tum++;
        
    }
    printf("%d\n",tum);
    return 0;
}

