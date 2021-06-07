#include<stdio.h>

int sum(int A[],int a, int key)
{
    int i=0;
    A[a]=key;
    while(A[i]!=key)i++;
    return i!=a;
}

int main()
{
    int a,b,A[10000+1],c,key,tum=0;
    
    scanf("%d",&b);
    for(a=0;a<b;a++)
    {
        scanf("%d",&A[a]);
    }
    scanf("%d",&c);
    for(a=0;a<c;a++)
    {
        scanf("%d",&key);
        if(sum(A,b,key))
        tum++;
        
    }
    printf("%d\n",tum);
    return 0;
}

