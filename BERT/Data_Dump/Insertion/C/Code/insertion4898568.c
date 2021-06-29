#include<stdio.h>

void insertionSort(int *A, int N);

int main(void)
{
    int N;
    scanf("%d",&N);
    
    int A[N];
    for(int i=0; i<N; i++)
    scanf("%d",&A[i]);
    
	for(int j=0; j<N; j++)
    {
     		
     		if(j==N-1)
     			printf("%d",A[j]);
     		else
     			printf("%d ",A[j]);
     }
     	
	
	printf("\n");
	
    insertionSort(A, N);
}

void insertionSort(int *A, int N)
{
     int i,j,v;
    
   	 for( i=1; i<N; i++)
     {
        v=A[i];
        j=i-1;
         
        while(j >= 0 && A[j] > v)
        {
           A[j+1] = A[j];
           j--;
        }
        
          A[j+1] = v;
     	for(j=0; j<N; j++)
     	{
     		
     		if(j==N-1)
     			printf("%d",A[j]);
     		else
     			printf("%d ",A[j]);
     	}
     	
     	printf("\n");
    }
}

