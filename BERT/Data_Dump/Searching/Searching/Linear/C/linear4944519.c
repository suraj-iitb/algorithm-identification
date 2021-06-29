#include<stdio.h>

int linearSearch(int A[], int key, int n)
{
    int i=0;
    A[n]=key;
    while(A[i]!=key)
    {
        i++;
    }
    return i;
}

int main(main)
{
    int n;
    scanf("%d", &n);
    int i;
    int a[n+1];
    for(i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    int q;
    scanf("%d", &q);
    int b, c=0, j;
    
    for(i=0; i<q; i++)
    {
        scanf("%d", &b);
        
        if((j=linearSearch(a,b,n))!=n)
        c++;
    }
    printf("%d\n", c);
    return 0;
    
}



