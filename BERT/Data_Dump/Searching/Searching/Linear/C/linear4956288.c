#include<stdio.h>
int linearSearch(int A[] ,int n,int key)
{
   int i = 0;
   A[n] = key;
   while( A[i]!=key)i++;
        return i!=n;
}
int main(void)
{
    int i,j,n,key;
    int A[10001];
    int sum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    scanf("%d",&j);
    for(i=0;i<j;i++)
    {
        scanf("%d",&key);
        if(linearSearch(A, n, key)){sum++;}
    }
    printf("%d\n",sum);
    return 0;
}

