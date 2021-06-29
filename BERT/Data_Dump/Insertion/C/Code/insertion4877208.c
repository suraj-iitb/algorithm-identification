#include<stdio.h>

int main(void)
{
    int i, j, n, key;
    int A[100];
    
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d", &A[i]);
    }
    
    for(j=1; j<n; j++)
    {
        for (i=0; i<n-1; i++)
        {
            printf("%d ", A[i]);
        }
        printf("%d\n", A[n-1]);
        
        key = A[j];
        i = j-1;
        
        while((i>=0) && (A[i]>key))
        {
            A[i+1] = A[i];
            i = i-1;
        }
        
        A[i+1] = key;
    }
    
    for(i=0; i<n-1; i++)
    {
        printf("%d ", A[i]);
    }
    
    printf("%d\n", A[n-1]);
    
    return 0;
}

