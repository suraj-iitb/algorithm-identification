#include <stdio.h>

int main(void)
{
    int i, j;
    int v, w;
    int N;
    scanf("%d", &N);
    
    int A[N];
    for(i=0; i<N; i++)
    {
        scanf("%d", &A[i]);
    }
    for(i=0; i<N; i++)
    {
        printf("%d", A[i]);
        
        if(i!=N-1)
        {
            printf(" ");
        }
    }
    
    printf("\n");
    
    for(i=1; i<N; i++)
    {
        v=A[i];
        w=i-1;
        
        while(w>=0 && A[w]>v)
        {
            A[w+1]=A[w];
            w--;
        }
        
        A[w+1]=v;
        
        for(j=0; j<N; j++)
        {
            printf("%d", A[j]);
            
            if(j!=N-1)
            {
                printf(" ");
            }
        }
        
        printf("\n");
    }
    
    return 0;
}
