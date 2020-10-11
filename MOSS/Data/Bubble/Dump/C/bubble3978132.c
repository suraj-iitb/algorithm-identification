#include<stdio.h>

int bubblesort(int A[], int N)
{
    int flag, j, temp, cnt, i;
    
    cnt=0;
    i=0;
    flag=1;
    
    while(flag ==1)
    {
        flag = 0;
        
        for(j=N-1; j>=i+1; j--)
        {
            if(A[j]<A[j-1])
            {
                temp = A[j];
                A[j] = A[j-1];
                A[j-1] = temp;
                cnt++;
            }
            
            flag=1;
        }
        i++;
        
    }
    
    return cnt;
    
}

int main(void)
{
    int N, cnt, i;
    
    scanf("%d", &N);
    
    int A[N];
    
    for(i=0; i<N; i++)
    {
        scanf("%d", &A[i]);
    }
    
   cnt = bubblesort(A, N);
    
    for(i=0; i<N; i++)
    {
        if(i>0)
        {
            printf(" ");
        }
        printf("%d", A[i]);
    }
    
    printf("\n");
    
    printf("%d\n", cnt);
}
