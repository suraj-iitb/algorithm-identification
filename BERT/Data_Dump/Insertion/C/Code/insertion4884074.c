#include<stdio.h>
int main(void)
{
    int N;
    scanf("%d",&N);
    
    int A[N],i,v,j;
    
    for(i=0;i<N;i++)
    {
        scanf("%d",&A[i]);
    }
    
    for(i=0;i<N-1;i++)
    {
        printf("%d ",A[i]);
    }
    
    printf("%d\n",A[i]);
    
    int k;
    
    for(i=1;i<=N-1;i++)
    {
        v=A[i];
        j=i-1;
        while(j>=0&&A[j]>=v)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=v;
        
        for(k=0;k<N-1;k++)
        {
            printf("%d ",A[k]);
        }
        
        printf("%d\n",A[k]);
    }
    
    return 0;
}
