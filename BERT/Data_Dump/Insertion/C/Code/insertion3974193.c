#include<stdio.h>

void insertionsort(int A[], int N);

int main(void)
{
    int N;
    
    scanf("%d", &N);
    
    int A[N];
    
    for(int i=0; i<N; i++)
    {
        scanf("%d", &A[i]);
        
    }
    
    for(int l=0; l<N; l++)
    {
        if(l>0)
        {
            printf(" ");
        }
        printf("%d", A[l]);
        
    }
    
    printf("\n");
    
    insertionsort(A, N);
    
}

void insertionsort(int A[], int N)
{
    int j, record;
    
    for(int i=1; i<N; i++)
    {
        record = A[i];
        j = i-1;
        
        while(j>=0 && A[j] > record)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = record;
        
        for(int k=0; k<N; k++)
        {
            if( k > 0)
            {
                printf(" ");   
            }
            
            printf("%d", A[k]);
        }
        
        printf("\n");
        
    }
    
    
}
