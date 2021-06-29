#include <stdio.h>
#include <stdlib.h>

void insertionSort(int [],int );
void Print(int [],int );

int main()
{
  int i,N;
  int *A;

  scanf("%d",&N);
  if(N<1||N>100) exit(1);
  A = (int *)malloc(N*sizeof(int));

  for(i=0;i<N;i++)
    {
      scanf("%d",&A[i]);
      if(A[i]<0 || A[i]>1000)
	{
	  free(A);
	  exit(2);
	}
    }

  Print(A,N);
  insertionSort(A,N);
      
  free(A);  
  return 0;
}

void insertionSort(int A[],int N)
{
  int i,j,key;
    
  for(i=1;i<=N-1;i++)
    {
      key = A[i];
      j = i-1;
      while( j>=0 && A[j] > key)
	    {
	      A[j+1] = A[j];
	      j--;
	      A[j+1] = key;
	    }
      Print(A,N);
    }
}

void Print(int A[],int N)
{
  int i;
  for(i=0;i<N-1;i++)
    {
      printf("%d ",A[i]);
    }
  printf("%d\n",A[i]);
}

